#include "lab5.h"

int main(void)
{
    Node *list;
    makeList(&list);
    printf("List Size: %d\n", getSize(list));
    insertAtHead(&list, "test");
    insertAtHead(&list, "test2");
    insertAtHead(&list, "test3");
    insertAtHead(&list, "test4");
    insertAtHead(&list, "test5");
    printf("List size: %d\n", getSize(list));
    void *data = removeFromTail(&list);
    printf("Removed: %s\n", (char*)data);
    printf("List Size: %d\n", getSize(list));
    freeList(&list);
    printf("List Size: %d\n", getSize(list));

    return 0;

}
