#include "inverted_search.h"

extern char *fname;

/* Function to insert word into list  */
int insert_at_last(Wlist **head, data_t *data)
{
	//create node
	Wlist *new = malloc(sizeof(Wlist));

	if(new == NULL)
		return FAILURE;

	//update new node
	new->file_count = 1;
	strcpy(new->word, data);
	new->Tlink = NULL;
	new->link = NULL;

	//function call to update link table
	update_link_table(&new);

	//check Wlist is empty or not

	if(*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}

	//list not empty
	Wlist *temp = *head;

	while(temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = new;
	return SUCCESS;
}

/* Function to update link table */
int update_link_table(Wlist **head)
{
	//create node
	Ltable *new = malloc(sizeof(Ltable));

	if(new == NULL)
		return FAILURE;

	//update new node
	new->word_count = 1;
	strcpy(new->file_name, fname);
	new->table_link = NULL;

	(*head)->Tlink = new;
	return SUCCESS;	
}
