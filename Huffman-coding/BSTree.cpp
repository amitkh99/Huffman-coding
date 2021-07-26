#include "BSTree.h"

namespace BStree {
	BSTree::BSTree(BSTreeNode* _root , int _size ) {
		root = _root;
		size = _size;
	}

	//adds data to a binary tree from a file
	void BSTree::AddDataFromFile(char* nameFile) {
		char val;
		ifstream infile(nameFile);
		if (!infile.is_open()) {
			cout << "input invalid" << endl;
			exit(1);
		}

		infile.get(val);
		while (!infile.eof()) {
			if (!infile.good()) {
				cout << "input invalid" << endl;
				exit(1);
			}
			Insert(val);
			infile.get(val);
		}
		infile.close();
	}


	BSTreeNode* BSTree::Find(char k) {
		BSTreeNode* temp = root;
		
		while (temp!=nullptr)
		{
			if (k == (temp->value).key) {
				return temp;
			}
			else if (k < (temp->value).key) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return nullptr;
	}

	void BSTree::Insert(char k) {
		BSTreeNode* temp = Find(k);
		if (temp != nullptr) {
			temp->value.freq++;
			return;
		}
		else {
			temp = root;
			BSTreeNode* parent = nullptr;
			BSTreeNode* NewNode = new BSTreeNode(k);
			while (temp != nullptr) {
				parent = temp;
				if (k < (temp->value).key)
					temp = temp->left;
				else
					temp = temp->right;
			}
			if (parent == nullptr)
				root = NewNode;
			else if (k < (parent->value).key)
				parent->left = NewNode;
			else
				parent->right = NewNode;
			size++;
		}
	}

	bool BSTree::isEmpty() {
		if (root == nullptr)
			return true;
		else
			return false;
	}

	//creates array from binary tree
	void BSTree::makeArrFromTree(BSTreeNode* root, BSTreeNode** arr) {
		static int index = 0;
		if (root == nullptr) {
			return;
		}
		else {
			arr[index] = root;
			int i = index;
			if (root->left) {
				index++;
				makeArrFromTree(root->left, arr);
			}
			if (root->right) {
				index++;
				makeArrFromTree(root->right, arr);
			}
			arr[i]->left = nullptr;
			arr[i]->right = nullptr;
		}
		
	}

	BSTreeNode* BSTree::FindParent(char k) {
		BSTreeNode* temp = root;

		while (temp != nullptr)
		{
			if (k == (temp->left->value).key) {
				return temp;
			}
			else if (k == (temp->right->value).key) {
				return temp;
			}
			else if (k < (temp->value).key) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return nullptr;
	}

	void BSTree::Delete(char k) {
		BSTreeNode* par = FindParent(k);
		BSTreeNode* temp;
		BSTreeNode* nodeToSwap;
		if (par == nullptr) {
			temp = Find(k);
			if (temp == nullptr) {
				cout << "Dont exist" << endl;
				return;
			}
		}
		if (par->right->value.key == k) {
			temp = par->right;
		}
		else {
			temp = par->left;
		}
		if (temp->right != nullptr && temp->left != nullptr) {
			nodeToSwap = MAX(temp->left);
			BSTreeNode* currPar = FindParent(nodeToSwap->value.key);
			currPar->right = nodeToSwap->left;
			nodeToSwap->left = par->left;
			nodeToSwap->right = par->right;
			if (par->left == temp)
				par->left = nodeToSwap;
			else if (par->right == temp)
				par->right = nodeToSwap;
			delete temp;
		}
		else {
			if (temp->left) {
				if (par->left == temp)
					par->left = temp->left;
				else
					par->right = par->left;
			}
			else {
				if (par->left == temp)
					par->left = temp->right;
				else
					par->right = par->right;
			}
		}
	}

	BSTreeNode* BSTree::MAX(BSTreeNode* root) {
		BSTreeNode* temp = root;
		while (temp->right) {
			temp = temp->right;
		}
		return temp;
	}

}