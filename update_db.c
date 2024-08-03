#include "inverted_search.h"

// Function to update database
void update_database(Flist **f_head, Wlist *head[])
{
	// Read file name from user
	char file_name[FNAME_SIZE];

	Colors(BLUE);
	printf("Enter the file name to update : ");
	Colors(NORMAL);

	scanf("%s", file_name);

	// validate file_name
	int empty = isFileEmpty(file_name);

	if (empty == FILE_NOTAVAILABLE)
	{
		Colors(RED);
		printf("ERROR: File %s is not available \n", file_name);
		printf("Hence %s not added into file linked listi\n", file_name);
		Colors(NORMAL);
	}
	else if (empty == FILE_EMPTY)
	{
		Colors(RED);
		printf("ERROR: File %s doesn't have contents\n", file_name);
		printf("Hence %s not added into file linked list\n", file_name);
		Colors(NORMAL);
	}
	else
	{
		// Function call to add file name into list
		int ret_val = to_create_list_of_files(f_head, file_name);

		if (ret_val == SUCCESS)
		{
			Colors(GREEN);
			printf("Successfull : inserting the file name : %s into the file linked list\n", file_name);

			// Declare local pointer for traversal
			Flist *temp = *f_head;

			// Check file name added or not in linked list
			while (temp)
			{
				if (!strcmp((temp)->file_name, file_name))
				{
					// Create database for new file if it is availabe in linked list
					create_database(temp, head);
				}
				temp = temp->link;
			}

			printf("Successfull : Database created for the file name : %s\n", file_name);
			Colors(NORMAL);
		}
		else if (ret_val == REPEATATION)
		{
			Colors(RED);
			printf("This file name : %s is repeated. Hence we are not adding that file into file linked list\n", file_name);
			Colors(NORMAL);
		}
		else
		{
			Colors(RED);
			printf("ERROR: Failed to insert the file name %s into the linked list\n", file_name);
			Colors(NORMAL);
		}
	}
	return;
}
