#ifndef ANIMAL_H
#define ANIMAL_H
typedef enum { DOG, CAT, DUCK } animal_type;
typedef enum { false, true } bool;

typedef struct
animal_functions_t
{
    char * (*says) ();
} AnimalFunctions;

typedef struct 
mytype_t
{
    animal_type type;
    char *name;
    void *data;
    void (*del) ();
    AnimalFunctions *functions;
} Animal;

char *say_type (Animal *);
void del (Animal *);

Animal *initDog(char *, char *);
Animal *initCat(char *, bool);
Animal *initDuck(char *, int);
#endif
