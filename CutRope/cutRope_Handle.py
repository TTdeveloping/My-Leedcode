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
            mul_val = [0] * (n + 1)
            mul_val[0] = 0
            mul_val[1] = 1
            mul_val[2] = 2
            mul_val[3] = 3
            for i in range(4, n + 1):
                max = 0
                for j in range(1, i // 2 + 1):
                    val = mul_val[j] * mul_val[i - j]
                    if val > max:
                        max = val
                mul_val[i] = max
            return mul_val[n]


if __name__ == "__main__":
    cutro = Solution()
    result = cutro.cutRope(18)
    print(result)


