// Encryption and Dycrption program.cpp :
#include<bits/stdc++.h>
using namespace std;
// cipher zero encryption
string Affine_Cipher_encryption(string input) {
	map<char, int>m;
	char s = 'A';
	for (int i = 0; i < 26; i++) {
		m[s] = i;
		s++;
	}
	vector<int>vec;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			vec.push_back(100);
		}
		else {
			for (auto it : m) {
				if (input[i] == it.first) {
					int z = (5 * (it.second) + 8) % 26;
					vec.push_back(z);
				}
			}
		}
	}
	string str3;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 100) {
			str3 += ' ';
		}
		else {
			for (auto n : m) {
				if (vec[i] == n.second) {
					str3+=n.first;
				}
			}
		}
	}
	return str3;
}

// cipher zero dycrption 
string Affine_Cipher_decryption(string input) {
	map<char, int>m;
	char s = 'A';
	for (int i = 0; i < 26; i++) {
		m[s] = i;
		s++;
	}
	vector<int>vec;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			vec.push_back(10000);
		}
		else {
			for (auto it : m) {
				if (input[i] == it.first) {
					int z = (21 * (it.second - 8)) % 26;
					if (z > 0) {
						vec.push_back(z);
					}
					else {
						while (z < 0) {
							z += 26;
						}
						vec.push_back(z);
					}
				}
			}
		}
	}
	string str3;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 10000) {
			str3 += ' ';
		}
		else {
			for (auto n : m) {
				if (vec[i] == n.second) {
					str3 += n.first;
				}
			}
		}
	}
	return str3;
}


// cipher 1 encryption
string Caesar_Cipher_encryption(string input,int num) {
	string str1 = "";
	string str2 = "";
	int counter = 0;
	for (int i = input.length()-num; i<input.length(); i++) {
		str1 += input[i];
		counter++;
		if (counter == num) {
			break;
		}
	}
	
	for (int i = 0; i < input.length() - num ; i++) {
		str2 += input[i];
	}
	string str3 = str1 + str2;
	return str3;
}

// cipher 1 dycrpyion 
string Caesar_Cipher_decryption(string input,int num) {
	string str1 = "";
	string str2 = "";
	int counter = 0;
	for (int i = 0; i < num; i++) {
		str1 += input[i];
		counter++;
		if (counter == num) {
			break;
		}
	}

	for (int i = num; i < input.length(); i++) {
		str2 += input[i];
	}
	string str3 = str2 + str1;
	return str3;
}

// cipher 2 encryption
string Atbash_Cipher_encryption(string input) {
	map<char, char>m;
	char s = 'A';
	char e = 'Z';
	for (int i = 0; i < 13; i++) {
		m[s] = e;
		m[e] = s;
		s++;
		e--;
	}
	string str = "";
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			str += ' ';
		}
		for (auto it : m) {
			if (input[i] == it.first) {
				str += it.second;
			}
		}
	}
	return str;
}
// cipher 2 decryption
string Atbash_Cipher_decryption(string input) {
	map<char, char>m;
	char s = 'A';
	char e = 'Z';
	for (int i = 0; i < 13; i++) {
		m[s] = e;
		m[e] = s;
		s++;
		e--;
	}
	string str = "";
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			str += ' ';
		}
		for (auto it : m) {
			if (input[i] == it.first) {
				str += it.second;
			}
		}
	}
	return str;
}

// cipher 3 encryption
string Vignere_Cipher_encryption(string input,string keyword) {
	string str2 ="";
	while (str2.length() < input.length()) {
		str2 += keyword;
	}
	
	string str3 = "";
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			str3 += ' ';
		}
		else if (input[i] >= '0' && input[i] <= '9') {
			str3 += input[i];
		}
		else {
			str3+=char(((int(input[i]) + int(str2[i])) % 26)+65);
		}
	}
	return str3;
}
// cipher 3 decryption
string Vignere_Cipher_decryption(string input,string keyword) {
	string str2 = "";
	while (str2.length() < input.length()) {
		str2 += keyword;
	}

	string str3 = "";
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			str3 += ' ';
		}
		else if (input[i] >= '0' && input[i] <= '9') {
			str3 += input[i];
		}
		else {
			int z= ((int(input[i]) - int(str2[i])) % 26) + 65 ;
			if (z > 65) {
				str3 += char(z);
			}
			else {
				str3 += char(z + 26);
			}
			
		}
	}
	return str3;
}

