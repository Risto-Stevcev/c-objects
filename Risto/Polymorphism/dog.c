#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "dog.h"


const char *
dog_says ()
{
    return "woof";
}

void
guards ()
{
    printf("A dog guards its owners and sheep.\n");
}

DogFunctions dog_functions = {
    dog_says,
    guards
};

Animal *
initDog (char *name, char *breed)
{
    Animal *dog = (Animal *) malloc(sizeof(Animal));
    DogData *dog_data = (DogData *) malloc(sizeof(DogData)); 
    dog->type = DOG; 
    dog->data = dog_data; 
    dog->del = del;
    dog->functions = (AnimalFunctions *) &dog_functions;

    dog->name = name;
    dog_data->breed = breed;
    return dog;
}
