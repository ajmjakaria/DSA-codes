#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* root = nullptr;
void add_node(int data){
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
	// cout << new_node -> data << " ";
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

void search_node(int data)
{
    Node* current_node =  root;
    int index = 0;
    while(current_node != nullptr)
    {
        if(current_node -> data == data){
            printf("Found at %d\n", index);
            return;
        }
        current_node = current_node->next;
        index++;
    }
    printf("Not Found\n");
}
void insert_node(int index, int data)
{
    Node* new_node = new Node();
	new_node -> data = data;
	new_node -> next = nullptr;
	//insert at beginning
	if(index == 0)
	{
	    new_node -> next = root;
	    root =  new_node;
	    return;
	}
	//insert at an specific postion
	Node* current_node = root;
	for(int i = 0; i < index - 1 && current_node != nullptr; i++){
	    current_node = current_node->next;
	}
	if(current_node == nullptr)
	{
	    printf("Index out of bound\n");
	    delete new_node; //free memory
	    return;
	}
	//insert at an specific position
	new_node -> next = current_node->next;
	current_node->next = new_node;
}
void delete_node(int index)
{
    if(root == nullptr){
        printf("List is empty\n");
        return;
    }
    //delete first node/root
    if(index == 0)
    {
        Node* temp = root;
        root = root->next;
        delete temp;
        return;
    }
    Node* current_node = root;
    for(int i = 0; i < index - 1 && current_node != nullptr; i++){
	    current_node = current_node->next;
	}
    if(current_node == nullptr || current_node->next == nullptr)
	{
	    printf("Index out of bound\n");
	    return;
	}
	Node* temp = current_node -> next;
	current_node -> next = temp -> next;
	delete temp;
}
void print_backward(Node* current_node)
{
    if(current_node != nullptr)
    {
        print_backward(current_node -> next);
        cout << current_node -> data << " ";
    }
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = 5;
	for(int i = 0; i < n; i++)
		add_node(arr[i]);
	// cout << endl;
	search_node(10);
	delete_node(2);
	insert_node(2, 100);
	print_forward();
	// print_backward(root);
	return 0;
}
