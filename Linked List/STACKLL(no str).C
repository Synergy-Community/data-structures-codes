/* Stack using Linked List - Program to create a stack ADT using linked list. ADT should support the following operations
1)  Createstack
2)  pushstack
3)  popstack
4)  destroystack
*/

#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>
#define  NULL  0

struct  node
{
  int  data ;
  struct  node  *next ;
} ;

struct  node  *top ;

/* top is a global variable and need not be passed to any function. Any changes made to variable top by any of the functions in the program will be permanent and will be reflected in the entire program */

/* This fn. initializes the stack to be empty by making top as NULL */
void  createstack()
{
  top=NULL ;
}

void  pushstack(int  x)
{
  struct  node  *pnode ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to push.\n") ;
    exit(1) ;
  }

  pnode->data=x ;

  pnode->next=top ;
  top=pnode ;
}

int  empty()
{
  if(top==NULL)
    return  1 ;
  else
    return  0 ;
}

int  popstack()
{
  int  x ;
  struct  node *p ;

  if(empty())
  {
    printf("Stack Underflow. Unable to pop.\n") ;
    getch() ;
    exit(1) ;
  }

  x=top->data ;
  p=top ;
  top=top->next ;
  free(p) ;
  return x ;
}

/* The  statements  
  p=top ;
  top=top->next ;
  free(p) ;
  SHOULD NOT BE WRITTEN for function stacktop() */

void  show()
{
  struct  node  *p ;

  if(empty())
    printf("Stack empty. No data to display.\n") ;
  else
  {
    printf("Stack from topmost element is as shown:\n") ;
    p=top ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->next ;
    }
    printf("\n") ;
  }
}

void  destroystack()
{
  top=NULL ;
}

void  main()
{
  int  x , ch ;

  createstack() ;

  clrscr() ;
  do
  {
    printf("\n\n  Menu: \n") ;
    printf("1:push \n") ;
    printf("2:pop \n") ;
    printf("3:exit \n") ;
    printf("Enter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch)
    {
      case 1:
      printf("Enter element to be pushed: ") ;
      scanf("%d",&x) ;
      pushstack(x) ;
      show() ;
      break ;

      case 2:
      x=popstack() ;
      printf("Element popped is: %d \n",x) ;
      show() ;
      break ;

      case 3:
      break ;
    }
  }
  while(ch!=3) ;

  destroystack() ;

  getch() ;
}

/*
The operation destroystack need not be given if not asked to do so. Morover even empty operation was not asked. But giving it is necessary for pop and show. 
*/