// cipher 4 encryption
string Baconian_Cipher_encryption(string input) {
	map<char, string>m = { {'A', "aaaaa"},{'B', "aaaab"},{'C', "aaaba"},{'D', "aaabb"},{'E', "aabaa"},{'F', "aabab"},
		{'G', "aabba"},{'H', "aabbb"},{'I', "abaaa"},{'J', "abaab"},{'K', "ababa"},{'L',"ababb"},{'M',"abbaa"},{'N',"abbab"},
		{'O', "abbba"},{'P', "abbbb"},{'Q', "baaaa"},{'R', "baaab"},{'S', "baaba"},{'T', "baabb"},{'U', "babaa"},
		{'V', "babab"},{'W', "babba"},{'X', "babbb"},{'Y', "bbaaa"},{'Z', "bbaab"} };
	string str3 = "";
	for (int i = 0; i < input.length(); i++) {
		for (auto it : m) {
			if (it.first == input[i]) {
				str3 += it.second;
			}
		}
		str3 += ' ';
	}
	return str3;

}
// cipher 4 decryption
string Baconian_Cipher_decryption(string input) {
	map<char, string>m = { {'A', "aaaaa"},{'B', "aaaab"},{'C', "aaaba"},{'D', "aaabb"},{'E', "aabaa"},{'F', "aabab"},
		{'G', "aabba"},{'H', "aabbb"},{'I', "abaaa"},{'J', "abaab"},{'K', "ababa"},{'L',"ababb"},{'M',"abbaa"},{'N',"abbab"},
		{'O', "abbba"},{'P', "abbbb"},{'Q', "baaaa"},{'R', "baaab"},{'S', "baaba"},{'T', "baabb"},{'U', "babaa"},
		{'V', "babab"},{'W', "babba"},{'X', "babbb"},{'Y', "bbaaa"},{'Z', "bbaab"} };
	string str3 = "";
	string str2 = "";
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	for (int i = 0; i < input.length(); i += 5) {
		for (int j = i; j < i + 5; j++) {
			str2 += input[j];
		}
		for (auto it : m) {
			if (it.second == str2) {
				str3 += it.first;
			}
		}
		str2.clear();
	}
	return str3;
}

// cipher 5 encryption 
string Simple_Substitution_Cipher_encryption(string input,string keyword) {
	string str3 ="";
	int counter = 0;
	for (int i = 0; i < keyword.length(); i++) {
		str3 += ' ';
		str3 += keyword[i];
	}
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < keyword.length(); j++) {
			if (input[i] == keyword[j]) {
				counter++;
			}
		}
		if (counter==0) {
			str3 += input[i];
		}
		else {
		}
		counter = 0;

	}
	return str3;
}

 // cipher 6 encryption
string Morse_Code_encryption(string input) {
	string str3 = "";
	for (int i = 0; i < input.length(); i++) {
		input[i] = char(toupper(input[i]));
	}
	map<char,string>m={{'A', ".-"},{'B', "-..."},{'C', "-.-."},{'D', "-.."},{'E', "."},{'F', "..-."},
		{'G', "--."},{'H', "...."},{'I', ".."},{'J', ".---"},{'K', "-.-"},{'L',".-.."},{'M',"--"},{'N',"-."},
		{'O', "---"},{'P', ".--."},{'Q', "--.-"},{'R', ".-."},{'S', "..."},{'T', "-"},{'U', "..-"},
		{'V', "...-"},{'W', ".--"},{'X', "-..-"},{'Y', "-.-- "},{'Z', "--.."} };
	for (int i = 0; i < input.length(); i++) {
		for (auto it : m) {
			if (it.first == input[i]) {
				str3 += it.second;
			}
		}
	}
	return str3;
}


