//====================================
// Algorithm & Data Structure Analysis
// Student: Raj Pravin Patel
// Student ID: a1809073
// Semester: 2
// Year: 2022
// Assignment: 2
//=====================================

//Importing libraries.
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <functional>

using namespace std;
int isEmpty = 0;

struct Node{

    //Attributes
    int Data;
    Node* Left;
    Node* Right;
    int TreeHeight;

    //functions for Node
	int height(Node*);
	Node* insertChild(Node*, int);
	Node* insertRoot(Node*, int);
	Node* deleteNode(Node*, int);
	Node* right_rotation(Node*);
	Node* left_rotation(Node*);
	int balanceTree(Node*);
	Node* getMaxLeftNode(Node*);
	Node* decideRotation(Node*, int, int, char);
	void printPreOrder(Node*);
	void printInOrder(Node*);
	void printPostOrder(Node*);
};

//get node Height
int height(Node* root){
    if(root!=NULL)
        return root->TreeHeight;
    else
        return 0;
}

//Get root node
Node* getRootNode(Node* newNode , int data){
    newNode = new Node();
    newNode->Data = data;
    newNode->Left,newNode->Right = NULL;
    newNode->TreeHeight = 1;
    return newNode;
}

//get max child from root->Left and traverse right child
Node* getMaxLeftNode(Node* root){
    Node* temp = root;
    while(temp->Right!=NULL)
        temp = temp->Right;
    return temp;
}


//check degree of node to get balanceFactor
int balanceTree(Node* root){
	if(root != NULL){
        //no child
		if(root->Left == NULL && root->Right == NULL)
			return 0;
        //no Left child 
		else if(root->Left == NULL && root->Right !=NULL)
			return 0-height(root->Right);
        //no right child
		else if(root->Left !=NULL && root->Right == NULL)
			return height(root->Left)-0;
        //if both child present calculate the balance factor left - right
		else
			return (height(root->Left)- height(root->Right));
	}
	return 0;
}


//RIghtRotation
Node* right_rotation(Node* root){
	Node* root_left = root->Left;
	Node* left_right = root_left->Right;

	root_left->Right = root;
	root->Left = left_right;

	//height of tree
	if(root!=NULL || root->Left!=NULL || root->Right!=NULL)
		root->TreeHeight = ((height(root->Left) > height(root->Right)) ? height(root->Left) : height(root->Right))+1;

	if(root_left!=NULL || root_left->Left!=NULL || root_left->Right!=NULL)
		root_left->TreeHeight = ((height(root_left->Left) > height(root_left->Right)) ? height(root_left->Left) : height(root_left->Right))+1;
	
    //new root
	return root_left;
}

//left rotation of node
Node* left_rotation(Node* root){
	Node* root_right = root->Right;
	Node* right_left = root_right->Left;

	root_right->Left = root;
	root->Right = right_left;

	//height of tree
	if(root!=NULL || root->Left!=NULL || root->Right!=NULL)
		root->TreeHeight = ((height(root->Left) > height(root->Right)) ? height(root->Left) : height(root->Right))+1;

	if(root_right!=NULL || root_right->Left!=NULL || root_right->Right!=NULL)
		root_right->TreeHeight = ((height(root_right->Left) > height(root_right->Right)) ? height(root_right->Left) :  height(root_right->Right))+1;

	//new root
	return root_right;
}

Node* decideRotation(Node* root, int balHeight, int value, char inODel){
	if(inODel == 'A'){
		//left left edges need right rotation
		if(balHeight >1 && value < root->Left->Data){
			return right_rotation(root);
		}
		//right left edges refire left right rotation
		if(balHeight >1 && value > root->Left->Data){
			root->Left = left_rotation(root->Left);
			return right_rotation(root);
		}
		//right right edges need left roation
		if(balHeight < -1 && value > root->Right->Data){
			return left_rotation(root);
		}
		//right left edges need left right rotation
		if(balHeight < -1 && value < root->Right->Data){
			root->Right = right_rotation(root->Right);
			return left_rotation(root);
		}
		
	}else if(inODel == 'D'){
		//left left edges need right rotation
		if(balHeight >1 && balanceTree(root->Left)>=0){
			return right_rotation(root);
		}
		//left right edges require left and right rotation
		if(balHeight >1 &&  balanceTree(root->Left)<0){
			root->Left = left_rotation(root->Left);
			return right_rotation(root);
		}
		//right right edges need left roation
		if(balHeight < -1 && balanceTree(root->Right)<=0){
			return left_rotation(root);
		}
		//right left edges need left right rotation
		if(balHeight < -1 && balanceTree(root->Right)>0){
			root->Right = right_rotation(root->Right);
			return left_rotation(root);
		}
		
	}
	return root;
}


