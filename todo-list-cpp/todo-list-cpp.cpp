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

int main() {
	//input variables
	char input_option;
	int input_id;
	std::string input_description;

	std::string version = "v1.0.0";
	std::list<TodoItem> todoItems;
	std::list<TodoItem>::iterator it; // declaring iterator;

	srand(time(NULL)); // ensures that ID is different every time program runs

	todoItems.clear(); // starts program with empty list

	//TodoItem test;
	//test.create("This is a test todo");
	//todoItems.push_back(test);

	while (true) {
		system("cls"); // clear screen in between every loop
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
