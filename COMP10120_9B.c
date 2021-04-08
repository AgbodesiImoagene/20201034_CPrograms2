/*
 * COMP10120_9B.c
 * Agbodesi Imoagene 08/04/21
 * A a new function that replaces a character in a linked list with another
 * character. The function takes three arguments – the list, the character
 * to be replaced and the new character. The function prints the elements
 * of the old list and then the new list to reflect the changes.It uses a
 * menu-driven system to demonstrate the functionality.
 */

/*  Operating and maintaining a linked list */
#include <stdio.h>
#include <stdlib.h>

    /* self-referential structure */
struct listNode {
             char data; /* each listNode contains a character */
             struct listNode *nextPtr; /* pointer to next node */
}; /* end structure listNode */


typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

/* prototypes */
void insert( ListNodePtr *sPtr, char value );
char deletea( ListNodePtr *sPtr, char value );
char replace( ListNodePtr sPtr, char value, char sub ); //New function
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void sortList( ListNodePtr *sPtr ); //New function
void instructions( void );

//Type to fit funtion pointers with different parameters and return types in an arrary
typedef void (*generic_fp)(void);

int main( void )
{
    ListNodePtr startPtr = NULL; /* initially there are no nodes */
    int choice; /* user's choice */
    char item; /* char entered by user */
    generic_fp funct[3] = {(generic_fp)insert, (generic_fp)deletea,
                           (generic_fp)replace}; //Function pointers for menu-driven functionality by typecasting functions

    instructions(); /* display the menu */
    printf( "? " );
    scanf( "%d", &choice );

     /* loop while user does not choose 4 */
    while ( choice != 4 ) {
        switch ( choice ) {
            case 1:
                printf( "Enter a character: " );
                scanf( "\n%c", &item );
                /* insert item in list */
                ((void (*)(ListNodePtr *, char)) funct[choice - 1])(&startPtr, item); //Call function from array
                printList( startPtr );
                break;
             case 2: /* delete an element */
                 /* if list is not empty */
                if ( !isEmpty( startPtr ) ) {
                    printf( "Enter character to be deleted: " );
                    scanf( "\n%c", &item );
                    /* if character is found, remove it*/
                    /* remove item */
                    if ( ((char (*)(ListNodePtr *, char)) funct[choice - 1])(&startPtr, item) ) { //Call function from array
                        printf( "%c deleted.\n", item );
                        printList( startPtr );
                    } /* end if */
                    else {
                        printf( "%c not found.\n\n", item );
                    } /* end else */
                } /* end if */
                else {
                    printf( "List is empty.\n\n" );
                } /* end else */

                break;
            case 3:
                if ( !isEmpty( startPtr ) ) { //Check that list is not empty
                    char newVal; //Holds char to replace existing character

                    //Get input from user
                    printf( "Enter character to be replaced: " );
                    scanf( "\n%c", &item );
                    printf( "Enter new character: " );
                    scanf( "\n%c", &newVal );

                    //Print old list
                    puts("This is the old list: ");
                    printList( startPtr );

                    //Call function from array
                    if ( ((char (*)(ListNodePtr, char, char)) funct[choice - 1])(startPtr, item, newVal) ) { //Check that item is in list
                        sortList( &startPtr ); //Sort list

                        //Print new list
                        printf( "%c was replaced with %c.\n", item, newVal );
                        puts("This is the new list: ");
                        printList( startPtr );
                    } /* end if */
                    else { //Case that item is not found in list
                        printf( "%c not found.\n\n", item );
                    } /* end else */

                } /* end if */
                else { //Case that list is empty
                    printf( "List is empty.\n\n" );
                } /* end else */

                break;
            default:
                 printf( "Invalid choice.\n\n" );
                 instructions();
                 break;
                 } /* end switch */

        printf( "? " );
        scanf( "%d", &choice );
} /* end while */

    printf( "End of run.\n" );
    return 0; /* indicates successful termination */
     } /* end main */

     /* display program instructions to user */
