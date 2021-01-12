#include<stdlib.h>
#include "fatal.h"
#include "queue.h"

struct QueueRecord{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

static int Succ(int Value, Queue Q);

Queue CreateQueue(int MaxElements){
	Queue Q = NULL;
	
	Q = malloc(sizeof(struct QueueRecord));
	if(Q == NULL)	FatalError("Out of space!!");
	
	Q->Array = malloc(sizeof(ElementType) * MaxElements);
	if(Q->Array == NULL)	FatalError("Out of space!!!");
	Q->Capacity = MaxElements;
	MakeEmpty(Q);
	
	return Q;
}

void Enqueue(ElementType X,Queue Q){
	if(IsFull(Q)){
		FatalError("Full queue");
	}
	else{
		Q->Size++;
		Q->Array[Q->Rear] = X;
		Q->Rear = Succ(Q->Rear,Q);
	}
}

ElementType Front(Queue Q ){
	if(!IsEmpty(Q))	return Q->Array[Q->Front];
	Error("Empty queue");
	return 0;
}

void Dequeue(Queue Q){
	if(IsEmpty(Q)){
		Error("Empty queue");
	}
	else{
		Q->Size--;
		Q->Front = Succ(Q->Front,Q);
	}
}

void DisposeQueue(Queue Q){
	if(Q != NULL){
		free(Q->Array);
		free(Q);
	}
}

void MakeEmpty(Queue Q){
	Q->Size = 0;
	Q->Front = 0;
	Q->Rear = 0;
}

int IsEmpty(Queue Q){
	return Q->Size == 0;
}

int IsFull(Queue Q){
	return Q->Size == Q->Capacity;
}

static int Succ(int Value, Queue Q){
	if(++Value == Q->Capacity)	Value = 0;
	return Value;
}

void Priority(ElementType X, Queue Q){
	if(!IsFull(Q)){
		Q->Size++;
		if(Q->Front>0){
			Q->Array[Q->Front-1]= X;
			if(--Q->Front<0)
				Q->Front=Q->Capacity-1;	
		}
		else
		if(--Q->Front<0){
			Q->Array[Q->Front]= X;
		}	
	}
	
}

ElementType Last(Queue Q){
	if(!IsEmpty(Q))
		return Q->Array[Q->Rear-1];
	
	Error("Empty Queue!");		//print Error dan terminasi progam
	return 0;		//Return value used to avoid warning
}
