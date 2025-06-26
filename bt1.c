//
// Created by Admin on 17/06/202
/*
* Xây dựng chương trình nhập vào một mảng số nguyên có n phần tử với (0 < n <= 100)
Tìm ra phần tử có giá trị lớn nhất trong mảng
 */
#include <stdio.h>
#include <stdlib.h>

//Yêu cầu nhập vào một giá trị bất kỳ, tìm  và in ra chỉ số của phần tử đầu tiên trong mảng giống với giá trị đã nhập

int main() {
    int n;
    printf("Enter number of elements:");
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

    int findNumber;
    int findIndex;
    printf("Enter number to find:");
    scanf("%d", &findNumber);

    for (int i = 1; i < n; i++) {
        if (arr[i] == findNumber) {
            findIndex = i;
            break;
        }
    }

    printf("Your number's index is %d\n", findIndex);

    free(arr);

    return 0;
}



