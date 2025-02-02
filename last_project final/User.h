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

	vector<Message> sentMessages;    //������������ ���������
	vector<Message> receivedMessages; //���������� ���������
public:
	User(const string& name, string password, const string& login) :name_(name), password_(password), login_(login) {};

	void SaveSendMessage(const Message& message); //�������� ������������ ��������� � ������ ������������ ���������
	void SaveReceiveMessage(const Message& message); //�������� �������� ��������� � ������ �������� ���������
	void ViewSendMessages(); //�������� ������ ������������ ���������
	void ViewReceivedMessages(); //�������� ������ ���������� ���������

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
