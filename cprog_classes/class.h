#ifndef CLASS_H
#define CLASS_H

typedef struct _obj Object;

typedef enum _field 
{
	x,
	y

} Field;

extern Object* object_create();
extern int     object_get(Object * obj, Field f);
extern void    object_set(Object *obj, Field f, int val);

#endif
