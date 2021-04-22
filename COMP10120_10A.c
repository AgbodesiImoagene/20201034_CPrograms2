/*
 * COMP10120_10A.c
 * Agbodesi Imoagene 13/04/21
 * A C Program that can copy the contents of a one-dimensional integer array into a newly
 * created single linked list. The nodes of the linked list are defined by the following
 * struct in which the member called data will hold the integer value for each array element.
 * It includes functionality to print the contents of the array and linked list to show the
 * copy was successful.
 */

#include <stdio.h>
#include <stdlib.h> //Contains malloc function

typedef struct node{ //Each node contains an integer and a pointer to the next node
  int data;
  struct node *nextNode;
}Node;

void arrToList(Node **sPtr, int arr[], unsigned int size, unsigned int index);
void printArray(int arr[], unsigned int size);
void printList(Node *sPtr);

int main(void) {
  Node *startPtr = NULL; //Holds pointer to first item in list, initialised to NULL
  unsigned int n; //Holds size of array and in turn list

  //Get input from user to initialise array
  printf("Enter the number of elements you want in the array: ");
  scanf("%u", &n);
  int x[n];
  for (size_t i = 0; i < n; i++) {
    printf("Enter element %d of the array: ", i + 1);
    scanf("%d", &x[i]);
  }

  arrToList(&startPtr, x, n, 0); //Create linked list of elements in array

  //Print array and list
  puts("");
  puts("The array of integers is: ");
  printArray(x, n);
  puts("The linked list of integers is: ");
  printList(startPtr);
  return 0;
}

void arrToList(Node **sPtr, int arr[], unsigned int size, unsigned int index) {
  if (index == size) { //Base case that there are no elements to be added to array
    return;
  }

  arrToList(sPtr, arr, size, index + 1); //Recursive call for the next element in the array to be added to the list

  Node *newPtr = (Node *)malloc(sizeof(Node)); //Create a new node and allocate to it sufficient space

  if (newPtr != NULL) { //Check that space is available
    newPtr->data = arr[index]; //Assign array element to node member data
    printf("\nA new node containing array element %d(%d) has been created. \n", index + 1, newPtr->data);

    newPtr->nextNode = *sPtr; //Assign *sPtr to node member nextNode(link node)
    *sPtr = newPtr; //Set newPtr as start of list
    puts("The node has been inserted at the start of the list. ");

    puts("The current list is: "); //Print current list
    printList(*sPtr);
  } else {
    puts("No memory available. ");
  }
}

void printArray(int arr[], unsigned int size) {
  for (size_t i = 0; i < size; i++) { //Iterate through array and print each element
    printf("%d     ", arr[i]);
  }
  puts("");
}

void printList(Node *sPtr) {
  if (sPtr->nextNode == NULL) { //Base case for the last item in the list
    printf("%d\n", sPtr->data); //Print last item
    return;
  }

  printf("%d - > ", sPtr->data); //Print first(current) item in list
  printList(sPtr->nextNode); //Recursive call to print rest of list
}