void instructions( void )
{
    printf( "Enter your choice:\n"
         " 1 to insert an element into the list.\n"
         " 2 to delete an element from the list.\n"
         " 3 to replace a character in the list.\n"
         " 4 to end.\n" );
} /* end function instructions */

     /* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, char value )
{
    ListNodePtr newPtr = (ListNode *)malloc( sizeof( ListNode ) ); /* create node */
    if ( newPtr != NULL ) { /* is space available */
        newPtr->data = value; /* place value in node */
        newPtr->nextPtr = NULL; /* node does not link to another node */

        ListNodePtr previousPtr = NULL;  /* pointer to previous node in list */
        ListNodePtr currentPtr = *sPtr; /* pointer to current node in list */

        /* loop to find the correct location in the list */
        while ( currentPtr != NULL && value > currentPtr->data ) {
            previousPtr = currentPtr; /* walk to ... */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */

                /* insert new node at beginning of list */
        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } /* end if */
        else { /* insert new node between previousPtr and currentPtr */
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
            } /* end else */
    } /* end if */
    else {
        printf( "%c not inserted. No memory available.\n", value );
    } /* end else */
} /* end function insert */

/* Delete a list element */
char deletea( ListNodePtr *sPtr, char value )
{
    /* delete first node */
    if ( value == ( *sPtr )->data ) {
        ListNodePtr tempPtr = *sPtr; /* hold onto node being removed */
        *sPtr = ( *sPtr )->nextPtr; /* de-thread the node */
        free( tempPtr ); /* free the de-threaded node */
        return value;
     } /* end if */

    else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = ( *sPtr )->nextPtr;

    /* loop to find the correct location in the list */
     while ( currentPtr != NULL && currentPtr->data != value ) {
         previousPtr = currentPtr; /* walk to ... */
         currentPtr = currentPtr->nextPtr; /* ... next node */
     } /* end while */

     /* delete node at currentPtr */
     if ( currentPtr != NULL ) {
         previousPtr->nextPtr = currentPtr->nextPtr;
         free(currentPtr);
         return value;
        } /* end if */
     } /* end else */

     return '\0';
} /* end function delete */

char replace( ListNodePtr sPtr, char value, char sub )
{
  int replaced = 0; //Holds 0 or 1 to indicate value is in list

  while (sPtr != NULL) { //Iterate through list
    if (value == sPtr->data) { //Replace any character == value
      sPtr->data = sub;
      replaced = 1;
    }
    sPtr = sPtr->nextPtr;
  }

  if (replaced) { //Return value if replacement was done
    return value;
  }
  return '\0';
}

     /* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
} /* end function isEmpty */

     /* Print the list */
void printList( ListNodePtr currentPtr )
{
    /* if list is empty */
    if ( currentPtr == NULL ) {
        printf( "List is empty.\n\n" );
     } /* end if */
    else {
        printf( "The list is:\n" );

    /* while not the end of the list */
    while ( currentPtr != NULL ) {
        printf( "%c --> ", currentPtr->data );
        currentPtr = currentPtr->nextPtr;
     } /* end while */

    printf( "NULL\n\n" );
     } /* end else */
} /* end function printList */


void sortList( ListNodePtr *sPtr )
{
  if ((*sPtr)->nextPtr == NULL) { //Base case for 1 item in list
    return;
  }

  sortList(&((*sPtr)->nextPtr)); //Recursive call to sort list minus first item

  if ((*sPtr)->data > (*sPtr)->nextPtr->data) { //Case current character is larger than next
    //Declare pointers to traverse list
    ListNodePtr prevPtr;
    ListNodePtr currPtr = *sPtr;

    //Shift current character and set second item as start of list
    *sPtr = currPtr->nextPtr;
    currPtr->nextPtr = currPtr->nextPtr->nextPtr;
    (*sPtr)->nextPtr = currPtr;
    prevPtr = *sPtr;

    //Iterate through list until 1 item remains or charcter is in correct position
    while (currPtr->nextPtr != NULL && currPtr->data > currPtr->nextPtr->data) {
      //Shift item down list by re-assigning item next-pointers
      ListNodePtr temp = currPtr->nextPtr;
      currPtr->nextPtr = currPtr->nextPtr->nextPtr;
      temp->nextPtr = currPtr;
      prevPtr->nextPtr = temp;
      prevPtr = prevPtr->nextPtr;
    }
  }
}
