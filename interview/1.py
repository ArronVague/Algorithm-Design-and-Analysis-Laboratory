def f(nums):
    n = len(nums)
    left, right = 0, 0
    while right < n:
        if nums[right] != 0:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
        right += 1


a = [1, 0, 0, 2, 3, 0, 4, 0]
f(a)
print(a)
