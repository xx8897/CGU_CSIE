/*******************************************************************************
 *
 * to define the data structure of a linked list
 *
 ******************************************************************************/

#ifndef LINKED_LIST_H

#define LINKED_LIST_H

typedef struct ListNode_s {
	int key;
	struct ListNode_s *suc;
} ListNode;

typedef struct LinkedList_s {
	ListNode *head;
	ListNode *tail;
} LinkedList;

//methods of the linked_list:
LinkedList *new_LinkedList ();
void delete_LinkedList (/* this */);
void AppendKey_LinkedList (/* this, key */);
void DeleteKey_LinkedList (/* this, key */);
void DumpKey_LinkedList (/* this */);

#endif



















