#include "HuffmanTree.h"

namespace HuffTree {

	//returns the maximum depth of the tree
	int HuffmanTree::maxDepth(BSTreeNode* root) {
		if (root == NULL)
			return 0;
		else
		{
			int LDepth = 0;
			int RDepth = 0;
			if (root->getLeft()) {
				LDepth = maxDepth(root->getLeft());
			}
			if (root->getRight()) {
				RDepth = maxDepth(root->getRight());
			}
			
			if (LDepth > RDepth)
				return(LDepth + 1);
			else return(RDepth + 1);
		}
	}

	//prints Risha code and returns the weight of the encoded file
	int HuffmanTree::printCode(BSTreeNode* root, int* arr, int top) {
		int res = 0;
		if (root->getLeft()) {
			arr[top] = 0;
			res += printCode(root->getLeft(), arr, (top + 1));
		}
		if (root->getRight()) {
			arr[top] = 1;
			res += printCode(root->getRight(), arr, (top + 1));
		}
		if (isLeaf(root)) {
			if (top == 0) {
				arr[0] = 1;
				top++;
			}
			if (root->getKey() == '\n') {
			cout << "'" << "\\n" << "'" << ":";
			}
			else {
				cout << "'" << root->getKey() << "'" << ":";
			}
			printArr(arr, top);
			res += (top * root->getfreq());
		}
		return res;
	}

	void HuffmanTree::printArr(int* arr, int size) {
		for (int i = 0; i < size; i++)
			cout << arr[i];
		cout << endl;
	}

	bool HuffmanTree::isLeaf(BSTreeNode* root) {
		if (root->getLeft() == nullptr && root->getRight() == nullptr)
			return true;
		else
			return false;
	}

	//sends to a method that prints Risha code and finally prints the weight of the encoded file
	void HuffmanTree::PrintHuffmanCode() {
		int size = maxDepth(getRoot());
		int* num_arr = new int[size];
		size = printCode(getRoot(), num_arr);
		cout << "Encoded file weight: " << size << endl;
		delete[] num_arr;
	}
}