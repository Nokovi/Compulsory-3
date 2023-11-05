#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <new>
#include <ctype.h>
#include "timefunction.h"
#include "folder.h"
#include "file.h"
using namespace std;

#define _help_ "Command list:\n help: Prints this list!\n mkdir: makes folder. \n mkf: makes file \n ls: lists the content of active folder \n cd: changes directory \n" << endl
using namespace std;


Folder*active_folder = 0;


int changedir(string newdir) {
	for (int i = 0; i < active_folder->childCount; i++) {
		if (newdir == ".." && active_folder->parent != 0) {
			
		}
		if (newdir == active_folder->childFolder[i]->getName()) {
				active_folder = active_folder->childFolder[i];
				cout << "Active folder set to " << active_folder->name;
				return 0;
		}
	cout << "\"" << newdir << "\" is not a folder in this directory";
	return 0;
	}

};


int main() {
	Folder root("Root");
	active_folder = &root;
	cout << _help_;
	int quit = false;
	while (quit == false) {
		string input;
		cin >> input;
		if (input == "quit") {
			quit = true;
		}
		else if (input == "ls") {
			active_folder->list();
		}
		else if (input == "mkdir") {
			active_folder->makeNew();
		}
		else if (input == "help") {
			cout << _help_;
		}
		else if (input == "cd") {
			string newdir;
			cin >> newdir;
			changedir(newdir);
		}
	}
}