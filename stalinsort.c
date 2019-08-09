#include <stdio.h>
#include <stdlib.h>

int *stalinSort(int *arr, int size, int *newSize) {
    int i;
    int *sortedArr;

    sortedArr = (int*) malloc(sizeof(int));
    sortedArr[0] = arr[0];

    for (i = 1; i < size; ++i) {
        if (arr[i] >= sortedArr[(*newSize)-1]) {
            ++(*(newSize));
            sortedArr = (int*) realloc(sortedArr, *newSize * sizeof(int));
            sortedArr[*newSize-1] = arr[i];
        }
    }
    return sortedArr;
}

// an example
int main(int argc, char const *argv[]) {
    int i, newSize = 1;
    int *sortedArr;
    int array[10] = {1, 2, 4, 3, 6, 8, 0, 9, 5, 7};
    
    sortedArr = stalinSort(array, 10, &newSize);

    for (i = 0; i < newSize; ++i)
        (void) printf("%i ", sortedArr[i]);

    (void) printf("\n");

    free(sortedArr);
    return 0;
}