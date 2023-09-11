// jdh CS3010 Fall 2023
// for the extra-credit portion of the warmup assignment

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "warmup.atlibby.akirscht.h"

#define NUM_THINGS 10

int buildThingArray(Thing **thingArray_p, int *numThings) {
  *thingArray_p = malloc(NUM_THINGS * sizeof(Thing));
  *numThings = NUM_THINGS;
  Thing *thingArray = *thingArray_p;

  char buffer[1 + MAX_NAME_LENGTH];
  for (int i=0; i<NUM_THINGS; ++i) {
    sprintf(buffer, "thing_%d", NUM_THINGS-i);
    strcpy(thingArray[i].name, buffer);
    unsigned int weight = (i*103 + (i+5)*199) % 13;
    thingArray[i].weight = weight;
    printf("%u\n", weight);
  }

  strcpy(thingArray[1].name, thingArray[0].name);

  return 0;
}

int main(){
    /*This will allocate and initialize an array of things. Then, sort the array using by calling the C function qsort() 
    (you’ll have to read about this function). One of the parameters to qsort() will be your
    compareThings() function. Print the thing array before and after you sort it.*/
    Thing *thingArray;
    int numThings = 10;
    buildThingArray(&thingArray, &numThings);

    for (int i = 0; i < numThings; i++) {
        printf("Unsorted: Name=%s, Weight=%u\n", thingArray[i].name, thingArray[i].weight);
    }
    printf("\n");

    qsort(thingArray, numThings, sizeof(Thing), (int (*)(const void *, const void *))compareThings);
    for (int i = 0; i < numThings; i++) {
        printf("Sorted: Name=%s, Weight=%u\n", thingArray[i].name, thingArray[i].weight);
    }
    
    return 0;
}

