#include <stdio.h>
#include "LinkedList.h"




//node* createNode(node* head, char*word)


node* insertNode(node* head, char* word){
	
  if (head == NULL){ //check if head is created
    head = talloc();
    head->word = strdup(word);
    head->frequency = 1;
    head->next = NULL;
  }
/*
	node* same = findNode(head, word);
	if(same != NULL){
		same->frequency++;
	}
	*/

	else if(findNode(head, word) == NULL){
		node *new_node = talloc(); // if word is not in linked list and not the head
		new_node->word = strdup(word);
		new_node->frequency = 1;

		new_node->next = head;
		head = new_node;
	}	

	else{
		findNode(head, word)->frequency++;
	}

  return head;

}

node* findNode(node* head, char* find){
	node* current = head;
	while(current != NULL){
		if (strcmp(current->word, find) == 0){
			return current;
		}
		current = current->next;

	}
	return NULL;
}





void increaseFrequency(node* node){
	node->frequency = node->frequency + 1;
}

node* strdup(char* word){
  char *ptr;
  ptr = (char*) malloc(strlen(word)+1); //+1 for '\0'
  if(ptr != NULL){
    strcpy(ptr, word);
  }
  return ptr;
}

node* talloc(void){
  return (node*) malloc(sizeof(node));
}


node* lastNode(node* head){
	node* current = head;
	while(current != NULL && current->next != NULL){
		current = current->next;
	}
	return current;
}

void printList(node* head){

	node* current = head;

	if(current == NULL){
		printf("\nHead is NULL\n");
	}
	printf("HEAD:\n");

	while(current != NULL) {
		
		//printf("Size: %d\n",strlen(current->word) );
		printf("\tFrequency: %d\n", current->frequency);
		printf("\tWord: ");
		for(int i = 0; i < strlen(current->word); i++){
			printf("%c", current->word[i]);
		}
		printf("\n");
		current = current->next;
	}
}

node* getMiddle(node* head){

	node* slow = head;
	node* fast = slow->next;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
	
	

}

node* merge(node* left, node* right){
	if(left == NULL){
		return right;
	}
	if(right == NULL){
		return left;
	}

	node* newHead;

	if(left->frequency > right->frequency){
		newHead = left;
		newHead->next = merge(left->next, right);
	}
	else if (left->frequency < right->frequency){
		newHead = right;
		newHead->next = merge(left, right->next);
	}
	else{
		int compare = strcmp(left->word, right->word);
		if (compare < 0){
			newHead = left;
			newHead->next = merge(left->next, right);
		}
		else{
			newHead = right;
			newHead->next = merge(left, right->next);
		}

	}
	return newHead;

}

node* mergeSort(node* head){
	if(head->next == NULL || head == NULL){
		return head;
	}

	node* leftHead = head;
	node* mid = getMiddle(head);
	node* rightHead = mid->next;
	mid->next = NULL;

	leftHead = mergeSort(leftHead);
	rightHead = mergeSort(rightHead);

	return merge(leftHead,rightHead);


}

