#include<iostream>
#define MAXN 150000
void NhapMang(int A[], int &N)
{
    std::cin>>N;
    for(int i = 0;i<N;i++)
    {
        std::cin>>A[i];
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

}
void Heapify(int a[], int n, int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l<n&&a[l]>a[largest])
        largest = l;
    if(r<n&&a[r]>a[largest])
        largest = r;
    if(largest!=i)
    {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}
void HeapSort(int a[], int n)
{
    for(int i =n/2-1;i>=0;i--)
    {
        Heapify(a,n, i);

    }
    for(int i=n-1;i>0;i--)
    {
        swap(a[i],a[0]);
        Heapify(a, i, 0);
    }
}
void XuatMang(int A[], const int &N)
{
    std::cout<<N<<std::endl;
    for(int i =0; i<N;i++)
    {
        std::cout<<A[i]<<" ";
    }
}
int main()
{
    int a[MAXN], n;
    NhapMang(a, n);
    HeapSort(a, n);
    XuatMang(a, n);
    return 0;
}
