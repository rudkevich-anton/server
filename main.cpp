#include "mdfile.h"
#include <cfloat>
#include <iomanip>
/**
@brief Главный файл курсовой работы Рудкевич Антона Максимовича
@detailed main.cpp - Главный файл
Сервер: вычисляет сумму квадратов и возвращает клиенту
Есть защита от переполнения типа double
*/

int main(int argc, char *argv[]) {
  if(argc == 1){
    std::cout << "Kalculator"  << std::endl;
    std::cout << "-h info" << std::endl;
    std::cout << "-f file name" << std::endl;
    std::cout << "-p port" << std::endl;
    std::cout << "-e error file" << std::endl;
  return 1;
  }
  int opt;
  int port = 33333;
  std::string file_name = "/etc/vcalc.conf";
  std::string file_error = "/var/log/vcalc.log";
  std::string error;
  while ((opt = getopt(argc, argv, "hf:p:i:e:" ))!=-1 ){
    switch(opt){
      case 'h':
        std::cout << "Kalculator"  << std::endl;
        std::cout << "-f БД пользователей -p порт -e файл ошибок" << std::endl;
        std::cout << "-h info" << std::endl;
        std::cout << "-f file name" << std::endl;
        std::cout << "-p port" << std::endl;
        std::cout << "-e error file" << std::endl;
        return 1;
        break;
      case 'f':{
        file_name = std::string(optarg);
        };
        break;
      case 'p':{
        port = stoi(std::string(optarg));
        }
      case 'e':{
        file_error = std::string(optarg);
        };
        break;
    }
  }
  if(er(file_name, file_error)==12){
    std::cout<<"Error open file"<<std::endl;
    return 1;
  }
  struct sockaddr_in {
    short sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
  };
  struct in_addr {
    unsigned long s_addr;
  };
  int s = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in * self_addr = new (sockaddr_in);
  self_addr->sin_family = AF_INET;
  self_addr->sin_port = htons(port);
  self_addr->sin_addr.s_addr = inet_addr("127.0.0.1");
  std::cout << "Wait for connect client...\n" << "my port is " << self_addr->sin_port << std::endl;
  int b = bind(s,(const sockaddr*) self_addr,sizeof(sockaddr_in));
  if(b == -1) {
    std::cout << "Binding error\n";
    error = "error binding";
    errors(error, file_error);
    return 1;
  }
  listen(s, SOMAXCONN);
  while(true) {
    sockaddr_in * client_addr = new sockaddr_in;
    socklen_t len = sizeof (sockaddr_in);
    int work_sock = accept(s, (sockaddr*)(client_addr), &len);
    if(work_sock == -1) {
      std::cout << "Error #2\n";
      error = "error #2";
      errors(error, file_error);
      return 1;
    }
    else {
      //Успешное подключение к серверу
      std::cout << "Successfull client connection!\n";
      char msg[255];
      char *buffer = new char[4096];
      uint32_t kolvo;
      uint32_t numb;
      // std::vector<double> vect={1, 2, 3, 4};
      double vect;
      std::string ok = "OK";
      std::string salt = "FGHJD4THCBF7PGB5";
      std::string err = "ERR";
      //Авторизация
      recv(work_sock, &msg, sizeof(msg), 0);
      std::cout << "msg: "<<  msg << std::endl;
      std::string message = msg;
      std::string login, hashq;
      std::fstream file;
      file.open(file_name);
      getline (file, login, ':');
      getline (file, hashq);
      std::cout <<"login from file: " << login << std::endl;
      std::cout <<"pass from file: " << hashq << std::endl;
      //СВЕРКА ЛОГИНОВ
      if(message != login){
        std::strcpy(buffer, err.c_str());
        send(work_sock, buffer, err.length(), 0);
        error = "Ошибка логина";
        errors(error, file_error);
        close(s);
        return 1;
      } else {
        //соль отправленная клиенту
        std::strcpy(buffer, salt.c_str());
        send(work_sock, buffer, salt.length(), 0);
        recv(work_sock, msg, sizeof(msg), 0);
        std::cout << "msg: "<< msg << std::endl;
        std::string sah = salt + hashq;
        std::cout << "salt + pass: " << sah << std::endl;
        std::string digest;
        digest = MD(sah);
        //СВЕРКА ПАРОЛЕЙ
        if(digest != msg){
          std::strcpy(buffer, err.c_str());
          send(work_sock, buffer, err.length(), 0);
          error = "Ошибка пароля";
          errors(error, file_error);
          close(s);
          return 1;
        } else {
          std::strcpy(buffer, ok.c_str());
          send(work_sock, buffer, ok.length(), 0);
          recv(work_sock, &kolvo, sizeof(kolvo), 0);
          std::cout << "kolvo: "<< kolvo << std::endl;
          //цикл векторов
          for(uint32_t j=0; j < kolvo; j++){
            recv(work_sock, &numb, sizeof(numb), 0);//прием длинны для первого вектора
            if (numb == 0){
              recv(work_sock, &numb, sizeof(numb), 0);//прием длинны для первого вектора
            }
            std::cout << " numb: "<< numb << std::endl;
            long double sum2 = 0;
            //цикл значений
            for(uint32_t i=0; i < numb; i++){
              int byte_recv;
              byte_recv = recv(work_sock, &vect, sizeof(vect), 0);
              std::cout << "Получено байт: " << byte_recv << std::endl;
              // if(vect == 0){
              //     recv(work_sock, &vect, sizeof(vect), 0);
              // }
              // std::cout <<" =" << 1+i <<"= " << j+1 << " vect value: "<< vect << std::endl;
              std::cout << vect << std::endl;
              sum2 = sum2 + vect*vect;
            }
            // send(work_sock, buffer, ok.length(), 0);
            long double mfc = sum2;
            if (mfc > DBL_MAX)
              mfc = DBL_MAX;
            if (mfc < DBL_MIN)
              mfc = DBL_MIN
            send(work_sock, &mfc, sizeof(mfc), 0);
            std::cout << "Отправляем сумму квадратов" << std::endl;
          }
        }
      }
      std::cout << "Program finish!" <<std::endl;                                    
    }
    return 1;
  }
  return 0;
}
