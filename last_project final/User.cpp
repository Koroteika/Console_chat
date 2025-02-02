#include"User.h"

void User::SaveSendMessage(const Message& message) {
	sentMessages.push_back(message);
}
void User::SaveReceiveMessage(const Message& message) {
	receivedMessages.push_back(message);
}
void User::ViewSendMessages() {
	if (sentMessages.empty())
	{
		cout << "There are no messages sent. \n";
		return;
	}
	cout << "Sent messages: \n";
	for (const auto& message : sentMessages)
	{
		message.ShowMessage();
	}
}
void User::ViewReceivedMessages() {
	if (receivedMessages.empty())
	{
		cout << "There are no messages received. \n";
		return;
	}
	cout << "Incoming messages: \n";
	for (const auto& message : receivedMessages)
	{
		message.ShowMessage();
	}
}
