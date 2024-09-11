#include <stdio.h>

void main() {
    int a = 5, b = 0, c;
    c = a / b;
    printf("The value of c is: %d\n", c);

    for (int i = 0; i <= 10; i++) {
        if (i == 5)
            continue;
        printf("%d\n", i);
    }

    char str[5] = "hello";
    printf("The length of the string is: %d\n", strlen(str));

    int arr[3];
    arr[4] = 10;
    printf("The value of the last element is: %d\n", arr[4]);

    int *ptr;
    *ptr = 10;
    printf("The value of the pointer is: %d\n", *ptr);
}
