/******************************************************************************
* fileName    : trinode.c 
* author      : 114233763@qq.com
* date        : 2020-09-06 15:57:01
* description : 稀疏矩阵--十字链表
非零元素多于零元素
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

typedef struct _CrossNode
{
    //行号
    int row;
    //列号
    int column;
    //值
    int value;
    //同列下一个非零元素节点
    struct _CrossNode *down;
    //同行下一个非零元素结点
    struct _CrossNode *right;
} CrossNode, *PCrossNode;

typedef struct _CrossMatrix
{
    PCrossNode *rowHead; //数组
    int rows;
    PCrossNode *columnHead; //数组
    int colums;

} CrossMatrix, *PCrossMatrix;

typedef struct _Matrix
{
    int rows, columns;
    int *table;
} Matrix, *PMatrix;

/**
* 初始化矩阵
* @param row 行总数
* @param column 列总数
* @return 矩阵
*/
PMatrix initMatix(int rows, int columns)
{
    const size_t intSize = sizeof(int);
    const size_t cells = rows * columns;
    PMatrix matrix = (PMatrix)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->table = (int *)malloc(intSize * cells);

    for (size_t row = 0; row < rows; row++)
    {
        for (size_t column = 0; column < columns; column++)
        {
            int *cell = &matrix->table[row * columns + column];
            if (column <= row)
            {
                *cell = row * columns + column + 1;
            }
            else
            {
                *cell = 0;
            }
        }
    }

    return matrix;
}

void printMatrix(PMatrix matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
        {
            printf("%5d,", *(matrix->table + i * matrix->columns + j));
        }
        printf("\n");
    }
}

/**
* 释放矩阵
* @param matrix 矩阵 
* @return 无
*/
void disposeMatrix(PMatrix matrix)
{
    free(matrix->table);
    free(matrix);
}

/**
* 创建单个十字交叉表节点
* @return 节点 
*/
PCrossNode createCrossNode()
{
    return (PCrossNode)malloc(sizeof(CrossNode));
}

/**
 * 插入节点到列头上
 */
void insertInColumn(PCrossNode *columnHead, PCrossNode insertNode)
{
    PCrossNode nextNode = columnHead[insertNode->column];
    while (nextNode)
    {
        if (nextNode->down == NULL)
        {
            //接在后面
            nextNode->down = insertNode;
            break;
        }
        else if (nextNode->down->row > insertNode->row)
        { //接在两个节点中间
            insertNode->down = nextNode->down;
            nextNode->down = insertNode;
            break;
        }

        nextNode = nextNode->down;
    }
}

/**
 * 在行上插入节点
 */
void inserInRow(PCrossNode *rowHead, PCrossNode insertNode)
{
    PCrossNode nextNode = rowHead[insertNode->row];
    while (nextNode)
    {
        if (nextNode->right == NULL)
        {
            //接在后面
            nextNode->right = insertNode;
            break;
        }
        else if (nextNode->right->column > insertNode->column)
        { //接在两个节点中间
            insertNode->right = nextNode->right;
            nextNode->right = insertNode;
            break;
        }

        nextNode = nextNode->right;
    }
}

PCrossNode *createRowHead(int length)
{
    PCrossNode *head = (PCrossNode *)malloc(sizeof(PCrossNode) * length);
    for (size_t i = 0; i < length; i++)
    {
        PCrossNode node = createCrossNode();
        node->column = -1;
        node->row = i;
        node->down = NULL;
        node->right = NULL;
        head[i] = node;
    }
    return head;
}

PCrossNode *createColumnHead(int length)
{
    PCrossNode *head = (PCrossNode *)malloc(sizeof(PCrossNode) * length);
    for (size_t i = 0; i < length; i++)
    {
        PCrossNode node = createCrossNode();
        node->column = i;
        node->row = -1;
        node->down = NULL;
        node->right = NULL;
        head[i] = node;
    }
    return head;
}

/**
* 保存下到十字链表节点
* @param matrix 矩阵
* @param count 数据长度
* @return 数组
*/
PCrossMatrix saveToCrossNodeLinkList(PMatrix matrix)
{
    PCrossMatrix crossMatrix = (PCrossMatrix)malloc(sizeof(CrossMatrix));
    crossMatrix->colums = matrix->columns;
    crossMatrix->rows = matrix->rows;
    crossMatrix->rowHead = createRowHead(matrix->rows);
    crossMatrix->columnHead = createColumnHead(matrix->columns);

    for (size_t matrixIndex = 0; matrixIndex < matrix->rows * matrix->columns; matrixIndex++)
    {
        const int value = *(matrix->table + matrixIndex);
        if (0 != value)
        {
            PCrossNode node = createCrossNode();
            node->row = matrixIndex / matrix->columns;
            node->column = matrixIndex - node->row * matrix->columns;
            node->value = value;
            node->down = NULL;
            node->right = NULL;
            inserInRow(crossMatrix->rowHead, node);
            insertInColumn(crossMatrix->columnHead, node);
        }
    }
    return crossMatrix;
}

/**
* 打印十字链表
* @param array 数组 
* @return 无
*/
void printCrossMatrixByColum(PCrossMatrix matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
    {
        PCrossNode nextNode = matrix->columnHead[i];
        while (nextNode)
        {
            if (nextNode->row > -1)
            {
                printf("(%d,%d,%d),", *nextNode);
            }
            nextNode = nextNode->down;
        }
    }
    printf("\n");
}

/**
* 打印十字链表
* @param array 数组 
* @return 无
*/
void printCrossMatrixByRow(PCrossMatrix matrix)
{
    for (size_t i = 0; i < matrix->colums; i++)
    {
        PCrossNode nextNode = matrix->rowHead[i];
        while (nextNode)
        {
            if (nextNode->column > -1)
            {
                printf("(%d,%d,%d),", *nextNode);
            }
            nextNode = nextNode->right;
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    PMatrix matrix = initMatix(5, 5);
    printMatrix(matrix);

    PCrossMatrix crossMatrix = saveToCrossNodeLinkList(matrix);
    printf("=====row======\n");
    printCrossMatrixByRow(crossMatrix);
    printf("=====colum======\n");
    printCrossMatrixByColum(crossMatrix);

    return 0;
}