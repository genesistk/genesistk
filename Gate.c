#include <stdio.h>

int findS(int a, int b)
{
    return (a|b)&(~(findC(a,b)));
}

int findC(int a, int b)
{
    return (a&b);
}

int findCout_FA(int a, int b, int c)
{
    return  (findS(a,b)|(findS(findC(a,b),c)));
}

int findS_FA(int a, int b, int c)
{
    return findC(findC(a,b),c);
}

main()
{
    int a,b,s,c;
    int i,j,k;
    //Haft Adder
    printf("HA \n");
    printf("-----------------\n");
    printf("| a | b | s | c |\n");
    printf("-----------------\n");
    for(i=1;i>=0;i--)
    {
        for(j=1;j>=0;j--)
        {
            printf("| %d | %d | %d | %d |\n", i, j, findS(i,j), findC(i,j));
        }
    }
    printf("-----------------\n\n");
    //Full Adder
    printf("Full Adder \n");
    printf("----------------------------\n");
    printf("| a | b | c_in | s | c_out |\n");
    printf("----------------------------\n");
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            for(k=0;k<=1;k++)
            {
                printf("| %d | %d |   %d  | %d |   %d   |\n",i, j, k, findS_FA(i,j,k), findCout_FA(i,j,k));
            }
        }
    }
    printf("----------------------------\n");
    return 0;
}

