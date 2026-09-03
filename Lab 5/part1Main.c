#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern char *  pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char * argv[])
{
	int ch;

	while ((ch = getchar()) != EOF) { // reads each input character by character 
		if (ch != '<') continue; // Skips the whole while loop if not a <

		char tag[100]; //Stores name of the node
		int i = 0;
		int isEnd = 0; 

		ch = getchar(); //reads the next character after <

		if (ch == '/') { //if its a / then its an end tag
			isEnd = 1;
			ch = getchar(); //moves to the start of the tag name
		}

		while (isalpha(ch)) { //only takes in all alphabetical characters
			tag[i++] = ch; //stores it in the array
			ch = getchar(); // actually reads the char
		}
		tag[i] = '\0'; //marks the end of the string

		if (isEnd) { //non 0 to be true
			char *topTag = pop(); //pops the most recent opening tag from the stack
			if (topTag == NULL || strcmp(topTag, tag) != 0) { //if its nothing or if tags dont match then invalid
			printf("Invalid XML\n");
			exit(0);
			}
		} else {
		char *copy = malloc(strlen(tag) + 1); // makes a copy with only the needed info from tag +1 for the /0
		strcpy(copy, tag); //copies the info into the copy variable
		push(copy); //pushes into the stack
		}
	}

	if (isEmpty()) {
		printf("Valid XML\n");
	} else {
		printf("Invalid XML\n");
	}
  exit(0);
}
