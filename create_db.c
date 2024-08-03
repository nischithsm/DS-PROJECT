#include "inverted_search.h"

// Declare char pointer to store file name
char *fname;

// Function definition for create database
void create_database(Flist *f_head, Wlist *head[])
{
	// traverse through file linked list
	while (f_head)
	{
		// Function call to read data from file
		read_datafile(f_head, head, f_head->file_name);
		f_head = f_head->link;
	}
}

// Function definition to read data from file
Wlist *read_datafile(Flist *f_head, Wlist *head[], char *filename)
{
	// declare local variables
	fname = filename;
	int flag = 1;

	// open file in read mode
	FILE *fptr = fopen(filename, "r");

	// declare an array to store words
	char word[WORD_SIZE];

	while (fscanf(fptr, "%s", word) != EOF)
	{
		// index
		int index = tolower(word[0]) % 97;

		// other than alphabets
		if (!(index >= 0 && index <= 25))
		{
			index = 26;
		}
		// Check words repeated or not
		if (head[index] != NULL)
		{
			Wlist *temp = head[index];

			// Compare new word with each word of a list
			while (temp)
			{
				if (!(strcmp(temp->word, word)))
				{ 
					update_word_count(&temp, filename);
					flag = 0;
					break;
				}
				temp = temp->link;
			}
		}
		if (flag == 1)
		{
			// func call only when words are not repeated
			insert_at_last(&head[index], word);
		}
	}
	Colors(GREEN);
	printf("Successfull creation of database for the file : %s\n", filename);
	Colors(NORMAL);
}

// Function definition to update word count if words are repeated in Wlist
int update_word_count(Wlist **head, char *filename)
{
	Ltable *temp = (*head)->Tlink;

	while (temp != NULL)
	{
		// Compare file name with each file name
		if (strcmp(temp->file_name, filename) == 0)
		{
			++(temp->word_count);
			return SUCCESS;
		}
		temp = temp->table_link;
	}

	// Increment file count(if file names are different) along with it create a new Ltable node
	++((*head)->file_count);

	// create Ltable node
	Ltable *new = malloc(sizeof(Ltable));

	if (new == NULL)
		return FAILURE;

	// update new node
	new->word_count = 1;
	strcpy(new->file_name, filename);
	new->table_link = NULL;

	// perform insert at last operation
	Ltable *traverse = (*head)->Tlink;

	while (traverse->table_link != NULL)
	{
		traverse = traverse->table_link;
	}
	// Establish link between new node and last node
	traverse->table_link = new;

	return SUCCESS;
}
