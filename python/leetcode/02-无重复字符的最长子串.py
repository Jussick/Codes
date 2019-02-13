# Python file
# -*- coding:utf-8 -*


class Solution(object):

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxLen = 0
        for i in range(0, len(s)):
            # 最大长度大于剩余长度时
            if maxLen > len(s[i:len(s)]):
                break
            print("i=%d" % i)
            tempLen = 0
            for j in range(i, len(s)):
                print("templen:%d" %tempLen)
                if s[j] in s[i:j]:
                    break
                else:
                    tempLen += 1
                    if maxLen < tempLen:
                        maxLen = tempLen
            print("maxlen: %d" % maxLen)
            # 一共有94个字符
            if maxLen >= 94:
                break
        return maxLen


if __name__ == '__main__':
    ss = Solution()
    print(ss.lengthOfLongestSubstring('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%uvwxyzABCDEFGHIJKLMNOPQ'))
