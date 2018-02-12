////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************
David Wisniewski
Project 1
09/14/2017
Description:
This program allows you to read in checks from a file once that is done the user
can rearrange them by either date check number and etc. You can also keep track
of your checking account balance, find the average amount you write your Checks
for and so much more.

*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////



#include<iostream>
#include<string>
#include<fstream>
#include "check.h"
using namespace std;
class Checkbook
{
    public:

  static const int CAPACITY = 200;

/////////////////////////////////////////////////////////


	Checkbook(std::string owner = "No One");
// Sets everything in the checkbook class to zero
/////////////////////////////////////////////////////////


  void load_from_file(std::istream& ins);
// Loads checks into book array
/////////////////////////////////////////////////////////


  void deposit(double a);
// Adds money to description
/////////////////////////////////////////////////////////


  void write_check(std::istream& ins);
// allows the user or a file to input checks into the array
/////////////////////////////////////////////////////////

  double get_balance()const;
// returns the balance
/////////////////////////////////////////////////////////


  void show_all(std::ostream& outs)const;
// Shows all of the checks in the class
/////////////////////////////////////////////////////////


  void remove(int n);
// Is supposed to remove a check from the array unfortunatley this does not work
/////////////////////////////////////////////////////////

  void number_sort();
// Sorts Checks by their  check numbers
/////////////////////////////////////////////////////////


  void payto_sort();
// Sorts Checks by who they are being paid to in aphabetical order
/////////////////////////////////////////////////////////

  void date_sort();
  // Sorts Checks by date in oldest to newest
/////////////////////////////////////////////////////////

  void show(const std::string& p)const;
// Shows everything in the array
/////////////////////////////////////////////////////////

  double average()const;
// Calculates the average
/////////////////////////////////////////////////////////

  void save(std::ostream& outs)const;
// saves the file
/////////////////////////////////////////////////////////

private:
string owner;
double balance;
Check book[CAPACITY];
int used;

};
