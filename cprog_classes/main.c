#include <stdio.h>
#include <stdlib.h>
#include "class.h"


int main(int argc, char *argv[])
{
	Object *obj = object_create();

	printf("The Object's x value is -> %d\n", object_get(obj, x));
	printf("The Object's y value is -> %d\n\n", object_get(obj, y));

	printf("Setting x to -1 and setting y to -2\n\n");	
	object_set(obj, x, -1);
	object_set(obj, y, -2);

	printf("The Object's x value is -> %d\n", object_get(obj, x));
	printf("The Object's y value is -> %d\n", object_get(obj, y));

	
	return 0;
}
