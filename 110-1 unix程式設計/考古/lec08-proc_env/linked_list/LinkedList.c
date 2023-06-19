/*******************************************************************************
 *
 * methods of LinkedList
 *
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

LinkedList *
new_LinkedList ()
{
	LinkedList *this;

	this = (LinkedList*) malloc (sizeof(LinkedList));

	this->head = NULL;
	this->tail = NULL;

	return this;
}//new_LinkedList ()

void
delete_LinkedList (this)
	LinkedList *this;
{
	ListNode *p, *q;

	p = this->head;
	while (p != NULL) {
		q = p->suc;
		free (p);
		p = q;
	}

	free (this);
}//delete_LinkedList ()

void
AppendKey_LinkedList (this, key)
	LinkedList *this;
	int key;
{
	ListNode *new_node;

	new_node = (ListNode*) malloc (sizeof(ListNode));
	new_node->key = key;
	new_node->suc = NULL;

	if (this->head==NULL) {
		this->head = new_node;
		this->tail = new_node;
	}
	else {
		this->tail->suc = new_node;
		this->tail = new_node;
	}
}//InsertKey_LinkedList ()

void
DeleteKey_LinkedList (this, key)
	LinkedList *this;
	int key;
{
	ListNode *p, *q;

	p = this->head;
	q = NULL;
	while ( (p != NULL) && (p->key != key) ) {
		q = p;
		p = p->suc;
	}

	if (p==NULL) return;

	if (q==NULL) {	//match the first
		this->head = p->suc;
	}
	else {
		q->suc = p->suc;
	}

	if (p==this->tail) this->tail = q;

	free (p);
}//DeleteKey_LinkedList ()

void
DumpKey_LinkedList (this)
	LinkedList *this;
{
	ListNode *p;

	p = this->head;
	while (p!=NULL) {
		printf ("key = %d\n", p->key);
		p = p->suc;
	}
}//DumpKey_LinkedList ()

















