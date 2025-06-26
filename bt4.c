#include <stdio.h>
#include <stdlib.h>

// Yêu cầu nhập vào một giá trị bất kỳ, tìm  và in ra chỉ số của phần tử cuối cùng trong mảng giống với giá trị đã nhập

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
    int flag = 0;
    int number, numberIndex;
    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            numberIndex = i;
            flag = 1;
        }
    }
    if (!flag) {
        printf("Element not found.\n");
        free(arr);
        return 1;
    }

    printf("The entered number's index is: %d\n", numberIndex);

    free(arr);
}




