/*******************************************************************************
 *
 * to demo the ust of the linked list
 *
 ******************************************************************************/

#include <stdio.h>

#include "linked_list.h"

main ()
{
	LinkedList *list;

	list = new_LinkedList ();

	AppendKey_LinkedList (list, 10);
	AppendKey_LinkedList (list, 8);
	AppendKey_LinkedList (list, 5);
	AppendKey_LinkedList (list, 15);
	AppendKey_LinkedList (list, 7);
	AppendKey_LinkedList (list, 12);

	printf ("======== 1st dump ==========\n");
	DumpKey_LinkedList (list);

	DeleteKey_LinkedList (list, 5);
	DeleteKey_LinkedList (list, 7);

	printf ("======== 2nd dump ==========\n");
	DumpKey_LinkedList (list);

	return 0;
}//main ()


















