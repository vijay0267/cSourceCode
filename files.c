

/*
1. Program to read data from a exesting text file.

int main(void)
{
	FILE *fptr;
	char ch;

	fptr = fopen("NOTES/strings.txt", "r");

	if(fptr == NULL)
		printf("Error....");
	else
	{
		while((ch = fgetc(fptr)) != EOF)
			printf("%c", ch);

		fclose(fptr);
	}

	return 0;
}

2. program to write to a text file.

int main(void)
{
	FILE *fptr;
	char ch;

	fptr = fopen("NOTES/files.txt", "w");
	if(fptr == NULL)
	{
		printf("Error....");
	}
	else
	{
		//fprintf(fptr, "This is a text file\n");
		fputs("Text File", fptr);
		fclose(fptr);
	}

	return 0;
}

3. Program to append to a file.

int main(void)
{
	FILE *fptr;
	char ch;

	fptr = fopen("NOTES/files.txt", "a");
	if(fptr == NULL)
	{
		printf("Error....");
	}
	else
	{
		//fprintf(fptr, "This is a text file\n");
		fputs("\nDelete this file", fptr);
		fclose(fptr);
	}

	return 0;
}

4. The following example shows the usage of fseek() function.

int main () {
   FILE *fp;

   fp = fopen("NOTES/files.txt","w+");
   fputs("This is tutorialspoint.com", fp);

   fseek( fp, 7, SEEK_SET );
   fputs(" C Programming Language", fp);
   fclose(fp);

   return(0);
}

output:- This is C Programming Language
