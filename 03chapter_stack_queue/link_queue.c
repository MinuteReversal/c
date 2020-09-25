#include <stdio.h>
#include <malloc.h>

typedef struct _LinkQueueNode
{
    int data;
    struct _LinkQueueNode *next;
} LinkQueueNode, *PLinkQueueNode;

/**
* 创建一个节点
* @param rear 队尾
* @param data 值
* @return 新创建的节点
*/
PLinkQueueNode createNode(PLinkQueueNode rear, int data)
{
    PLinkQueueNode p = (PLinkQueueNode)malloc(sizeof(LinkQueueNode)); //新创建的节点
    p->data = data;
    p->next = NULL;

    if (rear)
    {
        rear->next = p;
    }
    return p;
}

/**
* 初始化
* @param front 队首
* @param rear 队尾
* @return 无
*/
void init(PLinkQueueNode *front, PLinkQueueNode *rear)
{
    *front = createNode(NULL, -1);
    *rear = *front;
}

/**
* 入队
* @param rear 队尾
* @param data 值
* @return 无
*/
void push(PLinkQueueNode *rear, int data)
{
    *rear = createNode(*rear, data);
}

void pop(PLinkQueueNode *front, PLinkQueueNode *rear, int *value)
{
    PLinkQueueNode p = (*front)->next; //指向表头后面的一个元素
    if (*front != *rear)
    {
        (*front)->next = p->next;
        if (p->next == NULL)
            *rear = *front;
        *value = p->data;
        free(p);
    }
    else
    {
        printf("link queue is empty!");
    }
}

void print(PLinkQueueNode front)
{
    for (PLinkQueueNode p = front->next; p; p = p->next)
    {
        printf("%d\n", p->data);
    }
}

int main(int argc, char const *argv[])
{
    PLinkQueueNode front;
    PLinkQueueNode rear;
    init(&front, &rear);
    for (size_t i = 0; i < 5; i++)
    {
        push(&rear, i);
    }

    print(front);

    for (size_t i = 0; i < 5; i++)
    {
        int value;
        pop(&front, &rear, &value);
        printf("%d\n", value);
    }

    return 0;
}