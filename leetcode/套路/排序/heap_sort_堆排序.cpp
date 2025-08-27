#include <iostream>
#include <algorithm>

using namespace std;

void max_heapify(int arr[], int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1; // 左子节点一定存在，其为 2i+1

    while (son <= end) // 子节点指标在范围内才做比较
    {
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if (arr[dad] > arr[son])
            return;
        else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len)
{
    // 步骤1.构建初始堆
    // 从最后一个非叶子结点((n/2)-1)开始
    for(int i = len/2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1); // 大顶堆

    for (int i = len - 1; i > 0; i--)
    {
        // 步骤2.交换堆顶元素和末尾元素
        swap(arr[0], arr[i]);
        // 步骤3.重建堆
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr);

    heap_sort(arr, len);

    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}