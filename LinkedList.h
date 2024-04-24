#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>

typedef struct Node{
  int frequency;
  char *word;
  struct Node* next;

}node;

node* insertNode(node* head, char *word);

node* strdup (char *word);

node* talloc(void);

node* lastNode(node* head);

void increaseFrequency(node* node);

void printNode(node* head);

node* findNode(node*head, char* find);

node* getMiddle(node* head);
node* merge(node* left, node* right);
node* mergeSort(node* head);







#endif // LINKEDLIST_H