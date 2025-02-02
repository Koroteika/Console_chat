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
	vector<User>users; //список пользователей
	User* currentUser = nullptr; //указатель на текущего пользователя
	vector<Message> sharedMessage; //список сообщений в общем чате
public:
	bool Registration(string name, string password, string login); //регистрация пользователя 
	bool UserLogin(string login, string password); //вход пользователя
	void SendMessagetoUser(); //отправка сообщения конкретному пользователю
	void SentMessagetoSharedChat(); //отправка сообщения в общий чат (всем пользователям)
	void ViewSharedMessages() const; //просмотр сообщений в общем чате
	void ViewSentMessages(); //просмотр отправленных личных сообщений
	void ViewReceivedMessages(); //просмотр полученных сообщений
	void Logout(); //смена пользователя
};