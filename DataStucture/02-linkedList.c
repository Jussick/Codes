#include<stdio.h>                                                                                                                    
#include<stdlib.h>                                                                                                                  
#include<string.h>

#define MSIZE 45

typedef struct{
	char title[MSIZE];
	int rating;
}Film;

typedef struct{
	Film film;
	struct Node *next;
}Node;

typedef Node * List;

int main()
{
	Film film;
	List current = NULL;	
	List prev = NULL;
	List head = NULL;

	current = (List)malloc(sizeof(List));
	strcpy(film.title, "hahaha");
	film.rating = 3;
	current->film = film;

	printf("title = %s\trating = %d\n", current->film.title, current->film.rating);

	return 0;

}


