#ifndef EASYINPUT_INTERNAL_H
#define EASYINPUT_INTERNAL_H
#include <stdio.h>
#include <stdlib.h>

/*Error Codes*/
#define GENERAL_ERROR -1
#define MALLOC_ERROR -2
#define DEALLOC_ERROR -3

/*Macros*/
#define SUCCESS 0

/* typedefs */
typedef struct einput {
   int return_code;
   int buffer_size;
   char *buffer;
   
} EInput;

int error_check(int ret);
EInput *einput_create(int size, int flags);
int einput_destroy(EInput *to_destroy);

#endif
