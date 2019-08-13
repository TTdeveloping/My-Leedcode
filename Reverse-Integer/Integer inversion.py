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