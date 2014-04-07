#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "FooOBJ.h"

struct fooobj {
	int privateint;
	char *privateString;
	/* Depending on your preferences, you
	 * may prefer privateString to be a char buffer[],
	 * OR malloc it and free on delete.
	 */
};

/* Any "class static" vars simply get declared as
static int staticvar;
 * or whatever you like here.
 * Whereas instance variables go in the struct above.
 */

FooOBJ newFooOBJ(){
	FooOBJ foo=(FooOBJ)malloc(sizeof(struct fooobj));
	bzero(foo, sizeof(struct fooobj));
	return foo;
}

void setFooNumber(FooOBJ foo,int num){
	if(foo==NULL) return;  /* you may chose to debugprint something
				*instead
				*/
	foo->privateint=num;
}

void setFooString(FooOBJ foo,char *string){
	/* If you malloced the string, you'll want to free() it here!!*/
	if(foo==NULL) return;
	foo->privateString=string;
}
	

void dumpFooState(FooOBJ foo){
	if(foo==NULL) return;
	printf("value of private int==%d\n", foo->privateint);
        printf("value of private string==");
        if(foo->privateString == NULL){
		puts("(NULL)");
	} else {
		printf("%s\n", foo->privateString);
	}

}

void deleteFooOBJ(FooOBJ foo){
	/* dont forget to free privateString if you malloced it here!!*/
	free(foo);
}
