#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    int *arr = malloc(n * sizeof *arr);
    if (!arr) {
        perror("malloc");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    int *arr2 = NULL;
    int arr2Count = 0;
    int half = n / 2;

    for (int i = 0; i < half; i++) {
            if (arr[i] == arr[n-1-i]) {
                arr2Count++;
                int *temp = realloc(arr2, arr2Count * sizeof *arr2);
                if (!temp) {
                    perror("realloc");
                    free(arr2);
                    free(arr);
                    return 1;
                }
                arr2 = temp;
                arr2[arr2Count - 1] = arr[i];
        }
    }

    if (arr2Count > 0) {
        for (int i = 0; i < arr2Count; i++) {
            printf("%d \n", arr2[i]);
        }
    } else {
        printf("No mirror element\n");
    }

    free(arr2);
    free(arr);
    return 0;
}
