#pragma once
#include <fstream>
#include "BSTreeNode.h"



using namespace std;

namespace BStree {

	class BSTree{
	private:
		BSTreeNode* root;
		int size;
	public:
		BSTree(BSTreeNode* root = nullptr, int _size = 0);
		~BSTree() {}
		BSTreeNode* Find(char k);
		BSTreeNode* FindParent(char k);
		void Insert(char k);
		bool isEmpty();
		void Delete(char k);
		BSTreeNode* MAX(BSTreeNode* root);
		BSTreeNode* getRoot() { return root; }
		int getSize() { return size; }
		void makeArrFromTree(BSTreeNode* root, BSTreeNode** arr);
		void AddDataFromFile(char* nameFile);

		
	};

	

}