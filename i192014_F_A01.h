//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "gtest/gtest.h"
#include <iostream>
using namespace std;

int alen(string s) { //Using string length function specifically for strings
	int count = 0;
	for (; s[count] != 0; count++) {}
	return count;
}

template <class T> //Using templatized array length function for own use in program
int alen(T* arr) {
	int count = 0;
	for (; *arr; arr++, count++) {}
	return count;
}

string HextoBinary(string hex) { //Simple function to convert from Hexadecimal to Binary
	string binary = "";
	string arr[] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
	char c[17];
	int counter = 0;
	for (char ch = '0'; counter < 16; counter++, ch++) {
		counter == 10 ? ch = 'A' : ch = ch;
		c[counter] = ch;
	}
	c[16] = 0;
	for (int counter = 0; counter < alen(hex); counter++) {
		for (int count = 0; count < 16; count++) {
			hex[counter] == c[count] ? binary += arr[count] : binary = binary;
		}
	}
	return binary;
}

string initKeyPermutation(string key) {
	string temp = HextoBinary(key);
	int PC1[] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	string keyper = "";
	for (int counter = 0; counter < 56; counter++) {
		keyper += temp[PC1[counter] - 1];
	}
	return keyper;
}

string halfCircularShift(string half_key, int index) { //shift 
	switch (index) {
	case 1:
		for (int count = 0; count < (alen(half_key) - 1); count++) {
			char temp = half_key[count + 1];
			half_key[count + 1] = half_key[count];
			half_key[count] = temp;
		}
		break;
	case 2:
		for (int count = 0; count < (alen(half_key) - 1); count++) {
			char temp = half_key[count + 1];
			half_key[count + 1] = half_key[count];
			half_key[count] = temp;
		}
		for (int count = 0; count < (alen(half_key) - 1); count++) {
			char temp = half_key[count + 1];
			half_key[count + 1] = half_key[count];
			half_key[count] = temp;
		}
		break;
	default:
		break;
	}
	return half_key;
}

string roundPermutation(string key) {
	int PC2[] = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };
	string keyperm = "";
	for (int counter = 0; counter < 48; counter++) {
		keyperm += key[(PC2[counter]) - 1];
	}
	return keyperm;
}

string initTextPermutation(string text) {
	string temp = HextoBinary(text);
	//int PT[] = { '58', '50', '42', '34', '26', '18', '10', '2', '60', '52', '44', '36', '28', '20', '12', '4', '62 ', '54 ', '46 ', '38 ', '30 ', '22 ', '14 ', '6', '64 ', '56 ', '48 ', '40 ', '32 ', '24 ', '16 ', '8','57 ', '49 ', '41 ', '33 ', '25 ', '17 ', '9 ', '1' };
	int PTA[] = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };
	string result = "";
	for (int counter = 0; counter < 64; counter++) {
		result += temp[(PTA[counter]) - 1];
	}
	return result;

}

string expandHalfText(string rightHalfText) {
	int ET[] = { 32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1 };
	string result = "";
	for (int counter = 0; counter < 48; counter++) {
		result += rightHalfText[ET[counter] - 1];
	}
	return result;
}

string XOR(string text, string key) {
	string result = "";
	for (int counter = 0; counter < alen(key) || counter < alen(text); counter++) {
		text[counter] != key[counter] ? result += '1' : result += '0';
	}
	return result;
}


string HextoBinary2(int hex) { //Simple function to convert from Hexadecimal to Binary for final SBox result
	string binary = "";
	string arr[] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
	char c[17], h = 0;
	int counter = 0;
	for (char ch = '0'; counter < 16; counter++, ch++) {
		counter == 10 ? ch = 'A' : ch = ch;
		c[counter] = ch;
		counter == hex ? h = ch : h = h;
	}
	c[16] = 0;
	for (int count = 0; count < 16; count++) {
		h == c[count] ? binary = arr[count] : binary = binary;
	}
	return binary;
}

int BianarytoHex(string bin) { //Simple function to convert from Binary to Hexadecimal for SBox column
	char hex = 0;
	string arr[] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
	char c[17];
	int temp = 0;
	int counter = 0;
	for (char ch = '0'; counter < 16; counter++, ch++) {
		counter == 10 ? ch = 'A' : ch = ch;
		c[counter] = ch;
	}
	c[16] = 0;
	for (int count = 0; count < 16; count++) {
		bin == arr[count] ? hex = c[count], temp = count : hex = hex, temp = temp;
	}
	return temp;
}

int BinarytoDec(string bin) { // Simple function to convert from Binary to Dec for SBox row
	char dec = 0;
	int temp = 0;
	string arr[] = { "00", "01", "10", "11" };
	char c[5];
	int counter = 0;
	for (char ch = '0'; counter < 4; counter++, ch++) {
		c[counter] = ch;
	}
	c[4] = 0;
	for (int count = 0; count < 4; count++) {
		bin == arr[count] ? dec = c[count], temp = count : dec = dec, temp = temp;
	}
	return temp;
}

