#include <stdio.h>
#include <string.h>
/**
 * @brief	Function finds locations to chars matching the token in given string, stores in an array of pointers
 */
void delim(char* str, char token);

/**
 * @brief	Function sorts words from given string into alphabetical order
 */
void sort(char* str, char* loc[], int loc_len);

void main()
{
	char str[40];
	char* ptr = str;

	fgets(ptr, 40, stdin);			// Read from the console

	delim(ptr, ' ');

	printf("\n%s\n", ptr);			// Print out string

	return;
}

void delim(char* str, char token)
{
	char* loc[40] = { NULL };		// Array of substrings
	int j = 0;						// Number of substrings
	int length = strlen(str);

	loc[j] = str;
	j++;

	for (int i = 1; i < length; i++)
	{								// Loop cuts up original string into substrings
		if (*(str + i) == token)	// And saves start of each substring into location array
		{
			loc[j] = str + i + 1;
			*(str + i) = '\0';
			j++;
		}
	}

	sort(str, loc, j);

	return;
}

void sort(char* str, char** loc, int loc_len)
{
	char buffer[40] = { "\n" };

	printf("String -1: %s\n", str);		// Implement the sort function of your choice
	for (int i = 0; i < loc_len; i++)	// Sort words from the user string into alphabetic order
	{									// Ex: "hello world foo bar" sorts->into "bar foo hello world"
		printf("String  %d:", i);		// For debug, remove later
		printf("%s\n", loc[i]);			// For debug, remove later
	}

	strcpy(str, buffer);

	return;
}