#include <stdio.h>
#include <stdlib.h>


int zd1()
{
    printf("vvedite m i n:\n");
    int m;
    int n;
    scanf("%d",&m);
    scanf("%d",&n);
    int a[m][n];
    printf("vvedite matricu m*n");
    for(int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("a[%d][%d]=\n",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("tuda\n");
    int b[m * n];
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            b[n * j + i] = a[j][i];
            printf("%d ",b[n * j + i]);
        }
    }
    int c[m][n];
    printf("obratno\n");
    for(int k = 0; k < m * n - 1; ++k)
    {
        c[k % m][k % n] = b[k];
    }
    for(int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}


int zd2()
{
    int n, m, i, j, s, c, d;
    printf("vvedite m i n\n");
    scanf("%d%d", &m, &n);
    int b[m][n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[i][j] = abs(i-j) + 1;
            printf("%4d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int a[m][n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    s = 1;
    for (i = 0; i < n; i++)
    {
        a[0][i] = s;
        s++;
    }
    for (i = 1; i < m; i++)
    {
        a[i][n - 1] = s;
        s++;
    }
    for (i = n - 2; i >= 0; i--)
    {
        a[m - 1][i] = s;
        s++;
    }
    for (i = m - 2; i > 0; i--)
    {
        a[i][0] = s;
        s++;
    }


    c = 1;
    d = 1;

    while (s < m * n)
    {
        while (a[c][d + 1] == 0)
        {
            a[c][d] = s;
            s++;
            d++;
        }

        while (a[c + 1][d] == 0)
        {
            a[c][d] = s;
            s++;
            c++;
        }

        while (a[c][d - 1] == 0)
        {
            a[c][d] = s;
            s++;
            d--;
        }

        while (a[c - 1][d] == 0)
        {
            a[c][d] = s;
            s++;
            c--;
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][j] = s;
            }
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }



    return 0;
}


void treugol1(int n, double a[n][n], double *b, int k)
{
    if(k==n-1)
    {
        return;
    }
    int m=k;
    for(int i = k; i < n; i++)
    {
        if (fabs(a[i][k]) > 0.01)
        {
            m = i;
            break;
        }
    }
    if(m!=k)
    {
        for(int i = k; i < n; i++)
        {
            double t = a[k][i];
            a[k][i]=a[m][i];
            a[m][i]=t;
        }
        double t = b[k];
        b[k]=b[m];
        b[m]=t;
    }
    for(int i = k+1; i < n; i++)
    {
        if(fabs(a[i][k])>=0.01)
        {
            double d = a[i][k]/a[k][k];
            for(int j = k; j < n; j++)
            {
                a[i][j]-=a[k][j]*d;
            }
            b[i]-=b[k]*d;
        }
    }
    treugol1(n, a, b, k + 1);
}


void treugol2(int n, double a[n][n], double *b, int k)
{
    if(k==0)
    {
        return;
    }
    int m=-1;
    for(int i = k; i >= 0; i-=1)
    {
        if (fabs(a[i][k]) > 0.01)
        {
            m = i;
            break;
        }
    }
    if(m!=k)
    {
        for(int i = k; i >=0; i-=1)
        {
            double t = a[k][i];
            a[k][i]=a[m][i];
            a[m][i]=t;
        }
        double t = b[k];
        b[k]=b[m];
        b[m]=t;
    }
    for(int i = k-1; i >= 0; i-=1)
    {
        if(fabs(a[i][k])>=0.01)
        {
            double d = a[i][k]/a[k][k];
            for(int j = n-1; j >= 0; j-=1)
            {
                a[i][j]-=a[k][j]*d;
            }
            b[i]-=b[k]*d;
        }
    }
    treugol2(n, a, b, k - 1);
}


int zd5()
{
    printf("vvedite kolichestvo peremennih:\n");
    int n;
    scanf("%d",&n);
    printf("vvedite matricu bez stolbca constant:\n");
    double a[n][n];
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%lf",&a[i][j]);
        }
    }
    double b[n];
    printf("vvedite stolbec constant:\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf",&b[i]);
    }
    treugol1(n, a, b, 0);
    printf("verhnetreugolnaya matrica:\n");
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%lf ",a[i][j]);
        }
        printf("%lf\n",b[i]);
    }
    treugol2(n, a, b, n - 1);
    printf("\ndiagonalnaya matrica:\n");
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%lf ",a[i][j]);
        }
        printf("%lf\n",b[i]);
    }
    printf("\nreshenie sistemi:\n");
    for(int i = 0; i < n; i++)
    {
        printf("x[%d] = %lf\n", i +1, b[i]/a[i][i]);
    }


    return 0;
}


