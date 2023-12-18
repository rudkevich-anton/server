/**
@brief Unit tests.
*/
#include "mdfile.h"
void test(){
	assert(er("base.txt", "error.txt") == 1);
	assert(er("base.tx", "error.txt") == 12);
	assert(ermd("FGHJD4THCBF7PGB5") == "F004A6B95A6C4F840D2E1E206FB65C0E");
	assert(ermd("FGHJD4THCBF7PGB5") == "F004A6B95A6C4F840D2E1E206FB65C0");
	std::cout<<"Test OK"<<std::endl;
}
int main(){
	test();
	return 0;
}
