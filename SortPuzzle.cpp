#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class base{
	protected:
	int move_count;//to count the moves
	int i1 , j1 ;//position of 1st 0
	int i2 , j2 ;//position of 2nd 0
    public:
    virtual void display_puzzle()=0;
};

class display;

class swapnil: public base{
public:
int a[4][4] = { {0 , 1, 2, 3}, {5, 6, 4, 8}, {7, 9, 10, 12}, {13, 11, 14, 0} };
//constructor for initialization
swapnil(){
move_count=0;
i1 = 0, j1 = 0;
i2 = 3, j2 = 3;
}
//member functions
virtual void display_puzzle ();		//to display the puzzle board
void Slect_zero_toMove ();			//to display move 0 options
void move_1 ();						//move 1st zero
void move_2 ();						//move 2nd zero
int submit_puzzle ();				//to check if puzzle solved
void position_of_zero ();
void swap_zero (int i, int j);
friend class display;
};


//friend class
class display{
    public:
    void run(swapnil &o1){
        o1.Slect_zero_toMove();
    }
};

int main ()
{
    swapnil s1;//default constructor called
    display d1;
    d1.run(s1);
    return 0;
}

//main function to move numbers
void swapnil:: Slect_zero_toMove()
{
  display_puzzle ();
  int check;

  while (1)
    {
      cout<<"\n 1:For 1st zero";
      cout<<"\n 2:For 2nd zero";

      cout<<"\nenter which position you want to move:=";
      cin>>check;
      switch (check)
	{
	case 1:
	  {
	    move_count++;
	    move_1 ();
	    break;
	  }
	case 2:
	  {
	    move_count++;  
	    move_2 ();
	    break;
	  }
	default:
	  {
	    cout<<"\ninvalid input:";
	    break;
	  }

	}
    }
}


//moving first 0
void swapnil:: move_1 ()
{
  int check1, temp ;
  cout<<"\n....................................................................................";
  cout<<"\n 1: right";
  cout<<"\n 2: left";
  cout<<"\n 3: up";
  cout<<"\n 4: down";
  cout<<"\n 5: exit";
  cout<<"\n 6: submit";
  cout<<" \n\n         Move:- ";
  
  cin>>check1;
  switch (check1)
    {
    case 1:
      if (j1 == 3)
	{
	  cout<<"NOT POSSIBLE";
	  cout<<" \n";
	  display_puzzle ();
	  break;
	}
      else
	{
	  temp = a[i1][j1];
	  a[i1][j1] = a[i1][j1 + 1];
	  a[i1][j1 + 1] = temp;
	  j1 = j1 + 1;
	  display_puzzle ();
	  break;
	}
    case 2:
      if (j1 == 0)
	{
	  cout<<"NOT POSSIBLE";
	  cout<<" \n";
	  display_puzzle ();
	  break;

	}
      else
	{
	  temp = a[i1][j1];
	  a[i1][j1] = a[i1][j1 - 1];
	  a[i1][j1 - 1] = temp;
	  j1 = j1 - 1;
	  display_puzzle ();
	  break;
	}
    case 3:
      if (i1 == 0)
	{
	  cout<<"NOT POSSIBLE";
	  cout<<" \n";
	  display_puzzle ();
	  break;
	}
      else
	{
	  temp = a[i1][j1];
	  a[i1][j1] = a[i1 - 1][j1];
	  a[i1 - 1][j1] = temp;
	  i1 = i1 - 1;
	  display_puzzle ();
	  break;
	}
    case 4:
      if (i1 == 3)
	{
	  cout<<"NOT POSSIBLE";
	  cout<<" \n";
	  display_puzzle ();
	  break;
	}
      else
	{
	  temp = a[i1][j1];
	  a[i1][j1] = a[i1 + 1][j1];
	  a[i1 + 1][j1] = temp;
	  i1 = i1 + 1;
	  display_puzzle ();
	  break;
	}
    case 5:
      exit(0);
    case 6:
      submit_puzzle ();
      break;
    default:
      cout<<"\nenter the valid choice";
    }
}

