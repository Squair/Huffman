#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> //find
#include <map> 
#include "BinaryTree.h"

using namespace std;

class SymbolFreq {
public:
	SymbolFreq();
	~SymbolFreq();
	void setFilePath(string path);
	string getFilePath();
	void readFile(string filePath);
	void countLetters();
	vector<BinaryTreeNode*> loadFrequencies();


private:

	string filePath;
	ifstream toCompress;
	string fileData;

	multimap<int, char>* sortedLetterFreq;
};