//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

//This function divides the string according to comma and returns value after "count" commas from passed string
string divide_str(string s, int count) {
	string str = "";
	for (int count2 = 0, counter = 0; count2 < count; count2++) {
		str = "";
		for (; s[counter] != 0 && s[counter] != ','; counter++)
			str += s[counter];
		counter++;
	}
	//cout << s << " " << count << " " << str << endl;
	return str;
}


template <typename Type>
struct LinkedList {
	template <typename TypeValue>
	struct Node {
		TypeValue value;
		Node<TypeValue>* Next;
	};
	int Length = 0;
	Node<Type>* Head = NULL;
	//Insert val in the LinkedList
	void insert(Type val) {
		if (Head == NULL) {
			Node<Type>* New = new Node<Type>;
			New->value = val;
			Head = New;
			Head->Next = NULL;
			//cout << "Head: " << New->value << endl;
		}
		else {
			Node<Type>* temp = Head;
			while (temp->Next != NULL) {
				temp = temp->Next;
			}
			Node<Type>* New = new Node<Type>;
			New->value = val;
			temp->Next = New;
			New->Next = NULL;
			//cout << "Tail: " << New->value << endl;
		}
		Length++;
	}

	//This function returns value at i'th index
	Type& get(int Index) {
		if (Head == NULL) {
			Type ret_val;
			return ret_val;
		}
		Node<Type>* temp = Head;
		for (int counter = 0; temp != NULL && counter < Index; counter++) {
			temp = temp->Next;
		}
		if (temp != NULL) {
			return temp->value;
		}
	}

	void display() {
		Node<Type>* temp = Head;
		//cout << temp->value << endl;
		cout << divide_str(temp->value, 3) << ",";
		while (temp->Next != NULL) {
			temp = temp->Next;
			//cout << temp->value << endl;
			cout << divide_str(temp->value, 3) << ",";
		}
		cout << endl;
	}
	//Function to sort the list based on course code
	void sort() {
		Node<Type>* ptr = Head;
		Node<Type>* ptr2;
		Node<Type>* ptr3 = Head;
		while (ptr3->Next != nullptr) {
			ptr = Head;
			while (ptr->Next != nullptr) {
				ptr2 = ptr;
				ptr = ptr->Next;
				if (divide_str(ptr->value, 3) < divide_str(ptr2->value, 3)) {
					swap(ptr->value, ptr2->value);
				}
			}
			ptr3 = ptr3->Next;
		}
	}
	void DeleteNode(Type val) {
		Node<Type>* temp = Head, * temp2 = temp;
		if (temp->value == val) {
			Head = temp->Next;
			//delete temp;
			return;
		}
		while (temp->value != val) {
			temp2 = temp;
			temp = temp->Next;
		}
		temp2->Next = temp->Next;
		Length--;
		//delete temp;
	}
	//Function to return length of LinkedList
	int getLength() {
		return Length;
	}
	//Function to clear the list so that list can be reused with new values
	void clear() {
		Node<Type>* temp = Head;
		Node<Type>* temp2 = NULL;
		while (temp != NULL)
		{
			temp2 = temp->Next;
			//delete temp; // destroy the current node
			temp = temp2;
		}
		Head = NULL;
		Length = 0;
	}
	~LinkedList() {
		clear();
	}
};



string val_max(LinkedList<string> list, int count) {
	double max = 0.0;
	string mx = "";
	for (int counter = 0; counter < list.getLength(); counter++) {
		if (stod(divide_str(list.get(counter), count)) > max)
			mx = list.get(counter);
	}
	return mx;
}

string Label_CGPA(string val) {
	if (val >= "3.67")
		return "Excellent";
	else if (val >= "2.67")
		return "Good";
	else if (val >= "1.67")
		return "Average";
	else if (val > "1.0")
		return "Bad";
	else
		return "Worst";
}

string Label_Warning(string val) {
	if (val == "0")
		return "Excellent";
	else if (val == "1")
		return "Average";
	else
		return "Worst";
}

string Label(string grade) {
	if (grade == "A+" || grade == "A" || grade == "A-")
		return "Excellent";
	else if (grade == "B+" || grade == "B" || grade == "B-")
		return "Good";
	else if (grade == "C+" || grade == "C" || grade == "C-")
		return "Average";
	else if (grade == "D+" || grade == "D")
		return "Bad";
	else if (grade == "F" || grade == "W")
		return "Worst";
	else
		return "Unknown";
}

