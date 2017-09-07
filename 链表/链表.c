#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct LNode *next;
}LNode, *LinkList;

int InitList_L(LinkList **LN) {
	*LN = NULL;
	printf("��ʼ���ɹ�������ͷָ��Ϊ��\n");
	return 1;
}

LinkList CreatList_L(LinkList L) {
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
	printf("ֵΪ:%d\n", p->data);
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

LNode *ReverseCreateList_L(LNode *LbHead, int n) {  //�㷨2.11
	int i = 0;
	LNode *p1;
	LbHead = (int *)malloc(sizeof(LNode));
	LbHead->next = NULL;
	for ( i; i < n; i++)
	{
		p1 = (int *)malloc(sizeof(LNode));
		p1->data = rand()%10;  //random function
		p1->next = LbHead->next;
		LbHead->next = p1;
	}
	printf("creatList successful\n");
	return LbHead->next;
}

LNode *MergeList_l(LNode *LaHead, LNode *LbHead, LNode *LcHead) {  //�㷨2.12
	//LNode *pa, *pb, *pc, *pd;
	//pa = LaHead;
	//pb = LbHead;
	//pc = (int *)malloc(sizeof(LNode));
	//LcHead = pc;
	////LcHead = (int *)malloc(sizeof(LNode));
	////LcHead->next = NULL;
	//while (pa && pb)
	//{
	//	if (pa->data <= pb->data)
	//	{
	//		pc->next = pa;
	//		//pd = pa;
	//		pa = pa->next;
	//	}
	//	else
	//	{
	//		pc->next = pb;
	//		//pc = pb;
	//		pb = pb->next;
	//	}
	//	
	//	pc = pc->next;
	//	pc = (int *)malloc(sizeof(LNode));
	//}
	//pc->next = pa ? pa : pb;
	//free(LbHead);
	//printf("MergeList successful\n");
	//return pc->next;


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

int main() {
	LinkList *La , *Lb, *Lc;
	int i, e, o = 1;
	while (o != 0)
	{
		printf("(1)��������\n");
		printf("(2)�������\n");
		printf("(3)��������i��ֵ\n");
		printf("(4)�����i��Ԫ��֮ǰ����Ԫ��e\n");
		printf("(5)�Ƴ������i��Ԫ��\n");
		printf("(6)�������n���ڵ������\n");
		printf("(7)�鲢����La,Lb��������������\n");
		printf("(0)�˳�\n");

		scanf("%d", &o);
		switch (o)
		{
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
			printf("Lb��Ԫ�ڵ�Ϊ��%d\n", Lb);
			break;
		case 7:
			printf("�鲢����La,Lb,�õ�Lc\n");
			InitList_L(&Lc);
			Lc = MergeList_l(La, Lb, Lc);
			PrintList_L(Lc);
			break;
		case 0:
			break;
		}
	}
}