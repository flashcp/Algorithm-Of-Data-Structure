#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {         //����˳���ṹ
	int *elem;               //�洢�����ʼ��ַ
	int length;         //��ǰ����
	int listsize;     //�������
}SqList;

int InitList(SqList *L) //��ʼ���µ�˳���
{
	L->elem = (int *)malloc(MAX * sizeof(int));   //����һ��MAX�Ĵ洢�ռ䲢ǿ��ת��Ϊint��ָ��(int *)  L->elem��������ָ�룩ָ����洢�ռ���׵�ַ
	if (!L->elem)                                 //�����ڴ�ʧ��
		exit(0);
	L->length = 0;                 //��ʼ������Ϊ0
	L->listsize = MAX;         //�������
	return 1;                     //����ɹ�����1
}
void Creatlist(SqList *L)   //�ֶ���������˳���
{
	int i, n = 0, s;
	printf("���������������鳤��:\n");
	scanf("%d", &s);
	for (i = 0; i < s; i++) //���û�������������˳���
	{
		scanf("%d", &n);
		L->elem[i] = n;
	}
	L->length = i;
	printf("����ɹ���\n");   //���ص�ǰ����
}

void SortList(SqList *L) //��ð�������������������
{
	int i, j, k = 0;
	for (i = 0; i < L->length; i++)
		for (j = i; j < L->length; j++)
			if (L->elem[i] > L->elem[j])   //�������У�����Ԫ��
			{
				k = L->elem[i];
				L->elem[i] = L->elem[j];
				L->elem[j] = k;
			}
}

void TailInsert(SqList *L)//ʵ���ڱ�β����Ԫ��
{
	int num;
	char ch;
	do {
		printf("������Ҫ�����ĩ��Ԫ�أ�\n");
		scanf("%d", &num);
		getchar();
		L->elem[L->length] = num;//��num��ӵ���β
		(L->length)++; //����1
		printf("�Ƿ�������룿��Y/N��\n");//����y��������
		scanf("%c", &ch);
		getchar();      //getchar��һ��int�͵ķ���ֵ������getcharʱ����ȴ��û������ַ���֪������س�
	} while (ch == 'y' || ch == 'Y');
}
int DeleteElem(SqList *L, int i)//ʵ��ɾ������ֵΪi��Ԫ��
{
	int j;
	if (i<1 || i>L->length)//�ж�i�Ƿ���Ч
		printf("����������� ����ֵ����\n");

	for (j = i; j<L->length - 1; j++)//������ֵΪiԪ�غ��Ԫ�ض���ǰһλ
		L->elem[j] = L->elem[j + 1];
	L->length--;//����һ
	return L->elem[i];//������ɾ��Ԫ��
}



int PrintElem(SqList *L, int i)//ʵ�ִ�ӡ����ֵΪi��Ԫ��
{
	if (i<1 || i>L->length)//�ж�i�Ƿ���Ч
		printf("����������� ����ֵ����\n");
	else
		printf("����ֵΪ%d��Ԫ����%d\n", i, L->elem[i]);
	return L->elem[i];
}
int PrintLength(SqList *L)//ʵ�ִ�ӡ��
{

	printf("����������ԣ�\n");
	printf("%d\n", L->length);
	return L->length;
}
void PrintList(SqList *L)   //ʵ�����˳���
{
	int i;
	for (i = 0; i<L->length; i++)
		printf("%d   ", L->elem[i]);
	printf("\n");
}
void Merge(SqList *La, SqList *Lb, SqList *Lc)//ʵ�ֺϲ�La��Lb��Lc
{

	int *pa, *pb, *pc, *pa_last, *pb_last;
	pa = La->elem;
	pb = Lb->elem;
	/*printf("*pa:%d\n",*pa);
	printf("*pb:%d\n",*pb);*/
	Lc->length = Lc->listsize = La->length + Lb->length;//��Lc�ĳ�������ΪLa�ĳ�����Lb�ĳ���֮��
	pc = Lc->elem = (int *)malloc(Lc->listsize * sizeof(int));//�����ڴ浽���鲢��ʼ��pcָ�������ʼ��ַ
	if (!Lc->elem) exit(0);//����ʧ�ܾ��˳�
	pa_last = La->elem + (La->length - 1);//����La��β
	pb_last = Lb->elem + (Lb->length - 1);//����Lb��β
										  /*printf("*pa_last:%d\n",*pa_last);
										  printf("*pb_last:%d\n",*pb_last);*/
	while (pa <= pa_last&&pb <= pb_last)//pa��pb��û��Խ��ʱ����ѭ��
	{
		/*  printf("��ǰ*pa:%d\n",*pa);
		printf("��ǰ*pb:%d\n",*pb);*/
		if (*pa <= *pb) *pc++ = *pa++;//La��Ԫ��С��Lb��Ԫ�����LaԪ�طŵ�Lc�У�Ȼ��pa��pcָ����һ��Ԫ��
		else *pc++ = *pb++;
	}//����ͽ�LbԪ�ؽ�����ͬ����
	while (pa <= pa_last)*pc++ = *pa++;//��ʣ�µ�Ԫ�ز���
	while (pb <= pb_last)*pc++ = *pb++;

}

void Insert(SqList *L, int i, int e)//����Ԫ��e
									//д��unionʱ����insert:�ض�����󡣽�insert���ڵ��ú���ǰ����
{
	int j;
	if (i<1 || i>L->length + 1)//�ж�i�Ƿ���Ч
		printf("����ʧ��");
	for (j = L->length; j>i; j--)//������ֵΪi�����Ԫ�ض�������һ��
		L->elem[j] = L->elem[j - 1];

	L->elem[i] = e;
	L->length++;

}


