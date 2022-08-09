#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void initial_list(tNumStorHead *list)
{
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void print_list(tNumStorHead *list)
{
    tNumStorage *p_node = list->head;

    printf("\nFrom head --> ");
    while (p_node != NULL)
    {
        printf("%d ", p_node->number);
        p_node = p_node->next;
    }
    printf("\n");

    p_node = list->tail;

    printf("From tail --> ");
    while (p_node != NULL)
    {
        printf("%d ", p_node->number);
        p_node = p_node->prev;
    }
    printf("\n\n");
    
}

void sort_list(tNumStorHead *list, int input, int target_node, int before_after)
{
    int j=0, k=0;
    tNumStorage *pStor , *p_node, *p_node_next, *p_node_prev;
    pStor = (tNumStorage *) malloc (sizeof(tNumStorage));
    pStor->number = input;
    pStor->next = NULL;
    pStor->prev = NULL;
    

    if (list->counts == 0)
    {
        list->head = pStor;
        list->tail = pStor;
        list->counts ++;
    }
    else
    {
        int i = 0;
        p_node = list->head;
        p_node_next = list->head->next;
        p_node_prev = list->head->prev;
        while (i != list->counts + 1)
        {
            i++;
            if(before_after == 1 && i == target_node && p_node->prev == NULL){ //多個(含一個)node時，放最前面
                pStor->next = list->head;
                list->head->prev = pStor;
                list->head = pStor;
                list->counts ++;
            break;
            }
            else if(before_after == 1 && i == target_node && p_node_prev != NULL){ //多個(含一個)node時，node前面還有其他node
                pStor->next = p_node;
                p_node->prev = pStor;
                p_node_prev->next = pStor;
                pStor->prev = p_node_prev;
                list->counts ++;
                break;
            }
            else if(before_after == 2 && i == target_node && p_node->next == NULL){ //多個(含一個)node時，放最後面
                list->tail->next = pStor;
                pStor->prev = list->tail;
                list->tail = pStor;
                list->counts ++;
                break; 
            }
            else if(before_after == 2 && i == target_node && p_node->next != NULL){ //多個(含一個)node時，node後面還有其他node
                pStor->next = p_node_next;
                p_node_next->prev = pStor;
                p_node->next = pStor;
                pStor->prev = p_node;
                list->counts ++;
                break;
            }
            else
            {
                p_node_prev = p_node;
                p_node = p_node_next;
                p_node_next = p_node->next;
            }
            
        }
    }
    
    printf("count: %d", list->counts);
    print_list(list);
}

void delete_node(tNumStorHead *list, int target_node)
{
    tNumStorage *pRemove , *p_node, *p_node_next, *p_node_prev;
    pRemove = (tNumStorage *) malloc (sizeof(tNumStorage));
    pRemove->number = 0;
    pRemove->next = NULL;
    pRemove->prev = NULL;

    if (list->head->next == NULL && list->head->prev ==NULL) 
    { 
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->counts --;
    }
    else
    {
        int i = 0;
        p_node = list->head;
        p_node_next = list->head->next;
        p_node_prev = list->head->prev;
        while (i != list->counts + 1)
        {
            i++;
            if(i == target_node && p_node_prev == NULL){ //刪除最前面的時候
                pRemove = p_node;
                p_node = p_node_next;
                free(pRemove);
                p_node->prev = NULL;
                list->head = p_node; 
                list->counts --;
                break;
            }
            else if(i == target_node && p_node_next == NULL)
            {
                pRemove = p_node;
                p_node = p_node_prev;
                free (pRemove);
                p_node->next = NULL;
                list->tail = p_node;
                list->counts --;
                break;
            }
            else if(i == target_node && p_node_prev != NULL && p_node_next != NULL)
            {
                pRemove = p_node;
                p_node = p_node_prev;
                free (pRemove);
                p_node->next = p_node_next;
                p_node_next->prev = p_node;
                list->counts --;
                break;
            }
            
            else{
                p_node_prev = p_node;
                p_node = p_node_next;
                p_node_next = p_node->next;
            }
        }
    }

    printf("count: %d", list->counts);
    print_list(list);
}