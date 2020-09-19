#include <stdio.h>
#include <malloc.h>
#define QUEUE_SIZE 20

/**
 * 二叉树节点
 */
typedef struct _BinaryTreeNode
{
    int data;
    struct _BinaryTreeNode *leftChild;
    struct _BinaryTreeNode *rightChild;
} BinaryTreeNode, *PBinaryTreeNode;

/**
 * 循环队列
 */
typedef struct _CircularQueue
{
    int front, rear;
    PBinaryTreeNode data[QUEUE_SIZE]
} CircularQueue, *PCircularQueue;

/**
 * 创建单个树节点
 */
PBinaryTreeNode create(int data, PBinaryTreeNode leftChild, PBinaryTreeNode rightChild)
{
    PBinaryTreeNode node = (PBinaryTreeNode)malloc(sizeof(BinaryTreeNode));
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;
    if (leftChild)
    {
        node->leftChild = leftChild;
    }
    if (rightChild)
    {
        node->rightChild = rightChild;
    }
    return node;
}

/**
 * 初始化树
 */
void initByArray(PBinaryTreeNode *tree, int index, int datas[], int length)
{
    int data = datas[index];
    if (data == 0 || index >= length)
    {
        *tree = NULL;
    }
    else
    {
        *tree = (PBinaryTreeNode)malloc(sizeof(BinaryTreeNode));
        (*tree)->data = data;
        initByArray(&(*tree)->leftChild, 2 * index + 1, datas, length);  //左儿子=索引*2+1
        initByArray(&(*tree)->rightChild, 2 * index + 2, datas, length); //右儿子=索引*2+2
    }
}



int main(int argc, char const *argv[])
{
    /**
     *       1
     *     2   3
     *   4  5    6
     */
    int array[] = {1, 2, 3, 4, 5, 0, 6};
    PBinaryTreeNode root = NULL;
    initByArray(&root, 0, array, sizeof(array) / sizeof(int));
    return 0;
}