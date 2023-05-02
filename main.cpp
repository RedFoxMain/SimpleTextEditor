//Сделано RedFoxMain 
//Git hub: https://github.com/RedFoxMain

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
using namespace std;


string MakeText(){
	string text;
	string filename;
	cout << "Введите имя файла для создания(пример test.txt): ";
	cin >> filename;
	cout << "Вводите текст(exit для выхода)" << endl;
	string fullText = "";
	while(text != "exit"){
		getline(cin, text);
		if (text != "exit"){
			fullText.append("\n"+text);
		}
	}
	
	ofstream out;
	out.open(filename);
	if(out.is_open()){
		out << fullText << endl;
	}
	return fullText;	
}

string EditText(){
	string filename;
	string newText;
	string res;
	cout << "Введите название файла(пример test.txt): ";
	cin >> filename;
	ifstream out;
	out.open(filename);
	cout << "Файл содержит: "<< endl;
	if(out.is_open()){
		char text;
		while(out.get(text)){
			cout << text;
		}
	}
	cout << "Введите новый текст с изменениями: " << endl;
	string fullText = "";
	while(newText != "exit"){
		getline(cin, newText);
		if (newText != "exit"){
			res = fullText +"\n"+  newText;
		}
	}
	
	ofstream opFile;
	opFile.open(filename);
	if(opFile.is_open()){
		opFile << res;
	}
	cout << "Теперь файл содержит: " << endl;
	return res;	
	
}

string DeleteFile(){
	string filename;
	cout << "Введите имя(пример test.txt) или путь файла: ";
	cin >>filename;
	filesystem::remove(filename);
	return "Файл " + filename + "  удалён!";
	
}

int main(int argc, char *argv[])
{
	string userCan = "0.Выход\n1.Создать Файл\n2.Редактировать текст\n3.Удалить файл\n4.Очистить";
	int userChoice;
	string text;
	
	while(userChoice != 0){
		cout << endl;
		cout << userCan << endl;
		cout << endl;
		cout << "Я выбираю пункт номер: ";
		cin >> userChoice;
		cout << endl;
		if(userChoice == 0){
			break;
		}
		switch (userChoice){
			case 1:
			cout << endl;
			cout << "Ваш текст\n" + MakeText() << endl;
			break;
			case 2:
			cout << endl;
			cout << EditText();
			cout << endl;
			break;
			case 3:
			cout << endl;
			cout << DeleteFile();
			cout << endl;
			break;
			case 4:
			clrscr();
			break;
		}	
	}
}
