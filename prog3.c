#include <stdio.h>

int main() {
    int arr[100], n, i, j, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                found = 1;
                break;
            }
        }
        if(found)
            break;
    }

    if(found)
        printf("Duplicates found\n");
    else
        printf("No duplicates found\n");

    return 0;
}
