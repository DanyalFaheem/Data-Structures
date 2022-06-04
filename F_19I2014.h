#pragma once

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
struct CCID_NODE {
	CCID_NODE<T>* first, * next, * previous;
	string CNIC, crime, punishment, fine;
	CCID_NODE() {
		first = next = previous = nullptr;
	}
};

template <class T>
class CCID {
	CCID_NODE<T>* head;
	CCID_NODE<T>* tail;
public:
	CCID() {
		head = tail = nullptr;
	}
	void insert_CCID(CCID_NODE<T>* n) {
		//CCID_NODE<T>* n = data;
		if (head == nullptr) {
			tail = head = n;
			n->first = head;
			n->next = nullptr;
			n->previous = nullptr;
		}
		else {
			CCID_NODE<T>* temp = tail;
			tail->next = n;
			n->first = head;
			n->previous = tail;
			tail = n;
			n->next = head;
		}
	}
	void Sort_CCID() {
		CCID_NODE<T>* ptr = head;
		CCID_NODE<T>* ptr2;
		CCID_NODE<T>* ptr3 = head;
		while (ptr3->next != head) {
			ptr = head;
			while (ptr->next != head) {
				ptr2 = ptr;
				ptr = ptr->next;
				if (ptr->CNIC < ptr2->CNIC) {
					swap(ptr->crime, ptr2->crime);
					swap(ptr->punishment, ptr2->punishment);
					swap(ptr->fine, ptr2->fine);
					swap(ptr->CNIC, ptr2->CNIC);
				}
			}
			ptr3 = ptr3->next;
		}
	}
	void display() {
		CCID_NODE<T>* temp = head;
		while (temp->next != head) {
			cout << temp->CNIC + temp->crime + temp->punishment + temp->fine << endl;
			temp = temp->next;
		}
	}
	CCID_NODE<T>* gethead() {
		return head;
	}
};

template <class T>
struct CCND_NODE {
	CCND_NODE<T>* next, * previous, * last;
	string CNIC, network, Date, status, number;
	CCND_NODE() {
		next = previous = last = nullptr;
	}
};

template <class T>
class CCND {
	CCND_NODE<T>* head;
	CCND_NODE<T>* tail;
public:
	CCND() {
		head = tail = nullptr;
	}
	void insert_CCND(CCND_NODE<T>* n) {
		if (head == nullptr) {
			tail = head = n;
			n->next = nullptr;
			n->previous = nullptr;
		}
		else {
			CCND_NODE<T>* temp = tail;
			tail->next = n;
			n->previous = tail;
			tail = n;
			n->next = head;
		}
	}
	void Sort_CCND() {
		CCND_NODE<T>* ptr = head;
		CCND_NODE<T>* ptr2;
		CCND_NODE<T>* ptr3 = head;
		while (ptr3->next != head) {
			ptr = head;
			while (ptr->next != head) {
				ptr2 = ptr;
				ptr = ptr->next;
				if (ptr->CNIC < ptr2->CNIC) {
					swap(ptr->network, ptr2->network);
					swap(ptr->Date, ptr2->Date);
					swap(ptr->status, ptr2->status);
					swap(ptr->CNIC, ptr2->CNIC);
					swap(ptr->number, ptr2->number);
				}
			}
			ptr3 = ptr3->next;
		}
	}
	void display() {
		CCND_NODE<T>* temp = head;
		while (temp->next != head) {
			cout << temp->CNIC + temp->number + temp->network + temp->Date + temp->status<< endl;
			temp = temp->next;
		}
	}
	CCND_NODE<T>* gethead() {
		return head;
	}
};

template <class T>
struct CBID_NODE {
	CBID_NODE<T>* next, * previous;
	CCND_NODE<T>* ptr_CCND;
	CCID_NODE<T>* ptr_CCID;
	string Name, F_Name, address, CNIC, nationality, gender;
	CBID_NODE() {
		previous = next = nullptr;
		ptr_CCID = nullptr;
		ptr_CCND = nullptr;
	}
};

