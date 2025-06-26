#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements in array:");
    scanf("%d", &n);

    if (n<=0) {
        printf("Invalid Input");
        return 1;
    }

    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int m;
    printf("Enter number of elements wanting to add into array:");
    scanf("%d", &m);

    if (m<0) {
        printf("Invalid Input");
        return 1;
    }

    int newSize = n+m;
    int *temp = realloc(arr, newSize* sizeof(int));
    if (temp == NULL) {
        printf("Reallocation failed.\n");
        free(arr);
        return 1;
    }



    arr = temp;

    for (int i = n; i < newSize; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
}




