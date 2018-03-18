
#include "../ma_better.h"

//~~ STRUCTURE DEFS: ~~
typedef struct {

    char* name;
    int age;

} man;

//~~~~~~~~~~~~~~~~~~~~~


//~~ FUNCTION DEFS: ~~~
void better_float_example();
void better_int_example();
void better_man_example();

//~~~~~~~~~~~~~~~~~~~~~


DEFINE_BETTER_STRUCT(float, better_float);
DEFINE_BETTER_STRUCT(int,   better_int);
DEFINE_BETTER_STRUCT(man,   better_man);


int main() {

    better_float_example();
    better_int_example();
    better_man_example();

    return 0;
}


void better_float_example() {

    printf("~ BETTER_FLOAT_EXAMPLE ~\n");

    float array[3] = {1.0, 2.5, 3.0};

    better_float test = MA_GET_ARRAY(
        better_float, 
        array
    );

    for (unsigned i = 0; i < test.len; i++) {
        printf("#%.1f ", ma_get_value_better_float(&test, i));
    }
    printf("\n");

    test = ma_reverse_arr_better_float(&test);

    for (unsigned i = 0; i < test.len; i++) {
        printf("#%.1f ", ma_get_value_better_float(&test, i));
    }
    printf("\n");

    test = ma_trim_arr_better_float(&test, 2, 1);

    for (unsigned i = 0; i < test.len; i++) {
        printf("#%.1f ", ma_get_value_better_float(&test, i));
    }
    printf("\n");

    test = ma_expand_arr_better_float(&test, 10, 42.42);

    for (unsigned i = 0; i < test.len; i++) {
        printf("#%.1f ", ma_get_value_better_float(&test, i));
    }
    printf("\n");

    test = ma_fit_to_arr_better_float(&test, 6, 24.24);
    test = ma_fit_to_arr_better_float(&test, 8, 24.24);

    for (unsigned i = 0; i < test.len; i++) {
        printf("#%.1f ", ma_get_value_better_float(&test, i));
    }

    printf("\nLENGTH: %d\n", test.len);
    printf("SIZE-OF: %d\n", test.size_of);

    ma_clean_arr_better_float(&test);
}


void better_int_example() {

    printf("~ BETTER_INT_EXAMPLE ~\n");

    int array[3] = {1, 2, 3};

    better_int test_2 = MA_GET_ARRAY(
        better_int, 
        array
    );

    for (unsigned i = 0; i < test_2.len; i++) {
        printf("#%d ", ma_get_value_better_int(&test_2, i));
    }
    printf("\n");

    ma_set_value_better_int(&test_2, 1, 42);

    for (unsigned i = 0; i < test_2.len; i++) {
        printf("#%d ", ma_get_value_better_int(&test_2, i));
    }
    printf("\n");

    test_2 = ma_del_value_better_int(&test_2, 2);

    for (unsigned i = 0; i < test_2.len; i++) {
        printf("#%d ", ma_get_value_better_int(&test_2, i));
    }
    printf("\n");

    better_int test_3 = MA_GET_ARRAY(
        better_int,
        array
    );

    test_2 = ma_join_arr_better_int(&test_2, &test_3, 1);

    for (unsigned i = 0; i < test_2.len; i++) {
        printf("#%d ", ma_get_value_better_int(&test_2, i));
    }

    printf("\nLENGTH: %d\n", test_2.len);
    printf("SIZE-OF: %d\n", test_2.size_of);

    ma_clean_arr_better_int(&test_2);
}


void better_man_example() {

    printf("~ BETTER_MAN_EXAMPLE ~\n");

    man humans[4] = {
        {"Jacob", 23}, 
        {"Kyle",  21},
        {"Bobby", 25},
        {"Alice", 27}
    };

    better_man test_humans = MA_GET_ARRAY(
        better_man,
        humans
    );

    for (unsigned i = 0; i < test_humans.len; i++) {
        
        man local_man = ma_get_value_better_man(&test_humans, i);

        printf("#%d %5s, %d\n", 
            i + 1,
            local_man.name,
            local_man.age);
    }

    printf("LENGTH: %d\n", test_humans.len);
    printf("SIZE-OF: %d\n", test_humans.size_of);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");

    test_humans = ma_split_arr_better_man(&test_humans, 1, 1);

    for (unsigned i = 0; i < test_humans.len; i++) {
        
        man local_man = ma_get_value_better_man(&test_humans, i);

        printf("#%d %5s, %d\n", 
            i + 1,
            local_man.name,
            local_man.age);
    }

    printf("LENGTH: %d\n", test_humans.len);
    printf("SIZE-OF: %d\n", test_humans.size_of);

    ma_clean_arr_better_man(&test_humans);
}
