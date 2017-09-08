#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

int InitList_L(LinkList L) {
	L = NULL;
	printf("��ʼ���ɹ�������ͷָ��Ϊ��\n");
	return 1;
}

LinkList CreatList_L(LinkList L) {    //β�巨��������
	int x;
	L = (LNode *)malloc(sizeof(LNode));  //�����½ڵ�
	LNode *s, *r = L;
	
	printf("��������Ԫ�أ�\n");
	scanf("%d", &x);

	while (x > 0) {  //����ڵ����0
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next=NULL;
	return L;    //���������ͷ�ڵ㣨�൱��ͷָ�룩
}

void PrintList_L(LinkList L) {
	if (L == NULL)   //����ͷ�ڵ��ͷָ��Ϊ�ǿ�ָ��
	{
		printf("L is null!\n");
	}
	LNode *p = L->next;
	if (p == NULL) {
		printf("����Ϊ��\n");
	}
	else
	{
		while (p != NULL) {
			printf("%d\n", p->data);
			p = p->next;
		}
		printf("����Ԫ��������\n");
	}
}

LNode *GetElem_L(LinkList L, int i) {  //�㷨2.08
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

void ListInsert_L(LinkList *L, int i, int e) {  //�㷨2.09
	LNode *temp, *p = GetElem_L(L, i-1);
	temp = (LNode *)malloc(sizeof(LNode));
	temp->data = e;
	temp->next = p->next;
	p->next = temp;
	printf("insert successful\n");
	return 1;
}

void ListDelete_L(LinkList *L, int i) {   //�㷨2.10
	LNode *temp, *p = GetElem_L(L, i - 1);
	temp = (LNode *)malloc(sizeof(LNode));
	temp = p->next;
	p->next = temp->next;
	free(temp);  //�ſսڵ㣬���ڵ���ڣ�nextΪnull;p1 = null �����ÿ�
	printf("delete successful\n");
	return 1;
}

LinkList ReverseCreateList_L(LinkList L, int n) {  //�㷨2.11   ��ͷ�巨��
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

int LinkListLength(LinkList L) {   //��ȡ������
	int i = 0;
	LNode *p = L->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}


LNode *MergeList_l(LNode *LaHead, LNode *LbHead, LNode *LcHead) {  //�㷨2.12
	//�ô�����Ч������������û������ͷ�ڵ㣬�ڸô����µ�һ��Ԫ�ػᱻ
	//	���ԡ��������ҵ���Ҫ�������޸Ĵ���������룬��lhead���ó�ͷ�ڵ�
	//��������Ԫ�ڵ�
	LNode *pa, *pb, *pc;
	pa = LaHead->next;    pb = LbHead->next;
	LcHead = pc = LaHead;             // ��LaHead��ͷ�����ΪLc��ͷ���
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
	pc->next = pa ? pa : pb;  // ����ʣ���
	free(LbHead);
	return LcHead;
}

//---------------------------------------------------------------------------����ϰ��

void InvertPrintf(LinkList L) {
	/*int Length = LinkListLength(L);
	int i = Length;
	LNode *p;
	for ( i; i > 0; i--)
	{
	p = GetElem_L(L, i);
	printf("������%d��ֵ�ǣ�%d\n", i, p->data);
	}
	return 1;*/

	if (L->next != NULL)    //�α��㷨
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
		printf("(1)��������\n");
		printf("(2)�������\n");
		printf("(3)��������i��ֵ\n");
		printf("(4)�����i��Ԫ��֮ǰ����Ԫ��e\n");
		printf("(5)�Ƴ������i��Ԫ��\n");
		printf("(6)�������n���ڵ������(β�巨)\n");
		printf("(7)�鲢����La,Lb��������������\n");
		printf("(8)�������La\n");  //����������3
		printf("(100)����ѡ��\n");
		printf("(0)�˳�\n");

		scanf("%d", &o);
		switch (o)
		{
		case 100:
			printf("��ʼ����:\n");
			InitList_L(&Lb);
			SeparateList(La, Lb);
			printf("printf:\n");
			PrintList_L(La);
			break;
		case 1:
			if (InitList_L(&La))
			{
				La = CreatList_L(La);   //La�õ�����ͷָ��
				printf("������ɹ�\n");
			}
			//if (InitList_L(&Lb))
			//{
			//	printf("������ɹ�\n");
			//	CreatList_L(Lb);   //Lb�õ�����ͷָ��
			//	printf("Lb��Ԫ�ڵ�Ϊ��%d\n", Lb);
			//}
			break;
		case 2:
			printf("��ʼ���Ԫ��La:\n");
			PrintList_L(La);
			break;
		case 3:
			printf("�����i��ֵ:\n");
			scanf("%d", &i);
			GetElem_L(La, i);
			break;
		case 4:
			printf("������i��λ�ò���e\n");
			scanf("%d", &i);
			scanf("%d", &e);
			ListInsert_L(La, i, e);
			break;
		case 5:
			printf("�Ƴ������i��Ԫ��\n");
			scanf("%d", &i);
			ListDelete_L(La, i);
			break;
		case 6:
			printf("������ɳ���Ϊn������\n");
			InitList_L(&Lb);
			printf("����Ҫ��������ĳ���\n");
			scanf("%d", &i);
			Lb = ReverseCreateList_L(Lb, i);
			PrintList_L(Lb);
			break;
		case 7:
			printf("�鲢����La,Lb,�õ�Lc\n");
			InitList_L(&Lc);
			Lc = MergeList_l(La, Lb, Lc);
			PrintList_L(Lc);
			break;
		case 8:
			printf("�������La\n");
			InvertPrintf(La);
			break;
		case 0:
			break;
		}
	}
}