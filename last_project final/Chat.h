#pragma once
#include<iostream>
#include<string>
#include<vector>

#include"User.h"
#include"Message.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

class Chat {
	vector<User>users; //������ �������������
	User* currentUser = nullptr; //��������� �� �������� ������������
	vector<Message> sharedMessage; //������ ��������� � ����� ����
public:
	bool Registration(string name, string password, string login); //����������� ������������ 
	bool UserLogin(string login, string password); //���� ������������
	void SendMessagetoUser(); //�������� ��������� ����������� ������������
	void SentMessagetoSharedChat(); //�������� ��������� � ����� ��� (���� �������������)
	void ViewSharedMessages() const; //�������� ��������� � ����� ����
	void ViewSentMessages(); //�������� ������������ ������ ���������
	void ViewReceivedMessages(); //�������� ���������� ���������
	void Logout(); //����� ������������
};