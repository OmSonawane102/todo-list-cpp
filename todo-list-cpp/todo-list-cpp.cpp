// todo-list-cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<list> // includes standard list

class TodoItem {
private:
	int id;
	std::string description;
	bool completed;

public:
	TodoItem() : id(0), description(""), completed(false) {}
	~TodoItem() = default;

	bool create(std::string new_description) {
		static int next_id = 1; // only initialize once
		id = next_id++; // post increament so that the first id remains '1'
		description = new_description;
		return true;
	}

	int getID() const { return id; }
	std::string getDescription() const { return description; }
	bool isCompleted() const { return completed; }
	void setCompleted(bool val) { completed = val; } // set status of selected task
};

void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

int main() {
	//input variables
	char input_option;
	int input_id;
	std::string input_description;

	std::string version = "v1.3.0";
	std::list<TodoItem> todoItems;
	std::list<TodoItem>::iterator it; // declaring iterator;

	todoItems.clear(); // starts program with empty list

	while (true) {
		
		clearConsole(); // clear screen in between every loop

		std::cout << "Todo List Manager - " << version << std::endl;
		std::cout << "----------------------------------------------" << std::endl << std::endl;

		// prints all tasks to console 
		for (it = todoItems.begin(); it != todoItems.end(); it++) {

			std::string completed = it->isCompleted() ? "Completed" : "Remaining";
			std::cout << it->getID() << " | " << it->getDescription()<< " | " << completed << std::endl;

		}
		// prints if list is empty
		if (todoItems.empty()) {
			std::cout << "Add Your First TODO :	" << std::endl;
		}
		std::cout << "----------------------------------------------" << std::endl << std::endl;
		std::cout << "~ [a]dd a TODO" << std::endl;
		std::cout << "~ [d]elete a TODO" << std::endl;
		std::cout << "~ [c]omplete a TODO" << std::endl;
		std::cout << "~ [q]uit" << std::endl;

		std::cout << "Select : ";

		std::cin >> input_option;
		
		if (input_option == 'q') {
			std::cout << "Exited successfully..." << std::endl;
			break;
		}else if(input_option == 'a') {
			std::cout << "Add a new TODO description : ";
			std::cin.clear(); // clear input buffer beforehand
			std::cin.ignore(); // ignores the first return so that our description is non-empty
			std::getline(std::cin, input_description); // accepts evrthing in a line including spaces
			TodoItem newItem;
			newItem.create(input_description);
			todoItems.push_back(newItem);
		}else if(input_option == 'c'){
			std::cout << "Enter ID of completed task : ";
			std::cin >> input_id;

			bool found = false;
			for (it = todoItems.begin(); it != todoItems.end(); it++) {
				if (input_id == it->getID()) {
					it->setCompleted(true);
					found = true;
					break;
				}
			}
			if (!found) {
				std::cout << "Invalid ID no task found." << std::endl;
				std::cout << "Press enter to continue..." << std::endl;
				std::cin.ignore();
				std::cin.get();
			}
		}else if (input_option == 'd') {
			std::cout << "Enter ID to delete TODO : ";
			std::cin >> input_id;

			bool found = false;
			for (it = todoItems.begin(); it != todoItems.end(); it++) {
				if (input_id == it->getID()) {
					todoItems.erase(it); // don't remove break after this
					found = true;
					break;
				}
			}
			if (!found) {
				std::cout << "Invalid ID no task found." << std::endl;
				std::cout << "Press enter to continue..." << std::endl;
				std::cin.ignore();
				std::cin.get();
			}
		}
		//else {
		//	std::cout << "Invalid Option..." << std::endl;
		//	std::cout << "Press enter to continue!" << std::endl;
		//	std::cin.ignore();
		//	std::cin.get();
		//}
	}
	return 0;

}
