/******************************************************************************
* fileName    : binary_tree_rotate.c 
* author      : 114233763@qq.com
* date        : 2020-09-20 17:26:27
* description : 二叉树旋转
https://blog.csdn.net/q1007729991/article/details/88093023

      x                            y
     / \     ---left rotate->     / \
    a    y   <--right rotate--   x   c
        / \                     / \
       b   c                   a   b


***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

typedef struct _BinaryTreeNode
{
    int data;
    struct _BinaryTreeNode *leftChild;
    struct _BinaryTreeNode *rightChild;
} BinaryTreeNode, *PBinaryTreeNode;

/**
 * 创建单个树节点
 */
PBinaryTreeNode create(int data)
{
    PBinaryTreeNode node = (PBinaryTreeNode)malloc(sizeof(BinaryTreeNode));
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;
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
        *tree = create(data);
        (*tree)->data = data;
        initByArray(&(*tree)->leftChild, 2 * index + 1, datas, length);  //左儿子=索引*2+1
        initByArray(&(*tree)->rightChild, 2 * index + 2, datas, length); //右儿子=索引*2+2
    }
}

/**
 * 选序遍历
 */
void preorder(PBinaryTreeNode node)
{
    if (node)
    {
        printf("%d,", node->data);
        preorder(node->leftChild);
        preorder(node->rightChild);
    }
}

/**
 * 中序遍历
 */
void inorder(PBinaryTreeNode node)
{
    if (node)
    {
        inorder(node->leftChild);
        printf("%d,", node->data);
        inorder(node->rightChild);
    }
}

/**
 * 后序遍历
 */
void postorder(PBinaryTreeNode node)
{
    if (node)
    {
        postorder(node->leftChild);
        postorder(node->rightChild);
        printf("%d,", node->data);
    }
}

/**
 * 左旋：是以节点的"右分支"为轴，进行逆时针旋转。我们将左旋操作定义为 left_rotate.
 * 
 *       1                     3 
 *      / \                   / \
 *     2   3    --------->   1   7
 *        / \               / \
 *        6  7             2   6
 */
void leftRotate(PBinaryTreeNode *node)
{
    PBinaryTreeNode currentNode = *node;
    PBinaryTreeNode rightChild = currentNode->rightChild;
    currentNode->rightChild = rightChild->leftChild;
    rightChild->leftChild = currentNode;
    *node = rightChild;
}

/**
 * 右旋：是以节点的“左分支"为轴，进行顺时针旋转。我们将右旋操作定义为 right_rotate.
 *
 *       1                    2
 *      / \                  / \
 *     2   3   --------->   4   1
 *    / \                      / \
 *   4   5                    5   3
 */
void rightRotate(PBinaryTreeNode *node)
{
    PBinaryTreeNode currentNode = *node;
    PBinaryTreeNode leftChild = currentNode->leftChild;
    currentNode->leftChild = leftChild->rightChild;
    leftChild->rightChild = currentNode;
    *node = leftChild;
}

int main(int argc, char const *argv[])
{
    /**
     *      1    
     *     / \   
     *    2   3  
     *       / \ 
     *       6  7
     */
    int array1[] = {1, 2, 3, 0, 0, 6, 7};
    PBinaryTreeNode root = NULL;
    initByArray(&root, 0, array1, sizeof(array1) / sizeof(int));
    leftRotate(&root);

    /**
     *        1   
     *       / \  
     *      2   3 
     *     / \    
     *    4   5   
     */
    int array2[] = {1, 2, 3, 4, 5, 0, 0};
    initByArray(&root, 0, array2, sizeof(array2) / sizeof(int));
    rightRotate(&root);
    return 0;
}