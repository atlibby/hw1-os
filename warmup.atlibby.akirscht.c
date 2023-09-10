#include <stdio.h>
#include <stdlib.h>
#include "warmup.atlibby.akirscht.h"

Thing *createThing(char *name, unsigned int weight){
    if (name != NULL && sizeof(name) > 0 && sizeof(name) <= MAX_NAME_LENGTH && weight > 0){
        Thing *newThing;
        newThing = malloc(sizeof(Thing));
        return newThing;
    }
    else
        return NULL;

}

int compareThings(Thing *thingOne, Thing *thingTwo){
    
}

