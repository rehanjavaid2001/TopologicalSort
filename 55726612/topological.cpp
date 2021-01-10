//Rehan Javaid, rj3dxu, 11/16/2020, topological.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    vector<string> v1;

    string temp;
    while(getline(file, temp)){
      istringstream iss(temp);
      string s1, s2;
      iss >> s1 >> s2;
      if (s1 == "0"){
	break;
      }
      if (v1.size() == 0){
	v1.push_back(s1);
	v1.push_back(s2);
      }
      if (v1.size() > 0){
	if (!(find(v1.begin(), v1.end(), s1) != v1.end())){
	  v1.push_back(s1);  
	}
	if (!(find(v1.begin(), v1.end(), s2) != v1.end())){
	  v1.push_back(s2);
	}
      }
    }

    sort(v1.begin(), v1.end());

    vector<vector<string>> adjList;

     for(int i =0; i < v1.size(); i++){
       vector<string> vecstring = {v1[i]};
       adjList.push_back(vecstring);
      }

    ifstream file1(argv[1], ifstream::binary);
    string temp1;
    while(getline(file1, temp1)){
      istringstream iss(temp1);
      string s1, s2;
      iss >> s1 >> s2;
      for(int i = 0; i < adjList.size(); i++){
	 if (s2 == adjList[i][0]){
	   adjList[i].push_back(s1);
         }
      }
    }
    
    file.close();
    file1.close();

    //topological sort
    vector<string> courseOrder;
    
    queue<string> q1;
    for (int i = 0; i < adjList.size(); i++){
      if ((adjList[i].size()-1) == 0){
	q1.push(adjList[i][0]);
      }
    }
    while(!q1.empty()){
      string class1 = q1.front();
      if (!(find(courseOrder.begin(), courseOrder.end(), class1) != courseOrder.end())){
	 courseOrder.push_back(class1);
      } 
      q1.pop();
      for(int j = 0; j < adjList.size(); j++){
	for(int k = 0; k < adjList[j].size(); k++){
           if (class1 == adjList[j][k]){
	     adjList[j].erase(adjList[j].begin() + k);
	   }
	   if (adjList[j].size()-1 == 0){
	      q1.push(adjList[j][0]);
	   }
         }
       }
    }

    sort(courseOrder.begin(), courseOrder.end());
    
    for (int i = 0; i < courseOrder.size(); i++){
      cout << courseOrder[i] << " ";
    }
    cout << endl; 
}
