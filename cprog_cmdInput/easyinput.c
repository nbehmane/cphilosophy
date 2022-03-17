#include "easyinput_internal.h"


/* Error check for the user */
int error_check(int ret) {
   switch (ret) {
      case SUCCESS:
         break;
      case GENERAL_ERROR:
         fprintf(stderr, "General Error\n");
         break;
      case MALLOC_ERROR:
         fprintf(stderr, "Internal Malloc Error\n");
         break;
      case DEALLOC_ERROR:
         fprintf(stderr, "Internal Free Error\n");
         break;
      default: 
         fprintf(stderr, "Undefined Error\n");
         break;
   }
   return ret;
}

/* Create input interface */
EInput *einput_create(int size, int flags) {

   EInput *new_einput = (EInput *)malloc(sizeof(EInput));
   if (new_einput == NULL)
      return NULL;
   
   new_einput->buffer = (char *)malloc(sizeof(char) * size);
   if (new_einput->buffer == NULL)
      return NULL;

   new_einput->buffer_size = size;
   new_einput->return_code = SUCCESS;
   return new_einput;
}

/* Destroy input interface */
int einput_destroy(EInput *to_destroy) {
   if (to_destroy == NULL)
      return DEALLOC_ERROR;
   free(to_destroy->buffer);
   free(to_destroy);
   return SUCCESS;
}

