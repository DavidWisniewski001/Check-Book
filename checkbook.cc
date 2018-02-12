#include"checkbook.h"

using namespace std;

Checkbook::Checkbook(std::string owner)
{

    used = 0;
    balance = 0;

}

/////////////////////////////////////////////////////////


void Checkbook::load_from_file(std::istream& ins)
{

   ins >> balance;
   ins >> book[used];
     while((!ins.eof()) && (used < CAPACITY))
     {
       used++;
       ins >> book[used];
     }

}


/////////////////////////////////////////////////////////

void Checkbook::deposit(double a)
{
  balance = balance + a;

}
/////////////////////////////////////////////////////////

void Checkbook::write_check(std::istream& ins)
{
Check tmp;
int num =0;

  if (&std::cin == &ins)
  {
    ++used;
    std::cin >> tmp;
    num = tmp.get_num();
    for (size_t i = 0; i < used-1; i++)
    {
      while (book[i].get_num() == num )
      {
        std::cout << "That check number is taken try again" << '\n';
        std::cin >> tmp;
      }
    }
    tmp = book[used-1];
  }

  else
  {
    used++;
    ins >> tmp;
    for (size_t i = 0; i < used-1; i++)
    {
      while (book[i].get_num() == num )
      {
        std::cout << "That check number is taken try again" << '\n';
        std::cin >> tmp;
      }
    }
    tmp = book[used-1];

  }/*
  bool done = false;
	int j;
  Check tmp;
  while(!done)
  {
    ins >> tmp;
    done = true;
    for(j=0; j < used-1; ++j)
    {
      if(tmp.get_num() == book[j].get_num())
      {
      done = false;
      ins >> tmp;
      j=0;
      }
    }
  }
  if (used == 0)
  {
    used ++;
    book[0] = tmp;
  }
  else
  {
    used++;
    book[used-1] = tmp;
    balance = balance - tmp.get_amount();
  }*/
}




/////////////////////////////////////////////////////////

double Checkbook::get_balance()const
{
  return(balance);
}
/////////////////////////////////////////////////////////

void Checkbook::show_all(std::ostream& outs)const
{
  if(used == 0)
	    cout << "Empty Checkbook.\n";
	else
	    for(size_t i = 0; i < used; ++i)
      {

        cout << book[i] << endl;

      }
}

/////////////////////////////////////////////////////////

void Checkbook::remove(int n)
{
  int index=0;
  //std::cout << "function call" << '\n';
  // Moves the check outside of the array
  for (size_t i = 0; i < used-1; i++)
  {
  //  std::cout << "remove" << '\n';
      if(book[i].get_num() == n)
    {
      //std::cout << book[i].get_num() << '\n';
      book[used+1] = book[i];
      // Moves the check outside of the array
      i = index;
    }

  }
  balance = book[index].get_amount() + balance;
   for (size_t index; index < used-1; ++index)
   {
     book[index] = book[index+1];
   }
   --used;





}

/////////////////////////////////////////////////////////


void Checkbook::number_sort()
{
  bool done = false;
		int j;
		Check tmp;
		while(!done)
		{
		done = true;
		for(j=0; j < used-1; ++j)
		{
    //  std::cout << used << '\n';
			if(book[j].get_num() > book[j+1].get_num())
			    {
					done = false;
					tmp = book[j];
					book[j] = book[j+1];
					book[j+1] = tmp;


					}
		}
			}
}

/////////////////////////////////////////////////////////

void Checkbook::payto_sort()
{
  bool done = false;
    int j;
    Check tmp;
    while(!done)
    {
    done = true;
    for(j=0; j < used-1; ++j)
    {
      if(book[j].get_payto() > book[j+1].get_payto())
          {
          done = false;
          tmp = book[j];
          book[j] = book[j+1];
          book[j+1] = tmp;


          }
    }
      }
}

/////////////////////////////////////////////////////////

void Checkbook::date_sort()
{
  bool done = false;
    int j;
    Check tmp;
    while(!done)
    {
    done = true;
    for(j=0; j < used-1; ++j)
    {
      if(book[j].get_date() > book[j+1].get_date())
          {
          done = false;
          tmp = book[j];
          book[j] = book[j+1];
          book[j+1] = tmp;


          }
    }
      }
}

/////////////////////////////////////////////////////////

void Checkbook::show(const std::string& p)const
{
  for (size_t i = 0; i < used; ++i)
  {
      if (book[i].get_payto()== p)
      {
        std::cout << book[i] << '\n';
      }
  }
}

/////////////////////////////////////////////////////////

double Checkbook::average()const
{
  double temp = 0;
  for (size_t i = 0; i < used; ++i)
  {
    temp = book[i].get_amount()+temp;
  }
  return(temp/used);

}

/////////////////////////////////////////////////////////

void Checkbook::save(std::ostream& outs)const
{
  outs << balance << endl;
  for (size_t i = 0; i < used; ++i)
 {
    outs << book[i];

  }
}

/////////////////////////////////////////////////////////
