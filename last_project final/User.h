#pragma once
#include"Message.h"
#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

class User {
	string name_;
	string password_;
	string login_;

	vector<Message> sentMessages;    //отправленные сообщения
	vector<Message> receivedMessages; //полученные сообщения
public:
	User(const string& name, string password, const string& login) :name_(name), password_(password), login_(login) {};

	void SaveSendMessage(const Message& message); //добавить отправленные сообщения в список отправленных сообщений
	void SaveReceiveMessage(const Message& message); //добавить входящие сообщения в список входящих сообщений
	void ViewSendMessages(); //показать список отправленных сообщений
	void ViewReceivedMessages(); //показать список полученных сообщений

	const string GetName() const {
		return name_;
	}
	const string GetLogin() const {
		return login_;
	}
	const string GetPassword() const {
		return password_;
	}
};
