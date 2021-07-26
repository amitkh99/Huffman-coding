#pragma once

#include "Heap.h"

using namespace std;
using namespace BStree;

namespace HuffTree {

	class HuffmanTree
	{
	public:
		HuffmanTree(BSTreeNode* _root = nullptr) : root(_root) {}
	
		~HuffmanTree() {};
		bool isLeaf(BSTreeNode* root);
		int maxDepth(BSTreeNode* root);
		int printCode(BSTreeNode* root,int* arr, int top = 0);
		BSTreeNode* getRoot() { return root; }
		void printArr(int* arr, int size);
		void PrintHuffmanCode();
	private:
		BSTreeNode* root;
	};

	

	
}