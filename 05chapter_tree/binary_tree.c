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

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");
    return 0;
}