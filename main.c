#include <stdio.h>
#include <stdlib.h>

//numarul minim de monede care trebuie folosite pt a ajunge la suma data

int dp(int* M, int suma, int n)
{
    int v[suma+1];
    v[0] = 0;

    for(int i = 1; i<=suma; i++)
    {
        v[i] = suma+1;
    }

    for(int i = 0; i<n; i++)
    {
      for(int j=0; j<=suma; j++)
      {
          if(j >= M[i] && v[j-M[i]]+1<v[j])
            v[j]= v[j-M[i]]+1;
      }
    }
    return v[suma];
}



int main()
{
    int suma;
    int n=4;
    int M[]={1,2,5,7};

    scanf("%d", &suma);
    int minim = dp(M, suma, n);

    printf("%d", minim);
    return 0;
}
