#include<iostream>
using namespace std;
#define MAXN 50000
void NhapMang(int *&a, int &n)
{
    cin>>n;
    a = new int [n];
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
}
void QuickSort(int *a, int left, int right)
{
    int i = left;
    int j = right;
    int pivot = a[(left+right)/2];
    while(i<=j)
    {
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i<=j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(i<right) QuickSort(a, i, right);
    if(j>left) QuickSort(a, left, j);
}
void quick_sort_ascending(int *a, int n)
{
    QuickSort(a, 0, n-1);
}
int main()
{
    int *a;
    int n;
    NhapMang(a, n);
    quick_sort_ascending(a, n);
    int dem = 1;
    int temp = a[0];
    for(int i = 1;i<n;i++)
    {
        if(a[i]==temp) continue;
        else
        {
            dem++;
            temp = a[i];
        }
    }
    cout<<dem;
    return 0;


}
