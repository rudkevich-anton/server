/*!
\file
\brief Тестирование md5 алгоритма и существование файлов

Данный файл содержит в себе определения основных 
классов, используемых в модульном тестировании
*/

/**
@brief Тестирование md5 хеширования
*/
#include "mdfile.h"
/**
 * создает md строку из sah строки
 * @brief реализация md5 хеширования
 * @param sah строка для хеширования.
 */
std::string MD(std::string sah){
    Weak::MD5 hash;
    std::string digest;
    StringSource(sah, true,  new HashFilter(hash, new HexEncoder(new StringSink(digest))));  // строка-приемник
      return digest;
 }
/**
 * Write error to file with name
 * @brief write errors to error file
 * @param error error string.
 * @param name name file to write error
 */ 
void errors(std::string error, std::string name){
    std::ofstream file;
    file.open(name, std::ios::app);
    if(file.is_open()){
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        file<<error<<':'<<asctime(timeinfo)<<std::endl;
        std::cout << "error: " << error << std::endl;
    }
}
/**
 * Test file with databases exist
 * @brief Test is file with login and passwords exist
 * @param file_name string with tested database
 * @param file_error string name of file error
 */
int er(std::string file_name, std::string file_error)
{
    std::fstream file;
    file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try{
        file.open(file_name);
        return 1;
    } catch (const std::exception & ex){
        std::string error = "error open file";
        errors(error, file_error);
        return 12;
    }
}
/**
 * Test md5 of sah is correct
 * @brief Test is md5 of sah is correct
 * @param sah - string to md5 hash
 * @return correct md5 string on sah
 */
std::string ermd(std::string sah) {
    std::string res = MD(sah);
    return res;
}