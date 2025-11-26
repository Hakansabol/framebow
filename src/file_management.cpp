#include "file_management.h"

#include <filesystem>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <vector>

using namespace std;

vector<string> directories_list{}; // list of directories to recur downwards
vector<string> files_list{}; // list of files to display

vector<string>* BuildImageList(string path, bool clear) {
	if (clear) {
		files_list = {};
		directories_list = {};
	}

	struct stat s;

	for (const auto& entry : filesystem::directory_iterator(path)) {
		string fn = entry.path().string();

		if (stat(fn.c_str(), &s) == 0 && (s.st_mode & S_IFDIR))
			BuildImageList(fn, false);
		else 
			files_list.push_back(fn);
		cout << fn << endl;
	}
	return &files_list;
}

string GetImage() {
	return "";
}
