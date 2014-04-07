typedef struct fooobj * FooOBJ;
FooOBJ newFooOBJ();
void setFooNumber(FooOBJ,int);
void setFooString(FooOBJ,char *); /* make comments about copy or not here */
void dumpFooState(FooOBJ);      /* dumps debug contents of FooOBJ to stdout */
void deleteFooOBJ(FooOBJ);
