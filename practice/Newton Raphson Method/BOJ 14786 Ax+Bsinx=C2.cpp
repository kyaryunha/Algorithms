#include<bits/stdc++.h>
using namespace std;
double a,b,c;
double fx(double x){ return (a*x+b*sin(x)+c)/(a+b*cos(x)); }
int main(void)
{
    int cnt = 20000;
    double p1,p2;
    scanf("%lf %lf %lf",&a,&b,&c);
    p1 = 1;
    while(cnt--)
    {
        p2 = p1 - fx(p1);
        p1 = p2;
    }
    printf("%.20lf\n",-p2);
}