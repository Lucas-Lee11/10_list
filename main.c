#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main(int argc, char const *argv[]) {

    printf("Printing List: \n");
    struct item* head = NULL;
    print_list(head);

    printf("Adding Some Items: \n");
    printf("Printing List: \n");
    head = new_item("Hello", 5);
    insert_front(head, "World", 3);
    insert_front(head, "Banana", 8);
    insert_front(head, "Apple", 9);
    insert_front(head, "Grape", 7);
    print_list(head);

    printf("Removing \"Apple\": \n");
    printf("Printing List: \n");
    remove_node(head, 9);
    print_list(head);

    printf("Clearing List: \n");
    printf("Printing List: \n");
    free_list(head);


    return 0;
}