string process(LinkedList<string> list) {
	bool check = false, check2 = false;
	string result = "", DS_label, discard[] = {"CL118","CL217","CS118","CS217","EE182","EE227","EL227","MT104","MT119","MT224","SL101","SS101","SS111","SS113","SS122" };
	for (int counter = 0; counter < list.getLength(); counter++) {
		if (divide_str(list.get(counter), 3) == "CS201") {
			if (divide_str(list.get(counter), 2) != "Unknown" && divide_str(list.get(counter), 6) != "UK" && divide_str(list.get(counter), 6) != "FA" && divide_str(list.get(counter), 6) != "L1" && divide_str(list.get(counter), 6) != "L2" && divide_str(list.get(counter), 6) != "LL")
				check = true;
		}
	}
	if (check == false) {
		return "Not found";
	}
	else {
		for (int counter = 0; counter < list.getLength(); counter++) {
			check2 = false;
			//cout << divide_str(list.get(counter), 3) << ",";
			if (divide_str(list.get(counter), 3) == "CS201")
				DS_label = Label(divide_str(list.get(counter), 6));
			else {
				for (int count2 = 0; count2 < 15; count2++) {
					if (divide_str(list.get(counter), 3) == discard[count2]) {
						check2 = true;
						for (int count3 = counter + 1; count3 < list.getLength(); count3++) {
							if (divide_str(list.get(counter), 3) == divide_str(list.get(count3), 3)) {
								divide_str(list.get(counter), 2) < divide_str(list.get(count3), 2) ? list.DeleteNode(list.get(counter)), check = false : list.DeleteNode(list.get(count3)), check = true;
							}
						}
						break;
					}
				}
				if(check2 == true)
					result += Label(divide_str(list.get(counter), 6)) + ",";
			}
		}
		result += Label_CGPA(divide_str(val_max(list, 9), 9)) + ",";
		result += Label_Warning(divide_str(list.get(0), 10)) + ",";
		result += DS_label;
		//cout << result << endl;
	}
	return result;
}

//This function takes a File path as an input, preprocesses it and then returns a LinkedList of strings in csv format
//This function also writes the rows in a csv file i.e. preProcessed.csv
LinkedList<string> preProcessing(string FilePath) {
	LinkedList<string> list, list2;
	ifstream file;
	file.open(FilePath);
	//cout << "file: " << file.is_open() << endl;
	string s = "hello", sr_no = "0", middle = "";
	getline(file, s, '\n');
	while (!file.eof() && file.is_open()) {
		//cout << s << endl;
		getline(file, s);
		if (divide_str(s, 1) != sr_no) {
			sr_no = divide_str(s, 1);
			list2.sort();
			middle = s;
			s = process(list2);
			if (s != "Not found") {
				list.insert(s);
			}
			list2.clear();
			list2.insert(middle);
		}
		else {
			if (!s.empty())
				list2.insert(s);
		}
	}
	file.close();
	return list;
}


//This function takes path of a preprocessed csv file and loads it into LinkedList
LinkedList<string> read_csv(string FilePath) {
	LinkedList<string> list;
	ifstream file;
	file.open(FilePath);
	string s;
	getline(file, s);
	//cout << file.is_open();
	while (!file.eof()) {
		getline(file, s);
		if (!s.empty())
			list.insert(s);
	}
	return list;
}

float entropy_subtable(LinkedList<string> list, int commas) {
	float ent = 0.0, lgvalue = 0.0f;
	bool check = true;
	int count1 = 0;
	for (int counter = 0; counter < list.getLength(); counter++) {
		check = true;
		count1 = 0;
		for (int count = 0; count < counter; count++) {
			if (divide_str(list.get(counter), commas) == divide_str(list.get(count), commas)) {
				check = false;
			}
			//cout << count1 << endl;
		}
		if (check == true) {
			for (int count = counter; count < list.getLength(); count++) {
				if (divide_str(list.get(counter), commas) == divide_str(list.get(count), commas)) {
					count1++;
				}
			}
			lgvalue = count1;
			lgvalue /= list.getLength();
			ent += (lgvalue) * log2f(lgvalue);
			//cout << ent << endl;
		}
	}
	return ent;
}


//This function takes any specific Feature and calculate Entropy.
float calculateEntropyOnFeature(LinkedList<string> Dataset, int FeatureIndex) {
	int columns = 1, count1 = 0, rows = Dataset.getLength();
	float entropy = 0.0f, middle = 0.0f;
	string s = Dataset.get(0), * Feature = new string[rows];
	for (int counter = 0; counter < s.length(); counter++) {
		s[counter] == ',' ? columns++ : columns = columns;
	}
	for (int counter = 0; counter < rows; counter++) {
		Feature[counter] = divide_str(Dataset.get(counter), FeatureIndex + 1);
	}
	bool check = true;
	LinkedList<string> list;
	for (int counter = 0; counter < rows; counter++) {
		check = true;
		count1 = 0;
		for (int count = 0; count < counter; count++) {
			if (Feature[count] == Feature[counter]) {
				check = false;
			}
		}
		if (check == true) {
			for (int count = counter; count < rows; count++) {
				if (Feature[count] == Feature[counter]) {
					count1++;
					list.insert(Dataset.get(count));
				}
			}
			middle = count1;
			middle /= rows;
			entropy += (middle) * entropy_subtable(list, columns);
			list.clear();
		}
	}
	//cout << entropy << endl;
	return -1 * entropy;
}



