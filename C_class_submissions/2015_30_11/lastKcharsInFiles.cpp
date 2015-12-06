//program to printf the last n characters in a file.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void last_k_chars(FILE *fp, int n)
{
	FILE*fp1 = fopen("file.txt", "r");
	int len = 0,j,ch;
	char *content;
	
	content = (char *)malloc(sizeof(char)*10000);
	while ((ch = fgetc(fp)) != EOF)
	{
		content[len] = (char)ch;
		len++;
	}
	
	for (j = len - n; j < len; j++)
	{
		printf("%c", content[j]);
	}

	
}

void main()
{
	FILE*f= fopen("file.txt", "w+");
	fputs("this is a programt to find the last k characters in a given file",f);
	last_k_chars(f, 5);
	_getch();
}
