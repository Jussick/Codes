#include"my.h"

void init(struct data *pdata)
{
	pdata->p = NULL;
	pdata->length = 0;
	pdata->status = 0;
}

void reinit(struct data *pdata)
{
	if (pdata->p == NULL)
		return;
	else
	{
		free(pdata->p);
		pdata->p = NULL;
		pdata->length = 0;
		pdata->status = 0;
	}

}

void addOneElement(struct data *pdata, int num)
{
	if (pdata->p == NULL)
	{
		pdata->p = (int *)malloc(sizeof(int));
		pdata->length = 1;
		pdata->p[pdata->length - 1] = num;
	}
	else
	{
		pdata->length += 1;
		pdata->p = (int *)realloc(pdata->p, pdata->length*sizeof(int));
		pdata->p[pdata->length - 1] = num;

		
	}

}


void addOneArray(struct data *pdata, int *array, int len)
{
	if (pdata->p == NULL)
	{
		pdata->p = (int *)malloc(len*sizeof(int));
		pdata->length = len;
		for (int i = 0; i < len; i++)
		{
			pdata->p[i] = array[i];
		}
	}
	else
	{
		pdata->p = (int *)realloc(pdata->p, (pdata->length+len)*sizeof(int));
		for (int i = 0; i<len; i++)
		{
			pdata->p[i+pdata->length] = array[i];
		}
		pdata->length += len;
	}
}


void printfall(struct data *pdata)
{
	printf("\n");
	for (int i = 0; i < pdata->length; i++)
	{
		printf("%d\n", pdata->p[i]);
	}

}

void deleteone(struct data *pdata, int num)
{
	int * result = find(pdata, num);
	if (result != NULL)
	{
		for (int i = result - pdata->p; i < pdata->length - 1; i++)
		{
			pdata->p[i] = pdata->p[i + 1];
		}
		pdata->length--;
	}
	else
	{
		printf("Nothing to delete.\n");
	}
	

}


void deleteall(struct data *pdata, int num)
{
	while(int *result = find(pdata, num))
	{
		for (int i = result - pdata->p; i < pdata->length - 1; i++)
		{
			pdata->p[i] = pdata->p[i + 1];
		}
		printf("删除了：data1[%d]", result - pdata->p);
		pdata->length--;
	}


}

void sort(struct data *pdata, int type)  //  type=1从小到大;type=2从大到小
{
	if (type == 1)  // 升序
	{
		for (int i = 0; i < pdata->length - 1; i++)
		{
			for (int j = 0; j < pdata->length - i - 1; j++)
			{
				if (pdata->p[j]>pdata->p[j + 1])
				{
					pdata->p[j] ^= pdata->p[j + 1];
					pdata->p[j+1] ^= pdata->p[j];
					pdata->p[j] ^= pdata->p[j + 1];
				}
			}
		}
		pdata->status = 1;
	}
	else if(type == 2)// 降序
	{
		for (int i = 0; i < pdata->length - 1; i++)
		{
			for (int j = 0; j < pdata->length - i - 1; j++)
			{
				if (pdata->p[j]<pdata->p[j + 1])
				{
					pdata->p[j] ^= pdata->p[j + 1];
					pdata->p[j + 1] ^= pdata->p[j];
					pdata->p[j] ^= pdata->p[j + 1];
				}
			}
		}
		pdata->status = 2;
	}
	
}

int * find(struct data *pdata, int num)
{
	if (pdata->status == 0) // 顺序查找
	{
		for (int i = 0; i < pdata->length; i++)
		{
			if (pdata->p[i] == num)
			{
				//printf("Found it.");
				return &(pdata->p[i]);
			}
		}
		//printf("Not Found.");
		return NULL;

	}
	else if (pdata->status == 1)  // 二分查找
	{
		int i=0;
		int left = 0;
		int right = pdata->length;
		int middle = (left + right) / 2;
		while (left <= right)
		{
			i++; 
			//printf("\n这是第%d次二分查找,middle=%d\n",i,pdata->p[middle]);
			if (num == pdata->p[middle])
			{
				//printf("Found it.\n");
				return &(pdata->p[middle]);
			}
			else if (num >= pdata->p[middle])
			{
				left = middle + 1;
				middle = (left + right) / 2;
			}
			else
			{
				right = middle - 1;
				middle = (left + right) / 2;
			}
		}
		//printf("Not Found.\n");
		return NULL;
		
	}


}


void update(struct data *pdata, int oldnum, int newnum)
{
	int *result = find(pdata, oldnum);
	if (result == NULL)
	{
		printf("Nothing to be changed.");
		return;
	}
	else
	{
		*result = newnum;
	}
}

int * my_find(int *p, int num, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i] == num)
		{
			return p + i;
			break;
		}
	}
	return NULL;
}




findaddr findall(struct data *pdata,int num)
{
	findaddr addr;  // 创建结构体变量
	int *res,count=0;
	for (res = my_find(pdata->p, num, pdata->length - 1); res != NULL; res = my_find(res+1, num, pdata->length - 1 - (res - pdata->p))) // 计数
	{
		count++;
	}

	addr.n = count;
	addr.p = (int **)malloc(count*sizeof(int *)); // 指针数组，申请相应空间
	int i = 0;
	for (res = my_find(pdata->p, num, pdata->length - 1); res != NULL; res = my_find(res + 1, num, pdata->length - 1 - (res - pdata->p))) // 
	{
		addr.p[i] = res;
		i++;
	}
	return addr;

}

int insert(struct data *pdata, int pos_num, int num, int FrontOrbehind)
{
	int *pos = find(pdata, pos_num);
	if (pos == NULL)
	{
		return NULL;
	}
	pdata->length++;
	pdata->p = (int*)realloc(pdata->p, pdata->length*sizeof(int));
	//printf("%d", (pos - pdata->p));
	if (FrontOrbehind == 0)  // 前插
	{
		for (int i = pdata->length; i > pos-pdata->p; i--)
		{
			pdata->p[i] = pdata->p[i-1];
		}
		*pos = num;


	}
	else if (FrontOrbehind == 1)  // 后插
	{
		for (int i = pdata->length; i > pos - pdata->p + 1; i--)
		{
			pdata->p[i] = pdata->p[i-1];
		}
		*++pos = num;
	}
	return 0;




}


int max(struct data *pdata)
{
	int max, i;
	max = pdata->p[0];
	for (i = 1; i < pdata->length; i++)
	{
		if (max < *(pdata->p + i))
			max = *(pdata->p + i);
	}
	return max;
}

int min(struct data *pdata)
{
	int min, i;
	min = pdata->p[0];
	for (i = 1; i < pdata->length; i++)
	{
		if (min > *(pdata->p + i))
			min = *(pdata->p + i);
	}
	return min;
}