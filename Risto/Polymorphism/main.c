#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "duck.h"


int
main()
{
    Animal *dog  = initDog("Rocky", "Maltese");
    Animal *cat  = initCat("Felix", true);
    Animal *duck = initDuck("Daffy", 11903);
    Animal *animals[3] = {dog, cat, duck};

    ((DogFunctions *) dog->functions)->guards();
    ((CatFunctions *) cat->functions)->eats_mice();
    ((DuckFunctions *) duck->functions)->are_smart();
    printf("\n");
 
    int i;
    for (i = 0; i < sizeof(animals)/sizeof(animals[0]); i++) {
        printf("%s the %s says %s!\n", animals[i]->name, say_type(animals[i]), animals[i]->functions->says());
        if (animals[i]->type == DOG)
            printf("Breed: %s\n", ((DogData *) animals[i]->data)->breed);
        else if (animals[i]->type == CAT)
            ((CatData *) animals[i]->data)->is_friendly ? printf("Friendly cat\n") : printf("Unfriendly cat\n");
        else if (animals[i]->type == DUCK)
            printf("Number of feathers: %d\n", ((DuckData *) animals[i]->data)->number_of_feathers);
        printf("\n");
        animals[i]->del(animals[i]); 
    }
    return 0;
}
