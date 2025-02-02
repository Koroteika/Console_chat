#include"Chat.h"

bool Chat::Registration(string name, string password, string login) {
	for (const auto& user:users)
	{
		if (login==user.GetLogin())
		{
			cout << "Login exist! Try another one. \n";
			return false;
		}
	}
	cout << "User is registered \n";
	users.push_back(User(name, password, login));
	return true;
}
bool Chat::UserLogin(string login, string password) {
	for (auto& user:users)
	{
		if (login == user.GetLogin() && password == user.GetPassword())
		{
			currentUser = &user;
			cout << "Welcome back! " << user.GetName() << "\n";
			return true;
		}
	}
	cout << "Invalid login or password, please try other details. \n";
	return false;
}
void Chat::SendMessagetoUser() {
	if (!currentUser) {
		cout << "You must be logged in to send messages!" << "\n";
		return;
	}

	string recipientLogin, text;
	cout << "Enter user login: ";
	cin >> recipientLogin;

	User* recipient = nullptr;
	for (auto& user:users)
	{
		if (user.GetLogin() == recipientLogin) {
			recipient = &user;
			break;
		}
	}
	if (!recipient) {
		cout << "User " << recipientLogin << " no found" << "\n";
		return;
	}

	cout << "Message text: ";
	cin.get();
	std::getline(cin, text);

	Message message(currentUser->GetLogin(), text, recipientLogin);
	currentUser->SaveSendMessage(message);
	recipient->SaveReceiveMessage(message);

	cout << "Message to user " << recipient->GetLogin() << " sent." << "\n";
}
void Chat::SentMessagetoSharedChat() {
	if (!currentUser) {
		cout << "You must be logged in to send messages!" << "\n";
		return;
	}
	string text;
	cout << "Message to all users: ";
	cin.get();
	std::getline(cin, text);
	Message message(currentUser->GetLogin(), text, "all");
	sharedMessage.push_back(message);
	currentUser->SaveSendMessage(message);

	for (auto& user : users)
	{
		user.SaveReceiveMessage(message);
	}
	cout << "Message sent to all users \n";
}
void Chat::ViewSharedMessages() const {
	if (sharedMessage.empty()) {
		cout << "Shared chat emty. \n";
		return;
	}
	cout << "Messages: \n";
	for (const auto& message : sharedMessage) {
		message.ShowMessage();
	}
}
void Chat::ViewSentMessages() {
	currentUser->ViewSendMessages();
}
void Chat::ViewReceivedMessages() {
	currentUser->ViewReceivedMessages();
}
void Chat::Logout() {
	if (currentUser) {
		cout << "Good bye " << currentUser->GetName() << "\n";
		currentUser == nullptr;
	}
	else {
		cout << "You are not logged in. \n";
		return;
	}
}



