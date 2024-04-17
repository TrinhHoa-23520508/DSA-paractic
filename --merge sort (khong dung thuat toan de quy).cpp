#include<iostream>
#include<bits/stdc++.h>
#define MAXN 200000
using namespace std;
void NhapMang(int *a, int &n)
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
void XuatMang(int A[], const int &N)
{
    for(int i=0;i<N;i++)
    {
        std::cout<<A[i]<<" ";
    }
}
void copy(int a[], int *b, int left, int right)
{
    for(int i = left; i<=right;i++)
    {
        a[i]=b[i];
    }
}
void Merge(int a[], int *b, int n, int l, int m, int r)
{
    int i=l;
    int j=m;
    for(int k = l; k<=r;k++)
    {
        if(i<m&&(j>r||a[i]<a[j]))
            b[k]=a[i++];
        else b[k]=a[j++];
    }
}
MergeSort(int a[], int n)
{
    int *b = new int[n];
    int width;
    int left;
    int middle;
    int right;
    for(int width = 1;width<n; width*=2)
    {
        for(int i=0;i<n;i+=2*width)
        {
            left = i;
            middle = min(i+width, n);
            right = min(i+2*width, n)-1;
            Merge(a,b,n,left, middle, right);
        }
        copy(a,b,0,n-1);
    }
}
int main()
{
    int n, a[MAXN];
    NhapMang(a, n);
    MergeSort(a, n);
    XuatMang(a, n);
    return 0;
}
