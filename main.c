#include "inverted_search.h"

int main(int argc, char *argv[])
{
	system("clear");

	// Declare local variable
	int option;
	char choice;

	// Declare headpointer for word list
	Wlist *head[27] = {NULL};

	// validate CLA
	if (argc <= 1)
	{
		Colors(RED);
		printf("ERROR: Enter the valid number of arguments\n");
		printf("%s file1.txt file2.txt.......\n", argv[0]);
		Colors(NORMAL);
		return 0;
	}

	// create file linked list , declare head pointer
	Flist *f_head = NULL;

	// validate the files
	file_validation_n_file_list(&f_head, argv);

	if (f_head == NULL)
	{
		Colors(RED);
		printf("NO files are available in the file list\n");
		printf("Hence process got terminated\n");
		Colors(NORMAL);
		return 1;
	}

	printf("\e[1;36m------------------------------------------------------------------------------------------\e[0m\n\n");
	printf("\e[1;31m                                INVERTED SEARCH PROJECT\n\n");
	printf("\e[1;36m------------------------------------------------------------------------------------------\e[0m\n\n");

	char word[WORD_SIZE];

	// Prompt the user for choice
	do
	{
		printf("Select your choice among following options:\n1. Create DATABASE\n2. Display DATABASE\n3. Update DATABASE\n4. Search DATABASE\n5. Save DATABASE\nEnter your choice : ");

		scanf("%d", &option);

		switch (option)
		{
		case 1:
			// Create database
			create_database(f_head, head);
			break;
		case 2:
			// Display database
			display_database(head);
			break;
		case 3:
			// Updddate database
			update_database(&f_head, head);
			break;
		case 4:
			// Search word
			// char word[WORD_SIZE];

			Colors(BLUE);
			printf("Enter the word to search : ");
			Colors(NORMAL);
			scanf(" %s", word);

			int index = tolower(word[0]) % 97;
			if (!(index >= 0 && index <= 25))
				index = 26;

			search_word(head[index], word);
			break;
		case 5:
			// Save database
			save_database(head);
			break;
		default:
			Colors(RED);
			printf("Enter valid input!\n");
			Colors(NORMAL);
			break;
		}

		// prompt user to continue or not
		Colors(YELLOW);
		printf("Do you want to continue?\n");
		printf("Enter y/Y to continue or n/N to discontinue : ");
		Colors(NORMAL);

		scanf(" %c", &choice);
	} while (choice == 'y' || choice == 'Y');
}

// Function definition for text colors
void Colors(char *color)
{
	{
		printf("%s", color);
	}
}
