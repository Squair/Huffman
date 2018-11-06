#include "SymbolFreq.h"



SymbolFreq::SymbolFreq()
{
	this->sortedLetterFreq = new multimap<int, char>;
}

SymbolFreq::~SymbolFreq()
{
	delete this->sortedLetterFreq;
}

void SymbolFreq::setFilePath(string path)
{
	this->filePath = path;
}

string SymbolFreq::getFilePath()
{
	return this->filePath;
}

void SymbolFreq::readFile(string filePath)
{
	ifstream toCompress;

	toCompress.open(filePath);
	getline(toCompress, this->fileData);

	toCompress.close();
}

void SymbolFreq::countLetters()
{
	map<char, int>* letterFreq = new map<char, int>;
	string fileData = this->fileData;

	for (int i = 0; i < fileData.length(); i++) {
		map<char, int>::iterator it = letterFreq->find(fileData[i]);
		if (it != letterFreq->end()) {
			it->second += 1; //If character is already in map, add one to frequency.
		}
		else {
			letterFreq->insert(make_pair(fileData[i], 1)); //Otherwise create a new pair for that character.
		}
	}

	for (map<char, int>::iterator it = letterFreq->begin(); it != letterFreq->end(); ++it) {
		sortedLetterFreq->insert(make_pair(it->second, it->first)); //Switch pair around for sorting
	}
	delete letterFreq;


}

vector<BinaryTreeNode*> SymbolFreq::loadFrequencies()
{
	vector<BinaryTreeNode*> nodes;
	for (map<int, char>::reverse_iterator it = sortedLetterFreq->rbegin(); it != sortedLetterFreq->rend(); ++it) { //Iterate backwards for descending order.
		BinaryTreeNode* node = new BinaryTreeNode;
		node->value = it->first;
		node->letter = it->second;
		node->left = NULL;
		node->right = NULL;
		nodes.push_back(node);
		//cout << it->first << " : " << it->second << endl;
	}
	return nodes;
}

