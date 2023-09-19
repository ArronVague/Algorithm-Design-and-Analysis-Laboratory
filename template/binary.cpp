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