#include<iostream>
#include<stdlib.h>
using namespace std;

void swap(int *p, int *q)
{
    int s;
    s = *p;
    *p = *q;
    *q = s;

}

int opp(int *l)
{
    if(l >= r)
        return 1;
    swap(l, r);
    opp(l+1, r-1);
    return 1;
}
void input(int *p, int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        cout<<"Enter the the elemenet: ";
        cin>>p[i];
    }
}
void display(int *p, int n)
{
    int i,j;
    for(i=0; i<n ; i++)
    {
        cout<<" "<<*(p+i);
    }
}
int main()
{
    int n, *a;

    cout<<"How many elements to keep in the array?: ";
    cin>>n;
    a = (int*) malloc(sizeof(int)*n);
    input(a, n);
    display( a, n);
    opp(a);
    cout<<"\nThe reversed array is"<<endl;
    display(a, n);
}
