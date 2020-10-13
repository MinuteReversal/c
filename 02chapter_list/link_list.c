#include <stdio.h>
#include "link_list.h"

int main(int argc, char const *argv[])
{
    PLinkNode list = init(10);
    printf("#%p\n", list);
    printLinkList(list);

    PLinkNode node3 = findByIndex(list, 2);
    insertAfter(node3, 888);
    printLinkList(list);

    removeByValue(list, 8);
    printLinkList(list);

    clear(list);

    return 0;
}