#include<iostream> 
using namespace std;

//creating the node
struct Node{ 
	int data; 
	Node *next; 
	Node *prev; 
};
class Doubly{ 
	private: 
		Node *start; 
	public: 
		Doubly(){ 
			start = NULL; 
		}
			// Function to display the contents of the list 
		void display() { 
			Node* current = start; 
			while (current != NULL) { 
				cout << current->data << " "; 
				current = current->next; 
			} 
			cout << endl; 
		}
		//insert at the end 
		void insertAtEnd(int val){
			Node *newNode = new Node; 
			newNode->data = val; 
			newNode->next = NULL; 
			newNode->prev = NULL; 
			// check if the node linked list is empty or not 
			if(start == NULL){ 
				start = newNode; 
			} 
			else { 
				Node *currentNode = start; 
				while(currentNode->next != NULL){ 
					currentNode = currentNode->next; 
				} 
				newNode->prev = currentNode; 
				currentNode->next = newNode; 
				} 
				
			cout<<"After insertion at end: \n";
			display();
			}
		//delete at the end
		void deleteAtEnd(){
			Node *temp1 = start, *temp2;
			while(temp1->next!=NULL){
				temp2 = temp1;
				temp1= temp1->next;
			}
			temp2->next = NULL;
			delete temp1;
			display();
		}
		// function to insert at start
		void insertAtStart(int val){
		// creating the node
			Node *newNode = new Node;
			newNode->data = val;
			newNode->next = NULL;
			newNode->prev = NULL;
			Node *temp = start;
			temp->prev = newNode;
			newNode->next = temp;
			start = newNode;
			display();
		}
		// function to delete at start
		void deleteAtStart(){
			Node *temp,*temp2;
			temp=start;
			start = temp->next;
			temp2 = start;
			temp2->prev = NULL;
			delete temp;
			display();
		}
		// insert at given index
		void insertAtIndex(int val, int index) {
			Node *newNode = new Node;
			newNode->data = val;
			newNode->next = NULL;
			newNode->prev =NULL;
			int i = 1;
			Node *currentNode = start;
			if (index == 0) {
				Node *temp=start;
				newNode->next = start;
				temp->prev = newNode;
				start = newNode;
			}else {
				while (index > i) {
					if (currentNode->next != NULL) {
						currentNode = currentNode->next;
						++i;
					} else {
						cout << "Index is very large so, inserting at end" << endl;
						break;
					}
				}
				Node *temp = currentNode->next;
				newNode->next = currentNode->next;
				temp->prev=newNode;
				currentNode->next = newNode;
				display();
			}
		}			
	
	


};


int main(){ 
	Doubly sing;
	sing.insertAtEnd(5); 
	sing.insertAtEnd(6); 
	sing.insertAtEnd(7); 
//	sing.deleteAtEnd();
//	sing.deleteAtStart();
	sing.insertAtStart(4);
	sing.insertAtIndex(3,2);
	
}

