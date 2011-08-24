#include <check.h>
#include <stdlib.h>
#include "libcircle.h"
#include "queue.h"

START_TEST (test_queue_init_free)
{
    int free_result = -1;

    CIRCLE_queue_t *q;
    CIRCLE_init();

    q = CIRCLE_queue_init();
    fail_unless(q != NULL, "Initializing a queue failed.");

    free_result = CIRCLE_queue_free(q);
    fail_unless(free_result, "Circle context was not null after free.");
}
END_TEST
 
Suite * libcircle_suite (void)
{
    Suite *s = suite_create ("libcircle");
    TCase *tc_core = tcase_create ("Core");

    tcase_add_test (tc_core, test_queue_init_free);

    suite_add_tcase (s, tc_core);
    return s;
}

int main (void)
{
    int number_failed;

    Suite *s = libcircle_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed (sr);
    srunner_free (sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/* EOF */
