#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
void NhapMang(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
void XuatMang(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
void Heapify(int *a, int n, int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if(right<n&&a[right]>a[largest])
        largest = right;
    if(left<n&&a[left]>a[largest])
        largest = left;
    if(largest!= i)
    {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}
void BuildHeap(int *a, int n)
{
    for(int i = n/2-1;i>=0;i--)
    {
        Heapify(a, n, i);
    }
}
void HeapSort(int *a, int n)
{
    BuildHeap(a, n);
    for(int i=n-1;i>0;i--)
    {
        swap(a[i], a[0]);
        Heapify(a,i,0);
    }
}
void XoaSoLonNhatBatKi(int *a, int &n)
{
    HeapSort(a,n);
    n--;
}
void XoaTatCaSoLonNhat(int *a, int&n)
{
   HeapSort(a, n);
   int temp = a[n-1];
   int i = n-1;
   while(a[i]==temp)
   {
       n--;
   }
}
void GiamSoLonNhatBatKi(int *a, int n, int t)
{
    HeapSort(a, n);
    a[n-1]-=t;
}
void GiamTatCaSoLonNhat(int *a, int n, int t)
{
    HeapSort(a, n);
    int temp = a[n-1];
    int i = n-1;
    while(a[i-1]==temp)
    {
        a[i-1]-=t;
    }
}
int main()
{
    int *a;
    int n, m;
    cin>>n>>m;
    a = new int[n];
    NhapMang(a, n);
    HeapSort(a, n);
    int x;
    int t;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        if(x=1) XoaSoLonNhatBatKi(a, n);
        else if(x==2) XoaTatCaSoLonNhat(a, n);
        else if(x == 3) {cin>>t; GiamSoLonNhatBatKi(a, n, t);}
        else {cin>>t; GiamTatCaSoLonNhat(a,n,t);}
    }
    XuatMang(a,n);
    return 0;
}
