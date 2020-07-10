#### [剑指 Offer 11. 旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)

**题目：**把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

**示例 1：**

```
输入：[3,4,5,1,2]
输出：1
```

**示例 2：**

```
输入：[2,2,2,0,1]
输出：0
```

**思路：**

如果数组中只有一个数，那么就直接返回这个数。

如果数组长度大于1,，可以分为两种情况：

1. 确实将前面的小元素搬到了后面，我一个个遍历数组，找到第一个数，它前面的数比它大，那么我就返回这个数，因为这个数就是前面小数移过来的，它是第一个。
2. 遍历完数组，都没有找到前面的数比当前遍历的位置上的数大的情况，说明数组一直是递增的（相当于所有数都旋转过来了）或者数组里的数都相同，这两种情况下，返回第一个数就好了。

**代码：**

```python3
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        if len(numbers)==1:
            return numbers[0]
        for i in range(len(numbers)):
            if numbers[i]<numbers[i-1]:
                return numbers[i]
        return numbers[0]
```

**别人用的二分查找的思想，代码如下：**

```python3
class Solution:
    def minArray(self, numbers: [int]) -> int:
        i, j = 0, len(numbers) - 1
        while i < j:
            m = (i + j) // 2
            if numbers[m] > numbers[j]: i = m + 1
            elif numbers[m] < numbers[j]: j = m
            else: j -= 1
        return numbers[i]
```