#include <stdlib.h>

#include <check.h>
#include "../inc/uvec.h"

START_TEST(test_uv_create)
{
    uvec *v;
    int dims[] = {2, 3};

    v = uv_create(UV_INT, 2, dims);
    ck_assert_int_eq(v->dtype, UV_INT);
}
END_TEST


Suite * uvec_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("uvec");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_uv_create);
    suite_add_tcase(s, tc_core);

    return s;
}


int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = uvec_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
