#include <check.h>
#include <stdlib.h>
#include "../inc/uvec.h"


START_TEST(test_uv_create)
{
    uvec *v;
    int dims[] = {2, 3, 4};
    int i;

    v = uv_create(UV_INT, 3, dims);
    ck_assert_int_eq(v->dtype, UV_INT);
    ck_assert_int_eq(v->size, 2*3*4);
    ck_assert_int_eq(v->itemsize, sizeof(int));
    ck_assert_int_eq(v->nbytes, 2*3*4 * sizeof(int));
    ck_assert_int_eq(v->ndims, 3);

    for(i = 0; i < 3; i++)
        ck_assert_int_eq(v->dims[i], dims[i]);

    // XXX: Re-enable after getting latest libcheck on Travis

    //ck_assert_ptr_eq(v->add, uv_add_int);
    //ck_assert_ptr_eq(v->sum, uv_sum_int);

    /* TODO strides */

    uv_free(v);
}
END_TEST


START_TEST(test_uv_sum)
{
    uvec *v;
    int dims[] = {5};
    int sum, i;

    v = uv_create(UV_INT, 1, dims);
    /* TODO: find a better way to set values */
    int *vdata = (int *)v->data;
    for (i = 0; i < 5; i++)
        vdata[i] = i + 1;

    sum = v->sum(v);
    ck_assert_int_eq(sum, 15);
}
END_TEST


Suite * uvec_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("uvec");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_uv_create);
    tcase_add_test(tc_core, test_uv_sum);
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
