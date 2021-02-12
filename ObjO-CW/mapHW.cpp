#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

int main() {
  map<string, int> words;
  //initializing i and o streams
  ifstream infile;
  ofstream outfile;
  infile.open("input1.txt");
  outfile.open("output1.txt");
  //if fails
  if(infile.fail())
    exit(1);
  if(outfile.fail())
    exit(1);
  
  char ac;
  
  while(infile.get(ac)){ 
    if(!ispunct(ac))
      outfile.put(ac);
  }
  
  infile.close();
  infile.open("input2.txt");//new in file
  
  if(infile.fail())
    exit(1);
  
  while(infile.get(ac)){ //copying to output
    if(!ispunct(ac))
      outfile.put(ac);
  }
  
  infile.close();
  outfile.close();
  
  infile.open("output1.txt"); //combining
  
  if(infile.fail())
    exit(1);
  
  string s;
  
  while(infile >> s){ //words to map
    ++words[s];
  }
  
  infile.close();
  
  map<string, int>::iterator i;
  
  i = words.begin(); 
  int max = 0; 
  string mostCommon; 
  
  int c = 0; 
  int count = 0; //counter 
  int k = 90;
  
  for(i = words.begin(); i != words.end(); i++){ 
    if(i->second > 1)
      c++;
  }

  
  if(k < c) {
    while(count < k){ //will execute k times
      for(i = words.begin(); i != words.end(); i++){
        if(i->second > max){
          max = i-> second;
          mostCommon = i->first;
        }
      }
      count++;
      cout << mostCommon << ": " << max << endl;
      words.erase(mostCommon); 
      max = 0; //reset value of max
    }
  } else {
    while(count < c){ //will execute c times
      for(i = words.begin(); i != words.end(); i++){
        if(i->second > max){
          max = i-> second;
          mostCommon = i->first;
        }
      }
      count++;
      cout << mostCommon << ": " << max << endl;
      words.erase(mostCommon);
      max = 0;
    }
  }
  
  return 0;
  
}
  
  