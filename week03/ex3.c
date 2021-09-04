#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* next;
    int value;
} node;

typedef struct head
{
    node* next;
    int size;
} head;

head* init_linked_list()
{
    head* obj = (head*)malloc(sizeof(head));
    obj->next = NULL;
    obj->size = 0;
}

node* make_node(int value, node* to)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = to;
    new_node->value = value;
}

void print_list(head* list)
{
    node* cur_node = list->next;
    while(cur_node != NULL)
    {
        printf("%d ",cur_node->value);
        cur_node = cur_node->next;
    }
    printf("\n");
}

int insert_node(head* list, int idx, int value)
{
    if(idx < 0 || idx > list->size)
        return 0;

    ++list->size;

    if(!idx)
    {
        list->next = make_node(value, list->next);
        return 1;
    }

    node* cur_node = list->next;
    for(int i = 0; i+1<idx; ++i)
        cur_node = cur_node->next;

    cur_node->next = make_node(value, cur_node->next);
    return 1;
}

int delete_node(head* list, int idx)
{
    node* temp;

    if(idx<0 || idx>=list->size)
        return 0;

    --list->size;

    if(!idx)
    {
        temp = list->next->next;
        free(list->next);
        list->next = temp;
        return 1;
    }

    node* cur_node = list->next;
    for(int i = 0; i+1<idx; ++i)
        cur_node = cur_node->next;

    temp = cur_node->next->next;
    free(cur_node->next);
    cur_node->next = temp;

    return 1;
}

int main()
{
    head* linked_list = init_linked_list();
    print_list(linked_list);
    insert_node(linked_list, 0, 1);
    print_list(linked_list);
    insert_node(linked_list, 1, 2);
    print_list(linked_list);
    delete_node(linked_list, 1);
    print_list(linked_list);
    delete_node(linked_list, 0);
    print_list(linked_list);

    return 0;
}