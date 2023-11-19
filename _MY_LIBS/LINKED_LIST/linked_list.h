/*
 * linked_list.h
 *
 *  Created on: Nov 18, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MY_LIBS_LINKED_LIST_LINKED_LIST_H_
#define MY_LIBS_LINKED_LIST_LINKED_LIST_H_

#include "../STD_TYPES.h"

struct node{
    struct node *node_link;
    void *node_data;
};

void s_list_insert_node_at_beg(struct node **list, void* data_ptr);
void s_list_insert_node_at_end(struct node **list, void* data_ptr);
void s_list_insert_node_after_pos(struct node *list, u32 node_pos, void* data_ptr);
void s_list_delete_node_at_beg(struct node **list);
void s_list_delete_node_at_pos(struct node *list, u32 node_pos);
void s_list_display_all_nodes(struct node *list);
u32  s_list_get_length(struct node *list);


#endif /* MY_LIBS_LINKED_LIST_LINKED_LIST_H_ */
