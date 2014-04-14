#include <stdio.h>
#include <stdlib.h>
#include "animal.h"


void
del (void *animal)
{
    Animal *self = (Animal *) animal;
    free(self->data);
    free(self);
}

const char *
say_type (Animal *animal)
{
    if (animal->type == DOG)
        return "dog";
    else if (animal->type == CAT)
        return "cat";
    else if (animal->type == DUCK)
        return "duck";
    else
        return "";
}
