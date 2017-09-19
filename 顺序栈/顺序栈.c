#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define Elemtype int
#define true 1
#define false 0

typedef struct {
	Elemtype data[MaxSize];
	int top;
}SqStack;

typedef unsigned char boolean;

int InitStack(SqStack *S) {
	//S = (SqStack *)malloc(MaxSize * sizeof(Elemtype));
	S->top = -1;
	printf("InitStack successful!\n");
	return true;
}

int StackEmpty(SqStack *S) {
	if (S->top == -1)
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

int Push(SqStack *S, Elemtype x) {
	if (S->top == MaxSize - 1)
	{
		return false;
	}
	S->data[++S->top] = x;
	printf("push successful!\n");
	return true;
}

int Pop(SqStack *S, Elemtype x) {
	if (S->top == -1)
	{
		return false;
	}
	x = S->data[S->top--];
	printf("%d\n", x);
	printf("pop successful!\n");
	return x;
}

int GetTop(SqStack *S, Elemtype x) {
	if (S->top == -1)
	{
		return false;
	}
	x = S->data[S->top];
	return x;
}

void PrintStack(SqStack *S) {
	for (; S->top > -1; S->top--)
	{
		printf("%d\n", S->data[S->top]);
	}
	printf("PrintStack successful,Now this stack is empty!\n");
	return true;
}


int main() {
	int i, j, o = 1;
	int temp;
	SqStack s;      //顺序栈不需要使用结构体指针
					//调用时直接&传形参
	InitStack(&s);
	while (o != 0)
	{
		printf("(1)Judge the stack is empty!\n");
		printf("(2)push num in stack!\n");
		printf("(3)pop a num from stack!\n");
		printf("(4)printf stack num!\n");
		printf("(5)get num of top stack!\n");
		printf("(0)exit!\n");
		scanf("%d", &o);
		switch (o)
		{
		case 1:
			StackEmpty(&s);
			break;
		case 2:
			printf("please put in num\n");
			scanf("%d", &temp);
			Push(&s, temp);
			break;
		case 3:
			Pop(&s, temp);
			break;
		case 4:
			PrintStack(&s);    //输出后栈空
			break;
		case 5:
			GetTop(&s, temp);
			printf("栈顶是：%d\n", temp);
			break;
		case 0:
			break;

		}
	}
}







//#define maxsize 100
//#define elemtp int 
//
//typedef struct {
//	elemtp stack[maxsize];
//	int top[2];
//}stk;
//
//stk s;
//
//int push(int i, elemtp x) {
//	if (i<0||i>1)
//	{
//		printf("stack number is error!\n");
//		exit(0);
//	}
//	if (s.top[1]-s.top[0]==1)
//	{
//		printf("stack is fullness!\n");
//		return 0;
//	}
//	switch (i)
//	{
//	case 0:
//		s.stack[++s.top[0]] = x;
//		return 1;
//		break;
//	case 1:
//		s.stack[++s.top[1]] = x;
//		return 1;
//	}
//}
//
//elemtp pop(int i) {
//	if (i<0||i>1)
//	{
//		printf("stack number is error!\n");
//		exit(0);
//	}
//	switch (i)
//	{
//	case 0:
//		if (s.top[0]==-1)
//		{
//			printf("stack is empty!\n");
//			return -1;
//		}
//		else
//		{
//			return s.stack[s.stack[s.top[0]--]];
//		}
//	case 1:
//		if (s.top[1] == -1)
//		{
//			printf("stack is empty!\n");
//			return -1;
//		}
//		else
//		{
//			return s.stack[s.stack[s.top[1]++]];
//		}
//	}
//}

//int main() {
//	int o = 1, i, x;
//	elemtp num;
//	while (o!=0)
//	{
//		printf("(1)push a num!\n");
//		printf("(2)pop a num!\n");
//		printf("(0)退出\n");
//
//		scanf("%d", &o);
//		switch (o)
//		{
//		case 1:
//			printf("select stack 1 or 2!\n");
//			scanf("%d", &i);
//			printf("push num\n");
//			scanf("%d", &x);
//			push(i, x);
//			printf("push successful\n");
//			break;
//		case 2:
//			printf("select stack 1 or 2!\n");
//			scanf("%d", &i);
//			num = pop(i);
//			printf("out stack num is %d\n", num);
//			printf("pop successful\n");
//			break;
//		case 0:
//			break;
//		}
//	}
//}