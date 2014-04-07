#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"


void
say_hi(String *self)
{
    printf("Hello, %s!\n", self->name); 
}

void
say_bye(String *self)
{
    printf("%s\n", self->bye);
}

void
del(String *self)
{
    free(self->bye);
    free(self);
}

String * 
initString(char *name)
{
    String *str = (String *) malloc(sizeof(String));
    str->say_hi = say_hi;
    str->say_bye = say_bye;
    str->del = del;

    char *bye = (char *) malloc(sizeof(char) * (strlen("Bye!") + 1));
    strcpy(bye, "Bye!");
    str->name = name;
    str->bye = bye;
    str->length = strlen(str->name);
    return str;
}
