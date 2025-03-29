#include <stdio.h>
unsigned long long int fun(unsigned long long int y)
{
    unsigned long long int z;
    unsigned long long int result = 1;
 
    for( z = 1 ; z <= y ; z++ )
        result = result*z;
 
    return ( result );
}
int main()
{
    unsigned long long int x, y, z;
    printf("Input the number of rows in Pascal's triangle: ");
    scanf("%llu",&y);
    for ( x = 0 ; x < y ; x++ )
    {
        for ( z = 0 ; z <= ( y - x - 2 ) ; z++ )
            printf(" ");
        for( z = 0 ; z <= x ; z++ )
            printf("%llu ",fun(x)/(fun(z)*fun(x-z)));
 
        printf("\n");
    }
    return 0;
}
