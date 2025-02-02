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
	string sender_; //отправитель
	string recipient_; //получатель
	string text_; //текст сообщения
	time_t sent_time = time(nullptr); //текущее время (время отправки сообщения)

public:
	Message(const string& sender, const string& text, const string& recipient) : sender_(sender), text_(text), recipient_(recipient) {};
	void ShowMessage() const;
};