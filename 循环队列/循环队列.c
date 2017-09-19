#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define ElemType int
#define true 1
#define false 0

typedef unsigned char boolean;


typedef struct{
	ElemType data[MaxSize];
	int front, rear;
}SqQuene;

void InitQueue(SqQuene *Q) {
	Q->front = Q->rear = 0;
	printf("InitQueue successful!\n");
	return true;
}

boolean IsEmpty(SqQuene *Q) {
	if (Q->front == Q->rear)
	{
		printf("yes!\n");
		return true;
	}
	else
	{
		printf("no!\n");
		return false;
	}
}

boolean EnQueue(SqQuene *Q, ElemType x) {
	if ((Q->rear+1)%MaxSize==Q->front)
	{
		printf("the queue is fullness!\n");
		return false;
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear++) % MaxSize;   //不像栈，栈顶指针一直都和栈顶元素一样高
									  //队列尾指针比队尾高一
	return true;
}

boolean DeQueue(SqQuene *Q, ElemType x) {
	if (Q->front==Q->rear)
	{
		printf("the queue is emtpy!\n");
		return false;
	}
	x = Q->data[Q->front];
	Q->front = (Q->front++) % MaxSize;
	printf("%d\n", x);
	printf("pop successful!\n");
	return x;
}

void PrintStack(SqQuene *Q) {
	while (Q->rear != Q->front)
	{
		printf("%d\n", Q->data[Q->front]);
		Q->front = (Q->front + 1) % MaxSize;
	}
	printf("PrintQueue successful,Now this Queue is empty!\n");
	return true;
}



int main() {
	int i, j, o = 1;
	int temp;
	SqQuene q;      //顺序栈不需要使用结构体指针
					//调用时直接&传形参
	InitQueue(&q);
	while (o != 0)
	{
		printf("(1)Judge the queue is empty!\n");
		printf("(2)push num in queue rear!\n");
		printf("(3)pop a num from queue front!\n");
		printf("(4)printf all queue num!\n");
		printf("(5)get num of top stack!\n");
		printf("(0)exit!\n");
		scanf("%d", &o);
		switch (o)
		{
		case 1:
			IsEmpty(&q);
			break;
		case 2:
			printf("please put in num\n");
			scanf("%d", &temp);
			EnQueue(&q, temp);
			break;
		case 3:
			DeQueue(&q, temp);
			break;
		case 4:
			PrintStack(&q);    //输出后栈空
			break;
		case 5:
			printf("栈顶是：%d\n", temp);
			break;
		case 0:
			break;

		}
	}
}