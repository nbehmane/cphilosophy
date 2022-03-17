/* Global Includes */
#include <stdio.h>
#include <stdlib.h>

/* Directory Includes */
#include "easyinput.h"

/* Macros */
#define SUCCESS 0
#define FAIL -1
#define SIZE 256
#define FLAGS 0x00000000
#define MAX_ARGS 10
#define MAX_ARG_SIZE 10

int main(void) {
   int ret = FAIL;
   EInput *input_object = einput_create(SIZE, FLAGS);
   char **argv = (char **)malloc(sizeof(char *) * MAX_ARGS);
   int i = 0;
   
   if (input_object == NULL)
      return FAIL;

   while(ret != EOF_REACHED) {
      ret = einput_run(input_object, "$ ", MAX_ARGS, argv);

      for (i = 0; i < MAX_ARGS && argv[i] != NULL; i++)
         fprintf(stderr, "Arg: %s\n", argv[i]);

      error_check(ret);
   }
      
   ret = einput_destroy(input_object);
   error_check(ret);

   // The user is responsible for freeing the argv array.
   free(argv);

   return SUCCESS;
}
