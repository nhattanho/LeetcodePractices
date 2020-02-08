//Author: Nhat Ho
//davisho2411@gmail.com

#include<stdio.h>
#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int data){
		this->data = data;
		next = NULL;
	}
};

void insertHead(Node *&head, int data){
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}

void printList(Node *head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* reverse(Node* head, Node* pre){
	if(head == NULL) return head;
	if(head->next == NULL){
		head->next = pre;
		return head;
	}
	Node* cur = head;
	head = head->next;
	cur->next = pre;
	pre = cur;
	reverse(head, pre);
}

void reverse1(Node* head, Node* &p){
	if(head == NULL) return;
	if(head->next == NULL){
		p = head;
		return;
	}
	reverse1(head->next, p);
	head->next->next = head;
	head->next = NULL;
}

int main(){
	Node* list = NULL;
	insertHead(list, 1);
	insertHead(list, 2);
	insertHead(list, 3);
	printList(list);

	list = reverse(list, NULL);
	printList(list);

	Node* p = NULL;
	reverse1(list,p);
	printList(p);
	return 0;
}