// cipher 6 decryption
string Morse_Code_decryption(string input) {
	string str3 = "";
	map<char, string>m = { {'A', ".-"},{'B', "-..."},{'C', "-.-."},{'D', "-.."},{'E', "."},{'F', "..-."},
		{'G', "--."},{'H', "...."},{'I', ".."},{'J', ".---"},{'K', "-.-"},{'L',".-.."},{'M',"--"},{'N',"-."},
		{'O', "---"},{'P', ".--."},{'Q', "--.-"},{'R', ".-."},{'S', "..."},{'T', "-"},{'U', "..-"},
		{'V', "...-"},{'W', ".--"},{'X', "-..-"},{'Y', "-.-- "},{'Z', "--.."} };
	string str2;
	for (int i = 0; i < input.length(); i++) {
		str2 += input[i];
		if (input[i] == ' ') {
			str2.erase(remove(str2. begin(), str2.end(), ' '), str2.end());
			str3 += ' ';
			for (auto it : m) {
				if (str2==it.second) {
					str3 += it.first;
				}
			}
			str2.clear();
		}
	}
	return str3;
}



int main() {
	cout << "Welcome in Encryption&Dycryption program :) " << endl;
	cout << "This program have 7 ciphers :" << endl;
	cout << "1.Affine Cipher " << "\n" << "2.Caesar Cipher " << "\n" << "3.Atbash Cipher" << "\n" << "4.Vignere Cipher " << "\n" << "5.Baconian Cipher"
		<< "\n" << "6.Simple Substitution Cipher" << "\n" << "7.Morse Code" << "\n" << "Enter the number of cipher" << endl;
	int n,choice,key;
	cin >> n;
	cout << "For Encryption enter 1" << "\n" << "For decryption enter 2" << endl;
	cin >> choice;
	string keyword;
	cout << "Enter the text: ";
	char str[250];
	cin.ignore();
	cin.getline(str, 250);
	//cout << str;
	if (choice == 1) {
		if (n == 1) {
			cout<<Affine_Cipher_encryption(str);
		}
		else if (n == 2) {
			cout << "Enter the key:";
			cin >> key;
			cout << Caesar_Cipher_encryption(str, key);
		}
		else if (n == 3) {
			cout << Affine_Cipher_encryption(str);
		}
		else if (n == 4) {
			cout << "Enter the keyword:";
			cin >> keyword;
			cout << Vignere_Cipher_encryption(str, keyword);
		}
		else if (n == 5) {
			cout << Baconian_Cipher_encryption(str);
		}
		else if (n == 6) {
			cout << "Enter the keyword:";
			cin >> keyword;
			cout << Simple_Substitution_Cipher_encryption(str, keyword);
		}
		else if (n == 7) {
			cout << Morse_Code_encryption(str);
		}
		else {
			cout << "Invalid input" << endl;
		}
	}
	else if (choice == 2) {
			if (n == 1) {
				cout << Affine_Cipher_decryption(str);
			}
			else if (n == 2) {
				cout << "Enter the key:";
				cin >> key;
				cout << Caesar_Cipher_decryption(str, key);
			}
			else if (n == 3) {
				cout << Affine_Cipher_decryption(str);
			}
			else if (n == 4) {
				cout << "Enter the keyword:";
				cin >> keyword;
				cout << Vignere_Cipher_decryption(str, keyword);
			}
			else if (n == 5) {
				cout << Baconian_Cipher_decryption(str);
			}
			else if (n == 6) {
				cout << "This cipher only encryption :) ";
			}
			else if (n == 7) {
				 cout<<Morse_Code_decryption(str);
			}
			else {
				cout << "Invalid input" << endl;
			}
	}
	else {
		cout << "Invalid input" << endl;
	}
}