template <class T>
class CBID {
	CBID_NODE<T>* head;
public:
	CBID() {
		head = nullptr;
	}
	void insert_CBID(CBID_NODE<T>* n) {
		//CBID_NODE<T>* n = new CBID_NODE<T>;
		//n = &data;
		CBID_NODE<T>* temp = head;
		if (head == nullptr) {
			head = n;
			head->next = nullptr;
			head->previous = nullptr;
		}
		else {
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = n;
			n->previous = temp;
			n->next = nullptr;
		}
	}
	void display() {
		CBID_NODE<T>* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
	}
	void Sort_CBID() {
		CBID_NODE<T>* ptr = head;
		CBID_NODE<T>* ptr2;
		CBID_NODE<T>* ptr3 = head;
		while (ptr3->next != nullptr) {
			ptr = head;
			while (ptr->next != nullptr) {
				ptr2 = ptr;
				ptr = ptr->next;
				if (ptr->CNIC < ptr2->CNIC) {
					swap(ptr->address, ptr2->address);
					swap(ptr->F_Name, ptr2->F_Name);
					swap(ptr->Name, ptr2->Name);
					swap(ptr->nationality, ptr2->nationality);
					swap(ptr->gender, ptr2->gender);
					swap(ptr->CNIC, ptr2->CNIC);
				}
			}
			ptr3 = ptr3->next;
		}
	}
	void remove(CBID_NODE<T>* node) {
		node->previous->next = node->next;
		//node->next->previous = node->previous;
		//delete node;
	}
	CBID_NODE<T>* gethead() {
		return head;
	}
};


template <class T>
struct DPNode {
	DPNode* next;
	T data;
};

template <class T>
class DataPipeline {
	/*	A linkedlist based queue to implement databases
		Implement additional functions as per requirement
	*/
	DPNode<T>* front;
	DPNode<T>* rear;
	int num;
public:
	DataPipeline() {
		front = rear = nullptr;
		num = 0;
	}

	T frontelement() {
		return *front;
	}
	T back() {
		return *rear;
	}

	T enqueue(T node) {
		DPNode<T>* n = new DPNode<T>;
		n->data = node;
		n->next = nullptr;
		if (is_empty() != false) {
			front = n;
			rear = n;
		}
		else {
			rear->next = n;
			rear = n;
		}
		num++;
		return n->data;
	}

	T dequeue() {
		DPNode<T>* n = new DPNode<T>;
		DPNode<T>* temp;
		n = front;
		temp = front;
			front = front->next;
		//delete temp;
		num--;
		num == 0 ? rear = nullptr : rear = rear;
		return n->data;
	}

	bool is_empty() {
		return front == nullptr && rear == nullptr ? true : false;
	}
};

template <class T>
class AD {
	/* Implement a stack for your Alien Database operations */
public:
	CBID_NODE<T>* top;
	AD() {
		top = nullptr;
	}

	void push_roll(CBID_NODE<T>* &value) {
		//CBID_NODE<T>* temp = new CBID_NODE<T>;
		//temp = &value;
		value->next = top;
		top = value;
		top->nationality = "Alien";
		top->ptr_CCND->status = "Inactive";
	}

	CBID_NODE<T>& topelement() {
		return *top;
	}

	void pop() {
		if (is_empty() != false) {
			return;
		}
		CBID_NODE<T>* temp = top;
		top = top->next;
		//delete temp;
	}

	bool is_empty() {
		return top == nullptr ? true : false;
	}

	void empty() {
		while (!is_empty()) {
			pop();
		}
	}
	void display() {
		CBID_NODE<T>* temp = top;
		cout << top->CNIC + temp->Name + temp->F_Name + temp->gender + temp->address + temp->nationality << endl;
		if(temp->ptr_CCID != nullptr)
			cout << temp->ptr_CCID->crime + temp->ptr_CCID->punishment + temp->ptr_CCID->fine << endl;
		if(temp->ptr_CCND != nullptr)
			cout << temp->ptr_CCND->number + temp->ptr_CCND->network + temp->ptr_CCND->Date + temp->ptr_CCND->status << endl;
	}
	~AD() {
		empty();
	}
};




template <class T>
class Database {

