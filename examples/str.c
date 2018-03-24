
#include "../ma_better.h"

MA_DEFINE_BETTER_STRUCT(char, string);

void show_string(string* str);

int main() {

    char str_array[] = "Hello, World!";

    string test = MA_GET_ARRAY(string, str_array);

    // test.len = strlen(test.array); //small fix in case of char* variable, requires <string.h>

    show_string(&test);

    test = ma_reverse_string(&test);

    //remove null terminator from beginning of str, ma_reverse_string fucks with ma_swap_values_string (not needed for char*)
    test = ma_del_value_string(&test, 0);

    show_string(&test);

    ma_swap_values_string(&test, 0, 1);

    show_string(&test);

    test = ma_reverse_string(&test);

    show_string(&test);

    ma_clean_string(&test);

    return 0;
}

void show_string(string* str) {

    for (unsigned i = 0; i < str->len; i++) {
        printf("%c", ma_get_value_string(str, i));
    }

    printf("\n");
}
