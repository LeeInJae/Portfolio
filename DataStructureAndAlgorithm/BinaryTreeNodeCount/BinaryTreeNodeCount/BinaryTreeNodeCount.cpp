// BinaryTreeNodeCount.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <queue>
#include <iostream>

struct Node{
	Node * leftNode;
	Node * rightNode;
	int data;
};

Node * AddNode(){
	Node * newNode = new Node;
	return newNode;
}

void MakeTree(Node * root){
	root->data = 0;
	
	root->leftNode = AddNode();
	(root->leftNode)->data = 1;
	
	root->rightNode = AddNode();
	(root->rightNode)->data = 2;
	
	root->leftNode->leftNode = AddNode();
	(root->leftNode->leftNode)->data = 3;

	root->leftNode->leftNode->leftNode = nullptr;
	root->leftNode->leftNode->rightNode = nullptr;
	root->leftNode->rightNode = nullptr;
	root->rightNode->leftNode = nullptr;
	root->rightNode->rightNode = nullptr;
}

void DeleteTree(Node * root){
	if (root == nullptr)
		return;

	DeleteTree(root->leftNode);
	DeleteTree(root->rightNode);
	delete root;
}

int SearchNodeNumber(Node * root, int * nodeNumber){
	if (root == nullptr){
		*nodeNumber = *nodeNumber - 1;
		return -1;
	}
	 
	*nodeNumber = *nodeNumber + 1;
	int temp1 = SearchNodeNumber(root->leftNode, nodeNumber) + 1;
	*nodeNumber = *nodeNumber + 1;
	int temp2 = SearchNodeNumber(root->rightNode,nodeNumber) + 1;

	if (temp1 > temp2){
		return temp1;
	}
	return temp2;
}

void TreeBfs(Node * root){
	std::queue<Node*> nodeQueue;
	nodeQueue.push(root);
	while (!nodeQueue.empty()){
		Node * node = nodeQueue.front();
		nodeQueue.pop();
		printf("%d ", node->data);

		if (node->leftNode != nullptr){
			nodeQueue.push(node->leftNode);
		}
		if (node->rightNode != nullptr){
			nodeQueue.push(node->rightNode);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	Node * root = new Node;
	int * nodeNumber = new int;
	*nodeNumber = 1;

	MakeTree(root);
	
	int height = SearchNodeNumber(root, nodeNumber);
	printf("Hegiht = %d  ,  nodeNumber = %d\n",height, *nodeNumber);
	printf("Tree Bfs 출력\n");
	TreeBfs(root);
	DeleteTree(root);
	getchar();
	return 0;
}