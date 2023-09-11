#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup.atlibby.akirscht.h"

int createAndCheck(char *testname, char *name, int weight, int expectFail, Thing **thingReturn) {
  Thing *thing;
  int rc = 0;

  thing = createThing(name, weight);
  if ( expectFail ) {
    if (thing != NULL) {
      printf("error: test %s fails; expected NULL return value\n", testname);
      rc = 1;
    }
  } else {
    *thingReturn = thing;
    if ( strcmp(thing->name, name) ) {
      printf("error: test %s fails; name is not correct\n", testname);
      rc = 1;
    }
    if (thing->weight != weight) {
      printf("error: test %s fails; weight is not correct\n", testname);
      rc = 1;
    }
  }

  if (rc == 0)
    printf("pass test %s\n", testname);

  return rc;
} // createAndCheck()

//------------------------------------------------------

int compareCheck(char *testname, Thing *thing1, Thing *thing2, int expected) {
  int res, fail;

  fail = 0;
  res = compareThings(thing1, thing2);
  if (expected == 0) {
    if (res != 0) {
      printf("error: test %s fails; expected zero from comparison; got %d\n", testname, res);
      fail = 1;
    }
  } else if (expected > 0) {
    if (res != 1) {
      printf("error: test %s fails; expected return value = 1 from comparison; got %d\n", testname, res);
      fail = 1;
    }
  } else {
    if (res != -1) {
      printf("error: test %s fails; expected negative return value = -1 from comparison; got %d\n", testname, res);
      fail = 1;
    }
  }

  if (fail == 0)
    printf("pass test %s\n", testname);

  return fail;
} // compareCheck()

//------------------------------------------------------

int main() {
  Thing *thing1, *thing2, *thing3, *thing4, *thing5;
  int numfails = 0;
  int rc;

  thing1 = NULL;
  thing2 = NULL;
  thing3 = NULL;
  thing4 = NULL;
  thing5 = NULL;

  // this should fail
  rc = createAndCheck("T1", NULL, 34, 1, NULL);
  if (rc)
    numfails = numfails + 1;

  // this should fail
  rc = createAndCheck("T2", "", 81, 1, NULL);
  if (rc)
    numfails = numfails + 1;

  // this should fail
  rc = createAndCheck("T3", "rock", 0, 1, NULL);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T4", "rock", 121, 0, &thing1);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T5", "book", 10, 0, &thing2);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T6", "book", 12, 0, &thing3);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T7", "cat", 10, 0, &thing4);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T8", "egg",  4, 0, &thing5);
  if (rc)
    numfails = numfails + 1;

  if (thing1 != NULL && thing2 != NULL && thing3 != NULL && thing4 != NULL && thing5 != NULL) {
    rc = compareCheck("T9", thing1, thing2, 1);
    if (rc)
      numfails = numfails + 1;

    rc = compareCheck("T10", thing3, thing2, 1);
    if (rc)
      numfails = numfails + 1;

    rc = compareCheck("T11", thing3, thing3, 0);
    if (rc)
      numfails = numfails + 1;

    rc = compareCheck("T12", thing5, thing4, 1);
    if (rc)
      numfails = numfails + 1;
  } else {
    printf("was not able to run some tests\n");
  }

  if (numfails == 0) {
    printf("all tests pass\n");
    return 0;
  } else {
    printf("%d test(s) failed\n", numfails);
    return 8;
  }

}
