#ifndef DOG_H
#define DOG_H
typedef struct
dog_data_t
{
    char *breed;
} DogData;

typedef struct
dog_functions_t
{
    const char *(*says) ();
    void (*guards) ();
} DogFunctions; 

const char *dog_says ();
void guards ();
#endif
