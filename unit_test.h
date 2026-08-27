#ifndef UNIT_TEST
#define UNIT_TEST

#include "scanfs.h"

struct TestCase
{
    int TestType;
    int TestNum;
    double a, b, c;
    int nRootsRef;
    double x1Ref, x2Ref;
};

void RunOneTest(TestCase test);
void DiscrPosTests();
void DiscrZeroTests();
void DiscrNegTests();
void BNotZero();
void AllCoefIsZero();
void CIsntZero();
void RunTableTests();
void RunAllTests();
void TestMenu();

#endif
