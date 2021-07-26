#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <stdlib.h>
#include "BSTree.h"
#include "Heap.h"
#include "HuffmanTree.h"

using namespace std;
using namespace BStree;
using namespace HuffTree;


int main() {
	char nameFile[128];
	cin >> nameFile;
	BSTree BStree;
	BStree.AddDataFromFile(nameFile);
	Heap minHeap(BStree);
	HuffmanTree huffman(minHeap.MakeHuffmanTree());
	huffman.PrintHuffmanCode();

	return 1;
}




	