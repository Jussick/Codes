#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/mysql/mysql.h"

int main(int argc, char *argv[])
{
	MYSQL conn;
	MYSQL_ROW row;
	MYSQL_RES *result;	


	if (!mysql_init(&conn)){
		printf("mysql init failed!");
		return -1;
	}
	// 连接 mysql
	if ( mysql_real_connect(&conn, "localhost", "root", "p@s#0fSPV", "pvault", 3306, NULL, 0) ){
		printf("conn success!\n");
	//	mysql_close(&conn);
	}
	else{
		fprintf(stderr, "conn failed!\n");
		if (mysql_errno(&conn)){
			fprintf(stderr, "conn_failed %d %s\n", mysql_errno(&conn), mysql_error(&conn));	
			exit(1);
		}
	}

	// 查询语句
	if (mysql_query(&conn, "select *from union_user") == 0){
		result = mysql_store_result(&conn);
		while( (row = mysql_fetch_row(result)) != NULL)
		{
			printf("id:\t%d\t", atoi(row[0]));
			printf("username:\t%s\n", row[1]);
		}
	}
	else{
		fprintf(stderr, "query failed %d %s", mysql_errno(&conn), mysql_error(&conn));
		exit(1);
	}

	mysql_free_result(result);
	mysql_close(&conn);


	return 0;

}
