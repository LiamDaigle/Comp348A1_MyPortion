#include <stdio.h>
#include <stdlib.h>

//Creating linked list structure
typedef enum { ATOM, LIST } eltype;

typedef char atom;

struct _listnode;

typedef struct {
    eltype type;
    union {
        atom a;
        struct _listnode* l;
    };
} element;

typedef struct _listnode {
    element el;
    struct _listnode* next;
} * list;

const element NIL = { .type=LIST, .l=NULL };
//End of linked list structure

//Declaring all methods to be created
element aasel(atom);
element lasel(list);
element car(element);
list cdr(element);
list cddr(element);
list cons(element, list);
list append(list, list);
void lfreer(list);
void print(element);
//End of declarations

int main()
{

    //Creating list for question 6 by allocating memory
    list head = malloc(sizeof(list));
    list two = malloc(sizeof(list));
    list three = malloc(sizeof(list));
    list four = malloc(sizeof(list));

    list five = malloc(sizeof(list));
    list six = malloc(sizeof(list));
    
    //Linking the list nodes together in the form given by question 6
    
    //Primary List
    head->el = aasel('a');
    head->next = two;
    two->el = lasel(five);
    two->next = three;
    three->el = aasel('d');
    three->next = four;
    four->el = aasel('e'); 
    four->next = NULL;

    //Sub List
    five->el = aasel('b');
    five->next = six;
    six->el = aasel('c');
    six->next = NULL;

    //Creating elements to be outputted for question 7
    element lel = lasel(head);
    element car_el = car(lel);
    list cdrl = cdr(lel);
    element car_car_el = car(car_el);

    //Ouputting for question 7
    print(lel);
    printf("\n");
    print(car_el);
    printf("\n");
    print(lasel(cdrl));
    printf("\n");
    print(car_car_el);
    
    //Freeing all memory allocated for list
    lfreer(head);
    
    return 0;
}

//Method that takes an atom and returns an element
element aasel(atom a){

    element e = {.type = ATOM, .a = a};
    return e;
}
//Method that takes a list and returns an element
element lasel(list l){

    element e = {.type = LIST, .l = l};
    return e;
}
//Method that takes an element and returns the head of the list (provided the element is of type LIST)
element car(element e){

    if(e.type != LIST){
        return NIL;
    }
    else{
        return e.l->el;
    }
}
//Method that returns the elements of a list (provided the element is of type LIST) without the head
list cdr(element e){
    
    if(e.type != LIST || e.l == NULL || e.l->next == NULL){
        return NULL;
    }
    else{
       list head = e.l;
       list ptr = head->next;

       return ptr;
    }
    
}
//Method that returns the elements of a sublist (provided the element is of type LIST) without the head
list cddr(element e){
    
    if(e.type != LIST || e.l->el.l == NULL || e.l->el.l->next == NULL){
        return NULL;
    }

    list head = e.l->el.l;
    list ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    return ptr;
}

//Method that takes an element and list, and gives the head and tail those parameters
list cons(element e, list l){

    list newhead = malloc(sizeof(list));
    list newtail = malloc(sizeof(list));
    list newptr = newhead;

    e.l = l;

    newptr->el = e;
    newptr->next = newtail;
    newtail->el = e;
    newtail->next = NULL;

    return newhead;
    return NULL;
}
//Method that takes 2 lists and appends them into a new list
list append(list l1, list l2){

    list new = malloc(sizeof(list));
    list newhead = new;
    list newptr = newhead;

    list l1ptr = l1;
    list l2ptr = l2;

    while(l1ptr != NULL){
        newptr->el = l1ptr->el;
        list node = malloc(sizeof(list));
        newptr->next = node;

        newptr = newptr->next;
        l1ptr = l1ptr->next;
    }

    while(l2ptr != NULL){
        newptr->el = l2ptr->el;
        list node = malloc(sizeof(list));
        newptr->next = node;

        newptr = newptr->next;
        l2ptr = l2ptr->next;
    }
    newptr->el = NIL;
    newptr->next = NULL;

    return newhead;
}
//Method that takes a list and frees the allocated memory for said list
void lfreer(list l){
    list ptr = l;

    while(ptr != NULL){
        list next_list = ptr->next;
        if(ptr->el.type == ATOM){
            free(ptr);
        }
        else if(ptr->el.type == LIST){
            lfreer(ptr->el.l);
        }
        ptr = next_list;
    }
    return;
}
//Method that takes an element e and prints it 
void print(element e){
    if(e.type == LIST && e.l == NULL){
        printf("NIL");
        return;
    }

    else if(e.type == ATOM){
        printf(" %c ", e.a);
    }

    else if(e.type == LIST){
        list lptr = e.l;
        printf("(");
        while(lptr != NULL){
            print(lptr->el);
            lptr = lptr->next;
        }
        printf(")");
    }
}