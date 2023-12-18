#include <UnitTest++/UnitTest++.h>
#include "mdfile.h"

SUITE(Md5Test)
{
	TEST(MdAlgorithm) {
		CHECK_EQUAL("F004A6B95A6C4F840D2E1E206FB65C0E",MD("FGHJD4THCBF7PGB5"));
	}
	TEST(PassFileCorrect) {
		CHECK_EQUAL(1, er("base.txt", "error.txt"));
	}
	TEST(PassFileInCorrect) {
		CHECK_EQUAL(12, er("bas.txt", "error.txt"));
	}
}
int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
