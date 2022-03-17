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

int main(void) {
   int ret = FAIL;
   EInput *input_object = einput_create(SIZE, FLAGS);
   
   if (input_object == NULL)
      return FAIL;

   ret = einput_destroy(input_object);
   error_check(ret);
      

   return SUCCESS;
}
