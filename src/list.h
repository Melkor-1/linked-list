#ifndef LIST_H
#define LISH_H 

/*  The header is meant for users of the code. So in there I document the interface: 
*   how to use it, preconditions and postconditions, etcetera.
*
*   The .c file is for maintainers. In there, I document the implementation:
*   how things work internally, and why they work that way.
*/

struct ll_node;

/** 
*	@brief   ll_append_node() shall append a new node just before the given list 
*			 head - to the end of the list, in other words. ll_append_node() can 
*			 thus be used to build first-in first-out queues.
*	@param	 head - A double pointer to the head of the node.
*	@param	 data - The value to initialize the item associated with
*				   the new node.
*	@return  Upon successful return, ll_append_node() returns the value of head
*			 that was passed in. ELse, it returns a NULL pointer to indicate 
*			 allocation failure.
*/
void *ll_append_node (struct ll_node **head, intmax_t data);

/** 
*	@brief	 ll_build_head() shall build a linked list by inserting nodes at the
*			 head of the list.
*	@param	 size - The initial number of nodes in the list.
*	@param	 data[size] - An optional array to initialize the values of the items 
*						  of the nodes with. If data is NULL pointer, the items 
*						  of all nodes are initialized to 0.
*	@return	 Upon successful return, ll_build_head() shall return a pointer to the 
*			 head of the list. Otherwise, it shall return a NULL pointer to indicate 
*			 a memory allocation failure. A NULL pointer shall also be returned if
*			 size evaluates to 0.
*/
struct ll_node *ll_build_head (size_t size,
                                      const intmax_t data[static size]);

/** 
*	@brief	 ll_build_tail() shall build a linked list by inserting the first 
*			 node at the head, and henceforth at the tail.
*	@param	 size - The initial number of nodes in the list.
*	@param	 data[size] - An optional array to initialize the values of the 
*						  items of the nodes with. If data is a NULL pointer,
*						  the items of the nodes are initialized to 0.
*	@return	 Upon successful return, ll_build_tail() shall return a pointer 
*			 to the head of the list. Otherwise, it shall return a NULL pointer
*			 to indicate a memory allocation failure. A NULL pointer would also 
*			 be returned if size evaluates to 0..
*/
struct ll_node *ll_build_tail (size_t size,
                                      const intmax_t data[size]);


/**
*	@brief	 ll_count_occurrence() shall count the number of occurrences of 
*			 data in the list.
*	@param	 head - A double pointer to the head of the list.
*	@param	 data - The value to search for.
*	@return	 Upon successful return, ll_count_occurences() shall return the 
*			 count of the number of occurrences of data seen in the list.
*/
size_t ll_count_occurrence (struct ll_node **head, intmax_t data);

/**
*	@brief	 ll_delete() shall free all the items in the list. Allows head to be NULL
*			 to mimic free (NULL), in which case no operation is performed.
*	@param	 head - A pointer to the head of the list.
*	@return  This function returns nothing.
*/
void ll_delete (struct ll_node **head);

/** 
*	@brief	ll_find_node() shall search the list for the node at index index.
*	@param	head - A pointer to the head of the list.
*	@index	index - The index of the node to return.
*	@return Upon successful return, ll_find_node() shall return a pointer 
*			the node. Otherwise, it returns a NULL pointer to indicate failure.
*			A NULL pointer would also be returned for an empty list, i.e. 
*			a NULL head pointer.
*/
struct ll_node *ll_find_node (struct ll_node **head, size_t index);

/** 
*	@brief	 ll_get_data() shall obtain the value of the item associated with
*			 the node pointed to by head. ll_find_node() uses the C numbering 
*			 convention that the first node is index 0, the second is index 1
*			 ... and so on. It is akin to an array[i] operation.
*	@param	 head - A pointer to a node.
*	@return	 Upon successful return, ll_get_data() returns the value of the
*			 node's item..
*	@warning The caller is responsible for assuring a NULL pointer is not passed
*			 in. Failure to comply could result in unexpected program termination
*			 and potential loss of data.
*/
intmax_t ll_get_data (struct ll_node *const *head);

