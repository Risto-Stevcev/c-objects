#ifndef MYSTRING_H
#define MYSTRING_H
typedef struct mystring_t
{
    char *name;
    char *bye;
    int length;
    void (*say_hi) (void *);
    void (*say_bye) (void *);
    void (*del) (void *);
} String;

String *initString(char *);
void say_hi(void *);
void say_bye(void *);
#endif
