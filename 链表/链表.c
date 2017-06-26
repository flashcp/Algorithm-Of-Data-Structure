#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct LNode *next;
}LNode;

int InitList_L(LNode **LN) {
	*LN = NULL;
	printf("��ʼ���ɹ�������ͷָ��Ϊ��\n");
	return 1;
}

LNode *CreatList_L(LNode *Lhead) {
	LNode *p1, *p2;
	p1 = p2 = (LNode *)malloc(sizeof(LNode));  //�����½ڵ�
	if (p1 == NULL && p2 == NULL) {
		printf("�ڵ����ʧ�ܣ�\n");
		exit(0);
	}
//	memset(p1, 0, sizeof(Lhead));
	printf("��������Ԫ�أ�\n");
	scanf("%d", &p1->data);
	p1->next = NULL;

	while (p1->data > 0) {  //����ڵ����0
		if (Lhead == NULL) {
			Lhead = p1;
			printf("empty head distributing succssful\n");
		}
		else {
			printf("%d\n", p2->data);

			p2->next = p1;  //p2ʼ�ձ����ڱ�β
			printf("head distributing succssful\n");
		}
		p2 = p1;
		p1 = (LNode *)malloc(sizeof(LNode));  //������һ���½ڵ�
	//	memset(p1, 0, sizeof(Lhead));
		scanf("%d", &p1->data);
		p1->next = NULL;
	}
	printf("���������\n");
	return Lhead;    //�����������Ԫ�ڵ�
}

void PrintList_L(LNode *Lhead) {
	if (Lhead == NULL) {
		printf("����Ϊ��\n");
	}
	else
	{
		while (Lhead != NULL) {
			printf("%d\n", Lhead->data);
			Lhead = Lhead->next;
		}
		printf("����Ԫ��������\n");
	}
}

void GetElem_L(LNode *Lhead, int i) {  //�㷨2.08
	int num = 0;
	if (i <= 0)
	{
		printf("value is illegal\n");
		return 0;
	}
	while (Lhead != NULL && num < i-1)
	{
		num++;
		Lhead = Lhead->next;
	}
	if (num < i-1)
	{
		printf("i is more big than list length\n");
		return 0;
	}
	printf("ֵΪ:%d\n", Lhead->data);
	return 1;
}

void ListInsert_L(LNode *Lhead, int i, int e) {  //�㷨2.09
	int num = 0;
	LNode *p1;
	
	if (Lhead == NULL)
	{
		printf("Lhead is empty list\n");
		return 0;
	}
	while (Lhead != NULL && num < i-2)  //LheadҪȡ����i���ڵ�ǰ��Ľڵ�
	{
		num++;
		Lhead = Lhead->next;
	}
	if (num < i-2)
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

void ListDelete_L(LNode *Lhead, int i) {   //�㷨2.10
	int num = 0;
	LNode *p1;
	p1 = (int *)malloc(sizeof(LNode));
	while (Lhead != NULL && num < i-2)  //LheadҪȡ����i���ڵ�ǰ��Ľڵ�
	{
		num++;
		Lhead = Lhead->next;
	}
	if (num < i - 2)
	{
		printf("i is more big than list length\n");
		return 0;
	}
	p1 = Lhead->next;
	Lhead->next = p1->next;
	free(p1);  //�ſսڵ㣬���ڵ���ڣ�nextΪnull;p1 = null �����ÿ�
	printf("delete successful\n");
	return 1;
}

LNode *ReverseCreateList_L(LNode *Lhead, int n) {
	int i = 0;
	LNode *p1;
	Lhead = (int *)malloc(sizeof(LNode));
	Lhead->next = NULL;
	for ( i; i < n; i++)
	{
		p1 = (int *)malloc(sizeof(LNode));
		p1->data = rand()%10;  //random function
		p1->next = Lhead->next;
		Lhead->next = p1;
	}
	printf("creatList successful\n");
	return Lhead->next;
}

int main() {
	LNode *La , *Lb, Lc;
	int i, e, o = 1;
	while (o != 0)
	{
		printf("(1)��������\n");
		printf("(2)�������\n");
		printf("(3)��������i��ֵ\n");
		printf("(4)�����i��Ԫ��֮ǰ����Ԫ��e\n");
		printf("(5)�Ƴ������i��Ԫ��\n");
		printf("(6)�������n���ڵ������\n");
		printf("(0)�˳�\n");

		scanf("%d", &o);
		switch (o)
		{
		case 1:
			if (InitList_L(&La))
			{
				printf("������ɹ�\n");
				La = CreatList_L(La);   //La�õ�����ͷָ��
				printf("La��Ԫ�ڵ�Ϊ��%d\n", La->data);
			}
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
			scanf("%d", &i);
			Lb = ReverseCreateList_L(Lb, i);
			PrintList_L(Lb);
			printf("Lb��Ԫ�ڵ�Ϊ��%d\n", Lb->data);
			break;
		case 0:
			break;
		}
	}
}