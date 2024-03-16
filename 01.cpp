#include <iostream>
using namespace std;

class LinkList {
	private:
		struct Node{
			int data;
			Node *next_add;
		};
    int data;
    Node* head;
    public:
        LinkList(){
        	head=NULL;
		}
	
	void display_full();
	void insertNode(int);
	void searchNode(int);
	void reverse();
   
};

void LinkList::display_full(){
	if(head==NULL)
	{
		cout<<"No data to display, Because LinkList is empty"<<endl;
	}
	
	else
	{
		Node *nodePtr=head;
		while(nodePtr !=NULL)
		{
			cout<<nodePtr -> data<<endl;
			nodePtr=nodePtr -> next_add;
		}
	}
}

void LinkList::insertNode(int a){
	Node *new_Node = new Node;
	new_Node -> data = a;
	new_Node -> next_add = NULL;
	
	if(head == NULL){
		head = new_Node;
	}
	
	else
	{
		Node *nodePtr;
		nodePtr = head;
		while(nodePtr -> next_add !=NULL)
		{
			nodePtr = nodePtr -> next_add;
		}
		nodePtr -> next_add = new_Node;
	}
}

void LinkList::searchNode(int n){
	
	bool found = false;
    Node* nodePtr = head;
    while(nodePtr!=NULL){
    	if(nodePtr -> data == n)
    	{
    		found = true;
    		break;
		}
		
		nodePtr = nodePtr -> next_add;
	}
	if(found==true)
	{
		cout<<"YES!The Number "<<n<<" is found in the list!"<<endl;
	}
	
		else
	{
		cout<<"No!The Number "<<n<<" is Not Found in the list!"<<endl;
	}


};

  void LinkList:: reverse() {
        Node* prev = NULL;
        Node* current = head;
        while (current) {
            Node* next_node = current->next_add;
            current->next_add = prev;
            prev = current;
            current = next_node;
        }
        head = prev;
    }

int main() {
    LinkList l1;

    l1.insertNode(11);
    l1.insertNode(21);
    l1.insertNode(31);
    l1.insertNode(41);
    l1.insertNode(51);
    cout<<"Original List of values: "<<endl;
    l1.display_full();
    cout<<"Is 31 Found in the List?"<<endl;
    l1.searchNode(31);
    
       l1.reverse();
    cout << "Reversed LinkedList:" << endl;
    l1.display_full();
  

    return 0;
}