//moving second 0
void swapnil:: move_2()
{
  int check1, temp;
  cout<<"\n....................................................................................";
  cout<<"\n 1: right";
  cout<<"\n 2: left";
  cout<<"\n 3: up";
  cout<<"\n 4: down";
  cout<<"\n 5: exit";
  cout<<"\n 6: submit";
  cout<<" \n\n         Move:- ";
  cin>>check1;
  switch (check1)
    {
    case 1:
      if (j2 == 3)
	{
	  cout<<"NOT POSSIBLE";
	  cout<<" \n";
	  display_puzzle ();
	  break;
	}
      else
	{
	  temp = a[i2][j2];
	  a[i2][j2] = a[i2][j2 + 1];
	  a[i2][j2 + 1] = temp;
	  j2 = j2 + 1;
	  display_puzzle ();
	  break;
	}
    case 2:
      if (j2 == 0)
	{
	  cout<<"NOT POSSIBLE";
	  cout<<" \n";
	  display_puzzle ();
	  break;

	}
      else
	{
	  temp = a[i2][j2];
	  a[i2][j2] = a[i2][j2 - 1];
	  a[i2][j2 - 1] = temp;
	  j2 = j2 - 1;
	  display_puzzle ();
	  break;
	}
    case 3:
      if (i2 == 0)
	{
	  cout<<"NOT POSSIBLE";
	  cout<<" \n";
	  display_puzzle ();
	  break;
	}
      else
	{
	  temp = a[i2][j2];
	  a[i2][j2] = a[i2 - 1][j2];
	  a[i2 - 1][j2] = temp;
	  i2 = i2 - 1;
	  display_puzzle ();
	  break;
	}
    case 4:
      if (i2 == 3)
	{
	  cout<<"NOT POSSIBLE";
	  cout<<" \n";
	  display_puzzle ();
	  break;
	}
      else
	{
	  temp = a[i2][j2];
	  a[i2][j2] = a[i2 + 1][j2];
	  a[i2 + 1][j2] = temp;
	  i2 = i2 + 1;
	  display_puzzle ();
	  break;
	}
    case 5:
      exit(0);
    case 6:
      submit_puzzle ();
      break;
    default:
      cout<<"\nenter the valid choice";
    }


}

//to display the grid puzzle
void swapnil:: display_puzzle ()
{
  cout<<"\n                                     PUZZLE\n";
  for (int i = 0; i < 4; i++)
    {
      cout<<"                              ";
      for (int j = 0; j < 4; j++)
	{
	  cout<<"|";
	  cout<<"_";
	  cout<<a[i][j];
	  cout<<"_";
	}
      cout<<"|";
      cout<<" \n";
    }
}

//to check if the puzzle is solved
int swapnil :: submit_puzzle ()
{
  position_of_zero ();
  cout<<"\n*****************************\n";
  display_puzzle ();
  int b[4][4] =
    { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14,0,0} };
  for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
	{
	  if (a[i][j] == b[i][j])
	    continue;
	  else
	    cout<<"\n                                   WRONG SUBMIT";
	    cout<<"\n                             YOU HAVE PERFORMED "<<move_count<<" MOVES \n";
	    cout<<"\n*****************************\n";
	  return 0;
	}
    }
  cout<<"\n";
  cout<<"                     :) CONGRATULATION'S THE PUZZLE IS SOLVED :)";
  cout<<"\n                     :) YOU HAVE SOLVED THE PUZZLE IN "<<move_count<<" MOVES:)";
  cout<<"\n*****************************\n";
  exit (0);
}


void swapnil:: position_of_zero ()
{
  for (int i = 0; i < 4; i++)
  {
      for (int j = 0; j < 4; j++)
	{
	  if (a[i][j] == 0)
	    {
	      swap_zero(i, j);
	    }
	}
   }
}

//inline function
 inline void swapnil:: swap_zero (int i, int j)
{
  int temp, row,column;
  while (i != 3 || j != 3)
    {
      if (j == 3)
	{
	  temp = a[i][j];
	  row = i + 1;
	  column = 0;
	  a[i][j] = a[row][column];
	  a[row][column] = temp;
	  i = row;
	  j = column;

	}
      else
	{
	  temp = a[i][j];
	  a[i][j] = a[i][j + 1];
	  a[i][j + 1] = temp;
	  j = j + 1;
	}
    }
}