
#include "../ma_better.h"

DEFINE_BETTER_STRUCT(float*, floatptr_array);

int main() {

    float* array_normal[2] = {
        malloc(sizeof(float) * 3), 
        malloc(sizeof(float) * 3)
    };
    
    for (unsigned i = 1; i <= 2; i++) {
        for (unsigned n = 1; n <= 3; n++) {
            array_normal[i-1][n-1] = n + i;
        }
    }

    floatptr_array test = MA_GET_ARRAY(
        floatptr_array, 
        array_normal
    );

    for (unsigned i = 0; i < test.len; i++) {
        for (unsigned n = 0; n < 3; n++) {
            printf("#%.1f ", ma_get_value_floatptr_array(&test, i)[n]);
        }
    }

    printf("\n");

    free(array_normal[0]);
    free(array_normal[1]);

    return 0;
}
