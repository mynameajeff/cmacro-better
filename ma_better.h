
// INCLUDES:
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//~~~~~~~~~~~~~~~~~~~~~


// MACRO DEFINITIONS:

#define N_ITEMS(x)  (sizeof(x) / sizeof((x)[0]))

#define ERROR_FAILED(arg1) { \
    fprintf(stderr, "[CMB_ARRAY ERROR] failed to %s!\n", arg1); \
    exit(1); \
}

#define MA_GET_ARRAY(name, array) ma_expanded_get_##name(array, sizeof(array), N_ITEMS(array), false, true)

#define DEFINE_BETTER_STRUCT(value, name)              \
                                                       \
typedef struct {                                       \
                                                       \
    value* array;                                      \
                                                       \
    unsigned size_of;                                  \
    unsigned len;                                      \
                                                       \
    bool isMalloc   : 1;                               \
    bool shouldFree : 1;                               \
                                                       \
} name;                                                \
                                                       \
                                                       \
void ma_clean_arr_##name(name* array) {                \
                                                       \
    if (array->isMalloc && array->shouldFree) {        \
        free(array->array);                            \
    }                                                  \
}                                                      \
                                                       \
                                                       \
name ma_expanded_get_##name(value* name##_array,       \
                            unsigned size_param,       \
                            unsigned length,           \
                            bool isMalloc,             \
                            bool shouldFree) {         \
    name arr;                                          \
                                                       \
    arr.len        = length;                           \
    arr.array      = name##_array;                     \
    arr.size_of    = size_param;                       \
    arr.isMalloc   = isMalloc;                         \
    arr.shouldFree = shouldFree;                       \
                                                       \
    return arr;                                        \
}                                                      \
                                                       \
                                                       \
void ma_set_value_##name(name* array,                  \
                         unsigned index,               \
                         value val) {                  \
                                                       \
    if (index < array->len) {                          \
        array->array[index] = val;                     \
    }                                                  \
                                                       \
    else {                                             \
                                                       \
        char buffer[30];                               \
                                                       \
        sprintf(                                       \
            buffer,                                    \
            "set Value at index %u",                   \
            index                                      \
        );                                             \
                                                       \
        ERROR_FAILED(buffer);                          \
    }                                                  \
}                                                      \
                                                       \
                                                       \
value ma_get_value_##name(name* array,                 \
                          unsigned index) {            \
                                                       \
    if (index < array->len) {                          \
        return array->array[index];                    \
    }                                                  \
                                                       \
    else {                                             \
        ERROR_FAILED("get value at given index")       \
    }                                                  \
}                                                      \
                                                       \
                                                       \
name ma_del_value_##name(name* array,                  \
                         unsigned index) {             \
                                                       \
    unsigned l_index    = index + 1;                   \
    unsigned new_length = array->len - 1;              \
    unsigned size       = sizeof(value) * new_length;  \
                                                       \
    value*   new_array  = malloc(size);                \
    bool     isSwitched = false;                       \
                                                       \
    if (new_array == NULL) {                           \
        ERROR_FAILED("allocate memory for array");     \
    }                                                  \
                                                       \
    else if (l_index >  array->len) {                  \
                                                       \
        char buffer[32];                               \
                                                       \
        sprintf(                                       \
            buffer,                                    \
            "delete Value at index %u",                \
            index                                      \
        );                                             \
                                                       \
        ERROR_FAILED(buffer);                          \
    }                                                  \
                                                       \
    for (unsigned i = 0; i < new_length; i++) {        \
                                                       \
        if (i == (l_index - 1)) {                      \
            new_array[i] = array->array[i + 1];        \
            isSwitched   = true;                       \
        }                                              \
                                                       \
        else {                                         \
                                                       \
            if (isSwitched) {                          \
                new_array[i] = array->array[i + 1];    \
            }                                          \
                                                       \
            else {                                     \
                new_array[i] = array->array[i];        \
            }                                          \
                                                       \
        }                                              \
                                                       \
    }                                                  \
                                                       \
                                                       \
    ma_clean_arr_##name(array);                        \
                                                       \
    return ma_expanded_get_##name(new_array,           \
                                  size,                \
                                  new_length,          \
                                  true,                \
                                  true);               \
}                                                      \
                                                       \
                                                       \
name ma_reverse_arr_##name(name* array) {              \
                                                       \
    value* new_array = malloc(array->size_of);         \
                                                       \
    for (                                              \
        unsigned i = 0, x = (array->len - 1);          \
        i < array->len;                                \
        new_array[i++] = array->array[x--]             \
    );                                                 \
                                                       \
    ma_clean_arr_##name(array);                        \
                                                       \
    return ma_expanded_get_##name(new_array,           \
                                  array->size_of,      \
                                  array->len,          \
                                  true,                \
                                  true);               \
}                                                      \
                                                       \
                                                       \
