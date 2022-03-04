#ifndef CLASS_INTERNAL_H
#define CLASS_INTERNAL_H

#include <stdio.h>
#include <stdlib.h>

typedef enum _field 
{
	x,
	y

} Field;

typedef struct _obj
{
	int x;
	int y;

} Object;

extern Object* object_create();
extern int     object_get(Object *obj, Field f);
extern void    object_set(Object *obj, Field f, int val);

#endif
