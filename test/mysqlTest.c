
/************************************************
#
#      Filename: mysqlTest.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 直接查询sql语句。输入sql语句，返回查询结果(只能查询所有信息)
#        Create: 2018-03-31 11:28:27
# Last Modified: 2018-03-31 11:28:27
#***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/include/mysql/mysql.h"

int DupData(MYSQL_ROW result, char ***azResult, int row, int field)
{                                                                  
    int i;                                                         
    for (i = 0; i < field; ++i)                                    
    {                                                              
        (*azResult)[row*field+i] = NULL;                           
		printf("i=%d\n",i);
        if ( result[i] != NULL )                                   
            (*azResult)[row*field+i] = strdup( result[i] );        
        else                                                       
            (*azResult)[row*field+i] = strdup("");                 
    }                                                              
    return i;                                                      
} 

int main(int argc, char *argv[])
{
	MYSQL conn;
	MYSQL_ROW row;
	MYSQL_RES *result;	
	char sql[1024];
	int i, count;


	if (!mysql_init(&conn)){
		printf("mysql init failed!");
		return -1;
	}
	// 解决中文乱码
	mysql_options(&conn, MYSQL_SET_CHARSET_NAME, "utf8");

	// 连接 mysql
	if ( mysql_real_connect(&conn, "localhost", "root", "p@s#0fSPV", "pvault", 3306, NULL, 0) ){
		printf("conn success!\n");
	}
	else{
		fprintf(stderr, "conn failed!\n");
		if (mysql_errno(&conn)){
			fprintf(stderr, "conn_failed %d %s\n", mysql_errno(&conn), mysql_error(&conn));	
			exit(1);
		}
	}

	// 查询语句
	//if (mysql_query(&conn, "select *from union_user") == 0){
	//	result = mysql_store_result(&conn);
	//	while((row = mysql_fetch_row(result)) != NULL)
	//	{
	//		printf("id:\t%d\t", atoi(row[0]));
	//		printf("username:\t%s\n", row[1]);
	//	}
	//}
	//else{
	//	fprintf(stderr, "query failed %d %s\n", mysql_errno(&conn), mysql_error(&conn));
	//	exit(1);
	//}
#ifdef QueryCount
	// 查询出表属性的个数
	if(mysql_query(&conn, "select count(*) from information_schema.`columns` where table_name=\"userlevel\"") == 0){
		result = mysql_store_result(&conn);
			if((row = mysql_fetch_row(result)) != NULL)
				count = atoi(row[0]);
	}
	else{
		fprintf(stderr, "query failed %d %s\n", mysql_errno(&conn), mysql_error(&conn));
		exit(-1);
	}
	printf("count=%d\n", count);


	if(mysql_query(&conn, "select *from userlevel") == 0){
		result = mysql_store_result(&conn);
		while((row = mysql_fetch_row(result)) != NULL){
			for(i=0; i<count; i++)
				printf("%s\t", row[i]);

			printf("\n");
		}
	}
	else{
        fprintf(stderr, "query failed %d %s\n", mysql_errno(&conn), mysql_error(&conn)); 
        exit(1);  
    }
#endif
		
	if (argc == 2){
		sprintf(sql, "%s", argv[1]);
		printf("argv[1]=%s\n", argv[1]);
	}
	else{
		printf("Usage: ./app \"sql-sentence\"\n");
		exit(1);
	}
#ifdef FindTableName
	// 找出from后的数据库名
	int i = 0, count = 0;
	char *words[20] = {NULL};
	char *tableName = (char*)calloc(1, sizeof(char)*10);
	char *save = NULL;

    char *p = strtok_r(sql, " ", &save);
    while(p != NULL){
		words[i++] = p;
        p = strtok_r(save, " ", &save);
    }	
	i = 0;
	while(words[i] != NULL){
		if (strstr(words[i], "from") != NULL){
				strcpy(tableName, words[++i]);
				break;
		}
		i++;
	}
	printf("table is: %s\n", tableName);
#endif

// 开始查询
	int nrow = 0, ncolumn = 0;
	char *(**final_result) = {NULL};

	// 打印查询结果
	if (mysql_query(&conn, argv[1]) == 0){
		result = mysql_store_result(&conn);
		ncolumn = mysql_num_fields(result); // 获取属性个数
		nrow = mysql_num_rows(result); // 获取查询结果行数
		printf("nrow=%d\tncolumn=%d\n",nrow, ncolumn);
#ifdef way2
		if(nrow > 0 && ncolumn > 0)
		{	
			int j;
			for(i=0; i<nrow; i++)
			{
				row = mysql_fetch_row(result);
				for (j = 0; j < ncolumn; j++)
					printf("row[%d]: %s\n",j, row[j]);
				printf("--------------------------------------------------------------------------------------------\n");
			}
		}
		else
			printf("Empty set (0.00 sec)\n");
#endif
		if(nrow > 0){
			while((row = mysql_fetch_row(result)) != NULL){
				for (i=0; i<ncolumn; i++)
				{
					printf("row[%d]:%s\n", i, row[i]);
				}
				printf("--------------------------------------------------------------------------------------------\n");
			}
		}
		else
			printf("Empty set (0.00 sec)\n");
		
	}
	else{
		fprintf(stderr, "query failed %d %s\n", mysql_errno(&conn), mysql_error(&conn)); 
		exit(1); 
	}

	//free(tableName);
	mysql_free_result(result);
	mysql_close(&conn);

	return 0;

}
