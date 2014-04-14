#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "duck.h"


const char *
duck_says ()
{
    return "quack";
}

void
are_smart ()
{
    printf("A duck is mighty and smart.\n");
}

DuckFunctions duck_functions = {
    duck_says,
    are_smart
};

Animal *
initDuck (char *name, int number_of_feathers)
{
    Animal *duck = (Animal *) malloc(sizeof(Animal));
    DuckData *duck_data = (DuckData *) malloc(sizeof(DuckData)); 
    duck->type = DUCK; 
    duck->data = duck_data;
    duck->del = del;
    duck->functions = (AnimalFunctions *) &duck_functions;

    duck->name = name;
    duck_data->number_of_feathers = number_of_feathers;
    return duck;
}
