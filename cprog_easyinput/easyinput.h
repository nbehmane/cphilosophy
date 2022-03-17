#ifndef EASYINPUT_H
#define EASYINPUT_H

/* Types */
typedef struct einput EInput;

/*Error Codes*/
#define GENERAL_ERROR -1
#define MALLOC_ERROR -2
#define DEALLOC_ERROR -3
#define FAIL -1
#define EOF_REACHED -4
#define NO_OBJECT -5
#define NO_ARGV -6
#define WRONG_ARG -7

/* Functions */
int error_check(int ret);
EInput *einput_create(int size, int flags);
int einput_destroy(EInput *to_destroy);
int einput_run(EInput *object, char *disp, int max_args, char **einput_argv); 


#endif