/**
*	@brief   ll_is_singular() tests whether a list has only one item.
*	@param	 head - A double pointer to the head of the list.
*	@return  ll_is_singular() returns true if the list is singular.
*			 Otherwise, it returns false.
*/
bool ll_is_singular (struct ll_node **head);

/** 
*	@brief	 ll_is_empty() tests whether a list is empty.
*	@param	 head - A double pointer to the head of the list.
*	@return	 ll_is_empty() returns true if the list is empty. Otherwise,
*			 it returns false.
*/
bool ll_is_empty (struct ll_node **head);

/** 
*	@brief	 ll_is_containing() shall search each node of the list pointed to by head
*			 for data.
*	@param	 head - A double pointer to the head of the list.
*	@param	 data - The value to search for.
*	@return	 Upon successful return, ll_is_containing() returns true. Otherwise it returns 
*			 false to indicate failure.
*/
bool ll_is_containing (struct ll_node **head, intmax_t data);

/** 
*	@brief	 ll_insert_pos() shall insert a new node at position index 
*			 of	the list.
*	@param	 head - A double pointer to the head of the list.
*	@param	 index - The index of the node to insert at.
*	@param	 data - The value to initialize the item associated with
*				   the new node.
*	@return  Upon successful return, ll_insert_pos() shall return true. 
*			 Otherwise, it returns false to indicate a memory allocation failure.
*	@warning The caller is responsible for ensuring that the head pointer is 
*			 not NULL. Failing to comply could result in unexpected program
*			 termination and potential loss of data.
*/
bool ll_insert_pos (struct ll_node **head, size_t index,
                           intmax_t data);

/**	
*	@brief	 ll_push_node() shall push a new node immediately after the list
*			 head - normally at the beginning of the list. It can thus be used
*			 to build stacks.
*	@param	 head - A double pointer to the head of the list.
*	@param	 data - The value of the item to initialize the node with.
*	@return	 Upon successful return, ll_push node returns true. Otherwise it
*			 returns false to indicate an allocation failure.
*	@warning The caller is responsible for ensuring that the head pointer is 
*			 not NULL. Failing to comply could result in unexpected program
*			 termination and potential loss of data.
*/
bool ll_push_node (struct ll_node **head, intmax_t data);

/**
*	@brief	 ll_print() prints the value of all the items associated with a node.
*	@param	 head - A double pointer to the head of the linked list. Allows head
*				    to be NULL, in which case no operation is performed.
*	@return	 Upon successful return, ll_print return the number of bytes 
*			 written.
*/
int ll_print (struct ll_node **head);

/** 
*	@brief	 ll_pop_node() pops the first node pointed to by head.
*	@param	 head - A double pointer to the head of the list.
*	@return	 Upon successful return, ll_pop_node() shall free the 
*			 first node and return the value of the item associated
*			 with the node pointed to by head. 
*	@warning The caller is responsible for ensuring that the head pointer and
*			 the pointer pointed to by head is not NULL. Failing to comply 
*			 could result in unexpected program termination and potential loss
*			 of data.
*/
intmax_t ll_pop_node (struct ll_node **head);

/** 
*	@brief	 ll_pop_end() pops the node at the end of the list.
*	@param	 head - A double pointer to the head of the list.
*	@return  Upon successful return, ll_pop_end() frees the node and
*			 returns the value of the item associated with the node.
*	@warning The caller is responsible for ensuring that both head and 
*			 the pointer pointed to by head is not NULL. Failure to comply 
*			 could result in unexpected program termination and potential 
*			 loss of data.
*/
intmax_t ll_pop_end (struct ll_node **head);

/** 
*	@brief   ll_pop_pos() pops the node at index index of the list.	
*	@param	 head - A double pointer to the head of the node.
*	@param	 index - The index of the node to pop.
*	@return	 Upon successful return, ll_pop_pos() frees the node at 
*			 index index and returns the value associated with that node.
*			 Otherwise, it returns INTMAX_MIN to indicate failure.
*/
intmax_t ll_pop_pos (struct ll_node **head, size_t index);

