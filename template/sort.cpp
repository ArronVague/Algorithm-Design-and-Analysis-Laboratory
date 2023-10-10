// 其他
// 二分

int binary(int left, int right)
{
    // 开区间写法
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (check())
        {
            // 谁在check()中谁就是答案
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

// 归并排序
// https://vjudge.net/contest/581855#problem/A
int arr[500001];
int n;

void Merge(int low, int mid, int high)
{
    // low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i = low, j = mid + 1, k = 0;     // mid+1为第2有序区第1个元素，j指向第1个元素
    int *temp = new int[high - low + 1]; // temp数组暂存合并的有序序列
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        { // 较小的先存入temp中
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    { // 若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++] = arr[i++];
    }
    while (j <= high)
    { // 同上
        temp[k++] = arr[j++];
    }
    for (i = low, k = 0; i <= high; i++, k++)
    { // 将排好序的存回arr中low到high这区间
        arr[i] = temp[k];
    }
    delete[] temp; // 释放内存，由于指向的是数组，必须用delete []
}

void MergeSort(int low, int high)
{
    if (low >= high)
    {
        return;
    }                                 // 终止递归的条件，子序列长度为1
    int mid = low + (high - low) / 2; // 取得序列中间的元素
    MergeSort(low, mid);              // 对左半边递归
    MergeSort(mid + 1, high);         // 对右半边递归
    Merge(low, mid, high);            // 合并
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    MergeSort(0, n - 1);
    return 0;
}