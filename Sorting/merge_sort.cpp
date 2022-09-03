#include<bits/stdc++.h>

using namespace std;

int arr[103];
int temp[103];

void mergeSort(int lo, int hi)
{
    if(lo == hi) return;

    int mid = (lo+hi)/2;

    mergeSort(lo, mid);
    mergeSort(mid+1, hi);
    int i, j, k;
    for(k = lo, i = lo, j = mid+1; k <= hi; k++) {
        if(i == mid + 1) temp[k] = arr[j++];
        else if(j == hi + 1) temp[k] = arr[i++];
        else if(arr[i] > arr[j]) temp[k] = arr[j++];
        else temp[k] = arr[i++];
    }

    for(int i = lo; i <= hi; i++) arr[i] = temp[i];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        arr[i] = n - i + 1;
    }
    mergeSort(1, n);
    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
    return 0;
}
