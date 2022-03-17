#include "easyinput_internal.h"


/* Error check for the user */
int error_check(int ret) {
   switch (ret) {
      case SUCCESS:
         break;
      case GENERAL_ERROR | FAIL:
         fprintf(stderr, "General Error\n");
         break;
      case MALLOC_ERROR:
         fprintf(stderr, "Internal Malloc Error\n");
         break;
      case DEALLOC_ERROR:
         fprintf(stderr, "Internal Free Error\n");
         break;
      case EOF_REACHED:
         fprintf(stderr, "EOF reached.\n");
         break;
      case NO_OBJECT:
         fprintf(stderr, "No object given.\n");
         break;
      case NO_ARGV:
         fprintf(stderr, "No argv given.\n");
         break;
      case WRONG_ARG:
         fprintf(stderr, "Argument(s) are incorrect.\n");
         break;
      default: 
         fprintf(stderr, "Undefined Error\n");
         break;
   }
   return ret;
}

/* Internal functions */
int strip_newline(char *buffer, int size) {
   if (buffer == NULL)
      return FAIL;

   if (size == 0)
      return FAIL;

   if (buffer[size - 1] != '\n')
      return FAIL;
   buffer[size - 1] = '\0'; 

   return SUCCESS;
}

/* Get input from the user
 * return a list of strings.
 */
int einput_run(EInput *object, 
   char *disp,
   int max_args, 
   char **einput_argv) {

   int ret = -1;
   int i = 0;
   char *token = NULL;

   if (object == NULL)
      return NO_OBJECT;

   if (einput_argv == NULL)
      return NO_ARGV;
   
   if (max_args <= 0)
      return WRONG_ARG;
   

   printf("%s", disp);
   ret = getline(&(object->buffer), &(object->buffer_size), stdin); 

   if (ret == EOF) {
      einput_argv[0] = NULL;
      return EOF_REACHED;
   }

   strip_newline(object->buffer, ret);

   token = strtok(object->buffer, " ");
   for (; i < max_args; i++) {
      if (token == NULL) {
         einput_argv[i] = NULL;
         return SUCCESS;
      }
      einput_argv[i] = token;
      token = strtok(NULL, " ");
   }

   return SUCCESS;
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

