#include<iostream>
#include<ctime>
#include<algorithm>
#include<math.h>
#include<string>
#include<fstream>
#include<locale>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <sstream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
int main() 
{
	// ���� � 20 �� 4
	bool a = 0;
	string str[10];//temp ��� file_client_info
	string NUMBERS_ONLY[10];//������ ����� � ������� ����������
	string NUMBERS_MAIN;
	string Str[33];//temp ��� file_client_service
	string question;
	setlocale(LC_ALL, "rus");
	ifstream fin("file_client_info.txt");
	ofstream fout("output.txt");
	int G = 0;
    while (!fin.eof())
    {
        getline(fin, str[G]);
		G++;
    }
	//str[]-������ ����� ���������� ���������� �� ���� ���������
	
	cout <<"������� �������� �� ������ ������� �������� �� ������ ������:"<<endl;
	cin >>question;
	
	for (int i = 0; i < 10; i++) 
	{
		int count = 0;
		for (int j = 0; j < str[i].length(); j++) 
		{
			if (str[i][j] == ',') 
			{
				count++;
				j = j + 2;
			}
			if (count == 1 && str[i][j]!=' ')
			{
				NUMBERS_ONLY[i] = NUMBERS_ONLY[i] + str[i][j];
			}
		}
	}
	//���� ���������� �� �������
	fin.close();
	ifstream inf("file_client_service.txt");
	G = 0;
	while (!inf.eof())
	{
		getline(inf, Str[G]);
		G++;
	}
	

	for(int i=0;i<10;i++)
	{
		if (str[i].find(question) != string::npos)
		{
			NUMBERS_MAIN = NUMBERS_ONLY[i];//������� ����� �� ������� ���������
			a = a + 1;
			break;
		}
	}
	if (a == 0) 
	{
		cout << "������ 322, ������������ �� ������";
		return 1;
	}
	for (int i = 0; i < 33; i++)
	{
		if (Str[i].find(NUMBERS_MAIN) != string::npos)
		{
				string sTr;
				sTr = Str[i][26];
				sTr = sTr + Str[i][27];
				if (20 >= stoi(sTr) && stoi(sTr) <= 4)
				{
					fout << Str[i] << endl;
					
				}
		}//����� ���� ����� ������������ �������
	}
	fin.close();
	fout.close();
	return 0;
}