#include <stdio.h>

int main() {
    int a, b, c, d, e, f, g, result;
    printf("Enter the numbers to evaluate ((a -b / c * d + e) * (f +g)):\n");
    printf("Enter the value for a: ");
    scanf("%d",&a);
    printf("Enter the value for b: ");
    scanf("%d",&b);
    printf("Enter the value for c: ");
    scanf("%d",&c);
    printf("Enter the value for d: ");
    scanf("%d",&d);
    printf("Enter the value for e: ");
    scanf("%d",&e);
    printf("Enter the value for f: ");
    scanf("%d",&f);
    printf("Enter the value for g: ");
    scanf("%d",&g);
    result = ((a-b/c*d+e)*(f+g));
    printf("Result of evaluated expression: %d",result);
    return 0;
}
