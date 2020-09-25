/******************************************************************************
* fileName    : binary_tree_threaded.c 
* author      : 114233763@qq.com
* date        : 2020-09-19 22:02:59
* description : 中序线索树
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

typedef struct _BinaryTreeNode
{
    int data;              //数据
    int leftTag, rightTag; //标签 0 指向儿子，1指向前驱或后续
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
    node->leftTag = 1;
    node->rightTag = 1;

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

PBinaryTreeNode preNode = NULL;
/**
 * 中序线索化二叉树
 */
void inthread(PBinaryTreeNode tree)
{
    if (tree)
    {
        inthread(tree->leftChild); //左子树线索化
        if (tree->leftChild == NULL)
        {
            tree->leftChild = preNode; //前驱线索
        }
        else
        {
            tree->leftTag = 0;
        }

        if (preNode && preNode->rightChild == NULL)
        {
            preNode->rightChild = tree; //后继线索
        }
        else if (preNode)
        {
            preNode->rightTag = 0;
        }

        preNode = tree;
        inthread(tree->rightChild); //右子树线索化
    }
}

void printInOrderThread(PBinaryTreeNode tree)
{
    PBinaryTreeNode currentNode = tree;
    if (currentNode)
    {
        //找到根结点的最左端结点
        while (currentNode->leftTag == 0)
        {
            currentNode = currentNode->leftChild;
        }

        do
        {
            printf("%d,", currentNode->data);
            if (currentNode->rightTag == 1)
            {
                currentNode = currentNode->rightChild;
            }
            else
            {
                currentNode = currentNode->rightChild;
                while (currentNode->leftTag == 0)
                {
                    currentNode = currentNode->leftChild;
                }
            }
        } while (currentNode);
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
    inthread(root);
    printInOrderThread(root);
    printf("\n");
    return 0;
}