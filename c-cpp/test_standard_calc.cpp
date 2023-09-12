#include "stdio.h"
#include "cutest/CuTest.h"
#include "standard_calc.h"

/**************** Tests for bound_to_180() *******************/
void test_bound_basic1(CuTest *tc) {
    //Regular cases
    CuAssertDblEquals(tc, 60, bound_to_180(60), 0.0001);
    CuAssertDblEquals(tc, -90, bound_to_180(270), 0.0001);
    CuAssertDblEquals(tc, -50, bound_to_180(-50), 0.0001);
    CuAssertDblEquals(tc, 160, bound_to_180(-200), 0.0001);
    CuAssertDblEquals(tc, 100, bound_to_180(460), 0.0001);
    CuAssertDblEquals(tc, -20, bound_to_180(-380), 0.0001);

    //Edge Cases
    CuAssertDblEquals(tc, -180, bound_to_180(180), 0.0001);
    CuAssertDblEquals(tc, -180, bound_to_180(-180), 0.0001);

}

/**************** Tests for is_angle_between() *******************/
void test_between_basic1(CuTest *tc) {
    //Regular Case
    CuAssertTrue(tc, is_angle_between(45, 20, -50));
    CuAssertTrue(tc, is_angle_between(100, 140, 200));
    CuAssertTrue(tc, is_angle_between(400, 380, -390));
    CuAssertTrue(tc, !is_angle_between(20, 190, 100));
    CuAssertTrue(tc, !is_angle_between(200, 80, -60));
    CuAssertTrue(tc, !is_angle_between(480, -380, 550));
    CuAssertTrue(tc, !is_angle_between(1, 4, 3));

    //Edge Case
    CuAssertTrue(tc, is_angle_between(20, 100, 200));
    CuAssertTrue(tc, is_angle_between(10, 10, 10));


}


int main(int argc, char const *argv[]) {

    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_bound_basic1);
    SUITE_ADD_TEST(suite, test_between_basic1);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    return suite->failCount > 0 ? 1 : 0;
}
