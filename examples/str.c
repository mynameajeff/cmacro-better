
#include "ma_better.h"

DEFINE_BETTER_STRUCT(char, string);

int main() {
    
    string test = MA_GET_ARRAY(string, "Hello, World!");

    // test.len = strlen(test.array); //small fix in case of char* variable

    for (unsigned i = 0; i < test.len; i++) {
        printf("%c", ma_get_value_string(&test, i));
    }
    printf("\n");

    test = ma_reverse_arr_string(&test);

    for (unsigned i = 0; i < test.len; i++) {
        printf("%c", ma_get_value_string(&test, i));
    }
    printf("\n");

    ma_clean_arr_string(&test);

    return 0;
}
