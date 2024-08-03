#include "inverted_search.h"

// Function definition to validate user entered files
void file_validation_n_file_list(Flist **f_head, char *argv[])
{
	int i = 1, empty;

	// Check user entered files are valid or not
	while (argv[i] != NULL)
	{
		// Function call to check file is empty or not
		empty = isFileEmpty(argv[i]);

		if (empty == FILE_NOTAVAILABLE)
		{
			Colors(RED);
			printf("ERROR: File %s is not available \n", argv[i]);
			printf("Hence %s not added into file linked list\n", argv[i]);
			Colors(NORMAL);
		}
		else if (empty == FILE_EMPTY)
		{
			Colors(RED);
			printf("\033[1;31mERROR: File %s doesn't have contents\n", argv[i]);
			printf("Hence %s not added into file linked list\033[0m\n", argv[i]);
			Colors(NORMAL);
		}
		else
		{
			// Function call to create file list
			int ret_val = to_create_list_of_files(f_head, argv[i]);

			if (ret_val == SUCCESS)
			{
				Colors(GREEN);
				printf("Successfull : inserting the file name : %s into the file linked list\n", argv[i]);
				Colors(NORMAL);
			}
			else if (ret_val == REPEATATION)
			{
				Colors(RED);
				printf("This file name : %s is repeated. Hence we are not adding that file into file linked list\n", argv[i]);
				Colors(NORMAL);
			}
			else
			{
				Colors(NORMAL);
				printf("ERROR: Failed to insert the file name %s into the linked list\n", argv[i]);
				Colors(NORMAL);
			}
		}
		i++;
	}
}

// func is used to check files availability and for contents
int isFileEmpty(char *filename)
{
	// open file in read mode
	FILE *fptr = fopen(filename, "r");

	// do error check
	if (fptr == NULL)
	{
		if (errno == ENOENT)
		{
			return FILE_NOTAVAILABLE;
		}
	}

	// Move file pointer to the end of file if the file is available.
	fseek(fptr, 0, SEEK_END);

	// Check file is empty or not
	if (ftell(fptr) == 0)
	{
		return FILE_EMPTY;
	}
	return SUCCESS;
}

/* Function to create file linked list */
// Same as insert_at_last(instead of having the data here we have string i.e(file name))
int to_create_list_of_files(Flist **f_head, char *name)
{
	// Local pointer for traversal
	Flist *temp = *f_head;
	Flist *prev = temp;

	// check duplicancy of file names
	while (temp != NULL)
	{
		if (!strcmp(temp->file_name, name))
			return REPEATATION;

		prev = temp;
		temp = temp->link;
	}

	// Create new node
	Flist *new = malloc(sizeof(Flist));

	// do error check
	if (new == NULL)
		return FAILURE;

	// update data
	strcpy(new->file_name, name);
	new->link = NULL;

	// check head pointer is empty or not
	if (*f_head == NULL)
		*f_head = new;

	else
		// Establish link between last node and new node
		prev->link = new;

	return SUCCESS;
}
