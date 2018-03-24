#include<stdio.h>
#include<stdlib.h>


struct data
{
	int *p;
	int length;//数组长度
	int status;//状态0是无序，1是升序，2是降序
};

struct findarr
{
	int **p;  // 指针数组
	int n;  // 找到的结果数量
};
typedef struct findarr findaddr;

//增加，删除，修改，查询，初始化

void addOneElement(struct data *pdata, int num);  // 增加一个元素
void addOneArray(struct data *pdata, int *array, int len);  // 增加一个数组
void init(struct data *pdata);  // 第一次初始化
void reinit(struct data *pdata);  // 重新初始化
void deleteone(struct data *pdata, int num);  // 删除找到的第一个元素
void deleteall(struct data *pdata, int num);  // 删除找到的所有元素
int * find(struct data *pdata, int num);  // 返回找到的第一个元素的地址
findaddr  findall(struct data *pdata, int num);  // 返回所有找到元素的地址
void  printfall(struct data *pdata);  // 打印所有的数据
void sort(struct data *pdata, int type);  // 排序，type=1从小到大;type=2从大到小
void update(struct data *pdata, int oldnum, int newnum);  // 修改找到的第一个元素
int insert(struct data *pdata, int pos_num, int num, int behindOrFront);  // behindOrFront为0在pos_num之前插，1在后插
int max(struct data *pdata);  // return the maximum value
int min(struct data *pdata);  // return the minimum value