name ma_split_arr_##name(name* array,                  \
                         unsigned index,               \
                         unsigned lor) {               \
                                                       \
    bool isLooping = true;                             \
    bool isCutting = false;                            \
                                                       \
    unsigned length = ((lor == 0) ?                    \
        index : (array->len - index));                 \
                                                       \
    unsigned size = sizeof(value) * length;            \
                                                       \
    value* new_array = malloc(size);                   \
                                                       \
                                                       \
    for (unsigned i = 0, n = 0;                        \
         isLooping && i <= array->len; i++) {          \
                                                       \
        if (i == index) {                              \
                                                       \
            if (lor == 0) {                            \
                isLooping = false;                     \
            }                                          \
                                                       \
            else {                                     \
                isCutting = true;                      \
            }                                          \
                                                       \
        }                                              \
                                                       \
        else {                                         \
                                                       \
            if (lor == 0) {                            \
                new_array[i]   = array->array[i];      \
            }                                          \
                                                       \
            else if (isCutting) {                      \
                new_array[n++] = array->array[i - 1];  \
            }                                          \
        }                                              \
                                                       \
    }                                                  \
                                                       \
                                                       \
    ma_clean_arr_##name(array);                        \
                                                       \
    return ma_expanded_get_##name(new_array,           \
                                  size,                \
                                  length,              \
                                  true,                \
                                  true);               \
}                                                      \
                                                       \
                                                       \
name ma_join_arr_##name(name* array_1,                 \
                        name* array_2,                 \
                        unsigned lor) {                \
                                                       \
    unsigned length = (array_1->len + array_2->len);   \
    unsigned size   = sizeof(value) * length;          \
                                                       \
    value* new_array = malloc(size);                   \
                                                       \
    name *arr_1, *arr_2;                               \
                                                       \
    if (lor == 0) {                                    \
                                                       \
        arr_1 = array_2;                               \
        arr_2 = array_1;                               \
    }                                                  \
                                                       \
    else {                                             \
                                                       \
        arr_1 = array_1;                               \
        arr_2 = array_2;                               \
    }                                                  \
                                                       \
                                                       \
    for (unsigned i = 0; i < arr_1->len; i++) {        \
        new_array[i] = arr_1->array[i];                \
    }                                                  \
                                                       \
    for (unsigned i = 0; i < arr_2->len; i++) {        \
        new_array[i + arr_1->len] = arr_2->array[i];   \
    }                                                  \
                                                       \
    ma_clean_arr_##name(array_1);                      \
    ma_clean_arr_##name(array_2);                      \
                                                       \
    return ma_expanded_get_##name(new_array,           \
                                      size,            \
                                      length,          \
                                      true,            \
                                      true);           \
}                                                      \
                                                       \
                                                       \
name ma_trim_arr_##name(name* array,                   \
                        unsigned len,                  \
                        unsigned lor) {                \
                                                       \
    unsigned length = (array->len - len);              \
    unsigned size   = sizeof(value) * length;          \
                                                       \
    value* new_array = malloc(size);                   \
                                                       \
    for (unsigned i = 0; i < length; i++) {            \
        new_array[i] = array->array[                   \
            (lor == 0) ? i + len : i                   \
        ];                                             \
    }                                                  \
                                                       \
    ma_clean_arr_##name(array);                        \
                                                       \
    return ma_expanded_get_##name(new_array,           \
                                  size,                \
                                  length,              \
                                  true,                \
                                  true);               \
}                                                      \
                                                       \
                                                       \
name ma_return_expand_##name(name* array,              \
                             value* new_array,         \
                             value base_value,         \
                             unsigned size,            \
                             unsigned len) {           \
                                                       \
    for (unsigned i = 0; i < len; i++) {               \
                                                       \
        if (i >= array->len) {                         \
            new_array[i] = base_value;                 \
        }                                              \
                                                       \
        else {                                         \
            new_array[i] = array->array[i];            \
        }                                              \
    }                                                  \
                                                       \
    ma_clean_arr_##name(array);                        \
                                                       \
    return ma_expanded_get_##name(new_array,           \
                                  size,                \
                                  len,                 \
                                  true,                \
                                  true);               \
}                                                      \
                                                       \
                                                       \
name ma_expand_arr_##name(name* array,                 \
                          unsigned len,                \
                          value base_value) {          \
                                                       \
    unsigned length = (array->len + len);              \
    unsigned size   = sizeof(value) * length;          \
                                                       \
    value* new_array = malloc(size);                   \
                                                       \
    return ma_return_expand_##name(array,              \
                                   new_array,          \
                                   base_value,         \
                                   size,               \
                                   length);            \
}                                                      \
                                                       \
                                                       \
name ma_fit_to_arr_##name(name* array,                 \
                          unsigned len,                \
                          value base_value) {          \
                                                       \
    unsigned size = sizeof(value) * len;               \
                                                       \
    value* new_array = malloc(size);                   \
                                                       \
    return ma_return_expand_##name(array,              \
                                   new_array,          \
                                   base_value,         \
                                   size,               \
                                   len);               \
}

//~~~~~~~~~~~~~~~~~~~~~
