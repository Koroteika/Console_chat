#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::vector;

class Message {
	string sender_; //�����������
	string recipient_; //����������
	string text_; //����� ���������
	time_t sent_time = time(nullptr); //������� ����� (����� �������� ���������)

public:
	Message(const string& sender, const string& text, const string& recipient) : sender_(sender), text_(text), recipient_(recipient) {};
	void ShowMessage() const;
};