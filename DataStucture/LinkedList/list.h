#include<stdbool.h>
#define MSIZE 45

typedef struct{
   	char title[MSIZE];
	int rating;
}Item;

typedef struct node{
	Item item;
	struct node *next;
}Node;

typedef Node * List;

void InitailizeList(List *plist);
bool ListIsEmpty(const List *plist);
bool AddItem(Item item, List *plist);
void Traverse(const List *plist, void(*pfun)(Item item));
unsigned int ListItemCount(List *plist);
void EmptyTheList(List *plist);
