/**
@brief Header file with libraries
*/
#include <netinet/in.h>
#include <iostream>
#include <cassert>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <cryptopp/cryptlib.h>
#include <iostream>
#include <vector>
#include <getopt.h>
#include <cryptopp/hex.h> // HexEncoder
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
using namespace CryptoPP;
#include <cryptopp/md5.h> // MD5, for another algorithm - another header file
std::string MD(std::string sah);
void errors(std::string error, std::string name);
int er(std::string file_name, std::string file_error);
