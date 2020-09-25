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

/**
 * 查找值相同的节点和其父节点
 * @param tree 树根
 * @param value 值
 * @param parentNode 父节点
 * @return 找到的节点 
 */
PBinaryTreeNode findNodeByValue(PBinaryTreeNode tree, int value, PBinaryTreeNode *parentNode)
{
    PBinaryTreeNode node = tree;
    while (node != NULL && node->data != value)
    {
        if (value < node->data)
        {
            *parentNode = node;
            node = node->leftChild;
        }
        else
        {
            *parentNode = node;
            node = node->rightChild;
        }
    }
    return node;
}

/**
 * 按值删除
 */
PBinaryTreeNode deleteNode(PBinaryTreeNode t, int key)
{
    PBinaryTreeNode p, q, r, s;
    p = t;
    q = NULL;

    p = findNodeByValue(t, key, &q);

    if (p == NULL)
    {
        printf("Not found!");
        return NULL;
    }
    else if (p->leftChild == NULL && p->rightChild == NULL)
    {
        if (p == t)
        {
            t = NULL;
        }
        else if (p == q->leftChild)
        {
            q->leftChild = NULL;
        }
        else
        {
            q->rightChild = NULL;
        }
    }
    else if (p->leftChild == NULL || p->rightChild == NULL)
    {
        if (p == t)
        {
            if (p->leftChild == NULL)
            {
                t = p->rightChild;
            }
            else
            {
                t = p->leftChild;
            }
        }
        else
        {
            if (p == q->leftChild && p->leftChild != NULL)
            {
                q->leftChild = p->leftChild;
            }
            else if (p == q->leftChild && p->rightChild != NULL)
            {
                q->leftChild = p->rightChild;
            }
            else if (p == q->rightChild && p->leftChild != NULL)
            {
                q->rightChild = p->leftChild;
            }
            else if (p == q->rightChild && p->rightChild != NULL)
            {
                q->rightChild = p->rightChild;
            }
        }
    }
    else if (p->leftChild != NULL && p->rightChild != NULL)
    {
        r = p;
        s = p->leftChild;
        while (s->rightChild != NULL)
        {
            r = s;
            s = s->rightChild;
        }
        p->data = s->data;
        if (r == p)
        {
            p->leftChild = s->leftChild;
        }
        else
        {
            r->rightChild = s->leftChild;
        }
        p = s;
    }

    free(p);
    return t;
}

int main(int argc, char const *argv[])
{
    /**
     *       6
     *     4   8
     *   3       7
     *             9
     */
    int array[] = {6, 4, 8, 3, 7, 9, 0};
    PBinaryTreeNode root = NULL;
    root = initByArray(array, sizeof(array) / sizeof(int));

    inorder(root);
    printf("\n");

    deleteNode(root, 8);
    inorder(root);
    printf("\n");

    return 0;
}