#include <stdio.h>
#include <stdlib.h>

extern int pop();
extern void push(int);
extern void addHeap(int);
extern int heapDelete();
extern int heapSize();
extern int isEmpty();
extern int* getHeapArray();

/* recursive XML printer */
void printXML(int index, int size, int heap[]) {
    if (index >= size) return; //if index is outside heap, stop recursion

    printf("<node id=\"%d\">", heap[index]); //print opening XML tag with current node's value

    printXML(2 * index + 1, size, heap);  //recursively print left child (index formula for heap)
    printXML(2 * index + 2, size, heap); //same for right child

    printf("</node>"); //prints the end tag after children are processed
}

int main(int argc, char * argv[]) {
    int value; //variable to store each input integer

    //reads input and adds it to the stack
    while (scanf("%d", &value) != EOF) {
        fprintf(stderr, "READING INPUT: %d\n", value);
        addHeap(value);
    }
    
	
    if (heapSize() > 0) {  //only prints if heap is not empty
        printXML(0, heapSize(), getHeapArray()); //access the functions from intHeap.c
        printf("\n");
    }

     // DESCENDING
    while (heapSize() > 0) { //keep removing elements until heap is empty
		
        int x = heapDelete(); //remove largest element (root of max-heap)
        printf("%d\n", x); //print values in descending order
        push(x);//store values in stack for later reversal (ascending)
    }

    // ASCENDING 
    while (!isEmpty()) { //pop until stack is empty
		
        printf("%d\n", pop());  //popping reverses order, prints ascending
    }
    return 0;
}
