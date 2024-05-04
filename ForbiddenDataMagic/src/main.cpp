#include <stdio.h>

int memsize = 512;
volatile int global_var = 0;


void dangerous_read(int *ptr)
{
    global_var = *ptr;
}

void dangerous_write(int *ptr, int value)
{
    global_var = *ptr;
    *ptr = value;
}

int main() 
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 1024*1024*1024; i++) {
        dangerous_read(arr + i);
        printf("arr[%d] = %d\n", i, global_var);
    }

    return 0;
}