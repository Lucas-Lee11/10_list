#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct item {
    char name[256];
    int price;
    struct item* next;
};
struct item* new_item(char arr[], int i);
struct item* free_item(struct item *ip);
struct item* free_list(struct item* ip);
struct item* append_end(struct item* ip, char arr[], int i);
struct item* insert_front(struct item* ip, char arr[], int i);
struct item* remove_node(struct item *ip, int i);
int num_items(struct item* ip);
void change_name(struct item* ip, char arr[]);
void change_price(struct item* ip, int i);
void print_item(struct item* ip);
void print_list(struct item *ip);

#endif
