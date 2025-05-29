#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int n){
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = n;
	temp->next = NULL;
	if(front == NULL){
		front = temp;
	}
	else{
		rear->next = temp;
	}
	rear = temp;
}

void dequeue(){
	if(front == NULL){
		printf("Queue is Empty");
	}
	else{
		printf("%d is dequeued\t", front->data);
		front = front -> next;
		if(front == NULL){
			rear = NULL;
		}
	}
}

void display(){
	struct node *temp;
	if(front == NULL){
		printf("Queue is Empty");
	}
	else{
		temp = front;
		while( temp != NULL ){
			printf("%d\t", temp->data);
			temp = temp->next;
		}
	}
}
int main(){
	int choice, n;
	
	while(1){
		printf("\n1. Enqueue\n2. Dequeue\n3. display\n4. Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter the element to enqueue: ");
				scanf("%d", &n);
				enqueue(n);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
		}
	}
}