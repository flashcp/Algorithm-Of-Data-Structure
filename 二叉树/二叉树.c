#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define ElemType int
#define true 1
#define false 0

typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;