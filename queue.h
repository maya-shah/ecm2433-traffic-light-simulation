#include <stdio.h>

typedef struct node 
{
	int data; 
	struct node *next; 
} node; 

typedef struct queue 
{
	int count; 
	node *front; 
	node *rear; 
} queue; 

void initialize(queue *q)
{
	q->count = 0; 
	q->front = NULL; 
	q->rear = NULL; 
}

int isEmpty(queue *q)
{
    return (q->count == 0) ? 1 : 0;
}

void enqueue(queue *q, int value)
{
	node *tmp; 
	tmp = malloc(sizeof(node)); 
	tmp->data = value; 
	tmp->next = NULL; 

	if (!isEmpty(q)) {
		q->rear->next = tmp; 
		q->rear = tmp; 
		
	} else {
		q->front = q->rear = tmp; 
	}

	q->count++; 
}

void display(node *front){
	if (front == NULL){
		printf("NULL\n");
	} else {
		printf("%d\n", front->data);
		display(front->next);
	}
}

int dequeue(queue *q)
{
    if(isEmpty(q)){
        return 0; 
    }
    else {
        node *tmp; 
        int n; 
        tmp = q->front;
        n = tmp->data; 
        q->front = q->front->next; 
        q->count--; 
        free(tmp);
	    return (n); 
    }
}
