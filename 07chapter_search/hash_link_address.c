#include <stdio.h>
#include <malloc.h>
#define M 13

typedef struct _Node
{
    int key;
    struct _Node *next;
} Node, *PNode;

int hash(int key)
{
    return key % M;
}

void initList(Node list[])
{
    for (size_t i = 0; i < M; i++)
    {
        list[i].key = 0;
        list[i].next = NULL;
    }
}

PNode createNode(int key)
{
    PNode node = (PNode)malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    return node;
}

void appendNode(int key, PNode prior)
{
    PNode node = prior;
    if (node)
    {
        while (node->next != NULL)
        {
            node = node->next;
        }
        node->next = createNode(key);
    }
    else
    {
        *prior = *createNode(key);
    }
}

void save(int key, Node list[])
{
    int index = hash(key);
    if (list[index].key > 0)
    {
        appendNode(key, &list[index]);
    }
    else
    {
        list[index].key = key;
    }
}

void printList(Node list[])
{
    for (size_t i = 0; i < M; i++)
    {
        Node node = list[i];
        printf("%d,", node.key);
        PNode nextNode = node.next;
        while (nextNode)
        {
            printf("%d,", nextNode->key);
            nextNode = nextNode->next;
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int b[] = {36, 45, 85, 25, 74, 86, 38, 56, 27, 44, 70, 12};
    Node hashTable[M];
    initList(hashTable);

    for (size_t i = 0; i < sizeof(b) / sizeof(int); i++)
    {
        save(b[i], hashTable);
    }

    printList(hashTable);

    return 0;
}