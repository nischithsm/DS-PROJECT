#include "inverted_search.h"

//Function to display the database
void display_database(Wlist *head[])
{
	Colors(CYAN);
	printf("-----------------------------------------------------------------------------\n");
	Colors(NORMAL);

	//Print header of the file
	Colors(BLUE);
	printf("%-10s %-15s %-15s %-20s %s\n", "[index]", "[word]", "[File_count]", "[File_name]", "[word_count]");
	Colors(NORMAL);

	Colors(CYAN);
	printf("-----------------------------------------------------------------------------\n");
	Colors(NORMAL);
	
	//print only available index
	for(int i = 0; i < 27; i++)
	{
		if(head[i] != NULL)
		{
			//func call to print list
			print_word_count(head[i]);
		}
	}
}

//Function to print file list and word count
int print_word_count(Wlist *head)
{
	//traverse through Wlist
	while(head != NULL)
	{
		int space = 0;
		int index = tolower(head->word[0]) % 97;

		if(!(index >= 0 && index <= 25))
		{
			index = 26;
		}

		Colors(RED);
		printf("  %-8d %-15s %-3dfile/s %-6s", index, head->word, head->file_count, " ");
		
		Ltable *Thead = head->Tlink;

		//traverse through Ltable
		while(Thead)
		{
			if(space == 1)
				printf("%-43s", " ");

			printf("File: %s      %d\n", Thead->file_name, Thead->word_count);
			
			Thead = Thead->table_link;
			space = 1;
		}
		Colors(NORMAL);
		
		Colors(CYAN);
		printf("-----------------------------------------------------------------------------\n");
		Colors(NORMAL);
		
		head = head->link;
	}
}
