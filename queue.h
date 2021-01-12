#ifndef _Queue_H
#define _Queue_H

typedef int ElementType;
struct QueueRecord;
typedef struct QueueRecord *Queue;

Queue CreateQueue(int MaxElements);
void Enqueue(ElementType X,Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
int IsEmpty(Queue Q);
int IsFull(Queue Q);
void Priority(ElementType X, Queue Q);
ElementType Last(Queue Q);


#endif

