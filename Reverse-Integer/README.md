# No 7：[[整数反转](https://leetcode-cn.com/problems/reverse-integer/)]：

### **描述：**

> #### 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

### **示例 :**

> 示例1：
>
> 输入: 123
> 输出: 321
>
>  示例 2:
>
> 输入: -123
> 输出: -321
>
> 示例 3:
>
> 输入: 120
> 输出: 21
>
> #### **注意:**
>
> 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

### **代码：**

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        list = []
        list_symbol = []
        list_final = []
        if type(x) is int:
            if x >= -(2**31) and x <= 2**31-1:
                x = str(x)
            else:
                exit()
        x = int(x)
        if x >= -(2 ** 31) and x <= 2 ** 31 - 1:
            x = str(x)
        else:
            exit()
        for i in x:
            list.append(i)
        if list[0] == "-" and "+":
            list_symbol.append(list[0])
            list_rest = list[1:]
            list_rev = list_rest[::-1]
            list_symbol.extend(list_rev)
        else:
            list_symbol = list[::-1]
        string = ''
        final_out = string.join(list_symbol)
        final_int = int(final_out)
        if final_int >= -(2 ** 31) and final_int <= 2 ** 31 - 1:
            return int(final_out)
        else:
            return 0


if __name__ == '__main__':
    x = -12340
    rev = Solution()
    rev.reverse(x)


```

### **针对此题的感悟和总结**：



