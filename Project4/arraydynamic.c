#include <stdlib.h>
#include "arraydynamic.h"
#include <stdio.h>


void* memAlloc(int size);
void* memreAlloc(int size, int** array);
int deleteEl(arrayDynamic* array, int element);
int maxels(arrayDynamic array);


arrayDynamic createNewArray() {
	arrayDynamic NewArray;
	NewArray.array = memAlloc(sizeof(int));
	if ( !NewArray.array) return;
	*NewArray.array = NULL;
	return NewArray;
}


void* memAlloc(int size) {
	void* point = malloc(size);
	if (!point) {
		printf("error mem allocation");
		return NULL;
	}
	return point;
}



void* memreAlloc(int size,int** array) {
	void* point = realloc(array,size);
	if (!point) {
		printf("error mem allocation");
		return NULL;
	}
	return point;
}




int addNewEl(arrayDynamic* array, int element) {
	int size = 0;
	int** tmp = array->array;
	for (; *tmp != NULL; tmp++,size++);
	array->array = memreAlloc( (size + 1)* sizeof(int*), array->array);
	if (!array->array)return;
	tmp = array->array;
	for (int i=0; i<size; tmp++,i++);
	*tmp = memAlloc(sizeof(int));
	if (!*tmp)return;
	**tmp = element;
	tmp++;
	*tmp = NULL;
	return 0;
}

int printList(arrayDynamic array) {
	int** tmp = array.array;
	for (; *tmp != NULL; *tmp++) {
		printf("%d  ", **tmp);
	}
	return 0;
}

int deleteEls(arrayDynamic* array, int element) {
	for (;deleteEl(array,element)!=1;);
}

int deleteEl(arrayDynamic* array, int element) {
	
	int** tmp = array->array;
	for (; *tmp != NULL&& **tmp != element; tmp++);
	if (*tmp == NULL) {
		return 1;
	}
	for (;*tmp!=NULL;tmp++) {
		*tmp = *(tmp + 1);
	}
	*(tmp + 1) = NULL;
	int size = maxels(*array);

	array->array = memreAlloc((size+1 ) * sizeof(int*), array->array);
	
	if (!array->array)return 2;

	return 0;
}



int maxels(arrayDynamic array) {
	int size = 0;
	int** tmp = array.array;
	for (; *tmp != NULL; tmp++, size++);

	return size;
}



int Freearray(arrayDynamic array) {
	int** tmp = array.array;
	for (; *tmp != NULL; tmp++)free(*tmp);
	free(array.array);
	return 0;
}