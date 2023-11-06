#pragma once
using namespace std;


class Folder : public object {
private:
	Folder* parent = 0;
	Folder* childFolder[5];
	File* childFile[10];
	int childFolderCount = 0;
	int childFileCount = 0;
	string path;

	/// <summary>
	/// Compares file sizes then prints out all file information.
	/// </summary>
	/// <param name="objName"></param>
	/// <returns></returns>
	int inspect() {
		if (childFileCount == 0) { cout << "There are no files in that folder!\n"; return 0; }
		File* largestFile = childFile[0];
		for (int i = 0; i < childFileCount; i++) {
			if (largestFile < childFile[i]) {
				largestFile = childFile[i];
			}
		}
		cout << "Inspect results: \n" << "Name:" << largestFile->getName() << ", size: " << largestFile->getSize() << "MB, date: "
			<< largestFile->getTime() << endl;
	}
public:
	//Friends the "changedir" function. Had issues with having the changedir function inside this class. Allows access to private members.
	friend int changedir(string newdir);
	Folder(string inputName, Folder* set_parent) {
		cout << "Created folder " << inputName << "\n";
		name = inputName;
		timestamp = asctime_modified();
		parent = set_parent;
	}

	/// <summary>
	/// Make new folder.
	/// </summary>
	/// <returns>0</returns>
	int makeNew() {
		string input;
		cin >> input;
		for (int i = 0; i < childFolderCount; i++) {
			if (input == childFolder[i]->getName() || input == "..") {
				cout << "Existing subfolder in " << name << " already has that name!\n";
				return 0;
			}
		}
		for (int i = 0; i < childFileCount; i++) {
			if (input == childFile[i]->getName() || input == "..") {
				cout << "Existing file in " << name << " already has that name!\n";
				return 0;
			}
		}
		if (childFolderCount < 5) {
			childFolder[childFolderCount] = new Folder(input, this);
			childFolderCount++;
		}
		else {
			cout << "Folder capacity reached!\n";
		}
		return 0;
	}
	int makeFile() {
		string input;
		cin >> input;
		for (int i = 0; i < childFolderCount; i++) {
			if (input == childFolder[i]->getName() || input == "..") {
				cout << "Existing subfolder in " << name << " already has that name!\n";
				return 0;
			}
		}
		for (int i = 0; i < childFileCount; i++) {
			if (input == childFile[i]->getName() || input == "..") {
				cout << "Existing file in " << name << " already has that name!\n";
				return 0;
			}
		}
		if (childFileCount < 10) {
			childFile[childFileCount] = new File(input);
			childFileCount++;
		}
		else {
			cout << "File capacity reached!\n";
		}
		return 0;
	}

	/// <summary>
	/// recursive function that counts the size of all files in the folder and all subfolders.
	/// </summary>
	/// <returns>sum of size of all files underneath</returns>
	float getSize() {
		float sum = 0;
		if (childFolderCount != 0) {
			for (int i = 0; i < childFolderCount; i++) {
				sum += childFolder[i]->getSize();
			}
		}
		if (childFileCount != 0) {
			for (int i = 0; i < childFileCount; i++) {
				sum += childFile[i]->getSize();
			}
		}
		return sum;
	}

	//Lists all objects and their properties.
	int list() {
		cout << "Contents of folder " << name << "\n";
		for (int i = 0; i < childFolderCount; i++) {
			cout << " " << i << ": Name: " << childFolder[i]->getName() << ", Type: Folder, Time:" << childFolder[i]->getTime()
				<< ", Size:" << childFolder[i]->getSize() << "MB \n";
		}
		for (int i = 0; i < childFileCount; i++) {
			cout << " " << i + childFolderCount << ": " << childFile[i]->getName() << " Type: File, Time:" << childFile[i]->getTime()
				<< ", Size:" << childFile[i]->getSize() << "MB \n";;
		}
		return 0;
	}
	Folder* getParent() {
		return parent;
	}
	int renameObj(string oldName) {
		for (int i = 0; i < childFolderCount; i++) {
			if (childFolder[i]->getName() == oldName) {
				string newName;
				cin >> newName;
				childFolder[i]->changeName(newName);
				cout << "successfully renamed " << oldName << " to " << newName << "! \n";
				return 0;
			}
		}
		for (int i = 0; i < childFileCount; i++) {
			string newName;
			cin >> newName;
			if (childFile[i]->getName() == oldName) {
				childFile[i]->changeName(newName);
				cout << "successfully renamed " << oldName << " to " << newName << "! \n";
				return 0;
			}
		}
		cout << "There's no object with that name.\n";
	}
	/// <summary>
	/// Callss on the inspect function, which is separate to make read permissions easier.
	/// </summary>
	/// <param name="name"></param>
	/// <returns>0</returns>
	int callInspect(string name) {
		for (int i = 0; i < childFolderCount; i++) {
			if (name == childFolder[i]->getName()) {
				childFolder[i]->inspect();
				return 0;
			}
		}
		cout << "Can't find folder " << name << ".\n";
		return 0;
	}


	/// <summary>
	/// Gets file system path via recursion to make navigation easier
	/// </summary>
	/// <returns>path</returns>
	string getPath() {
		string Path;
			if (parent == 0) {
				return name;
			}
			else {
				Path += parent->getPath() + "/" + name;
				
			}
		return Path;
	}
};