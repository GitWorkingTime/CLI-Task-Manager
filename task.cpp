#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

//Class declarations:
class Task{
	public:
		std::string title;
		std::vector<std::string> description;
		std::string priority;
		std::string deadline;
};

//Function declarations:
void mainMenu(std::vector<Task> &taskList);
void options(std::vector<Task> &taskList);
void displayTasks(std::vector<Task> &taskList);
void addTask(std::vector<Task> &taskList);
void deleteTask();
void clearAll();
void selectEditTask(std::vector<Task> &taskList);
void refreshAddEditTaskScreen(Task &task, std::string mode);
void selectTask(std::vector<Task> &taskList, int &taskNumber);
void editTask(std::vector<Task> &taskList, int &taskIndex);

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
	std::cout << "4 - Select / Edit" << std::endl;
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
			selectEditTask(taskList);
			break;
		case 5:
			std::cout << "Exiting..." << std::endl;
			break;
	}
}

void addTask(std::vector<Task> &taskList){
	Task newTask;

	refreshAddEditTaskScreen(newTask, "add");

	std::cout << "Title: ";
	std::getline(std::cin >> std::ws, newTask.title);

	refreshAddEditTaskScreen(newTask, "add");

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

	refreshAddEditTaskScreen(newTask, "add");	

	std::cout << "Options: Urgent (U), High (H), Medium (M), Low (L)" << std::endl;
	std::string priorityChoice;
	choosingPriority:
		std::cout << "Priority (press ENTER to skip): ";
		std::getline(std::cin, newTask.priority);
		if(!newTask.priority.empty() && newTask.priority != "U" && newTask.priority != "H" && newTask.priority != "M" && newTask.priority != "L"){
			std::cout << "Invalid Choice" << std::endl;
			goto choosingPriority;
		}

	refreshAddEditTaskScreen(newTask, "add");

	std::cout << "Deadline (press ENTER to skip): ";
	std::getline(std::cin, newTask.deadline);

	refreshAddEditTaskScreen(newTask, "add");
	taskList.push_back(newTask);

	std::cout << "Press [ENTER] to exit: ";

	std::string key;
	std::getline(std::cin, key);

	mainMenu(taskList);
}

void refreshAddEditTaskScreen(Task &task, std::string mode){
	system("clear");
	std::cout << "===========================" << std::endl;
	if(mode == "add"){
		std::cout << "        Adding Task        " << std::endl;
	}else if(mode == "edit"){
		std::cout << "       Editing Task        " << std::endl;
	}
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

	if(task.priority.empty()){
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
			std::cout << "Priority: ";
			if(taskList[i].priority.empty()){
				std::cout << "N/A" << " | ";
			}else{
				std::cout << taskList[i].priority << " | ";
			}

			std::cout << "Deadline: ";

			if(taskList[i].deadline.empty()){
				std::cout << "N/A" << std::endl;
			}else{
				std::cout << taskList[i].deadline << std::endl;
			}
		}
	}
}

void selectEditTask(std::vector<Task> &taskList){
	system("clear");
	std::cout << "===========================" << std::endl;
	std::cout << "       Select / Edit       " << std::endl;
	std::cout << "===========================" << std::endl;

	displayTasks(taskList);
	std::cout << std::endl;
	std::cout << "===========================" << std::endl;

	if(taskList.empty()){
		std::cout << "NO TASK TO SELECT / EDIT" << std::endl;
		std::cout << "Enter any KEY to exit: ";
		std::string key;
		std::getline(std::cin, key);

		mainMenu(taskList);

	}else{
		int choice;
		// printf("tasklist size: %d \n", taskList.size());
		selectingTask:
			std::cout << "Enter TASK NUMBER to select task: ";
			std::cin >> choice;
			if(choice > taskList.size()){
				std::cout << "TASK DOES NOT EXIST" << std::endl;
				goto selectingTask;
			}

		selectTask(taskList, choice);
	}
}

