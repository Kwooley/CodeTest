/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include 	<stdio.h>
#include	<iostream>
using namespace std;


template<typename ItemType>
class Node{
public:
	ItemType			info;
	Node<ItemType>		*next;
};

template<typename ItemType>
class LinkedList{
public:
	Node<ItemType>	*listData;
	LinkedList();
	int insertion(ItemType item);
	int deletion(ItemType item);
	void printitems();
};

template<typename ItemType>
LinkedList<ItemType>::LinkedList(){
	listData = NULL;
}

template<typename ItemType>
int LinkedList<ItemType>::insertion(const ItemType item){
	Node<ItemType> *ptr, *temp;
	Node<ItemType> *newitem;
	
	temp = ptr = listData;
	newitem = new Node<ItemType>;
	newitem->info = item;
	
	if ((temp ==NULL) && (ptr == NULL)) { /* Case 0 : List is empty */
	    listData = newitem;
	    newitem->next = NULL;    
	    return 0;
	}
	while (ptr != NULL){
		if ( (ptr->info < item) && (ptr->next != NULL) )
		{
		        temp = ptr;
		        ptr = ptr->next;
		}
		else {
		    if ((ptr->info < item) && (ptr->next == NULL)) { /* insertion to terminal node */
		        ptr->next = newitem;
		        return 2;
		    }
		    if ((ptr->info > item) && (temp == ptr) ) { /* insertion to head node */
		        newitem->next = listData;
        		listData = newitem;
        		return 0;
		    }
		    /* insertion to mid node */
    	        temp->next = newitem;
		newitem->next = ptr;
		return 1;
		}
	}
}

template<typename ItemType>
int LinkedList<ItemType>::deletion(ItemType item){
    Node<ItemType> *ptr, *temp;
    temp = ptr = listData;
    
    while ( ptr != NULL){
        if (( ptr->info != item ) && (ptr->next != NULL)) {
            temp = ptr;
            ptr = ptr->next;
        }
        else{
            if ( ptr->info != item){
                    printf("Not Found item.");
                    return 0;
            }
            if ( temp == ptr ) { /* delete the first node */
                listData = ptr->next;
                delete ptr;
                return item;
            }
            else { /* delete the mid node or ternimal node */
                temp->next = ptr->next;
                delete ptr;
                return item;
            }
        }
    }
    return 0;
}

template<typename ItemType>
void LinkedList<ItemType>::printitems(){
	Node<ItemType> *ptr=listData;
	while (ptr != NULL){
		cout << ptr->info << endl;
		ptr = ptr->next;
	}

}

int main(){
	LinkedList<int>	L1;
	L1.insertion(10); /* test for empty */
	L1.insertion(20); /* test for terminal node */
	L1.insertion(30); /* test for terminal node */
	L1.insertion(15); /* test for mid positin */
	L1.insertion(5);  /* test for head */
	
	L1.printitems();
	
	
	int ret = L1.deletion(20);
	printf(" %d deleted\n", ret);
	L1.printitems();
	
	ret = L1.deletion(5);
	printf(" %d deleted\n", ret);
	L1.printitems();

	ret = L1.deletion(30);
	printf(" %d deleted\n", ret);
	L1.printitems();

	ret = L1.deletion(99);
	printf(" %d deleted\n", ret);
	L1.printitems();
	
	ret = L1.deletion(15);
	printf(" %d deleted\n", ret);
	L1.printitems();
	ret = L1.deletion(10);
	printf(" %d deleted\n", ret);
	L1.printitems();
}
