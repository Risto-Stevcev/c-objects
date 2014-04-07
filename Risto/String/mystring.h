#ifndef MYSTRING_H
#define MYSTRING_H
typedef struct mystring_t
{
    char *name;
    char *bye;
    int length;
    void (*say_hi) ();
    void (*say_bye) ();
    void (*del) ();
} String;

String *initString(char *);
void say_hi(String *);
void say_bye(String *);
#endif