int LocateElem(SqList *L, int e)//�ڱ��в���Ԫ��
{
	int i;
	for (i = 0; i<L->length; i++)
		if (L->elem[i] == e)
		{
			return i;//�����ҵ���������ֵ
			break;
		}
	return -1;//���Ҳ����򷵻�-1
}

void Union(SqList *La, SqList *Lb)   //�㷨2.1
{
	int i, e;
	for (i = 0; i < Lb->length; i++)
	{
		e = Lb->elem[i];//��ȡ��b��Ԫ�ظ���e
		if (LocateElem(La, e) == -1)//���ڱ�a�Ҳ���Ԫ��e
			Insert(La, La->length, e);//�����㷨2.1�ǰѱ�b�б�aû�е�Ԫ�ز嵽��a���
	}
}

void MergeList(SqList *La, SqList *Lb, SqList *Lc)    // �㷨2.2
{
	int i = 0, j = 0, k = 0;//��ʼ����ֵΪ0
	Lc->listsize = Lc->length = La->length + Lb->length;   //C���ʵ�ʳ���
	Lc->elem = (int *)malloc(Lc->length * sizeof(int));
	if (!Lc->elem)   exit(0);//�ڴ���䲻��
	while (i < La->length && j < Lb->length)    //�ϲ�
	{
		if (La->elem[i] <= Lb->elem[j])//��a iԪ��С�ڵ��ڱ�b jԪ��ʱ
		{
			Lc->elem[k++] = La->elem[i++];
			printf("La = %d",Lc->elem[k-1]);
		}//��a iԪ�ز����c����������һ��Ԫ��
		else
			Lc->elem[k++] = Lb->elem[j++];
	}
	while (i < (La->length))    //��a��ʣ����ֱ�Ӳ���
		Lc->elem[k++] = La->elem[i++];

	while (j < (Lb->length))    //��b��ʣ��Ҳֱ�Ӳ���
		Lc->elem[k++] = Lb->elem[j++];

}

int main()
{
	char ch;      //��ȡ�ַ������жϳ���Ľ��������
	SqList la, lb, lc;
	int i, e, o = 1, example, temp, tem;
	while (o != 0)
	{//����ò˵�
		printf("(1)��ʼ��˳���\n");
		printf("(2)��β����Ԫ��\n");
		printf("(3)����ĺ���\n");
		printf("(4)���λ��i��Ԫ��\n");
		printf("(5)��iλ��ǰ����Ԫ��\n");
		printf("(6)ɾ��λ��i��Ԫ��\n");
		printf("(7)���˳���\n");
		printf("(8)�ϲ�˳���La��Lb��Lc\n");
		printf("(9)����Ԫ��λ��\n");
		printf("(10)�㷨2.1����Lb��Laû�е�Ԫ�ز���La\n");
		printf("(11)�㷨2.2���ϲ�La��Lb�õ�Lc������������\n");
		printf("(0)�˳�\n");

		scanf("%d", &o);
		switch (o)//��switch�����Բ˵��и���Ĺ���
		{
		case 1:
			if (InitList(&la))
			{
				printf("��ʼ��La�ɹ�\n");
				printf("La:\n");
				Creatlist(&la);
				SortList(&la);
			}
			if (InitList(&lb))      //����b��
			{
				printf("��ʼ��Lb�ɹ�\n");
				printf("Lb:\n");
				Creatlist(&lb);
				SortList(&lb);
			}
			getchar();

			break;
		case 2:
			printf("��Laĩβ����Ԫ�أ�\n");
			TailInsert(&la);
			getchar();

			break;
		case 3:
			printf("La����");
			PrintLength(&la);
			printf("Lb����");
			PrintLength(&lb);
			getchar();

			break;
		case 4:
			printf("��ӡ����ֵΪ���ٵ�Ԫ�أ�\n");
			scanf("%d", &temp);
			PrintElem(&la, temp);
			getchar();

			break;
		case 5:
			printf("��������Ҫ����Ԫ�ص�����ֵ��\n");
			scanf("%d", &temp);
			printf("��������Ҫ�����Ԫ�أ�\n");
			scanf("%d", &tem);
			Insert(&la, temp, tem);
			getchar();

			break;
		case 6:
			printf("ɾ��La����ֵΪ���ٵ�Ԫ��:\n");
			scanf("%d", &temp);
			DeleteElem(&la, temp);
			getchar();

			break;
		case 7:
			printf("������Ա�La:\n");
			PrintList(&la);
			printf("������Ա�Lb:\n");
			PrintList(&lb);
			getchar();
			break;
		case 8:
			printf("���Ժϲ������㷨2.7\n");
			Merge(&la, &lb, &lc);
			printf("�ϲ���Lc��\n");
			PrintList(&lc);
			getchar();
			break;
		case 9:
			printf("����Lc�е�Ԫ��:\n");
			scanf("%d", &example);
			if (LocateElem(&lc, example) == -1)
				printf("�Ҳ�����\n");
			else
				printf("�ҵ�������ֵΪ��%d", LocateElem(&lc, example));
			break;
		case 10:
			printf("��Lb��Laû�е�Ԫ�ز���La\n");
			Union(&la, &lb);
			printf("������La\n");
			PrintList(&la);
			break;
		case 11:
			printf("�ϲ�La��Lb�õ�Lc������������\n");
			MergeList(&la, &lb, &lc);
			printf("������Lc\n");
			PrintList(&lc);
			break;
		case 0:
			break;
		default:
			printf("��������\n");
		}

		//system("cls"); //�����Ļ

	}
	return 0;
}
