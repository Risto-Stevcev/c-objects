#ifndef CAT_H
#define CAT_H
typedef struct
cat_data_t
{
    bool is_friendly;
} CatData;

typedef struct
cat_functions_t
{
    char * (*says) ();
    void (*eats_mice) ();
} CatFunctions;

char *cat_says ();
void eats_mice ();
#endif
