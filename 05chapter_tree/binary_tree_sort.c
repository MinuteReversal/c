/******************************************************************************
* fileName    : binary_tree_order.c 
* author      : 114233763@qq.com
* date        : 2020-09-19 22:28:41
* description : 二叉树排序
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
 * 在二叉排序树中插入结点
 */
PBinaryTreeNode insertNode(PBinaryTreeNode node, PBinaryTreeNode tree)
{
    if (tree == NULL)
    {
        tree = node;
    }
    else if (node->data < tree->data)
    {
        tree->leftChild = insertNode(node, tree->leftChild);
    }
    else
    {
        tree->rightChild = insertNode(node, tree->rightChild);
    }
    return tree;
}

/**
 * 初始化树
 */
PBinaryTreeNode initByArray(int datas[], int length)
{
    PBinaryTreeNode tree;
    PBinaryTreeNode node;
    for (size_t i = 0; datas[i] != 0 && i < length; i++)
    {
        node = create(datas[i]);
        tree = insertNode(node, tree);
    }
    return tree;
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

int main(int argc, char const *argv[])
{
    /**
     *       2
     *     3   5
     *           6
     *          5  8
     */
    int array[] = {3, 5, 6, 2, 8, 5, 0};
    PBinaryTreeNode root = NULL;
    root = initByArray(array, sizeof(array) / sizeof(int));

    inorder(root);
    printf("\n");

    return 0;
}