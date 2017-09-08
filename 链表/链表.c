#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

int InitList_L(LinkList L) {
	L = NULL;
	printf("初始化成功，链表头指针为空\n");
	return 1;
}

LinkList CreatList_L(LinkList L) {    //尾插法创建链表
	int x;
	L = (LNode *)malloc(sizeof(LNode));  //申请新节点
	LNode *s, *r = L;
	
	printf("输入链表元素：\n");
	scanf("%d", &x);

	while (x > 0) {  //输入节点大于0
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next=NULL;
	return L;    //返回链表的头节点（相当于头指针）
}

void PrintList_L(LinkList L) {
	if (L == NULL)   //加入头节点后头指针为非空指针
	{
		printf("L is null!\n");
	}
	LNode *p = L->next;
	if (p == NULL) {
		printf("链表为空\n");
	}
	else
	{
		while (p != NULL) {
			printf("%d\n", p->data);
			p = p->next;
		}
		printf("链表元素输出完成\n");
	}
}

LNode *GetElem_L(LinkList L, int i) {  //算法2.08
	int num = 0;
	LNode *p = L->next;
	if (i <= 0)
	{
		printf("value is illegal\n");
		return L;
	}
	while (p != NULL && num < i-1)
	{
		num++;
		p = p->next;
	}
	if (num < i-1)
	{
		printf("i is more big than list length\n");
		return 0;
	}
	return p;
}

void ListInsert_L(LinkList *L, int i, int e) {  //算法2.09
	LNode *temp, *p = GetElem_L(L, i-1);
	temp = (LNode *)malloc(sizeof(LNode));
	temp->data = e;
	temp->next = p->next;
	p->next = temp;
	printf("insert successful\n");
	return 1;
}

void ListDelete_L(LinkList *L, int i) {   //算法2.10
	LNode *temp, *p = GetElem_L(L, i - 1);
	temp = (LNode *)malloc(sizeof(LNode));
	temp = p->next;
	p->next = temp->next;
	free(temp);  //放空节点，但节点存在，next为null;p1 = null 可以置空
	printf("delete successful\n");
	return 1;
}

LinkList ReverseCreateList_L(LinkList L, int n) {  //算法2.11   （头插法）
	int i = 0;
	LNode *p;
	L = (int *)malloc(sizeof(LNode));
	L->next = NULL;
	for ( i; i < n; i++)
	{
		p = (int *)malloc(sizeof(LNode));
		p->data = rand()%10;  //random function
		printf("created random num is:%d\n", p->data);
		p->next = L->next;
		L->next = p;
	}
	return L;
}

int LinkListLength(LinkList L) {   //获取链表长度
	int i = 0;
	LNode *p = L->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}


LNode *MergeList_l(LNode *LaHead, LNode *LbHead, LNode *LcHead) {  //算法2.12
	//该代码生效，但问题是我没有设置头节点，在该代码下第一个元素会被
	//	忽略。接下来我的主要问题是修改创建链表代码，将lhead设置成头节点
	//而不是首元节点
	LNode *pa, *pb, *pc;
	pa = LaHead->next;    pb = LbHead->next;
	LcHead = pc = LaHead;             // 用LaHead的头结点作为Lc的头结点
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;   pc = pa;   pa = pa->next;
			printf("current insert number is:%d\n", pc -> data);
		}
		else {
			pc->next = pb;   pc = pb;   pb = pb->next;
			printf("current insert number is:%d\n", pc->data);
		}
	}
	pc->next = pa ? pa : pb;  // 插入剩余段
	free(LbHead);
	return LcHead;
}

//---------------------------------------------------------------------------王道习题

void InvertPrintf(LinkList L) {
	/*int Length = LinkListLength(L);
	int i = Length;
	LNode *p;
	for ( i; i > 0; i--)
	{
	p = GetElem_L(L, i);
	printf("倒数第%d个值是：%d\n", i, p->data);
	}
	return 1;*/

	if (L->next != NULL)    //课本算法
	{
		InvertPrintf(L->next);
	}
	printf(L->data);
}

void DeleteAreaNum(LinkList L, int min, int max) {   //wangdao2.2.7
	LNode *pre = L, *p = L->next;
	while (p != NULL)
	{
		if (p->data > min && p->data < max)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	return L;
}

void PrintfIncreaseingList(LinkList L) {
	LNode *pre;
	LNode *p = L->next;
	LNode *r = p->next;
	p->next = NULL;
	p = r;

	while (p != NULL)
	{
		r = p->next;
		pre = L;
		while (pre->next != NULL && p->data > pre->next->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
	return L;
}

void SeparateList(LinkList La,LinkList Lb) {
	Lb = (LNode *)malloc(sizeof(LNode));
	LNode *p = La->next;
	LNode *r = Lb;
	LNode *odd, *even;
	while (p!=NULL)
	{
		odd = p;
		even = p->next;
		odd->next = even->next;

		r->next = even;
		r = even;

		p = p->next;
		if (p == NULL || p->next == NULL)
		{
			break;
		}
	}
	r->next = NULL;
	return La;
}

int main() {
	LinkList *La , *Lb, *Lc;
	int i, j, e, o = 1;
	while (o != 0)
	{
		printf("(1)创建链表\n");
		printf("(2)输出链表\n");
		printf("(3)输出链表第i个值\n");
		printf("(4)链表第i个元素之前插入元素e\n");
		printf("(5)移除链表第i个元素\n");
		printf("(6)逆序产生n个节点的链表(尾插法)\n");
		printf("(7)归并链表La,Lb，并按递增排列\n");
		printf("(8)逆序输出La\n");  //王道单链表3
		printf("(100)测试选项\n");
		printf("(0)退出\n");

		scanf("%d", &o);
		switch (o)
		{
		case 100:
			printf("开始测试:\n");
			InitList_L(&Lb);
			SeparateList(La, Lb);
			printf("printf:\n");
			PrintList_L(La);
			break;
		case 1:
			if (InitList_L(&La))
			{
				La = CreatList_L(La);   //La得到链表头指针
				printf("链表构造成功\n");
			}
			//if (InitList_L(&Lb))
			//{
			//	printf("链表构造成功\n");
			//	CreatList_L(Lb);   //Lb得到链表头指针
			//	printf("Lb首元节点为：%d\n", Lb);
			//}
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
		case 5:
			printf("移除链表第i个元素\n");
			scanf("%d", &i);
			ListDelete_L(La, i);
			break;
		case 6:
			printf("随机生成长度为n的链表\n");
			InitList_L(&Lb);
			printf("输入要生成链表的长度\n");
			scanf("%d", &i);
			Lb = ReverseCreateList_L(Lb, i);
			PrintList_L(Lb);
			break;
		case 7:
			printf("归并链表La,Lb,得到Lc\n");
			InitList_L(&Lc);
			Lc = MergeList_l(La, Lb, Lc);
			PrintList_L(Lc);
			break;
		case 8:
			printf("逆序输出La\n");
			InvertPrintf(La);
			break;
		case 0:
			break;
		}
	}
}