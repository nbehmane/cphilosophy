#ifndef EASYINPUT_INTERNAL_H
#define EASYINPUT_INTERNAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Error Codes*/
#define GENERAL_ERROR -1
#define MALLOC_ERROR -2
#define DEALLOC_ERROR -3
#define FAIL -1
#define EOF_REACHED -4
#define NO_OBJECT -5
#define NO_ARGV -6

/*Macros*/
#define SUCCESS 0

/* typedefs */
typedef struct einput {
   int return_code;
   size_t buffer_size;
   char *buffer;
   
} EInput;

int error_check(int ret);
EInput *einput_create(int size, int flags);
int einput_destroy(EInput *to_destroy);
int einput_run(EInput *object, char *disp, int max_args, int max_arg_size, char **einput_argv); 

#endif