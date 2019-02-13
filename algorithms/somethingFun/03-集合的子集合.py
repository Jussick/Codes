# Python file
#!/usr/local/bin/python3
# -*- coding:utf-8 -*
"""
author: Edward
date: 2019-01-14
找出一个集合的所有子集合
@思路：
    首先初始化一个元素都为NULL，长度为given_set的子集合，然后把集合中的元素一个一个往子集合中加，每次加入时都会有两种情况：分别是加入null和加入当前元素，直到判断的指针指出集合的长度，打印当前的子集合。
"""


def all_subsets(given_set):
    """
    Args:
        given_set, 输入的集合，一个list
    Return:
        NULL, 由于是输出所有子集合，无需返回
    """
    subset = []
    for i in range(len(given_set)):
        subset.append(None)
    helper(given_set, subset, 0);


def helper(given_set, subset, index):
    """
    Args:
        given_set, 输入的集合，a list
        subset, 当前的子集合，a list
        index, 当前判断到集合的元素位置，即第几个要不要放到subset中
    Return:
        NULL
    """
    if index == len(given_set):
        print_set(subset)
    else:
        subset[index] = None
        helper(given_set, subset, index + 1)
        subset[index] = given_set[index] 
        helper(given_set, subset, index + 1)


def print_set(a_set):
    print('{', end="")
    for i in range(len(a_set)):
        if a_set[i] is not None:
            if i == len(a_set) - 1:
                print(a_set[i], end = "")
            else:
                print(a_set[i], end = ",")
    print('}')


if __name__ == "__main__":
    given_set = [1,2,3]
    all_subsets(given_set)
