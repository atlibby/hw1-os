#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup.atlibby.akirscht.h"

Thing *createThing(char *name, unsigned int weight){
    if (name != NULL && strlen(name) > 0 && sizeof(name) <= MAX_NAME_LENGTH && weight > 0){
        Thing *newThing;
        newThing = malloc(sizeof(Thing));
        strcpy(newThing->name, name); // the arrow says that this is a pointer variable
        newThing->weight = weight;

        return newThing;
    }
    else{return NULL;}

}


int compareThings(Thing *thingOne, Thing *thingTwo){
    if (strcmp(thingOne->name, thingTwo->name) < 0){return -1;}
    else if (strcmp(thingOne->name, thingTwo->name) > 0){return 1;}
    else {
        if (thingOne->weight < thingTwo->weight){return -1;}
        else if (thingOne->weight > thingTwo->weight){return 1;}
        else {return 0;}
    }
}