//This function takes Labels as an input and calculate Total Entropy.
float calculateTotalEntropy(LinkedList<string> Dataset) {
	int count1 = 0, columns = 1;
	bool check = true;
	float entropy = 0.0f, middle = 0.0f;
	string s = Dataset.get(0);
	for (int counter = 0; counter < s.length(); counter++) {
		s[counter] == ',' ? columns++ : columns = columns;
	}
	for (int counter = 0; counter < Dataset.getLength(); counter++) {
		check = true;
		count1 = 0;
		for (int count = 0; count < counter; count++) {
			if (divide_str(Dataset.get(counter), columns) == divide_str(Dataset.get(count), columns)) {
				check = false;
			}
		}
		if (check == true) {
			for (int count = counter; count < Dataset.getLength(); count++) {
				if (divide_str(Dataset.get(counter), columns) == divide_str(Dataset.get(count), columns)) {
					count1++;
				}
			}
			middle = count1;
			middle /= Dataset.getLength();
			entropy += middle * log2f(middle);
		}
	}
	return -1 * entropy;
}


//Data Structure to maintain Nodes in a Tree
template<typename T>
struct treeNode {
	treeNode<T>** left;
	treeNode<T>** right;
	T value;
	treeNode(int left_child, int right_child) {
		left = new treeNode<T>[left_child];
		right = new treeNode<T>[right_child];
	}
};

//Data Structure to maintain Tree for training, predictions and traversal
template <typename T>
struct Tree {
private:
	treeNode<T>* root;
public:

	void build_tree(LinkedList<T> trainDataset, int start, int WindowSize) {

	}

	//Takes a testDataset and rowIndex as input and returns a potential string i.e. 'Good'
	T predictOne(LinkedList<T> testDataset, int rowIndex) {
		return "                                                                   ";
	}

	//Takes a testDataset as input and returns a potential predictions as LinkedList<string> i.e. {'Good','Excellent','Notfound'}
	LinkedList<T> predictAll(LinkedList<T> testDataset) {
		LinkedList<T> ret_list;
		T val = "Completely default dummy value";
		for (int counter = 0; counter < 25; counter++)
			ret_list.insert(val);
		return ret_list;
	}

	//This function computes accuracy after training
	float accuracy(LinkedList<T> testDataset) {
		return -1;
	}

	//This function returns string in csv format i.e. "1,16,2,9" after traversing in preOrder fashion.
	//Check Test Case for better understanding of output
	string preOrderTraversal() {
		return "                                                                   ";


	}

	//This function returns string in csv format i.e. "1,16,2,9" after traversing in inOrder fashion
	//Check Test Case for better understanding of output
	string inOrderTraversal() {
		return "                                                                   ";


	}

	//This function returns string in csv format i.e. "1,16,2,9" after traversing in postOrder fashion
	//Check Test Case for better understanding of output
	string postOrderTraversal() {
		return "                                                                   ";


	}
};


//Data Structure to maintain Multiple Trees for training and predictions
template <typename T>
struct Forest {

	//Constructor to set some data members
	Forest(int NTrees, int WindowSize, int stepSize) {

	}

	//This function calls train on each tree individually by following the sliding window logic and keeps track of those trees.
	void build_forest(LinkedList<T> trainDataset) {

	}

	//This function takes predictions on 1 entry of testDataset from all Trees and then merge them together,
	//and only gives those entries whose occurence is maximum in that list and return that.
	LinkedList<T> predictOne(LinkedList<T> testDataset, int rowIndex) {
		LinkedList<T> ret_list;
		T val = "Completely default dummy value";

		for (int counter = 0; counter < 25; counter++)
			ret_list.insert(val);
		return ret_list;
	}

	//This function takes predictions on all entries of testDataset from all Trees and then merge them together,
	//and only gives those entries whose occurence is maximum in that list and return that.
	LinkedList<LinkedList<T>> predictAll(LinkedList<T> testDataset) {
		LinkedList<LinkedList<T>> ret_list;
		LinkedList<T> insrt;
		T val = "Completely default dummy value";
		for (int counter = 0; counter < 25; counter++)
			insrt.insert(val);
		for (int counter = 0; counter < 25; counter++)
			ret_list.insert(insrt);
		return ret_list;
	}


	float accuracy(LinkedList<T> testDataset) {
		return -1;
	}

};

