//C++ file
/***********************************************
#
#      Filename: 27-根据字符出现频率排序.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:

输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:

输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:

输入:
"Aabb"

输出:
"bbAa"

解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
#        Create: 2019-03-28 14:37:58
#**********************************************/
#include<iostream>
#include <map>
#include<vector>
#define LEN 128
#define PAIR pair<char, int>

using namespace std;

/* 整体思路：
 * 先用一个桶储存每个字符出现的次数，然后把桶里的内容放在map<char, int>中储存(char是字符，int是出现次数)，
 * 之后把map通过value降序排序（即次数），最后把map中的内容转换回字符串即可。
 */

/* 比较函数，用于在sort方法排序的时候通过函数指针传参 */
bool compare_By_val(PAIR &one, PAIR &two) {
	return one.second>two.second;	
}

class Solution {
private:

public:

    string frequencySort(string s) {
		int bucket[LEN] = {0};  // 桶
		map<char, int> mm;  // key: charactor, value: show times

		// 向桶里保存次数
		for (size_t i = 0; i < s.size(); ++i) {
			bucket[int(s[i])] ++;
		}

		// 向哈希表中赋值,key：字符，value：出现的次数 
		for (int i = 0; i < LEN; ++i) {
			if (bucket[i] > 0) {
				mm[i] = bucket[i];
			}
		}

		// 由于sort方法只能给线性对象如vector，list进行排序，故要将map放入vector<pair>中排序
		vector<PAIR> mm_vec(mm.begin(), mm.end());
		sort(mm_vec.begin(), mm_vec.end(), compare_By_val);


		// 组返回的字符串
		int i;
		string res_s = "";
		vector<char> vec;
		for (auto pair : mm_vec) {
			for (i = pair.second; i > 0; --i) {
				vec.push_back(pair.first);
				res_s += pair.first;  // 这里有个疑问，用+连接字符串可以，但是用下标方式一个一个赋值就不好使，怪哉！
			}
		}
		return res_s;
	}


};


int main() {
	Solution s;
	string ss = s.frequencySort("aasssffgh");
	cout << ss << endl;

	return 0;
}
