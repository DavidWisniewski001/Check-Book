/******************************************************
   A primitive main solution for lab2 - cs2401
*****************************************************/
#include<iostream>
#include<fstream>
#include "numlist.h"
using namespace std;

int main(){
     NumList num1;
     int tmp;
     ifstream ifs;
     string filename;
     cout<<"Please enter the name of your number file.\n";
     cin>>filename;
     ifs.open(filename.c_str());
     if(ifs.fail()){
	cout<<"Input file failed to open.\n";
	return -1;
     }
     num1.load_from_file(ifs);
     ifs.close();
     num1.see_all();
     cout<<"Please enter three numbers to add to the list.\n";
     cin>>tmp;
     num1.insert(tmp); //1
     cin>>tmp;
     num1.insert(tmp); //2
     cin>>tmp;
     num1.insert(tmp); //3
     num1.b_sort();
     num1.see_all();
// here you will use the find function to find the . in the filename
// immediately before the . you will insert the word "sorted"
// the filename will now be changed so the following will save to the new 
// name -- this only takes two or three lines of code
     ofstream ofs(filename.c_str());
     num1.save_to_file(ofs);
     ofs.close();

return 0;
}


