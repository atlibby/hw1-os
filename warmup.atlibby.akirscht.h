

#ifndef CS3010_ASSIGNMENT1_WARMUP_ATLIBBY_AKIRSCHT_H
#define CS3010_ASSIGNMENT1_WARMUP_ATLIBBY_AKIRSCHT_H

#define MAX_NAME_LENGTH 63
typedef struct {
    unsigned int weight;
    char name[1+MAX_NAME_LENGTH];
} Thing;

Thing *createThing(char *name, unsigned int weight);

int compareThings(Thing *thingOne, Thing *thingTwo);

int buildThingArray(Thing **thingArray_p, int *numThings);

#endif //CS3010_ASSIGNMENT1_WARMUP_ATLIBBY_AKIRSCHT_H

