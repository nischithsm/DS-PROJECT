#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

// defining macros
#define FAILURE -1
#define SUCCESS 0
#define FNAME_SIZE 15
#define WORD_SIZE 15
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4

// defining macros for Colorss
#define NORMAL "\e[0m"
#define RED "\e[1;31m"
#define BLUE "\e[1;34m"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define CYAN "\e[1;36m"
#define MAGENTA "\e[1;35m"

// Structure for file list
typedef char data_t;

typedef struct file_node
{
	data_t file_name[FNAME_SIZE];
	struct file_node *link;

} Flist;

// Structure for link table
typedef struct linkTable_node
{
	int word_count;
	data_t file_name[FNAME_SIZE];
	struct linkTable_node *table_link;
} Ltable;

// structure to store word count
typedef struct word_node
{
	int file_count;
	data_t word[WORD_SIZE];
	Ltable *Tlink;
	struct word_node *link;

} Wlist;

/*check file empty or not */
int isFileEmpty(char *filename);

/*File validation */
void file_validation_n_file_list(Flist **f_head, char *argv[]);

/* create file linked list */
int to_create_list_of_files(Flist **f_head, char *name);

/* create database */
void create_database(Flist *f_head, Wlist *head[]);

/* read contents of a file */
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename);

/* create word_list */
int insert_at_last(Wlist **head, data_t *data);

/* update linktable */
int update_link_table(Wlist **head);

/* update word count */
int update_word_count(Wlist **head, char *filename);

/* print_word_count */
int print_word_count(Wlist *head);

/* display database */
void display_database(Wlist *head[]);

/* write database to the file */
void write_databasefile(Wlist *head, FILE *databasefile);

/* update databae */
void update_database(Flist **f_head, Wlist *head[]);

/* searching a word */
void search_word(Wlist *head, char *word);

/* save_databse */
void save_database(Wlist *head[]);

/*Text colors */
void Colors(char *color);

#endif
