#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

typedef struct State {
    char name;
    struct State *next0; //pointer that points to a state and not containing one since it would be infinite size
    struct State *next1; //pointer that points to a state
    bool deleted;
    bool garbage;
} State;

State states[N]; // an array with an element containing all the components of the struct State
State *current; // pointer that points to a certain state

/* ---------- Queue ---------- */ //operations for queues

State* queue[20]; //Each element points to a State struct object
int front = 0;
int rear = 0;

void resetQueue() {
    front = 0;
    rear = 0;
}

void enqueue(State *s) {
    queue[rear++] = s; //starts at 0 first
}

State* dequeue() {
    return queue[front++]; //starts at 0 first
}

bool empty() {
    return front == rear;
}

/* ---------- Find State ---------- */

State* findState(char name) { //searches for a name in the states array
    int i;
    for(i = 0; i < N; i++) {
        if(states[i].name == name)
            return &states[i];
    }
    return NULL;
}

/* ---------- Reachability ---------- */

void markReachable() {

    int i;

    for(i = 0; i < N; i++){
        states[i].garbage = true; //first assumes every state is not reached
	}
    resetQueue(); //makes sure it is at the start

    enqueue(current); //puts the current state info into queue
    current->garbage = false; //changes that actual current states garbage status to false (not pointers)

    while(!empty()) { //calls the function every time it is being checked

        State *s = dequeue(); //temporary variable s that points to whatever is being removed from the queue

        if(!s->next0->deleted && s->next0->garbage) { //We only want to explore a state if it still exists and we haven't visited it before
            s->next0->garbage = false; //marks it reachable
            enqueue(s->next0); //puts that next state into queue that was checked so it can be checked in the next loop
        }

        if(!s->next1->deleted && s->next1->garbage) { //same for the input1 which means this function is like a tree
            s->next1->garbage = false;
            enqueue(s->next1);
        }
    }
}

/* ---------- Print Machine ---------- */

void printMachine() {

    int i;

    for(i = 0; i < N; i++) {

        if(!states[i].deleted) { //prints all the non deleted states

            printf("%c %c %c\n",
                   states[i].name,
                   states[i].next0->name,
                   states[i].next1->name);
        }
    }
}

/* ---------- Garbage Command ---------- */

void garbageCmd() {

    int i;
    bool found = false;

    markReachable();

    for(i = 0; i < N; i++) {

        if(states[i].garbage && !states[i].deleted) { //garbage still remains true and is not deleted

            if(!found) { 
                printf("Garbage:");
                found = true;
            }

            printf(" %c", states[i].name);
        }
    }

    if(!found)
        printf("No Garbage");

    printf("\n");
}

/* ---------- Delete Garbage ---------- */

void deleteGarbage() {

    int i;
    bool found = false;

    markReachable();

    for(i = 0; i < N; i++) {

        if(states[i].garbage && !states[i].deleted) { //garbage still remains true and is not deleted

            if(!found) {
                printf("Deleted:");
                found = true;
            }

            states[i].deleted = true;

            printf(" %c", states[i].name);
        }
    }

    if(!found)
        printf("No states deleted.");

    printf("\n");
}

/* ---------- MAIN ---------- */

int main(int argc, char *argv[]) {

    int i;

    /* create state names */

    states[0].name = 'A';
    states[1].name = 'B';
    states[2].name = 'C';
    states[3].name = 'D';
    states[4].name = 'E';
    states[5].name = 'F';
    states[6].name = 'G';
    states[7].name = 'H';

    /* initialize flags */

    for(i = 0; i < N; i++) {
        states[i].deleted = false;
        states[i].garbage = false;
    }

    /* transitions from machine given*/

    states[0].next0 = &states[7];  // A H C
    states[0].next1 = &states[2];

    states[1].next0 = &states[2];  // B C F
    states[1].next1 = &states[5];

    states[2].next0 = &states[6];  // C G H
    states[2].next1 = &states[7];

    states[3].next0 = &states[5];  // D F A
    states[3].next1 = &states[0];

    states[4].next0 = &states[0];  // E A D
    states[4].next1 = &states[3];

    states[5].next0 = &states[1];  // F B G
    states[5].next1 = &states[6];

    states[6].next0 = &states[4];  // G E G
    states[6].next1 = &states[6];

    states[7].next0 = &states[3];  // H D B
    states[7].next1 = &states[1];

    /* starting state */

    current = &states[4];   // E

    printf("%c\n", current->name);

    char cmd;

    while(scanf(" %c", &cmd) != EOF) {

        if(cmd == '0') {

            current = current->next0;
            printf("%c\n", current->name);
        }

        else if(cmd == '1') {

            current = current->next1;
            printf("%c\n", current->name);
        }

        else if(cmd == 'c') {

            char bit;
            char targetName;

            scanf(" %c %c", &bit, &targetName);

            State *target = findState(targetName);

            if(bit == '0')
                current->next0 = target;
            else
                current->next1 = target;
        }

        else if(cmd == 'p') {

            printMachine();
        }

        else if(cmd == 'g') {

            garbageCmd();
        }

        else if(cmd == 'd') {

            deleteGarbage();
        }
    }

    exit(0);
}

