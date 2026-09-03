/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

static int heap[100];
static int size = 0;

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
	if (size == 0) return 0; //nothing in the heap so far

	int root = heap[0]; //due to add heap, the root will always be the first element in the array
	heap[0] = heap[size - 1]; //remove the root with the last element in the array
	size--; //size - 1

	int i = 0; 
	while (1) { //infite loop
		int left = 2 * i + 1; //computes the child indices
		int right = 2 * i + 2;
		int largest = i; //assumes the current is the largest

		if (left < size && heap[left] > heap[largest]){
			largest = left; //Check: Left child exists, Left child is bigger If so, update largest
		}
			
		if (right < size && heap[right] > heap[largest]){
			largest = right; //same idea for right child
		}
			

		if (largest == i) {
			break; //no need to do anything since assumption is right
			}

		int temp = heap[i]; // Move bigger child up and push current value down
		heap[i] = heap[largest];
		heap[largest] = temp;
		i = largest; //continues from new position
	}

	return root; //returns the removed value
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	int i = size;
	heap[i] = thing2add; //puts the number into the heap array at the end
	size++;

	while (i > 0) { //goes until it reaches the root ie i = 0
		int parent = (i - 1) / 2; //formula that calculates the parent's index
		if (heap[parent] >= heap[i]) { //if the heap at parents index is larger that whatever is being added, its already a proper max heap so it can stop
			break;
			}

		int temp = heap[parent]; // swaps the 2 values if the parent is not larger than whatever was newly added
		heap[parent] = heap[i];
		heap[i] = temp;

		i = parent; //this causes the rest of the array to be fully sorted as well
	}
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
	return size;
}

/**
 * getHeapArray() returns the Heap.
 *
 */
int* getHeapArray()
{
    return heap;
}
