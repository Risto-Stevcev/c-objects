#include <stdio.h>
#include "mystring.h"


int
main(int argc, char *argv[])
{
    char *name;
    if (argc == 2)
        name = argv[1];
    else {
        printf("Usage: %s [name]\n", argv[0]);
        return 1;
    }

    String *str = initString(name);
    str->say_hi(str);
    printf("Name length: %d\n", str->length);
    str->say_bye(str);
    str->del(str);

    return 0;
}
