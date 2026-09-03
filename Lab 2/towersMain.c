#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n;
    int from;
    int dest;
    
	//3 inputs
    if (argc == 4) {
		n = atoi(argv[1]);
		from = atoi(argv[2]);
		dest = atoi(argv[3]);
		
		//2 different towers check
		if (atoi(argv[2]) == atoi(argv[3])){
		fprintf(stderr, "Tower IDs must be 1, 2, or 3 and different.\n");
		exit(1);
		}
	}   //only disk is inputted
		else if (argc == 2) {
        n = atoi(argv[1]);
		from = 1;
		dest = 2;
		
		//no inputs
    } else if (argc == 1) {
        n = 3;
		from = 1;
		dest = 2;
    }
    towers(n, from, dest);
    exit(0);
}

