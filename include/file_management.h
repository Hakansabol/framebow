#ifndef IMGCACHE
#define IMGCACHE

#include <string>
#include <vector>
using namespace std;

vector<string>* BuildImageList(string path, bool clear);
string GetImage();

#endif
