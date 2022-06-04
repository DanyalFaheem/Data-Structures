#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

template <typename Type>
struct LinkedList{
    template <typename TypeValue>
	struct Node{
		TypeValue value;
		Node<TypeValue>* Next;
	};
	int Length=0;
	Node<Type>* Head=NULL;
	//Insert val in the LinkedList
	void insert(Type val){
		if(Head == NULL) {		
			Node<Type>* New = new Node<Type>;
			temp->value = val;
			Head = New;
			Head->Next = NULL;
		}
		else {
			Node<Type>* temp = Head;
			while(temp->Next != NULL) {
				temp = temp->Next;
			}
			Node<Type>* New = new Node<Type>;
			New->value = val;
			temp->Next = New;
			New->Next = NULL;
		}
		Length++;
	}

	//This function returns value at i'th index
	Type& get(int Index){
		Node<Type>* temp = Head;
		for(int counter = 0; temp != NULL && counter < Index; counter++) {
			temp = temp->Next;
		}
		return temp == NULL ? "Not found" : temp->value;
	}

	void display(){
		Node<Type>* temp = Head;
		cout << temp->value << endl;
		while(temp->Next != NULL) {
			temp = temp->Next;
			cout << temp->value << endl;
		}
	}
	//Function to sort the list based on course code
	void sort() {
			Node<Type>* ptr = Head;
			Node<Type>* ptr2;
			Node<Type>* ptr3 = Head;
			while (ptr3->Next != nullptr) {
				ptr = head;
				while (ptr->Next != nullptr) {
					ptr2 = ptr;
					ptr = ptr->Next;
					if (divide_str(ptr->value, 3) < divide_str(ptr->value, 3)) {
						swap(ptr->value, ptr2->value);
					}
				}
				ptr3 = ptr3->next;
			}
	}
	//Function to return length of LinkedList
	int getLength(){
		return Length;
	}
	//Function to clear the list so that list can be reused with new values
	void clear() {
		Node<Type>* temp = Head;
   		Node<Type>* temp2 = NULL;
   		while (temp != NULL)
		{
			temp2  =  temp->next;
			delete temp; // destroy the current node
			temp  =  temp2;
		}
		Head = NULL;
		Length = 0;
	}
	~LinkedList() {
		clear();
	}
};

//This function takes a File path as an input, preprocesses it and then returns a LinkedList of strings in csv format
//This function also writes the rows in a csv file i.e. preProcessed.csv
LinkedList<string> preProcessing(string FilePath){
	ifstream file;
	file.open(FilePath);
	LinkedList<string> list, list2;
	string s, sr_no = "0";
	getline(file, s);
	while(!file.eof()) {
		getline(file, s);
		if(divide_str(s, 1) != sr_no) {
			sr_no = divide_str(s, 1);
			list2.sort();
			s = process(list2);
			if(s != "Not found") {
				list.insert(s);
			}  
			list2.clear();
		}
		else {
			if(!s.empty())
				list2.insert(s);
		}
	}
	file.close();
	return list;
}

//This function divides the string according to comma and returns value after "count" commas from passed string
string divide_str(string s, int count) {
	string str = "";
	for(int count2 = 0, counter = 0; count2 < count; count2++) {
		str = "";
		for(; s[counter] != 0 && s[counter] != ','; counter++)
			str += s[counter];	
	}
	return str;	
}

string process(LinkedList<string> list) {
	bool check = false;
	string result = "", DS_label;
	for(int counter = 0; counter < list.getLength(); counter++) {
		if(divide_str(list.get(counter), 3) == "CS201") {
			if(divide_str(list.get(counter), 2) != "Unknown" && divide_str(list.get(counter), 6) != "UK")
				check = true;
		}
 	}
	if(check == false) {
		return "Not found";
	}
	else {
		for(int counter = 0; counter < list.getLength(); counter++) {
			if(divide_str(list.get(counter), 3)) == "CS201") 
				DS_label = Label(divide_str(list.get(counter), 6));
			else
			result += Label(divide_str(list.get(counter), 6)) + ",";
		}
		result += Label_CGPA(divide_str(list.get(0), 9)) + ",";
		result += Label_Warning(divide_str(list.get(0), 10)) + ",";
		result += DS_label;
	}
	return result;
}

string CGPA_sort(string max, string CGPA) {
	string year = "";
	int counter = 0;
	for(; CGPA[counter] != " "; counter++) 
	for(; counter < CGPA.length(); counter++)
		year += CGPA[counter];
	return max;
}

string Label_CGPA(string val) {
	if(val >= "3.67") 
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
		if(val == 0) 
		return "Excellent";
	else if (val == 1) 
		return "Average";
	else
		return "Worst";
}

