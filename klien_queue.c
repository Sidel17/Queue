#include<stdio.h>
#include "queue.h"
#include "fatal.h"

int main(){
	Queue Q;
	static int max_queue_size = 15;
	
	Q = CreateQueue(max_queue_size);
	/*
	Enqueue (17,Q);
	Enqueue (19,Q);
	Enqueue (21,Q);
	Enqueue (32,Q);
	printf("Elemen pertama %d\n", Front(Q));
	Priority(18,Q);
	printf("Elemen pertama yang baru %d\n", Front(Q));
	*/
	
	//Enqueue(11,Q);
	
	
	
	Enqueue(11,Q);
	Enqueue(17,Q);
	Enqueue(21,Q);
	Enqueue(27,Q);
	Enqueue(31,Q);
	printf("Front = %d\n",Front(Q));
	 
	Priority(18,Q);
	printf("Elemen pertama yang baru %d\n", Front(Q));
	
	Dequeue(Q);
	Dequeue(Q);
	printf("Front = %d\n",Front(Q));
	 
	MakeEmpty(Q);
	printf("Front = %d\n",Front(Q));
	
	DisposeQueue(Q);
	
	
	return 0;
}

