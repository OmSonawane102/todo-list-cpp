// todo-list-cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<list> // includes standard list
#include<ctime> // for time() function 



class TodoItem {
private:
	int id;
	std::string description;
	bool completed;

public:
	TodoItem() : id(0), description(""), completed(false) {}
	~TodoItem() = default;

	bool create(std::string new_description) {
		id = rand() % 100 + 1; // generates random number between 1 and 100
		description = new_description;
		return true;
	}

	int getID() { return id; }
	std::string getDescription() { return description; }
	bool isCompleted() { return completed; }
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

	std::string version = "v1.1.0";
	std::list<TodoItem> todoItems;
	std::list<TodoItem>::iterator it; // declaring iterator;

	srand(time(NULL)); // ensures that ID is different every time program runs

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

			for (it = todoItems.begin(); it != todoItems.end(); it++) {
				if (input_id == it->getID()) {
					it->setCompleted(true);
					break;
				}
			}
		}
		//else {
		//	std::cout << "Invalid Option..." << std::endl;
		//	std::cout << "Press enter to continue!" << std::endl;
		//	std::cin.get();
		//}
	}
	return 0;

}
