/*
Write a C code that define 3 int variables x, y and z and 3 pointers to int p, q 
and r. Set x, y, z to three distinct values. Set p, q, r to the addresses of x, y, z 
respectively.
a- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
b- Print the message: Swapping pointers.
c- Execute the swap code: r = p; p = q; q = r;
d- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
*/

#include <stdio.h>

void swapPointers(int **p, int **q, int **r){
    int *temp = *r;
    *r = *p;
    *p = *q;
    *q = temp;
}
int main(){
    int x = 10, y = 20, z = 30;
    int *p, *q, *r;
    p = &x;
    q = &y;
    r = &z;
    printf("Values Before Swapping:\n x = %d, y = %d, z = %d\np = %p, q = %p, r = %p\n*p = %d, *q = %d, *r = %d\n\nSwapping Pointers\n\n", x, y, z, (void *)p, (void *)q, (void *)r, *p, *q, *r);
    swapPointers(&p, &q, &r);
    printf("Values After Swapping:\n x = %d, y = %d, z = %d\np = %p, q = %p, r = %p\n*p = %d, *q = %d, *r = %d\n", x, y, z, (void *)p, (void *)q, (void *)r, *p, *q, *r);
    return 0;
}