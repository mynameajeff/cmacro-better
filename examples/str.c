
#include "../ma_better.h"

DEFINE_BETTER_STRUCT(char, string);

int main() {

    char* array_normal = "Hello, World!";
    
    string test = MA_GET_ARRAY(
        string, 
        array_normal
    );

    test.len = strlen(test.array); //small fix, as since this is with a pointer, it can't detect the length correctly.

    for (unsigned i = 0; i < test.len; i++) {
        printf("%c", ma_get_value_string(&test, i));
    }
    printf("\n");

    return 0;
}
