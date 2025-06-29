#include <bits/stdc++.h>
using namespace std;
//define node structure

struct Node{
  int data;
  Node* next;
};
Node* root = nullptr;

//function to add node at the end of the list
void add_node(int data)
{
    Node* new_node = new Node();
    new_node -> data = data;
    new_node -> next = nullptr;
    if(root == nullptr)
        root = new_node;
    else{
        Node* current_node = root;
        while(current_node -> next != nullptr){
            current_node = current_node -> next;
        }
        current_node -> next = new_node;
    }
    //cout << new_node -> data << endl;
}
void print_forward()
{
    Node* current_node = root;
    while(current_node != nullptr){
        cout << current_node -> data << " ";
        current_node = current_node -> next;
    }
    cout << endl;
}
void print_backward(Node* current_node)
{
    if(current_node != nullptr)
    {
        cout << current_node -> data << " ";
        print_backward(current_node -> next);
        
    }
}
int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 5; i++)
	    add_node(arr[i]);
	cout << "Forward: ";
	print_forward();
	cout << endl << "Backward: ";
	print_backward(root);
	cout << endl;
	    
	
}
