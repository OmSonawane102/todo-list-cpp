// todo-list-cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list> // includes standard list
#include <iomanip> // includes setw() for specifying width before or after
#include <climits> // includes std::numeric_limits

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

// Helper function to validate integer input : 
int validIntInput(const std::string& prompt) {
	int value;
	while (true) {
		std::cout << prompt;
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, please enter a number " << std::endl;
		}else{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return value;
		}
	}
}

int main() {
	// Basic ANSI escape codes
	const std::string RESET = "\033[0m";
	const std::string BOLD = "\033[1m";
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string YELLOW = "\033[33m";
	const std::string BLUE = "\033[34m";

	//input variables
	char input_option;
	int input_id;
	std::string input_description;

	std::string version = "v1.6.0";
	std::list<TodoItem> todoItems;
	std::list<TodoItem>::iterator it; // declaring iterator;

	todoItems.clear(); // starts program with empty list

	while (true) {
		
		clearConsole(); // clear screen in between every loop

		std::cout << BOLD << "Todo List Manager - " << version << RESET << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl << std::endl;

		// prints all tasks to console 
		for (it = todoItems.begin(); it != todoItems.end(); it++) {

			std::string completed = it->isCompleted() ? "Completed" : "Remaining";
			std::cout << std::right <<  std::setw(4) << it->getID() << " | " << std::left << std::setw(40) << it->getDescription()<< " | " << completed << std::endl;

		}
		// prints if list is empty
		if (todoItems.empty()) {
			std::cout << "Add Your First TODO :	" << std::endl;
		}
		std::cout << "------------------------------------------------------------" << std::endl << std::endl;
		std::cout << BLUE << "~ [a]dd a TODO" << RESET << std::endl;
		std::cout << RED << "~ [d]elete a TODO" << RESET << std::endl;
		std::cout << GREEN << "~ [c]omplete a TODO" << RESET << std::endl;
		std::cout << YELLOW << "~ [q]uit" << RESET << std::endl;

		std::cout << "Select : ";

		std::cin >> input_option;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if (input_option == 'q') {
			std::cout << "Exited successfully..." << std::endl;
			break;
		}else if(input_option == 'a') {
			std::cout << "Add a new TODO description : ";
			std::cin.clear(); // clear input buffer beforehand
			std::getline(std::cin, input_description); // accepts everthing in a line including spaces
			TodoItem newItem;
			newItem.create(input_description);
			todoItems.push_back(newItem);
		}else if(input_option == 'c'){
			input_id = validIntInput("Enter ID of completed task : ");

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
				std::cin.get();
			}
		}else if (input_option == 'd') {
			if (todoItems.empty()) {
				std::cout << "Nothing to delete — your list is empty." << std::endl;
				std::cout << "Press enter to continue..." << std::endl;
				std::cin.get();
			}else {
				input_id = validIntInput("Enter ID to delete TODO : ");

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
					std::cin.get();
				}
			}
		}else {
			std::cout << "Invalid Option..." << std::endl;
			std::cout << "Press enter to continue!" << std::endl;
			std::cin.get();
		}
	}
	return 0;

}