string SBoxbreak(int row, int column, int Box[4][16]) {
	int c = Box[row][column];
	return (HextoBinary2(c));
}


string calcSBox(string text) {
	int Box1[4][16] = { {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7}, {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8}, {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0}, {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13} };
	int Box2[4][16] = { {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10}, {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5}, {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15}, {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9} };
	int Box3[4][16] = { {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8}, {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1}, {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7}, {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12} };
	int Box4[4][16] = { {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15}, {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9}, {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4}, {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14} };
	int Box5[4][16] = { {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9}, {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6}, {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14}, {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3} };
	int Box6[4][16] = { {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11}, {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8}, {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6}, {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13} };
	int Box7[4][16] = { {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1}, {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6}, {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2}, {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12} };
	int Box8[4][16] = { {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7}, {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2}, {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8}, {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11} };
	string result = "", arr[8], row[8], column[8], temp;
	for (int counter = 0; counter < 8; counter++) {
		arr[counter] = "";
		row[counter] = "";
		column[counter] = "";
		temp = "";
		for (int count = counter * 6; count < ((counter * 6) + 6); count++) {
			arr[counter] += text[count];
		}
		temp = arr[counter];
		for (int count = 0; count < 6; count++) {
			count == 0 || count == 5 ? row[counter] += temp[count] : column[counter] += temp[count];
		}
		//cout << "row: " << row[counter] << "   col:" << column[counter] << endl << arr[counter] << endl << temp << endl;
	}
	result += SBoxbreak(BinarytoDec(row[0]), BianarytoHex(column[0]), Box1);
	result += SBoxbreak(BinarytoDec(row[1]), BianarytoHex(column[1]), Box2);
	result += SBoxbreak(BinarytoDec(row[2]), BianarytoHex(column[2]), Box3);
	result += SBoxbreak(BinarytoDec(row[3]), BianarytoHex(column[3]), Box4);
	result += SBoxbreak(BinarytoDec(row[4]), BianarytoHex(column[4]), Box5);
	result += SBoxbreak(BinarytoDec(row[5]), BianarytoHex(column[5]), Box6);
	result += SBoxbreak(BinarytoDec(row[6]), BianarytoHex(column[6]), Box7);
	result += SBoxbreak(BinarytoDec(row[7]), BianarytoHex(column[7]), Box8);
	return result;
}


string DivideString(string str, int part) { //Simple function to divide any string into two parts 
	string part1 = "", part2 = "";
	for (int counter = 0; counter < alen(str); counter++) {
		counter < alen(str) / 2 ? part1 += str[counter] : part2 += str[counter];
	}
	return part == 1 ? part1 : part2;
}

string FinalStage(string text, string SBox) { //Function to divide and XOR final SBox string and then combine back again
	string result = DivideString(text, 2);
	result += XOR(DivideString(text, 1), SBox);
	return result;
}

//The final(driver) function without test cases start from here
string FinalRound(string key, string text) { // Using the initial key and text provided to us in hexadecimal form, not binary
	int round_shifts[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	string final_text = "", keys[16], texts[16], result = "";
	keys[0] = initKeyPermutation(key);
	texts[0] = initTextPermutation(text);
	keys[0] = halfCircularShift(DivideString(keys[0], 1), round_shifts[0]) + halfCircularShift(DivideString(keys[0], 2), round_shifts[0]);
	for (int counter = 1; counter < 16; counter++) { // Loop to acquire all 16 keys
		keys[counter] = halfCircularShift(DivideString(keys[counter - 1], 1), round_shifts[counter]) + halfCircularShift(DivideString(keys[counter - 1], 2), round_shifts[counter]);
	}
	for (int counter = 0; counter < 16; counter++) {
		keys[counter] = roundPermutation(keys[counter]);
	}
	for (int counter = 1; counter < 16; counter++) {
		texts[counter] = FinalStage(texts[counter - 1], calcSBox(XOR(expandHalfText(DivideString(texts[counter - 1], 2)), keys[counter - 1])));
	}
	final_text = texts[15];
	int IPT[] = { 40 , 8 , 48 , 16 , 56 , 24 , 64 , 32, 39 , 7 , 47 , 15 , 55 , 23 , 63 , 31, 38 , 6 , 46 , 14 , 54 , 22, 62 , 30, 37 , 5 , 45 , 13 , 53 , 21 , 61 ,29, 36 , 4 , 44 , 12 , 52 , 20 , 60 ,28, 35 , 3 , 43 , 11 , 51 , 19 , 59 ,27, 34 , 2 , 42 , 10 , 50 , 18, 58 , 26, 33 , 1 , 41 , 9 , 49 , 17 , 57 , 25 };
	for (int counter = 0; counter < 64; counter++) {
		result = final_text[IPT[counter] - 1];
	}
	return result;
}


