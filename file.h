#pragma once
using namespace std;

class object {
protected:
	string name = "";
	float size = 0;
	string timestamp = "";
public:
	string getName() {
		return name;
	}
	string getTime() {
		return timestamp;
	}
	void changeName(string newName) {
		name = newName;
	}
};


class File : public object {
public:
	File(string inputName) {;
		name = inputName;
		timestamp = asctime_modified();
		cout << "Created file " << name << "Successfully \n";
		size = rand() % 100;
	}
	float getSize() {
		return size;
	}
};

void help() {
	cout << "Command list: \n"
		<< " cd <folder>: changes folder\n"
		<< " help: Prints this list!\n"
		<< " inspect <folder>: returns information on the largest file in a subfolder \n"
		<< " mkdir <name>: makes folder. \n"
		<< " mkf <name>: makes file \n"
		<< " ls: lists the content of active folder\n"
		<< " return: return to parent folder. \n"
		<< " rn <old name> <new name>: renames file or folder\n"
		<< " quit: exits program \n" << endl;
}