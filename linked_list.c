#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"

struct item* new_item(char arr[], int i){
    struct item* ip;
    ip = malloc(sizeof(struct item));

    strncpy(ip->name, arr, sizeof(ip->name));
    ip->price = i;
    ip->next = NULL;

    return ip;
}

struct item* free_item(struct item *ip){
    free(ip);
    return NULL;
}

struct item* free_list(struct item* ip){
    if(ip->next != NULL) free_list(ip->next);
    printf("Freeing item %s\n", ip->name);
    free(ip);
    return ip;
}

struct item* append_end(struct item* ip, char arr[], int i){
    struct item* toAdd = new_item(arr, i);
    while(ip->next != NULL) ip = ip->next;
    ip->next = toAdd;
    return ip;
}

struct item* insert_front(struct item* ip, char arr[], int i){
    struct item* toAdd = new_item(arr, i);
    if (ip == NULL){
        printf("Starting List\n");
        *ip = *toAdd;
        return ip;
    }
    toAdd->next = ip->next;
    ip->next = toAdd;
    return ip;
}

struct item* remove_node(struct item *ip, int i){
    struct item* head = ip;
    while(ip->next->price != i) {
        ip = ip->next;
        if (ip->next == NULL) return ip;
    }
    struct item* temp = ip->next->next;
    free(ip->next);
    ip->next = temp;
    return ip;
}

int num_items(struct item* ip){
    int i = 1;
    while(ip->next != NULL) {
        ip = ip->next;
        i++;
    }
    return i;
}

void change_name(struct item* ip, char arr[]){
    strncpy(ip->name, arr, sizeof(ip->name));
}

void change_price(struct item* ip, int i){
    ip->price = i;
}

void print_item(struct item* ip){
    printf("Item {\n\tname: \"%s\"\n\tprice: $%d\n}\n", ip->name, ip->price);
}

void print_list(struct item *ip){
    if(ip == NULL){
        printf("List Empty\n");
        return;
    }
    print_item(ip);
    while(ip->next != NULL){
        ip = ip->next;
        print_item(ip);
    }
}
