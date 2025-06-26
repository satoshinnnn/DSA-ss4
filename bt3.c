#include <stdio.h>
#include <stdlib.h>

// Tìm  và in ra chỉ số của phần tử lớn nhất đầu tiên trong mảng

int main() {
    int n;
    printf("Enter number of elements in array:");
    scanf("%d", &n);

    if (n<=0) {
        printf("Invalid Input");
        return 0;
    }

    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int indexMin =0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min =arr[i];
            indexMin = i;
        }
    }

    printf("The min element is %d\n", min);
    printf("The main element's index is %d", indexMin);

    free(arr);
}