string Label(string grade) {
	if(grade == "A+" || grade == "A" || grade == "A-") 
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



//This function takes path of a preprocessed csv file and loads it into LinkedList
LinkedList<string> read_csv(string FilePath){
	LinkedList<string> list;
	ifstream file;
	file.open(FilePath);
	string s;
	getline(file, s);
	while(!file.eof()) {
		getline(file, s);
		if(!s.empty())
			list.insert(s);
	}
	return list;
}

//This function takes any specific Feature and calculate Entropy.
float calculateEntropyOnFeature(LinkedList<string> Dataset , int FeatureIndex){
	int columns = 1, rows = Dataset.getLength(), count1 = 0;
	float entropy = 0.0;
	string s = Dataset.get(0), Feature[rows];
	for(int counter = 0; counter < s.length(); counter++) {
		s[counter] == ',' ? columns++ : columns = columns;
	}
	for(int counter = 0; counter < rows; counter++) {
		Feature[counter] = divide_str(Dataset.get(counter), FeatureIndex);
	}
	bool check = true;
	LinkedList list;
	for(int counter = 0; counter < rows; counter++) {
		check = true;
		count1 = 0;
		for(int count = 0; count < counter; count++) {
			if(Feature[count] == Feature[counter]) {
				check = false;
			}
		}
		if(check == true) {
			for(int count = counter; count < rows; count++) {
				if(Feature[count] == Feature[counter]) {
					count1++;
					list.insert(Dataset.get(count));
				}
			}
			entropy += (count1/rows) * entropy_subtable(list, columns - 1);
			list.clear();
		}
	}
	return -1 * entropy;
}

float entropy_subtable(LinkedList<string> list, int commas) {
	string s;
	float ent = 0.0;
	bool check = true;
	int count1 = 0;
	for(int counter = 0; counter < list.getLength(); counter++) {
		check = true;
		count1 = 0;
		for(int count = 0; count < counter; count++) {
			if(divide_str(list.get(counter), commas) == divide_str(list.get(count), commas)) {
				check = false;
			}
		}
		if(check == true) {
			for(int count = counter; count < list.getLength(); count++) {
				if(divide_str(list.get(counter), commas) == divide_str(list.get(count), commas)) {
					count1++;
				}
			}
			ent += (count1/list.getLength()) * (log2f(count1/list.getLength()));
		}
	}
	return ent;
}

//This function takes Labels as an input and calculate Total Entropy.
float calculateTotalEntropy(LinkedList<string> Dataset){

}

//Data Structure to maintain Nodes in a Tree
template<typename T>
struct treeNode{

};

//Data Structure to maintain Tree for training, predictions and traversal
template <typename T>
struct Tree{

	void build_tree(LinkedList<T> trainDataset, int start, int WindowSize){

	}

	//Takes a testDataset and rowIndex as input and returns a potential string i.e. 'Good'
	T predictOne(LinkedList<T> testDataset, int rowIndex){

	}

	//Takes a testDataset as input and returns a potential predictions as LinkedList<string> i.e. {'Good','Excellent','Notfound'}
	LinkedList<T> predictAll(LinkedList<T> testDataset){

	}

	//This function computes accuracy after training
	float accuracy(LinkedList<T> testDataset){
		
	}

	//This function returns string in csv format i.e. "1,16,2,9" after traversing in preOrder fashion.
	//Check Test Case for better understanding of output
	string preOrderTraversal(){

	}

	//This function returns string in csv format i.e. "1,16,2,9" after traversing in inOrder fashion
	//Check Test Case for better understanding of output
	string inOrderTraversal(){

	}

	//This function returns string in csv format i.e. "1,16,2,9" after traversing in postOrder fashion
	//Check Test Case for better understanding of output
	string postOrderTraversal(){

	}
};


//Data Structure to maintain Multiple Trees for training and predictions
template <typename T>
struct Forest{

	//Constructor to set some data members 
	Forest(int NTrees,int WindowSize, int stepSize){

	}

	//This function calls train on each tree individually by following the sliding window logic and keeps track of those trees.
	void build_forest(LinkedList<T> trainDataset){

	}

	//This function takes predictions on 1 entry of testDataset from all Trees and then merge them together, 
	//and only gives those entries whose occurence is maximum in that list and return that.
	LinkedList<T> predictOne(LinkedList<T> testDataset, int rowIndex){

	}

	//This function takes predictions on all entries of testDataset from all Trees and then merge them together, 
	//and only gives those entries whose occurence is maximum in that list and return that.
	LinkedList<LinkedList<T>> predictAll(LinkedList<T> testDataset){

	}

	
	float accuracy(LinkedList<T> testDataset){

	}

};

