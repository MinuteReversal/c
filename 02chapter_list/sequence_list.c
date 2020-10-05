#include <stdio.h>
#include "sequence_list.h"

int main(int argc, char const *argv[])
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    PList list = createListByArray(a, sizeof(a) / sizeof(int));
    printList(list);
    insertBefore(3, 9, list);
    printList(list);
    removeAt(4, list);
    printList(list);
    return 0;
}