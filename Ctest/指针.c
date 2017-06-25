#include<stdio.h>
void main() {

	int a = 5, *p1, *p2, *p3, *p4, arr[5] = { 1,2,3,4,5 };  //*p表示一个指针变量，p的值表示变量的地址
	char *p5;

	//表示指针变量p取得了整型变量a的地址。本语句表示输出变量a的值
	p1 = &a;  //&a表示a值的地址
	p2 = p1;  //*p1 *p2都是指针变量可以直接赋值，相当把a的地址赋予p2


	//把数组的首地址赋予指向数组的指针变量
	p3 = arr;
	//p3 = p3 + 1;
	p4 = &arr[1];

	p5 = "C language";
	
	printf("*p1是：%d\n", *p1);  //p的值表示变量的地址，加上*即可得到地址里的值
	printf("p1是：%d\n", p1);  //输出19922516二进制a的地址
	printf("*p2是：%d\n", *p2);
	printf("p2是：%d\n", p2);
	printf("*p3是：%d\n", *p3);  //数组名表示数组的首地址，故可赋予指向数组的指针变量p3
	printf("++*p3是：%d\n", ++*p3);  //对于数组指针变量，指针变量可以加减，表示指向上（下）N个指针地址
									  //++*p3语句相当于：p3 = arr;p3+1;  或  ：p3 = &arr[1]

	printf("*p4是：%d\n", *p4);
	printf("p5是：%d\n", p5);
	printf("*p5是：%d\n", *p5);  //字符串的首字符赋予p5，用ascll输出

	*p1 = 55;
	printf("更改指针后a的值：%d\n", a);  //更改指针变量相当于直接更改变量的值
	printf("&a是：%d\n", &a);

	int *p6 = 555, **p7;  //**p7 == *(*p7);  *p7是一个存储的值为指针的变量，p7就是存储上个变量地址的变量
	p7 = &p6;
	printf("*p7是：%d\n", *p7);
	printf("&p6是：%d\n", &p6);
	printf("p6是：%d\n", p6);

	int x = 10, y = 20, s, t, *pa, *pb;
	pa = &x;
	pb = &y;
	s = *pa + *pb;
	t = *pa**pb;
	printf("x=%d\ny=%d\nx+y=%d\nx*y=%d\n", x, y, x + y, x*y);
	printf("s=%d\nt=%d\n", s, t);

	int *ad = NULL;
	if (ad == NULL)
	{
		printf("为空\n");
	}
	else
	{
		printf("not empty\n");
	}
}

void test() {

}