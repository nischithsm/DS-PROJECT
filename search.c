#include "inverted_search.h"

//Function to search a word in a database
void search_word(Wlist *head, char *word)
{
	//check list is empty or not
	if(head == NULL)
	{
		Colors(RED);
		printf("ERROR: List is empty, hence search is not possible\n");
		Colors(NORMAL);
		return;
	}

	//not empty, traverse through Wlist
	while(head)
	{
		//print word list if it is available
		if(!(strcmp(head->word, word)))
		{
			Colors(MAGENTA);
			printf("Word %s is present in %d file/s\n", word, head->file_count);
			Colors(NORMAL);

			Ltable *Thead = head->Tlink;

			//Traverse throgh Ltable
			while(Thead)
			{
				Colors(MAGENTA);
				printf("In file : %s : %d time/s\n", Thead->file_name, Thead->word_count);
				Colors(NORMAL);
				Thead = Thead->table_link;
			}
			return;
		}
		head = head->link;
	}
	//print error if search word not found
	Colors(RED);
	printf("ERROR: Search word %s not found\n", word);
	Colors(NORMAL);
}