// insert the node 
Node* insertNode(Node* root, int data){

    //insert root node
    if(root==NULL){
        return (getRootNode(root , data));
    }

    //insert node to the left of the root
    if(data<root->Data){
        root->Left = insertNode(root->Left,data);
    }

    //insert node to the right of the root
    else if(data > root->Data){
        root->Right = insertNode(root->Right , data);
    }
    //if the data is already there ignore 
    else{
        return root;
    }

    //update the height of the node
    if(root!=NULL){
        root->TreeHeight = ((height(root->Left) > height(root->Right))? height(root->Left) : height(root->Right))+1;
    }

    //get balance factor after insertion
    int balanceHeight = balanceTree(root);

    //rotate the tree 
    return decideRotation(root,balanceHeight,data,'A');

}


//delete the node
Node* deleteNode(Node* root , int data){
    
    //if it tree is empty
    if(root==NULL){
        return root;
    }
    
    //find the data on the left of tree
    if(data < root->Data)
        root->Left = deleteNode(root->Left , data);
    //find data on the right of the tree
    else if(data > root->Data)
        root->Right = deleteNode(root->Right , data);
    //if data point found in tree
    else if(data==root->Data){
        //if no child for the node to be deleted
        if(root->Left ==NULL && root->Right ==NULL)
            root = NULL;
        //if no left chils
        else if(root->Left==NULL && root->Right!=NULL)
            root = root->Right;
        //if no right child
        else if(root->Left!=NULL && root->Right==NULL)
            root = root->Left;
        
        //if there are two child 
        else{
            Node* temp = getMaxLeftNode(root->Left);
            root->Data = temp->Data;
            root->Left = deleteNode(root->Left , temp->Data);
        }
    }
    //update the height of node
    if(root!=NULL)
        root->TreeHeight = ((height(root->Left) > height(root->Right))? height(root->Left) : height(root->Right))+1;

    //get balancefactor
    int balanceHeight = balanceTree(root);
    //update the rotation of the tree
    return decideRotation(root,balanceHeight, data,'D');

}




// Inorder Traversal
void inorder(Node *root) {
  if (root!=NULL){
    // left child
    inorder(root->Left);
    //root
    cout << root->Data << " ";
    // right child
    inorder(root->Right);
  }
}

void preorder(Node *root){
  if (root!=NULL){
    //root
    cout << root->Data << " ";
    //left child
    preorder(root->Left);
    //right child
    preorder(root->Right);
  }
}

void postorder(Node *root){
  if (root!=NULL){
    //left child
    postorder(root->Left);
    //right child
    postorder(root->Right);
    //root
    cout << root->Data << " ";
  }
}


int main(){
    string decision,order;
    int value;
    Node* root = NULL;
    // root->TreeHeight = 1;
    char input[100000];
    vector<char*> v;
    //read data from the terminal 
    cin.getline(input, 100000);
    //split the input data based on " " to get I1,I2,Base
	char* chars_array = strtok(input, " ");
    while(chars_array)
    {
		//input the I1,I2,D1,D2... into vector v
        v.push_back(chars_array);
		// proceed till ther is no token
		chars_array = strtok(NULL, " ");
    }
    //check if to add or deleteA
	for(unsigned int i=0;i<v.size()-1;i++){
        // cout << v[i] << " ";
		decision=v[i];
		value = stoi(decision.substr(1, decision.size()-1));
		if(decision[0]== 'A'){
    //   cout << "Inserting: " << value << endl;
			root= insertNode(root, value);
    //   cout << "height -->" << root->nodeHeight; 
    //   cout << endl;
		}else{
			root = deleteNode(root, value);
		}
	}
    //take order to print
	order = v[v.size()-1];
    if(root==NULL){
        cout<<"EMPTY";
    }
    else{
        if(order=="IN")
            inorder(root);
        else if(order == "PRE")
            preorder(root);
        else if(order=="POST")
            postorder(root);
    }
    // printTree(root, "" , false);

}
