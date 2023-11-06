#define _CRT_SECURE_NO_WARNINGS
/// Bypasses compiler complaints about time.h
#include <iostream>
#include <string>
#include <new>
#include <ctype.h>
#include "timefunction.h"
#include <math.h>
#include "file.h"
#include "folder.h"
using namespace std;


Folder*active_folder = 0;

/// <summary>
/// Changes directory to a different one. ".." returns to the parent.
/// </summary>
/// <param name="newdir"></param>
/// <returns></returns>
int changedir(string newdir) {
	for (int i = 0; i < active_folder->childFolderCount; i++) {
		if (newdir == active_folder->childFolder[i]->getName()) {
				active_folder = active_folder->childFolder[i];
				cout << "Active folder set to " << active_folder->name << endl;
				return 0;
		}
	}
	cout << "\"" << newdir << "\" is not a folder in this directory-\n";
	return 0;

};
/// <summary>
/// returns to parent folder if it exists.
/// </summary>
void branchUp() {
	if (active_folder->getParent() != 0) {
		active_folder = active_folder->getParent();
		cout << "returned to " << active_folder->getName() << ".\n";
	}
	else {
		cout << active_folder->getName() << " has no parent folder. \n>";
	}
}


int main() {
	Folder root("Root", 0);
	active_folder = &root;
	help();
	int quit = false;
	while (quit == false) {
		cout << active_folder->getPath() << ":";
		string input;
		cin >> input;
		
		//I know if-else statements are inefficient here, but you can't use strings inside switch statements so might as well.
		//Somehow I made it interpret input as <command> <argument>, no idea how, it just happened.
		if (input == "quit") {
			quit = true;
		}
		else if (input == "ls") {
			active_folder->list();
		}
		else if (input == "mkdir") {
			active_folder->makeNew();
		}
		else if (input == "mkf") {
			active_folder->makeFile();
		}
		else if (input == "help") {
			help();
		}
		else if (input == "cd") {
			string newdir;
			cin >> newdir;
			changedir(newdir);
		}
		else if (input == "rn") {
			string rndir;
			cin >> rndir;
			active_folder->renameObj(rndir);
		}
		else if (input == "return") {
			branchUp();
		}
		else if (input == "inspect") {
			string insdir;
			cin >> insdir;
			active_folder->callInspect(insdir);
		}
		if (input == "quit") {
			break;
		}
	}
	return 0;
}