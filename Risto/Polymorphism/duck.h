#ifndef DUCK_H
#define DUCK_H
typedef struct
duck_data_t
{
    int number_of_feathers;
} DuckData;

typedef struct
duck_functions_t
{
    char * (*says) ();
    void (*are_smart) ();
} DuckFunctions; 

char *duck_says ();
void are_smart ();
#endif
