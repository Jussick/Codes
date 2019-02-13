# Python file
#!/usr/local/bin/python3
# -*- coding:utf-8 -*

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        # 判断只有1个和0个字符串的特殊情况
        if len(strs) < 2:
            if len(strs) == 1:
                return strs[0]
            return ''

        common_str = ''
        # 得到strs中的最小长度
        min_length = len(strs[0])
        for str in strs[1:]:
            if len(str) < min_length:
                min_length = len(str)

        same = 1
        for pos in range(min_length):
            for i in range(len(strs)-1):
                if strs[i][pos] != strs[i+1][pos]:
                    same = 0
                    break
            if not same:
                break
            else:
                common_str += strs[0][pos]

        return common_str


if __name__ == '__main__':
    ss = Solution()
    findlist = ["a"]
    commonStr = ss.longestCommonPrefix(findlist)
    print(commonStr)









