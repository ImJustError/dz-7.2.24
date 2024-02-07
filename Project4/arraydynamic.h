#pragma once
#include <stdlib.h>
#include <stdio.h>


typedef struct { int** array; }arrayDynamic;

int deleteEls(arrayDynamic* array, int element);
int addNewEl(arrayDynamic* array, int element);
int printList(arrayDynamic array);
arrayDynamic createNewArray();
int Freearray(arrayDynamic array);