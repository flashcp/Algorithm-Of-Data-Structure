#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct LNode *next;
}LNode;

int InitList_L(LNode **LN) {
	*LN = NULL;
	printf("初始化成功，链表头指针为空\n");
	return 1;
}

LNode *CreatList_L(LNode *Lhead) {
	LNode *p1, *p2;
	p1 = p2 = (LNode *)malloc(sizeof(LNode));  //申请新节点
	if (p1 == NULL && p2 == NULL) {
		printf("节点分配失败！\n");
		exit(0);
	}
//	memset(p1, 0, sizeof(Lhead));
	printf("输入链表元素：\n");
	scanf("%d", &p1->data);
	p1->next = NULL;

	while (p1->data > 0) {  //输入节点大于0
		if (Lhead == NULL) {
			Lhead = p1;
			printf("empty head distributing succssful\n");
		}
		else {
			printf("%d\n", p2->data);

			p2->next = p1;  //p2始终保持在表尾
			printf("head distributing succssful\n");
		}
		p2 = p1;
		p1 = (LNode *)malloc(sizeof(LNode));  //申请下一个新节点
	//	memset(p1, 0, sizeof(Lhead));
		scanf("%d", &p1->data);
		p1->next = NULL;
	}
	printf("链表创建完成\n");
	return Lhead;    //返回链表的头指针
}

void PrintList_L(LNode *Lhead) {
	if (Lhead == NULL) {
		printf("链表为空\n");
	}
	else
	{
		while (Lhead != NULL) {
			printf("%d\n", Lhead->data);
			Lhead = Lhead->next;
		}
		printf("链表元素输出完成\n");
	}
}

void GetElem_L(LNode *Lhead, int i) {
	int num = 0;
	if (i <= 0)
	{
		printf("value is illegal\n");
		return 0;
	}
	while (Lhead != NULL)
	{
		num++;
		if (num == i)
		{
			printf("值为:%d\n", Lhead->data);
			return 1;
		}
		//printf("%d\n", Lhead->data);
		Lhead = Lhead->next;
	}
	printf("value inexitence\n");
	return 0;
}

void ListInsert_L(LNode *Lhead, int i, int e) {
	int num = 0;
	LNode *p1;
	
	if (Lhead == NULL)
	{
		printf("Lhead is empty list\n");
		return 0;
	}
	while (Lhead != NULL)
	{
		num++;
		if (num == i-1)
		{
			break;
		}
		Lhead = Lhead->next;
	}
	if (num < i-1)
	{
		printf("i is more big than list length\n");
		return 0;
	}
	p1 = (LNode *)malloc(sizeof(LNode));
	p1->next = Lhead->next;
	p1->data = e;
	Lhead->next = p1;
	printf("insert successful\n");
	return 1;
}

int main() {
	LNode *La , Lb, Lc;
	int i, e, o = 1;
	while (o != 0)
	{
		printf("(1)创建链表\n");
		printf("(2)输出链表\n");
		printf("(3)输出链表第i个值\n");
		printf("(4)链表第i个元素之前插入元素e\n");
		printf("(0)退出\n");

		scanf("%d", &o);
		switch (o)
		{
		case 1:
			if (InitList_L(&La))
			{
				printf("链表构造成功\n");
				La = CreatList_L(La);   //La得到链表头指针
			}
			break;
		case 2:
			printf("开始输出元素La:\n");
			PrintList_L(La);
			break;
		case 3:
			printf("输出第i个值:\n");
			scanf("%d", &i);
			GetElem_L(La, i);
			break;
		case 4:
			printf("在链表i的位置插入e\n");
			scanf("%d", &i);
			scanf("%d", &e);
			ListInsert_L(La, i, e);
			break;
		case 0:
			break;
		}
	}
}