#include"Message.h"

void Message::ShowMessage() const {
	tm timeStruct;
	localtime_s(&timeStruct, &sent_time);
	cout << "[" << std::put_time(&timeStruct, "%Y-%m-%d %H:%M:%S") << "] ";
	cout << sender_ << " -> " << recipient_ << ": " << text_ << "\n";
}