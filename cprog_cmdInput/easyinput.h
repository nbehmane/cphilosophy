#ifndef EASYINPUT_H
#define EASYINPUT_H

/* Types */
typedef struct einput EInput;

/* Functions */
int error_check(int ret);
EInput *einput_create(int size, int flags);
int einput_destroy(EInput *to_destroy);
int einput_run(EInput *object, char *disp, int max_args, int max_arg_size, char **einput_argv); 


#endif
