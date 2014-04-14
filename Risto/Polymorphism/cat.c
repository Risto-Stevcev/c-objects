#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "cat.h"


const char *
cat_says ()
{
    return "meow";
}

void
eats_mice ()
{
    printf("A cat eats mice in the house.\n");
}

CatFunctions cat_functions = {
    cat_says,
    eats_mice
};

Animal *
initCat (char *name, bool is_friendly)
{
    Animal *cat = (Animal *) malloc(sizeof(Animal));
    CatData *cat_data = (CatData *) malloc(sizeof(CatData)); 
    cat->type = CAT; 
    cat_data->is_friendly = is_friendly;
    cat->del = del;
    cat->functions = (AnimalFunctions *) &cat_functions;

    cat->name = name;
    cat->data = cat_data;
    return cat;
}
