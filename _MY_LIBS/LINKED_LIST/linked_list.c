/*
 * linked_list.c
 *
 *  Created on: Nov 18, 2023
 *      Author: Mahmoud El Arabi
 */

#include "linked_list.h"
#include "stdlib.h"
u32  s_list_get_length(struct node *list){
    u32 count =0;
    struct node *temp = list;
    while (temp != NULL)
    {
        count ++;
        temp = temp->node_link;
    }
    return count;
}

void s_list_insert_node_at_beg(struct node **list, void* data_ptr){
    struct node *temp_node = (struct node *) malloc (sizeof(struct node));
    if(NULL == temp_node){    }
    else{
        temp_node->node_data = data_ptr;
        temp_node->node_link = *list;
        *list = temp_node;
    }
}

void s_list_insert_node_at_end(struct node **list, void* data_ptr){
    struct node *last_node = *list;
    struct node *temp_node = (struct node *) malloc (sizeof(struct node));
    if(NULL == temp_node){}
    else{
        temp_node->node_data = data_ptr;
        temp_node->node_link = NULL;
        if(*list == NULL){
            *list = temp_node;
        }
        else{
            while (NULL != (last_node->node_link)){
                last_node = last_node->node_link;
            }
            last_node->node_link = temp_node;
        }
    }
}

void s_list_insert_node_after_pos(struct node *list, u32 node_pos, void* data_ptr){
    u32 count = s_list_get_length(list);
    struct node *node_befor= list;
    struct node *node_after= list;
    struct node *tempnode= (struct node *)malloc (sizeof(struct node));
    if(node_pos > count){}
    else if(node_pos == count){
        s_list_insert_node_at_end(&list, &data_ptr);
    }
    else{
        if(tempnode == NULL){}
        else{
            tempnode->node_data = data_ptr;
            u32 node_cout = 1;
            while (node_cout <= node_pos) {
                node_cout ++;
                node_befor = node_befor->node_link;
            }
            node_after = node_befor->node_link;
            tempnode->node_link = node_after;
            node_befor->node_link = tempnode;
        }
    }
}

void s_list_delete_node_at_beg(struct node **list){
    struct node *tempnode = *list;
    *list = tempnode->node_link;
    tempnode->node_link = NULL;
    free(tempnode);
}

void s_list_delete_node_at_pos(struct node *list, u32 node_pos){
    u32 count = s_list_get_length(list);
    struct node *node_befor= list;
    struct node *node_after= list;
    struct node *tempnode= (struct node *)malloc (sizeof(struct node));
    if(node_pos > count){}
    else{
            u32 node_cout = 1;
            while (node_cout < node_pos-1) {
                node_cout ++;
                node_befor = node_befor->node_link;
            }
            tempnode = node_befor->node_link;
            node_after = tempnode->node_link;
            node_befor->node_link = node_after;
            tempnode->node_link = NULL;
            free(tempnode);
        }
}

//void s_list_display_all_nodes(struct node *list){
//    struct node *temp_node = list;
//    printf("Node values:  ");
//    if(NULL == temp_node){
//        printf("List is empty\n");
//    }
//    else{
//        while (temp_node != NULL){
//            printf("%i -> ", *(u32*)(temp_node->node_data));
//            temp_node = temp_node->node_link;
//        }
//        printf("NULL\n");
//    }
//}


