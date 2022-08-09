#include<stdio.h>
#include<stdlib.h>
#include "main.h"

int main(void)
{
    int i;
    tNumStorHead *list;
    list = (tNumStorHead *) malloc (sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

void get_input(tNumStorHead *list)
{
    int input = 0, result;

    while (input != -1)
    {
        
        int target_node = 0, before_after = 0;
        printf("1. Add a number or 2. Delete a number: ");
        scanf("%d", &input);
        if(input == -1)
        {
            break;
        }
        if(input == 2)
        {
            if(list->counts == 0){
                printf("No node can remove !\n");
                continue;
            }
            else
            {
                printf("Specify a target location: ");
                scanf("%d", &target_node);
                printf("\n\n");
                delete_node(list, target_node);
            }
        }
        else if (input == 1)
        {
            printf("Add a number: ");
            scanf("%d", &input);
            printf("\n");

            if (list->counts > 0)
            {
                printf("Specify a target location: ");
                scanf("%d", &target_node);
            
                if(target_node > list->counts){
                    printf("No this node !\n");
                    continue;
                }
                else
                {
                    printf("1. Before or 2. After a number %d: ", target_node);
                    scanf("%d", &before_after);
                    printf("\n\n");
                    sort_list(list, input, target_node, before_after);
                }
                
            }
            else
            {
                sort_list(list, input, 0, 0);
            }
        }
        else{
            printf("No such choose !\n");
        }
    }       
}