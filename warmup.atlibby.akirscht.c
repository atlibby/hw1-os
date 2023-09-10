#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    thingOne = malloc(sizeof(Thing));
    thingTwo = malloc(sizeof(Thing));
    char name1[1 + MAX_NAME_LENGTH], name2[1 + MAX_NAME_LENGTH];
    int res;
    strcpy(name1, thingOne->name);
    strcpy(name2, thingTwo->name);
    res = strcmp(name1, name2);
    if (res == -1)
        return -1;
    if (res == 1)
        return 1;
    if (res == 0){
        if(thingOne->weight > thingTwo->weight)
            return -1;
        if(thingOne->weight < thingTwo->weight)
            return 1;
        if(thingOne->weight == thingTwo->weight)
            return 0;
    }
}

