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
	ItemType		info;
	Node<ItemType>		*next;
};

template<typename ItemType>
class LinkedList{
public:
	Node<ItemType>	*listData;
	LinkedList();
	Node<ItemType> *insertion(Node<ItemType> *listptr, ItemType item);
	Node<ItemType> * deletion(Node<ItemType> *listPtr, ItemType item);
	void printitems();
};

template<typename ItemType>
LinkedList<ItemType>::LinkedList(){
	listData = NULL;
}

template<typename ItemType>
Node<ItemType> * LinkedList<ItemType>::insertion(Node<ItemType> *listPtr, const ItemType item){
	
        Node<ItemType> *temp;
        if ( (listPtr == NULL) || (listPtr->info > item) ){
                temp = listPtr;
                listPtr = new Node<ItemType>;
                listPtr->info = item;
                listPtr->next = temp;
                return listPtr;
        }	
        else
                listPtr->next = insertion(listPtr->next, item);
}

template<typename ItemType>
Node<ItemType> * LinkedList<ItemType>::deletion(Node<ItemType> *listPtr, ItemType item){
    Node<ItemType>  *temp;
    
    if (listPtr == NULL) return listPtr;
    
    if ( listPtr->info == item ) {
            temp = listPtr;
            listPtr = listPtr->next;
            delete temp;
            return listPtr;
    }
    else{
                listPtr->next = deletion(listPtr->next, item);
    }
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
	L1.listData = L1.insertion(L1.listData, 10); /* test for empty */
	L1.listData = L1.insertion(L1.listData, 20); /* test for terminal node */
	L1.listData = L1.insertion(L1.listData, 30); /* test for terminal node */
	L1.listData = L1.insertion(L1.listData, 15); /* test for mid positin */
	L1.listData = L1.insertion(L1.listData, 5);  /* test for head */
//	
	L1.printitems();
        printf ("===\n")	;
	L1.listData = L1.deletion(L1.listData, 20);
	printf(" deleted 20\n");
	L1.printitems();
	
	L1.listData = L1.deletion(L1.listData, 5);
	printf(" deleted 5\n");
	L1.printitems();

	L1.listData = L1.deletion(L1.listData, 30);
	printf(" deleted 30\n");
	L1.printitems();

	L1.listData = L1.deletion(L1.listData, 99);
	printf(" deleted 99\n");
	
	L1.printitems();
	
	L1.listData =  L1.deletion(L1.listData, 15);
	printf(" deleted 15\n");
	
	L1.printitems();

	L1.listData = L1.deletion(L1.listData, 10);
	printf(" deleted 10\n");
	L1.printitems();

}
