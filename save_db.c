#include "inverted_search.h"

//Function to save database
void save_database( Wlist *head[])
{
	char file_name[FNAME_SIZE];

	//Prompt user to read file name

	Colors(BLUE);
	printf("Enter the file name : ");
	Colors(NORMAL);
	scanf(" %s", file_name);

	//open the file in write mode
	FILE *fptr = fopen(file_name, "w");

	for(int i = 0; i < 27; i++)
	{
		if(head[i] != NULL)
		{
			//Writing availabe contents to the file pointer
			fprintf(fptr, "\e[1;34m#[%d]\n", i);

			write_databasefile(head[i], fptr);
		}
	}
	Colors(NORMAL);

	Colors(GREEN);
	printf("INFO: Database saved successfully\n");
	Colors(NORMAL);
}

//Function to write contents to the file pointer
void write_databasefile(Wlist *head, FILE *db_file)
{
	//Traverse through Wlist
	while(head)
	{
		int space = 0;
		//write word and file count
		fprintf(db_file, "\e[1;34mword is \e[1;31m%-15s \e[1;34m: filecount is %d file/s : ", head->word, head->file_count);

		Ltable *Thead = head->Tlink;

		//Traverse through Ltable
		while(Thead)
		{
			if(space == 1)
			{
				fprintf(db_file, "%-50s", " ");
			}

			//write file name and word count
			fprintf(db_file, "\e[1;34mfile is %-15s : word count is %-3d \e[0m\n", Thead->file_name, Thead->word_count);
		
			Thead = Thead->table_link;
			space = 1;
		}
		fprintf(db_file, "%s", "\n");
		head = head->link;
	}		
}
