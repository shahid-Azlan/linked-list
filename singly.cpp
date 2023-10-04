#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
class LinkedList{
	private:
		Node *start;
	public:
		LinkedList(){
			start = NULL;
		}
		//insert at end
		void insertAtEnd(int val){
			Node *newNode = new Node;
			newNode->data = val;
			newNode->next = NULL;
			if(start==NULL){
				start = newNode;
			}
			else{
				Node *currentNode = start;
				while(currentNode->next!=NULL){
					currentNode=currentNode->next;
				}
				currentNode->next=newNode;
			}
		}
		// insert at start
		void insertAtStart(int val){
			Node *newNode = new Node;
			newNode->data = val;
			newNode->next = NULL;
			newNode->next = start;
			start = newNode;
		}
		//insert at given index
		void insertAtIndex(int val, int index) {
			Node *newNode = new Node;
			newNode->data = val;
			newNode->next = NULL;
			int i = 1;
			Node *currentNode = start;
			if (index == 0) {
				newNode->next = start;
				start = newNode;
			} else {
				while (index > i) {
					if (currentNode->next != NULL) {
						currentNode = currentNode->next;
						++i;
					} else {
						cout << "Index is very large so, inserting at end" << endl;
						break;
					}
				}
				newNode->next = currentNode->next;
				currentNode->next = newNode;
			}
		}


		// delete at start 
		void deleteAtStart(){ 
			Node *temp = new Node; 
			temp=start; 
			start = temp->next; 
			delete temp;
			temp=NULL;
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
			temp1=NULL;
		}
		
		//del at specific data
		void delData(int d){
				Node *currentNode = start,*temp;
				
				while(currentNode->data != d){
					temp = currentNode;
					currentNode = currentNode->next;
				}
				temp->next = currentNode->next;
				delete currentNode;
				currentNode =  NULL;
				
		}		
		
		void display() { 
		Node* current = start; 
		while (current != NULL) { 
		cout << current->data << " "; 
		current = current->next; 
		} 
		cout << endl; 
		}

};

int main(){
	LinkedList list;
	list.insertAtEnd(1);
	list.insertAtEnd(2);
	list.insertAtEnd(3);
	list.insertAtStart(0);
	list.insertAtIndex(4,2);
//	list.deleteAtStart();
//	list.deleteAtEnd();
	list.delData(3);
	list.display();
	return 0;
}
