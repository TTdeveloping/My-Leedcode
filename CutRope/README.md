# 题目描述 ：

给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

#  输入描述:

输入一个数n，意义见题面。（2 <= n <= 60）

# 示例:

输入：8

输出：18 

# 我的总结和感悟（附代码）：

## 首先要知道什么是动态规划问题？

如果要求一个问题的最优解，而且该问题能分成若干个子问题，**整体问题的最优解依赖于子问题的最优解**，可以考虑用动态规划解决。动态规划一般是**自顶向下思考**，**自底向上实现**的，为了避免计算子问题时重复，可以将子问题的结果**打表**记录下来。

 很显然这是一道动态规划的问题。对绳子剪一刀后就得到两段长度的绳子i 和 n-i,记f(n)为长度为n的绳子的最大乘积。那么f(n) =max( f(i) * f(n-i) ).当然对长度为i和长度为n-i的绳子还可以分别再剪，这就是子问题了。然后自下而上的解决问题，可以从f(1)开始向上计算并打表保存，最终获得f(n)的值。

```python
# -*- coding:utf-8 -*-
class Solution:
    def cutRope(self, number):
        # write code here
        n = number
        if n <= 1:
            return 0
        if n == 2:
            return 1
        if n == 3:
            return 2
        if n > 3:
            mul_val = [0] * (n + 1)  #这就是定义的列表空间 
            # 在n>3前提下，下面这4为个就是定义绳长度为0,1,2,3时的值（其实关于这个0的理解，我就是觉得是为了方便操作，正好是长度对应列表索引，因为索引是从0开始的。）
            mul_val[0] = 0
            mul_val[1] = 1
            mul_val[2] = 2
            mul_val[3] = 3
            
            # 接下来就是n>=4的情况
            for i in range(4, n + 1):
                max = 0  # 每讨论一个绳长时，就把最大值清零。
                # 为了避免情况重复，所以j控制在i的一半。因为2*3=3*2
                for j in range(1, i // 2 + 1):  
                    val = mul_val[j] * mul_val[i - j]
                    if val > max:
                        max = val
                mul_val[i] = max  # 更新最大值
            return mul_val[n]  # 返回长度为n的最大乘积。
```

我们可以知道绳长为1的时候是没办法剪的，所以这是非法输入，就返回0了，当绳长为2的时候可以剪一刀，剪为1和1两段 ，则f(1) = 1*1=1；当绳长为3时，可以剪一刀，剪为1和2两段，也可以剪两刀，剪为1,1和1三段，则f(n) = max(1*2, 1*1*1)=2。所以就有了开头这段代码：

```python
   if n <= 1:
            return 0
        if n == 2:
            return 1
        if n == 3:
            return 2
```

其实最不好理解的应该就是这一块吧，我在下面分析一下：

```python
            mul_val[0] = 0
            mul_val[1] = 1
            mul_val[2] = 2
            mul_val[3] = 3
```

其实这一段代码是根据n>3而言的，从前边那段代码可以看出2和3再被划分的话乘积反而没有本身的值大，所以就不再对2和3往下划分了。怎么理解？举个例子，假如绳长为4，那么可以分为两种情况：1,3--乘积为3，2,2--乘积为4，如果将3再划分，见第一段代码，3划分后最大乘积是2，那么1*3就变为1*2=2<3；如果将2再划分，就变成了1*1=1<4。所以看到这里就明白了为什么到2和3就不再往下继续剪了，这就是最小的子集。