void selectTask(std::vector<Task> &taskList, int &taskNumber){
	system("clear");
	int taskIndex = taskNumber - 1;
	std::cout << "===========================" << std::endl;
	std::cout << "Title: " << taskList[taskIndex].title << std::endl;

	std::cout << "Description: ";
	if(taskList[taskIndex].description.empty()){
		std::cout << "N/A" << std::endl;
	}else{
		std::cout << std::endl;
		for(int i = 0; i < taskList[taskIndex].description.empty(); i++){
			std::cout << taskList[taskIndex].description[i] << std::endl;
		}
	}

	std::cout << "Priority: ";
	if(taskList[taskIndex].priority.empty()){
		std::cout << "N/A" << std::endl;
	}else{
		std::cout << taskList[taskIndex].priority << std::endl;
	}

	std::cout << "Deadline: ";
	if(taskList[taskIndex].deadline.empty()){
		std::cout << "N/A" << std::endl;
	}else{
		std::cout << taskList[taskIndex].deadline << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===========================" << std::endl;

	std::cout << "Select one of the following:" << std::endl;
	std::cout << "1 - Edit" << std::endl;
	std::cout << "2 - Exit" << std::endl;
	std::cout << "Choice: ";
	int choice = 0;
	selectingOption:
		std::cin >> choice;
		if(choice != 1 && choice != 2){
			std::cout << "INVALID CHOICE" << std::endl;
			goto selectingOption;
		}

	switch(choice){
		case 1:
			editTask(taskList, taskIndex);
			break;
		case 2:
			mainMenu(taskList);
			break;
	}
}

void editTask(std::vector<Task> &taskList, int &taskIndex){
	refreshAddEditTaskScreen(taskList[taskIndex], "edit");

	char key = '\0';
	editingTitleScreen:
		std::cout << "Change current title? [y/n]: ";
		std::cin >> key;
		if(key == 'y'){
			std::cout << "Enter new title: ";
			std::getline(std::cin >> std::ws, taskList[taskIndex].title);
		}else if(key == 'n'){
			//Nothing
		}else{
			std::cout << "INVALID OPERATION" << std::endl;
			goto editingTitleScreen;
		}

	refreshAddEditTaskScreen(taskList[taskIndex], "edit");
	key = '\0';
	std::string desc;

	editingDescriptionScreen:
		std::cout << "Change current description? [y/n]: ";
		std::cin >> key;
		std::cin.ignore();
		if(key == 'y'){
			do{
				std::cout << "< ";
				std::getline(std::cin, desc);
				if(desc.empty()){
					break;
				}
				taskList[taskIndex].description.push_back(desc);
			}while(!desc.empty());
		}else if(key == 'n'){
			goto editingPriorityScreen;
		}else{
			std::cout << "INVALID OPERATION" << std::endl;
			goto editingDescriptionScreen;
		}

	refreshAddEditTaskScreen(taskList[taskIndex], "edit");
	key = '\0';

	editingPriorityScreen:
		std::cout << "Change current priority? [y/n]: ";
		std::cin >> key;
		std::cin.ignore();
		if(key == 'y'){
			std::cout << "Options: Urgent (U), High (H), Medium (M), Low (L)" << std::endl;
			std::string priorityChoice;
			choosingPriority:
				std::cout << "Priority (press ENTER to skip): ";
				std::getline(std::cin, taskList[taskIndex].priority);
				if(!taskList[taskIndex].priority.empty() && taskList[taskIndex].priority != "U" && taskList[taskIndex].priority != "H" && taskList[taskIndex].priority != "M" && taskList[taskIndex].priority != "L"){
					std::cout << "Invalid Choice" << std::endl;
					goto choosingPriority;
				}
		}else if(key == 'n'){
		}else{
			std::cout << "INVALID OPERATION" << std::endl;
			goto editingPriorityScreen;
		}

	refreshAddEditTaskScreen(taskList[taskIndex], "edit");
	key = '\0';

	editingDeadlineScreen:
		std::cout << "Change current deadline? [y/n]: ";
		std::cin >> key;
		std::cin.ignore();
		if(key == 'y'){
			std::cout << "Deadline (press [ENTER] to skip): ";
			std::getline(std::cin, taskList[taskIndex].deadline);
		}else if(key == 'n'){

		}else{
			std::cout << "INVALID OPERATION" << std::endl;
			goto editingDeadlineScreen;
		}

	int taskNumber = taskIndex + 1;

	selectTask(taskList, taskNumber);
}