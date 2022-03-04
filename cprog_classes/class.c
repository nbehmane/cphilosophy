#include "class_internal.h"


Object* object_create()
{
	Object *new_object = (Object *)malloc(sizeof(Object *));
	
	new_object->x = 0;
	new_object->y = 0;

	return new_object;
}

int object_get(Object *obj, Field f)
{
	switch (f)
	{
		case x: return obj->x;
		case y: return obj->y;
	}

	// Should only get here if user is trying to get a field that doesn't exist.

	fprintf(stderr, "object: field does not exist.\n");
	return 0;
}

void object_set(Object *obj, Field f, int val)
{
	switch (f)
	{
		case x: obj->x = val; break;
		case y: obj->y = val; break;
	}
}


