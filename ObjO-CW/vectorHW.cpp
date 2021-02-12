#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    //initializing vectors
    vector<string> sort_str;
    vector<string>::iterator j;
  
    string w;
    
    //fstream initalizing
    fstream infile;
    infile.open("data.txt");
  
    if(infile.fail())
        exit(1);
    //getting file
    while(getline(infile, w)){
        sort_str.push_back(w);
    }
  
    sort(sort_str.begin(), sort_str.end());
    //printing
    for(j = sort_str.begin(); j != sort_str.end(); j++){    
        cout << *j << endl;
    }
  
    infile.close();
    return 0;
}