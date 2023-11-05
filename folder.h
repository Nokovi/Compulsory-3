#pragma once
#include <math.h>
using namespace std;
class Folder {
private:
	Folder* parent = 0;
	string name;
	Folder* childFolder[5];
	int childCount = 0;
	string path;
	float size;
	string time;
public:
	//Constructor:
	Folder(string inputname) {
		cout << ">Created folder " << inputname << "\n";
		name = inputname;
		time = asctime_modified();
		size = rand() % 100;
	}
	//Make new folder:
	int makeNew() {
		string input;
		cin >> input;
		if (childCount < 5) {
			childFolder[childCount] = new Folder(input);
			childCount++;
		}
		else {
			cout << "Folder capacity reached!\n";
		}
		return 0;
	}
	int makeFile() {
		string input;
		cin >> input;
		if (childCount < 5) {
			childFolder[childCount] = new Folder(input);
			childCount++;
		}
		else {
			cout << "Folder capacity reached!\n";
		}
	}
	//Get folder name:
	string getName() {
		return name;
	}

	//Friends the "changedir" function.
	friend int changedir(string newdir);


	//Lists all objects and their properties.
	int list() {
		cout << "Contents of folder " << name << "\n";
		for (int i = 0; i < childCount; i++) {
			cout << " " << i << ": " << childFolder[i]->getName() << " Folder " << childFolder[i] "\n";
		}
		return 0;
		for (int i = 0; i < childCount; i++) {
			cout << " " << i << ": " << childFolder[i]->getName() << "\n";
		}
		return 0;
	}
};
