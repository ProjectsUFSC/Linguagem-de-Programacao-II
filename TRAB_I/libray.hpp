#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>

using namespace std; 


bool openfiles (string filename, vector<pair<string,vector<string> > > &fileList);
bool searchsubstring (const vector<pair<string,vector<string> > > &fileList);
bool removesubtrings ( vector<pair<string,vector<string> > > &fileList);
bool removerepeated ( vector<pair<string,vector<string> > > &fileList);
void stats (const vector<pair<string,vector<string> > > &fileList);
bool save ( vector<pair<string,vector<string> > > &fileList);
