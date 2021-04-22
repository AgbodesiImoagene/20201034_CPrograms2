/*
 * COMP10120_10B.c
 * Agbodesi Imoagene 13/04/21
 * A C Program that creates a queue.
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
 void enqueue( ListNodePtr *sPtr, char value );
 void dequeue( ListNodePtr *sPtr );
 int isEmpty( ListNodePtr sPtr );
 void printList( ListNodePtr currentPtr );
 void instructions( void );

 int main( void )
 {
     ListNodePtr startPtr = NULL; /* initially there are no nodes */
     int choice; /* user's choice */
     char item; /* char entered by user */

     instructions(); /* display the menu */
     printf( "? " );
     scanf( "%d", &choice );

      /* loop while user does not choose 3 */
     while ( choice != 3 ) {
         switch ( choice ) {
             case 1:
                 printf( "Enter a character: " );
                 scanf( "\n%c", &item );
                 enqueue( &startPtr, item ); /* insert item in list */
                 printList( startPtr );
                 break;
              case 2: /* delete an element */
                  /* if list is not empty */
                 if ( !isEmpty( startPtr ) ) {
                     /* if character is found, remove it*/
                     dequeue( &startPtr);
                     printList(startPtr);
                 } /* end if */
                 else {
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
          " 1 to insert(enqueue) an element into the queue.\n"
          " 2 to delete(dequeue) an element from the queue.\n"
          " 3 to end.\n" );
 } /* end function instructions */

      /* Insert a new value into the list in sorted order */
 void enqueue( ListNodePtr *sPtr, char value )
 {
     ListNodePtr newPtr = (ListNodePtr )malloc( sizeof( ListNode ) ); /* create node */
     if ( newPtr != NULL ) { /* is space available */
         newPtr->data = value; /* place value in node */
         newPtr->nextPtr = *sPtr; //Assign *sPtr to node member nextNode(link node)
         *sPtr = newPtr; //Set newPtr as start of list

     } /* end if */
     else {
         printf( "%c not inserted. No memory available.\n", value );
     } /* end else */
 } /* end function insert */

 /* Delete a list element */
 void dequeue( ListNodePtr *sPtr )
 {
     /* delete first node */
     if ( ( *sPtr )->nextPtr == NULL ) { //Case for only 1 item
         ListNodePtr tempPtr = *sPtr; /* hold onto node being removed */
         *sPtr = NULL; /* de-thread the node */
         printf("%c deleted. \n", tempPtr->data);
         free( tempPtr ); /* free the de-threaded node */
      } /* end if */

     else {
         ListNodePtr previousPtr = *sPtr;
         ListNodePtr currentPtr = ( *sPtr )->nextPtr;

     /* loop to find the correct location in the list */
      while ( currentPtr->nextPtr != NULL ) {
          previousPtr = currentPtr; /* walk to ... */
          currentPtr = currentPtr->nextPtr; /* ... next node */
      } /* end while */

      /* delete node at currentPtr */
      previousPtr->nextPtr = NULL;
      printf("%c deleted. \n", currentPtr->data);
      free(currentPtr);

      } /* end else */

 } /* end function delete */

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
