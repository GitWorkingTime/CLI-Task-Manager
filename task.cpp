#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

//Class declarations:
class Task{
	public:
		std::string title;
		std::vector<std::string> description;
		char priority = '\0';
		std::string deadline;
};

//Function declarations:
void mainMenu(std::vector<Task> &taskList);
void options(std::vector<Task> &taskList);
void displayTasks(std::vector<Task> &taskList);
void addTask(std::vector<Task> &taskList);
void deleteTask();
void clearAll();
void editTask();
void refreshAddTaskScreen(Task &task);

//Main Code:
int main(){
	std::vector<Task> taskList;

	mainMenu(taskList);

	return 0;
}

void mainMenu(std::vector<Task> &taskList){
	system("clear"); //Unix-based OS
	//system("cls"): //Windows

	//Title
	std::cout << "===========================" << std::endl;
	std::cout << "        TASK-MANAGER       " << std::endl;
	std::cout << "===========================" << std::endl;

	//Options:
	std::cout << "Choose one of the following:" << std::endl;
	std::cout << "1 - Add Task" << std::endl;
	std::cout << "2 - Delete Task / Clear all" << std::endl;
	std::cout << "3 - Filter" << std::endl;
	std::cout << "4 - Edit Task" << std::endl;
	std::cout << "5 - Exit" << std::endl;

	displayTasks(taskList);
	options(taskList);
}

void options(std::vector<Task> &taskList){
	std::cout << std::endl;
	std::cout << "===========================" << std::endl;
	std::cout << "          OPTION           " << std::endl;
	std::cout << "===========================" << std::endl;


	int choice = 0;
	do{
		std::cout << "Choice: ";
		std::cin >> choice;

		if(choice > 5){
			std::cout << "Invalid Choice" << std::endl;
		}

	}while(choice > 5);

	switch(choice){
		case 1:
			addTask(taskList);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			std::cout << "Exiting...";
			break;
	}
}

void addTask(std::vector<Task> &taskList){
	Task newTask;

	refreshAddTaskScreen(newTask);

	std::cout << "Title: ";
	std::getline(std::cin >> std::ws, newTask.title);

	refreshAddTaskScreen(newTask);

	std::string desc;

	std::cout << "Description (press ENTER to skip):" << std::endl;
	do{
		std::cout << "< ";
		std::getline(std::cin, desc);
		if(desc.empty()){
			break;
		}
		newTask.description.push_back(desc);
	}while(!desc.empty());

	refreshAddTaskScreen(newTask);	

	std::cout << "Options: Urgent (U), High (H), Medium (M), Low (L)" << std::endl;

	choosingPriority:
		std::cout << "Priority (press ENTER to skip): ";
		std::cin >> newTask.priority;
		if(newTask.priority != 'U' && newTask.priority != 'H' && newTask.priority != 'M' && newTask.priority != 'L' && newTask.priority != '\0'){
			std::cout << "Invalid Choice" << std::endl;
			goto choosingPriority;
		}

	refreshAddTaskScreen(newTask);

	std::cout << "Deadline (press ENTER to skip): ";
	std::getline(std::cin >> std::ws, newTask.deadline);

	refreshAddTaskScreen(newTask);
	taskList.push_back(newTask);
	std::cout << "Enter any KEY to exit: ";

	char key = '\0';
	std::cin >> key;

	switch(key){
		default:
			mainMenu(taskList);
			break;
	}

}

void refreshAddTaskScreen(Task &task){
	system("clear");
	std::cout << "===========================" << std::endl;
	std::cout << "        Adding Task        " << std::endl;
	std::cout << "===========================" << std::endl;

	if(task.title.empty()){
		std::cout << "Title: N/A" << std::endl;
	}else{
		std::cout << "Title: " << task.title << std::endl;
	}

	if(task.description.empty()){
		std::cout << "Description: N/A" << std::endl;
	}else{
		std::cout << "Description: " << std::endl;
		for(int i = 0; i < task.description.size(); i++){
			std::cout << "  " << task.description[i] << std::endl;
		}
	}

	if(task.priority == '\0'){
		std::cout << "Priority: N/A" << std::endl;	
	}else{
		std::cout << "Priority: " << task.priority << std::endl;
	}

	if(task.deadline.empty()){
		std::cout << "Deadline: N/A" << std::endl;
	}else{
		std::cout << "Deadline: " << task.deadline << std::endl;
	}

}

void displayTasks(std::vector<Task> &taskList){
	std::cout << std::endl;
	std::cout << "===========================" << std::endl;
	std::cout << "         TASK-LIST         " << std::endl;
	std::cout << "===========================" << std::endl;

	if(taskList.empty()){
		std::cout << "TASK-LIST: N/A" << std::endl;
	}else{
		for(int i = 0; i < taskList.size(); i++){
			std::cout << "[" << i + 1 << "] ";
			std::cout << "Title: " << taskList[i].title << " | ";
			std::cout << "Priority: " << taskList[i].priority << " | ";
			std::cout << "Deadline: " << taskList[i].deadline << std::endl;
		}
	}
}



