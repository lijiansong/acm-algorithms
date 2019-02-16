#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double T, C, N;
    while(scanf("%lf%lf", &N, &C) != EOF)
    {
        T = 0;
        if(N == 0.0)
        {
            printf("0\n");
            continue;
        }
        T = C / (2 * N);
        if(T - floor(T) <= 0.5)
          T = floor(T);
        printf("%.0f\n", T);
    }
    //system("PAUSE");
    return 0;
}