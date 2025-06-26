#include <stdio.h>
#include <stdlib.h>
// Yêu cầu nhập vào một giá trị bất kỳ, tìm và in ra vị trí của tất cả các phần tử có giá trị đó trong mảng
int main() {
    int n;
    printf("Enter number of elements in array:");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int target, *arr2 = NULL, arr2Count = 0;
    printf("Enter element to search indexs:");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
            if (arr[i] == target){
                arr2Count++;
                int *temp = realloc(arr2, arr2Count * sizeof *arr2);
                if (!temp) {
                    perror("realloc");
                    free(arr2);
                    free(arr);
                    return 1;
                }
                arr2 = temp;
                arr2[arr2Count - 1] = i;
            }
    }

    if (arr2Count > 0) {
        for (int i = 0; i < arr2Count; i++) {
            printf("%d ", arr2[i]);
        }
    } else {
        printf("Element is not found");
    }

    free(arr);
    free(arr2);

    return 0;
}




