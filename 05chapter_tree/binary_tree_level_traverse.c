/******************************************************************************
* fileName    : binary_tree_level_traverse.c 
* author      : 114233763@qq.com
* date        : 2020-09-26 11:38:09
* description : 按层次遍历
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
#define MAX_LEN 20

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
    PBinaryTreeNode data[MAX_LEN];
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

PCircularQueue init()
{
    PCircularQueue queue = (PCircularQueue)malloc(sizeof(CircularQueue));
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

int isFull(PCircularQueue queue)
{
    return (queue->rear + 1) % MAX_LEN == queue->front;
}

int isEmpty(PCircularQueue queue)
{
    return queue->front == queue->rear;
}

int pushQueue(PCircularQueue queue, PBinaryTreeNode node)
{
    if (isFull(queue))
        return 0;

    queue->rear = (queue->rear + 1) % MAX_LEN;
    queue->data[queue->rear] = node;
    return 1;
}

int popQueue(PCircularQueue queue, PBinaryTreeNode *node)
{
    if (isEmpty(queue))
        return 0;
    else
    {
        queue->front = (queue->front + 1) % MAX_LEN;
        *node = queue->data[queue->front];
        return 1;
    }
}

void levelorder(PBinaryTreeNode tree)
{
    PCircularQueue queue;

    queue = init();
    pushQueue(queue, tree);
    while (!isEmpty(queue))
    {
        PBinaryTreeNode currentTreeNode;   //当前取出的树节点
        popQueue(queue, &currentTreeNode); //出队
        printf("%d,", currentTreeNode->data);
        if (isFull(queue))
        {
            printf("queue is full\n.");
            continue;
        }

        if (currentTreeNode->leftChild)
        { //左儿子入队
            pushQueue(queue, currentTreeNode->leftChild);
        }

        if (currentTreeNode->rightChild)
        { //右儿子入队
            pushQueue(queue, currentTreeNode->rightChild);
        }
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
    levelorder(root);
    printf("\n");
    return 0;
}