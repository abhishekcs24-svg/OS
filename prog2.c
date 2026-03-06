#include <stdio.h>

int main() {
    int arr[100], n, i;
    int min, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    min = arr[0];
    pos = 0;

    for(i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
            pos = i;
        }
    }

    printf("Smallest number = %d\n", min);
    printf("Position = %d\n", pos);

    return 0;
}