/**
*	@brief	 ll_remove() shall remove all nodes that matches data.
*	@param	 head - A double pointer to the head of list.
*	@param	 data - The value to remove.
*	@return  ll_remove() returns nothing.
*	@warning The caller is responsible for ensuring that both head and 
*			 the pointer pointed to by head is not NULL. Failure to comply 
*			 could result in unexpected program termination and potential 
*			 loss of data.
*/
void ll_remove (struct ll_node **head, intmax_t data);

/**
*	@brief	 ll_remove_dup() takes a sorted list in increasing order and removes 
*			 any consecutive duplicate nodes from the list.
*	@param	 head - A double pointer to the head of the list.
*	@return	 ll_remove_dup() returns nothing.
*	@warning The caller is responsible for ensuring that both head and 
*			 the pointer pointed to by head is not NULL. Failure to comply 
*			 could result in unexpected program termination and potential 
*			 loss of data.
*/
void ll_remove_dup (struct ll_node **head);

/**
*	@brief	 ll_remove_if() shall remove all nodes for which predicate returns true.
*	@param 	 head - A double pointer to the head of the list.
*	@param	 predicate - A pointer to a function taking an intmax_t and returning
*			 a boolean value. 
*	@return  ll_remove_if() returns nothing.
*	@warning The caller is responsible for ensuring that both head and 
*			 the pointer pointed to by head is not NULL. Failure to comply 
*			 could result in unexpected program termination and potential 
*			 loss of data.
*/
void ll_remove_if (struct ll_node **head,
                          bool (*predicate) (intmax_t data));

/** 
*	@brief   ll_replace_node() shall update the value of the item of the first
*			 node that matches the value of old_data. No operation is performed if
*			 no match is found.
*	@param	 head - A double pointer to the head of the list.
*	@param	 old_data - The value of the item associated with a node to update.
*	@param	 new_data - The new value to initialize the item with.
*	@return  ll_replace_node() returns nothing.
*	@warning The caller is responsible for ensuring that the head pointer is 
*			 not NULL. Failing to comply could result in unexpected program
*			 termination and potential loss of data.
*/
void ll_replace_node (struct ll_node **head, intmax_t old_data,
                             intmax_t new_data);
/**
*	@brief	 ll_reverse() shall reverse the list pointed to by head. 
*	@param	 head - A double pointer to the head of the list.
*	@return	 ll_reverse() returns nothing.
*	@warning The caller is responsible for ensuring that head, and the 
*			 pointer referenced by head is not NULL. Failing to comply
*			 could result in unexpected program termination and potential
*			 loss of data.
*/
void ll_reverse (struct ll_node **head);

/**
*	@brief	 ll_size() shall count the number of items in the list.
*	@param	 head - A double pointer to the head of the list.
*	@return  Upon successful return, ll_size() returns number
*			 of items present.
*/
intmax_t ll_size (struct ll_node **head);

/**
*	@brief	 ll_splice() shall join two lists by inserting list immediately 
*			 after head.
*	@param	 list - A double pointer to the head of the new list to add.
*	@param	 head - A double pointer to the head of the list to add it in.
*	@return  ll_splice() returns nothing.
*	@warning The caller is responsible for ensuring that the head and list
*			 pointers, and the pointer referenced by head is not NULL. If the
*			 pointer referenced by list is NULL, no operation is performed.
*			 Failing to comply could result in unexpected program termination
*			 and potential loss of data.
*/
void ll_splice (struct ll_node **list, struct ll_node **head);

/**
*	@brief	 ll_set_data() shall update the value of the item associated with 
*			 the node pointed to by head. 
*	@param	 head - A pointer to a node.
*	@param	 data - The new value.
*	@return  ll_set_data() returns nothing.
*	@warning The caller is responsible for assuring a NULL pointer is not passed
*			 in. Failure to comply could result in enexpected program termination
*			 and potential loss of data.
*/
void ll_set_data (struct ll_node **head, intmax_t data);

#endif