void treugol3(int n, double a[n][n], double b[n][n], int k)
{
    if(k==n-1)
    {
        return;
    }
    int m=k;
    for(int i = k; i < n; i++)
    {
        if (fabs(a[i][k]) > 0.01)
        {
            m = i;
            break;
        }
    }
    if(m!=k)
    {
        for(int i = k; i < n; i++)
        {
            double t = a[k][i];
            a[k][i]=a[m][i];
            a[m][i]=t;
        }
        for(int i = 0; i < n; i++)
        {
            double t = b[k][i];
            b[k][i]=b[m][i];
            b[m][i]=t;
        }
    }
    for(int i = k+1; i < n; i++)
    {
        if(fabs(a[i][k])>=0.01)
        {
            double d = a[i][k]/a[k][k];
            for(int j = k; j < n; j++)
            {
                a[i][j]-=a[k][j]*d;
            }
            for(int j = 0; j < n; j++)
            {
                b[i][j]-=b[k][j]*d;
            }
        }
    }
    treugol3(n, a, b, k + 1);
}

void treugol4(int n, double a[n][n], double b[n][n], int k)
{
    if(k==0)
    {
        return;
    }
    int m=-1;
    for(int i = k; i >= 0; i-=1)
    {
        if (fabs(a[i][k]) > 0.01)
        {
            m = i;
            break;
        }
    }
    if(m!=k)
    {
        for(int i = k; i >=0; i-=1)
        {
            double t = a[k][i];
            a[k][i]=a[m][i];
            a[m][i]=t;
        }
        for(int i = n-1; i >=0; i-=1)
        {
            double t = b[k][i];
            b[k][i]=b[m][i];
            b[m][i]=t;
        }
    }
    for(int i = k-1; i >= 0; i-=1)
    {
        if(fabs(a[i][k])>=0.01)
        {
            double d = a[i][k]/a[k][k];
            for(int j = n-1; j >= 0; j-=1)
            {
                a[i][j]-=a[k][j]*d;
            }
            for(int j = n-1; j >= 0; j-=1)
            {
                b[i][j]-=b[k][j]*d;
            }
        }
    }
    treugol4(n, a, b, k - 1);
}

int zd6()
{
    printf("vvedite poryadok matrici:\n");
    int n;
    scanf("%d",&n);
    printf("vvedite matricu:\n");
    double a1[n][n];
    double a2[n][n];
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%lf",&a1[i][j]);
            a2[i][j]=a1[i][j];
        }
    }
    double b[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j)
            {
                b[i][j]=1;
            }else
            {
                b[i][j]=0;
            }
        }
    }
    treugol3(n, a1, b, 0);
    treugol4(n, a1, b, n - 1);
    printf("\nobratnaya matrica:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j]/=a1[i][i];
            printf("%lf ",b[i][j]);
        }
        printf("\n");
    }
    double c[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j]=0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; k++)
            {
                c[i][j] += a2[i][k] * b[k][j];
            }
        }
    }
    printf("\nproverka:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ",c[i][j]);
        }
        printf("\n");
    }
}


//int zd7()
//{
//    printf("vvedite poryadok matrici:\n");
//    int n, opr;
//    opr = 1;
//    scanf("%d",&n);
//    printf("vvedite matricu:\n");
//    double a1[n][n];
//    for(int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            scanf("%lf",&a1[i][j]);
//        }
//    }
//    treugol1(n, a, b, 0);
//    for(int i = 0; i < n; i++)
//    {
//        opr *= a[i][i];
//    }
//    printf("opredelitel raven %d\n", opr);
//}

int main()
{
    int i = 1;
    while (i)
    {
        printf("vvedite nomer zadachi\n");
        scanf("%d", &i);
        switch(i)
        {
        case 1: zd1(); break;
        case 2: zd2(); break;
        //case 3: zd3(); break;
        //case 4: zd4(); break;
        case 5: zd5(); break;
        case 6: zd6(); break;
        //case 7: zd7(); break;
        }
    }

    return 0;
}
