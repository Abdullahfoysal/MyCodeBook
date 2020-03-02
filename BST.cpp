#include "bits/stdc++.h"

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int data){
		this->data=data;
		left=right=NULL;
	}
	
}*root=new Node(5);

void insert(Node *cu,int data){
	// Node *cu=root;

	if(cu!=NULL){
		if(cu->data > data){
			if(cu->left!=NULL){
				insert(cu->left,data);
			}else{
				cu->left=new Node(data);
			}
			
		}else{
			if(cu->right!=NULL){
				insert(cu->right,data);
			}else{
				cu->right=new Node(data);
			}
		}
	}else{
		cu=new Node(data);
	}
}

Node* searchNode(Node *cu,int data){
	
	if(cu!=NULL){
		if(cu->data==data) return cu;
		else if(cu->data > data) return searchNode(cu->left,data);
		else{
			return searchNode(cu->right,data);
		} 
	}else{

		return NULL;
	}
}


Node* findRightMostData(Node *cu){
	if(cu!=NULL){
		if(cu->left!=NULL) return findRightMostData(cu->left);
		return cu;
	}
}

void deleteNode(Node *cu,int data){
	
	if(cu!=NULL){
		if(cu->data==data){
			if(cu->left==NULL && cu->right==NULL) delete cu;
			else if((cu->left==NULL && cu->right!=NULL) || (cu->left!=NULL && cu->right==NULL) ){

				if(cu->left!=NULL){
					Node *temp=cu->left;
					delete cu;
					cu=temp;
				}else {
					
					Node *temp=cu->right;
					delete cu;
					cu=temp;
				}
			}
			else{

				Node *temp=findRightMostData(cu->right);
				
				cu->data= temp->data;
				// temp->right=cu->right;
				delete temp;

			}
		}
	

	}
}

void updateNode(Node *cu,int pre_data,int up_data){
	//cout<<"$";
	Node *tt=searchNode(cu,pre_data);
	//cout<<tt->data<<"*"<<endl;
	// cout<<"hello";
	
	insert(root,up_data);
	deleteNode(tt,pre_data);
}

int main(int argc, char const *argv[])
{
	insert(root,55);
	insert(root,-55);
	insert(root,-10);
	insert(root,-9);
	insert(root,-11);


	Node *temp=searchNode(root,-10);
	cout<<temp->data<<endl;
	
	deleteNode(temp,-10);
	cout<<temp->data<<endl;
	updateNode(root,-9,-50);
	cout<<temp->data<<endl;


	return 0;
}