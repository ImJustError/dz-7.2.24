#include <stdlib.h>
#include <stdio.h>
#include "arraydynamic.h"

int main() {

	arrayDynamic array = createNewArray();
	for (int i = 0; i < 5; i++) {
		addNewEl(&array, i);
	}
	addNewEl(&array, 2);
	addNewEl(&array, 2);




	deleteEls(&array, 2);
	printList(array);
	Freearray(array);

	return 0;
}





