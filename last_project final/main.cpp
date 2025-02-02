#include"Chat.h"
#include"User.h"
#include"Message.h"


int main() {
	Chat chat;
	string name, pw, login;
	int val, work = 1;

	while (work) {

		cout << "1 - Registration \n";
		cout << "2 - Enter \n";
		cout << "3 - Exit \n";
		cout << "Your choice: ";
		cin >> val;

		switch (val)
		{
		case 1:
		{
			cout << "Hello to registration page \n";
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter password: ";
			cin >> pw;
			cout << "Enter login: ";
			cin >> login;
			chat.Registration(name, pw, login);
			break;
		}
		case 2:
		{
			bool user = true;
			cout << "Enter login: ";
			cin >> login;
			cout << "Enter password: ";
			cin >> pw;

			if (chat.UserLogin(login, pw) == false)
			{
				user = false;
			}


			while (user)
			{
				cout << "1 - Message to user \n";
				cout << "2 - Message to all users \n";
				cout << "3 - View group chat messages \n";
				cout << "4 - Veiw received messages \n";
				cout << "5 - View sent messages \n";
				cout << "6 - logout \n";
				cout << "Your choice: ";
				cin >> val;

				switch (val)
				{
				case 1:
				{
					chat.SendMessagetoUser();
					break;
				}
				case 2:
				{
					chat.SentMessagetoSharedChat();
					break;
				}
				case 3:
				{
					chat.ViewSharedMessages();
					break;
				}
				case 4:
				{
					chat.ViewReceivedMessages();
					break;
				}
				case 5:
				{
					chat.ViewSentMessages();
					break;
				}
				case 6:
				{
					chat.Logout();
					user = false;
					break;
				}
				default:
					user = false;
					break;
				}
			}
			break;
		}
		case 3:
		{
			work = 0;
			break;
		}
		default:
			cout << "Error \n";
			break;
		}
	}

	return 0;
}