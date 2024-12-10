#include <bits/stdc++.h>
using namespace std;
void qsort(vector<int> &arr, int left, int right)
{
    int i, j, mid;
    int pivot;
    i = left;
    j = right;
    mid = (left + right) / 2; // 计算中间元素的索引
    pivot = arr[mid];         // 选择中间元素作为基准值
    do
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]); // 交换两个元素
            i++;
            j--;
        }
    }while (i <= j); // 在此处填入代码

    if (left < j)
        qsort(arr, left, j); // 对左子数组进行快速排序
    if (i < right)
        qsort(arr, i, right); // 对右子数组进行快速排序
}
int main()
{
    int n, a;
    cin >> n;
    vector<int> arr;
    
    for (int i = 0; i < n; i++){
        cin>>a;
        arr.push_back(a);
    }
    qsort(arr,0,n-1);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}