	CBID<T> list1;
	CCID<T> list2;
	CCND<T> list3;
	DataPipeline<T> dataPipeline;
	AD<T> AlienData;
public:
	Database(const T& filename, const T& filename1, const T& filename2) {
		/*
			Initialize the data from the given file and populate database
		*/
		int cbid_count = 0, ccid_count = 0, ccnd_count = 0;
		string cbid[51], ccid[11], ccnd[55];
		ifstream file1;
		file1.open(filename);
		for (; file1.eof() != true; cbid_count++) {
			getline(file1, cbid[cbid_count]);
			if (empty(cbid[cbid_count]) == true)
				break;
			dataPipeline.enqueue(cbid[cbid_count]);
		}
		file1.close();
		ifstream file2;
		file2.open(filename1);
		for (; file2.eof() != true; ccid_count++) {
			getline(file2, ccid[ccid_count]);
			dataPipeline.enqueue(ccid[ccid_count]);
		}
		file2.close();
		ifstream file3;
		file3.open(filename2);
		for (; file3.eof() != true; ccnd_count++) {
			getline(file3, ccnd[ccnd_count]);
			dataPipeline.enqueue(ccnd[ccnd_count]);
		}
		file3.close();
		while (cbid_count > 0) {
			list1.insert_CBID(createCBID(dataPipeline.dequeue()));
			cbid_count--;
		}
		while (ccid_count > 0) {
			list2.insert_CCID(createCCID(dataPipeline.dequeue()));
			ccid_count--;
		}
		while (ccnd_count > 0) {
			list3.insert_CCND(createCCND(dataPipeline.dequeue()));
			ccnd_count--;
		}
		list1.Sort_CBID();
		list2.Sort_CCID();
		list3.Sort_CCND();
		JoinNodes();
	}
	/*Return a string in following format "Name FName Gender Address Nationality Crimes(if any) Charges punishment fine number network activation_date deactivation_date status"
	 Refer to test cases for further clerification*/
	CBID_NODE<T>* createCBID(string data) {
		CBID_NODE<T>* node = new CBID_NODE<T>;
		string s[8] = { "","","","","","","","" }; 
		for (int counter = 0, index = 0; counter < data.length(); counter++) {
			s[index] += data[counter];
			//data[counter] == " " ? index = index + 1 : index = index;
			if (data[counter] == 32) {
				index++;
			}
		}
		node->CNIC = s[0];
		node->Name = s[1];
		node->F_Name = s[2];
		node->gender = s[3];
		node->address = s[4] + s[5] + s[6];
		node->nationality = s[7];
		return node;
	}
	CCID_NODE<T>* createCCID(string data) {
		CCID_NODE<T>* node = new CCID_NODE<T>;
		string s[7] = { "","","","","","","" };
		for (int counter = 0, index = 0; counter < data.length(); counter++) {
			s[index] += data[counter];
			if (data[counter] == 32) {
				index++;
			}
		}
		node->CNIC = s[0];
		node->crime = s[1];
		node->punishment = s[2] + s[3] + s[4] + s[5];
		node->fine = s[6];
		return node;
	}
	CCND_NODE<T>* createCCND(string data) {
		CCND_NODE<T>* node = new CCND_NODE<T>;
		string s[6] = { "","","","","","" };
		for (int counter = 0, index = 0; counter < data.length(); counter++) {
			s[index] += data[counter];
			//data[counter] == 32 ? index = index + 1 : index = index;
			if (data[counter] == 32) {
				index++;
			}
		}
		node->CNIC = s[0];
		node->number = s[1];
		node->network = s[2];
		node->Date = s[3] + s[4];
		node->status = s[5];
		return node;
	}
	void JoinNodes() {
		//list2.display();
		CBID_NODE<T>* temp = list1.gethead();
		CCID_NODE<T>* temp2 = list2.gethead();
		CCND_NODE<T>* temp3 = list3.gethead();
		while (temp->next != nullptr) {
			temp2 = list2.gethead();
			while (temp2->next != list2.gethead()) {
				if (temp->CNIC == temp2->CNIC) {
					temp->ptr_CCID = temp2;
					break;
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		temp = list1.gethead();
		while (temp->next != nullptr) {
			temp3 = list3.gethead();;
			while (temp3->next != list3.gethead()) {
				if (temp->CNIC == temp3->CNIC) {
					temp->ptr_CCND = temp3;
					break;
				}
				temp3 = temp3->next;
			}
			temp = temp->next;
		}
	}

	T CBID_Search_by_CNIC(T cnic) {
		CBID_NODE<T>* temp = list1.gethead();
		bool check = false;
		T result = "";
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				result += temp->Name + temp->F_Name + temp->gender + temp->address + temp->nationality + " ";
				if (temp->ptr_CCID != nullptr)
					result += temp->ptr_CCID->crime + temp->ptr_CCID->punishment + temp->ptr_CCID->fine + " ";
				temp->ptr_CCND != nullptr ? result += temp->ptr_CCND->number + temp->ptr_CCND->network + temp->ptr_CCND->Date + temp->ptr_CCND->status : result = result;
				check = true;
				break;
			}
			temp = temp->next;
		}
		return check ? result : "Not found";
	}
	T CCID_Search_by_CNIC(T cnic) {
		CBID_NODE<T>* temp = list1.gethead();
		bool check = false;
		T result = "";
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				result += temp->Name + temp->F_Name + temp->gender + temp->address + temp->nationality + " ";
				if (temp->ptr_CCID != nullptr)
					result += temp->ptr_CCID->crime + temp->ptr_CCID->punishment + temp->ptr_CCID->fine + " ";
				temp->ptr_CCND != nullptr ? result += temp->ptr_CCND->number + temp->ptr_CCND->network + temp->ptr_CCND->Date + temp->ptr_CCND->status : result = result;
				check = true;
				break;
			}
			temp = temp->next;
		}
		return check ? result : "Not found";
	}
	T CCND_Search_by_CNIC(T cnic) {
		CBID_NODE<T>* temp = list1.gethead();
		bool check = false;
		T result = "";
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				result += temp->Name + temp->F_Name + temp->gender + temp->address + temp->nationality + " ";
				if (temp->ptr_CCID != nullptr)
					result += temp->ptr_CCID->crime + temp->ptr_CCID->punishment + temp->ptr_CCID->fine + " ";
				temp->ptr_CCND != nullptr ? result += temp->ptr_CCND->number + temp->ptr_CCND->network + temp->ptr_CCND->Date + temp->ptr_CCND->status : result = result;
				check = true;
				break;
			}
			temp = temp->next;
		}
		return check ? result : "Not found";
	}

	bool updateCBIDName(T Name, T cnic) {
		/*update and return true when cnic found else return false*/
		CBID_NODE<T>* temp = list1.gethead();
		bool check = false;
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				temp->Name = Name + " ";
				check = true;
				break;
			}
			temp = temp->next;
			if ((cnic + " ") == temp->CNIC) {
				temp->Name = Name + " ";
				check = true;
				break;
			}
		}
		return check;
	}

	bool updateCBIDFName(T Father_Name, T cnic) {
		/*update and return true when cnic found else return false*/
		CBID_NODE<T>* temp = list1.gethead();
		bool check = false;
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				temp->F_Name = Father_Name + " ";
				check = true;
				break;
			}
			temp = temp->next;
			if ((cnic + " ") == temp->CNIC) {
				temp->F_Name = Father_Name + " ";
				check = true;
				break;
			}
		}
		return check;
	}

	bool updateCBIDAddress(T Address, T cnic) {
		/*update and return true when cnic found else return false*/
		CBID_NODE<T>* temp = list1.gethead();
		bool check = false;
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				temp->address = Address + " ";
				check = true;
				break;
			}
			temp = temp->next;
			if ((cnic + " ") == temp->CNIC) {
				temp->address = Address + " ";
				check = true;
				break;
			}
		}
		return check;
	}

	bool updateCBIDNationality(T Nationality, T cnic) {
		/*update and return true when cnic found else return false*/
		CBID_NODE<T>* temp = list1.gethead();
		bool check = false;
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				temp->nationality = Nationality;
				check = true;
				break;
			}
			temp = temp->next;
			if ((cnic + " ") == temp->CNIC) {
				temp->nationality = Nationality;
				check = true;
				break;
			}
		}
		return check;
	}
	bool addCrime(T cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false*/
		CBID_NODE<T>* temp = list1.gethead();
		bool check = false;
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				check = true;
				list2.insert_CCID(createCCID(cnic + " " + charges + " " + punishment + " " + fine));
				break;
			}
			temp = temp->next;
		}
		return check;
	}

	bool updateCrime(T cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false*/
		CCID_NODE<T>* temp = list2.gethead();
		bool check = false;
		while (temp->next != list2.gethead()) {
			if ((cnic + " ") == temp->CNIC) {
				temp->crime = charges;
				temp->fine = fine;
				temp->punishment = punishment;
				check = true;
				break;
			}
			temp = temp->next;
		}
		return check;
	}

	bool deleteCrime(T cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false*/
		CCID_NODE<T>* temp = list2.gethead();
		CCID_NODE<T>* temp2 = list2.gethead();
		bool check = false;
		while (temp->next != list2.gethead()) {
			if ((cnic + " ") == temp->CNIC) {
				check = true;
				temp->next->previous = temp2->previous;
				//temp->next = temp->previous = nullptr;
				return true;
			}
			temp = temp->next;
		}
		return check;
	}

	int addNumber(T cnic, T number) {
		/*return number of cell-numbers registered on given cnic after adding this number*/
		if (checkRegistred_No(cnic) > 3) {
			return -1;
		}
		CCND_NODE<T>* temp = list3.gethead();
		CCND_NODE<T>* n = new CCND_NODE<T>;
		n->number = number;
		list3.insert_CCND(n);
		return (checkRegistred_No(cnic) + 1);
	}

	int checkRegistred_No(T cnic) {
		/*return number of cell-numbers registered on given cnic*/
		int number = 0;
		CCND_NODE<T>* temp = list3.gethead();
		while (temp->next != list3.gethead()) {
			if ((cnic + " ") == temp->CNIC) {
				number++;
			}
			temp = temp->next;
		}
		return number;
	}

	CCND_NODE<T>& swapCCND(T cnic, T cnic1, T number, T number1) {
		CCND_NODE<T>* temp = list3.gethead();
		T s;
		while (temp->next != list3.gethead()) {
			if ((cnic + " ") == temp->CNIC) {
				temp->number = number1;
				return *temp;
			}
			if ((cnic1 + " ") == temp->CNIC) {
				temp->number = number;
				return *temp;
			}
			temp = temp->next;
		}
	}

	CBID_NODE<T>& declareAlien(T cnic) {
		/*For Implementation of this function, Refer to CBID point 'iv', CCID point 'vi' and CCND point 'vii'. Also,
		write test-cases for this function yourself*/
		CBID_NODE<T>* temp = list1.gethead();
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				AlienData.push_roll(temp);
				list1.remove(temp);
				break;
			}
			temp = temp->next;
		}
		return AlienData.topelement();
	}

	bool verifyAlienDBUpdate(T cnic) {
		/*Verify that given CNIC is moved from CBID to AD, Also add test-case for this function yourself*/
		bool check = true;
		CBID_NODE<T>* temp = list1.gethead();
		while (temp->next != nullptr) {
			if ((cnic + " ") == temp->CNIC) {
				check = false;
				break;
			}
			temp = temp->next;
		}

		return check;
	}

	int printcount()
	{
		int total = 0, count = 1, net[5] = { 0,0,0,0,0 };
		bool check = false;
		/*Print count of cell phone numbers registered on each network. For example: (Telenor= 10, Jazz= 5, Ufone= 8, Zong= 9, Total= 32)
		 Return total*/
		string s[5] = { "", "", "" ,"" ,"" };
		CCND_NODE<T>* temp = list3.gethead();
		while (temp->next != list3.gethead()) {
			check = false;
			for (int counter = 0; counter < count - 1; counter++) {
				if (temp->network == s[counter]) {
					check = true;
					break;
				}
			}
			if (check == false) {
				s[count - 1] = temp->network;
				count++;
			}	
			temp = temp->next;
		}
		for (int counter = 0; counter < count - 1; counter++) {
			temp = list3.gethead();
			while (temp->next != list3.gethead()) {
				temp->network == s[counter] ? total += 1, net[counter] += 1 : total += 0, net[counter] += 0;
				temp = temp->next;
			}
		}
		for (int counter = 0; counter < count - 1; counter++) {
			temp->network == s[counter] ? total += 1, net[counter] += 1 : total += 0, net[counter] += 0;
		}
		cout << "--------------------\n";
		for (int counter = 0; counter < count - 1; counter++) {
			cout << s[counter] << ": " << net[counter] << endl;
		}
		cout << "--------------------\n";
 		return total;
	}
	void Display_AD() {
		/*Display data as instructed in point (xiv) of PDF*/
		CBID_NODE<T>* temp;
		AD<T> Alienqueue;
		while (AlienData.is_empty() == false) {
			temp = &AlienData.topelement();
			Alienqueue.push_roll(temp);
			AlienData.pop();
		}
		while (Alienqueue.is_empty() == false) {
			Alienqueue.display();
			temp = &Alienqueue.topelement();
			AlienData.push_roll(temp);
			Alienqueue.pop();
		}
	}

	~Database() {
		/* deallocate and cleanup */
	}
};

