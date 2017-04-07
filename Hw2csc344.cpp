/* Marcello Cierro
   Assignent #2 Due Friday November. 4th 2016

   This program will simulate a fish vendor who sells his storage based on the
   criteria that the oldest fish must be sold first. The command line is used to
   specify if a customer wants to buy fish, or if the merchant wants to stock his
   fish. There are set values of fish for each type, for example; For every
   box of shrimp there are 50 shrimp.

   The primary data structure utilized is priority queueing. As well utilization
   of command line options. Priority queue is used to make simulate the arrival
   and departure of the fish product.

   Uses while loop to begin the sequence, though implementation can be described
   decent at best. I imagine a for loop would have been better though I could
   not figure out how to do so.

   Users are prompted to enter an event, a date, a fishtype, and a quantity.
   For example;
   stock 10/01/2015 shrimp 3
   This stocks 3 crates of shrimp each containing 50 shrimp each, so 150 shrimp
   total.
   Another example buying would be.
   buy 11/11/2015 shrimp 25
   This would purchase 25 shrimp from the topmost box of shrimp, while opening
   the said box. Should a user buy more than what a crate is carrying, it will
   open the second box or third box if needed while depleteing and removing the
   now empty boxes.

   Errors are not handled well, as the assumption is that the user, at least in
   this program, is aware of the limitations. Also I couldnt get it to work :(

   Data and data structures utilized involve priority queues, string pointers,
   boolean operators, for and while loops,

   Code reference from Odendahl
   http://www.cs.oswego.edu/~odendahl/coursework/csc344/eg-programs/cpp/stl/priority-queue/main3.cc
   
  */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;


class FishBox {

  //made variables public to mostly avoid getter methods
public:
  int year, month, day;
  FishBox(int m, int d, int y){
	 month = m;
	 day = d;
	 year = y;
  }
  bool isClosed = true;
};

//down below are derivations of the Fishbox class
class Shrimp: public FishBox{
public:
  Shrimp(int m, int d, int y)
	: FishBox(m,d,y){
  }
  int countShrimp = 50;
};

class Lobster: public FishBox{
public:
  Lobster(int m, int d, int y)
	: FishBox(m,d,y){
  }
  int countLobster = 4;
};

class Crab: public FishBox{
public:
  Crab(int m, int d, int y)
	: FishBox(m,d,y){
  }
  int countCrab = 6;
};

class Swordfish: public FishBox{
public:
  Swordfish(int m, int d, int y)
	: FishBox(m,d,y){
  }
  int countSwordfish = 8;
};

int to_int(char const *s) {
     if ( *s == '/' )
         ++s;
     int result = 0;
      while(*s){
          if ( *s >= '0' && *s <= '9' ){
		result = result * 10  + (*s - '0');
          } else if(*s == '/'){
	break;
	}
          else
              break;
          ++s;
     }
    return result;
}

bool operator<(const FishBox& x, const FishBox& y){
	if (x.isClosed > y.isClosed) return true;
	if (x.isClosed == y.isClosed && x.year > y.year) return true;
	if (x.isClosed == y.isClosed && x.year == y.year && x.month > y.month) return true;
	if (x.isClosed == y.isClosed && x.year == y.year && x.month == y.month && x.day > y.day) return true;
	return false;
}

int main(int argc, char* argv[]) {

	string event;
	char date[10];
	string food;
	int amount;

	priority_queue<Shrimp> ShQ;
	priority_queue<Lobster> LQ;
	priority_queue<Crab> CQ;
	priority_queue<Swordfish> SfQ;

	priority_queue<Shrimp> test1;
	priority_queue<Lobster> test2;
	priority_queue<Crab> test3;
	priority_queue<Swordfish> test4;


  //the while loop works, though im not sure how,
  //If end is entered nothing happens, yet if I remove the while loop the program brreaks
	while(event != "End"){

	cin >> event;
	for(int i = 0; i<10; i++){
	    cin >> date[i];
	}
	cin >> food;
	cin >> amount;


	int month = to_int(date);
	int day = to_int(date + 3);
	int year = to_int(date + 6);


  //case 1 is stock, I wanted to implement cases though I could not
  if(event == "stock"){
      if(food == "shrimp"  ){
        cout << "Adding shrimp to stockpile" << endl;
       cout << "Shrimp: ";
       for (int i = 0; i < amount; i++) {
           ShQ.push(Shrimp(month,day,year));
       }
       //this for loop keys track of the stock's order same for all other classes
        test1 = ShQ;
           int x = test1.size();
           for(int i = 0; i < x; i++){
           cout << "Shrimp[50(50)" << test1.top().month << "/" << test1.top().day << "/" << test1.top().year << "]" << "c" << " ";
           test1.pop();
       } cout << endl;
      }




	  if(food == "lobster"){
	     cout << "Adding lobster to stockpile" << endl;
      cout << "Lobster: ";
	    for(int i = 0; i < amount; i++){
	      LQ.push(Lobster(month,day,year));
      }
       test2 = LQ;
        int x = test2.size();
        for(int i = 0; i < x; i++){
          cout << "Lobster[4(4)" << test2.top().month << "/" << test2.top().day << "/" << test2.top().year << "]" << "c" << " ";
          test2.pop();
	    } cout << endl;
	  }


    if(food == "crab"){
	     cout << "Adding crab to stockpile" << endl;
      cout << "Crab: ";
	    for(int i = 0; i < amount; i++){
	      CQ.push(Crab(month,day,year));
      }
       test3 = CQ;
        int x = test3.size();
        for(int i = 0; i < x; i++){
          cout << "Crab[6(6)" << test3.top().month << "/" << test3.top().day << "/" << test3.top().year << "]" << "c" << " ";
          test3.pop();
	    } cout << endl;
	  }




    if(food == "swordfish"){
	     cout << "Adding swordfish to stockpile" << endl;
      cout << "swordfish: ";
	    for(int i = 0; i < amount; i++){
	      SfQ.push(Swordfish(month,day,year));
      }
       test4 = SfQ;
        int x = test4.size();
        for(int i = 0; i < x; i++){
          cout << "Swordfish[8(8)" << test4.top().month << "/" << test4.top().day << "/" << test4.top().year << "]" << "c" << " ";
          test4.pop();
	    } cout << endl;
	  }

	}

  //second case, is buy. I am painfully aware of the redundencies, however could not implement a template class to...
  //...consolidate code. The comments below apply for all respective seafood
	if(event == "buy"){
	if(ShQ.size() != 0){
	  if(food == "shrimp"){
		cout << "selling some product from stockpile" << endl;
  //different situations, this takes care of the case in which 50 a whole crate it bought
  	if(50 == amount){
			ShQ.pop();
		}
		cout << "Using some resources from stockpile" << endl;
    //this opens another box if the limit per seafood is reached, ie buying 60 uses 1 box completely and opens another box for 10

    if(amount > 50){
			int leftOver = amount - 50;
			ShQ.pop();
			while(leftOver > 50){
			   ShQ.pop();
			   leftOver = leftOver - 50;
			}

      //my error here is that there is no way to store the bought food per trail
      //Need some type of variable which tracks and updates the amount of food bought for the runtime of the program.
			if(leftOver < 50){
			   Shrimp s = Shrimp(ShQ.top().month, ShQ.top().day, ShQ.top().year);
			   s.countShrimp = s.countShrimp-leftOver;
			   s.isClosed = false;
			   ShQ.pop();
			   ShQ.push(s);
			   cout << "DEBUG: have " << s.countShrimp << " units left." << endl;
			   cout << "Shrimp[50(" << s.countShrimp << ")" << s.month << "/" << s.day << "/" << s.year << "]" << "o" <<endl;
			   test1 = ShQ;
		           int x = test1.size();
		           for(int i = 0; i < x-1; i++){
			       test1.pop();
			       cout << "Shrimp[50(50)" << test1.top().month << "/" << test1.top().day << "/" << test1.top().year << "]" << "c" <<endl;
			   }

			}
		} else {
			Shrimp s = Shrimp(ShQ.top().month, ShQ.top().day, ShQ.top().year);
			s.countShrimp = s.countShrimp-amount;
			s.isClosed = false;
			ShQ.pop();
			ShQ.push(s);
			cout << "DEBUG: have " << s.countShrimp << " units left." << endl;
		        cout << "Shrimp[50(" << s.countShrimp << ")" << s.month << "/" << s.day << "/" << s.year << "]" << "o" <<endl;
			   test1 = ShQ;
		           int x = test1.size();
		           for(int i = 0; i < x-1; i++){
			       test1.pop();
			       cout << "Shrimp[50(50)" << test1.top().month << "/" << test1.top().day << "/" << test1.top().year << "]" << "c" <<endl;
			   }

		}
	  }
	}
	if(LQ.size() != 0){
	if(food == "lobster"){
		cout << "selling some product from stockpile" << endl;
		if(LQ.top().countLobster == amount){
			LQ.pop();
		}
		cout << "Using some resources from stockpile" << endl;
		if(amount > 4){
			int leftOver = amount - 4;
			LQ.pop();
			while(leftOver > 4){
			   LQ.pop();
			   leftOver = leftOver - 4;
			}
			if(leftOver < 4){
			   Lobster s = Lobster(LQ.top().month, LQ.top().day, LQ.top().year);
			   s.countLobster = s.countLobster-leftOver;
			   s.isClosed = false;
			   LQ.pop();
			   LQ.push(s);
			   cout << "DEBUG: have " << s.countLobster << " units left." << endl;
			   cout << "Lobster[4(4)(" << s.countLobster << ")" << s.month << "/" << s.day << "/" << s.year << "]" << "o" <<endl;
			   test2 = LQ;
		           int x = test2.size();
		           for(int i = 0; i < x-1; i++){
			       test2.pop();
			       cout << "Lobster[4(4)" << test2.top().month << "/" << test2.top().day << "/" << test2.top().year << "]" << "c" <<endl;
			   }

			}
		} else {
			Lobster s = Lobster(LQ.top().month, LQ.top().day, LQ.top().year);
			s.countLobster = s.countLobster-amount;
			s.isClosed = false;
			LQ.pop();
			LQ.push(s);
			cout << "DEBUG: have " << s.countLobster << " units left." << endl;
		        cout << "Lobster[4(" << s.countLobster << ")" << s.month << "/" << s.day << "/" << s.year << "]" << "o" <<endl;
			   test2 = LQ;
		           int x = test2.size();
		           for(int i = 0; i < x-1; i++){
			       test2.pop();
			       cout << "Lobster[4(4)" << test2.top().month << "/" << test2.top().day << "/" << test2.top().year << "]" << "c" <<endl;
			   }

		}
	  }
	}

	if(CQ.size() != 0){
	if(food == "crab"){
		cout << "selling some product from stockpile" << endl;
		if(CQ.top().countCrab == amount){
			CQ.pop();
		}
		cout << "Using some resources from stockpile" << endl;
		if(amount > 6){
			int leftOver = amount - 6;
			CQ.pop();
			while(leftOver > 6){
			   CQ.pop();
			   leftOver = leftOver - 6;
			}
			if(leftOver < 6){
			   Crab s = Crab(CQ.top().month, CQ.top().day, CQ.top().year);
			   s.countCrab = s.countCrab-leftOver;
			   s.isClosed = false;
			   CQ.pop();
			   CQ.push(s);
			   cout << "DEBUG: have " << s.countCrab << " units left." << endl;
			   cout << "Crab[6(" << s.countCrab << ")" << s.month << "/" << s.day << "/" << s.year << "]" << "o" <<endl;
			   test3 = CQ;
		           int x = test3.size();
		           for(int i = 0; i < x-1; i++){
			       test3.pop();
			       cout << "Crab[6(6)" << test3.top().month << "/" << test3.top().day << "/" << test3.top().year << "]" << "c" <<endl;
			   }

			}
		} else {
			Crab s = Crab(CQ.top().month, CQ.top().day, CQ.top().year);
			s.countCrab = s.countCrab-amount;
			s.isClosed = false;
			CQ.pop();
			CQ.push(s);
			cout << "DEBUG: have " << s.countCrab << " units left." << endl;
		        cout << "Crab[6(" << s.countCrab << ")" << s.month << "/" << s.day << "/" << s.year << "]" << "o" <<endl;
			   test3 = CQ;
		           int x = test3.size();
		           for(int i = 0; i < x-1; i++){
			       test3.pop();
			       cout << "Crab[6(6)" << test3.top().month << "/" << test3.top().day << "/" << test3.top().year << "]" << "c" <<endl;
			   }

		}
	  }
  	}
	if(SfQ.size() != 0){
	if(food == "swordfish"){
		cout << "selling some product from stockpile" << endl;
		if(SfQ.top().countSwordfish == amount){
			SfQ.pop();
		}
		cout << "Using some resources from stockpile" << endl;
		if(amount > 8){
			int leftOver = amount - 8;
			SfQ.pop();
			while(leftOver > 8){
			   SfQ.pop();
			   leftOver = leftOver - 8;
			}
			if(leftOver < 8){
			   Swordfish s = Swordfish(SfQ.top().month, SfQ.top().day, SfQ.top().year);
			   s.countSwordfish = s.countSwordfish-leftOver;
			   s.isClosed = false;
			   SfQ.pop();
			   SfQ.push(s);
			   cout << "DEBUG: have " << s.countSwordfish << " units left." << endl;
			   cout << "Swordfish[8(" << s.countSwordfish << ")" << s.month << "/" << s.day << "/" << s.year << "]" << "o" <<endl;
			   test4 = SfQ;
		           int x = test4.size();
		           for(int i = 0; i < x-1; i++){
			       test4.pop();
			       cout << "Swordfish[8(8)" << test4.top().month << "/" << test4.top().day << "/" << test4.top().year << "]" << "c" <<endl;
			   }

			}
		} else {
			Swordfish s = Swordfish(SfQ.top().month, SfQ.top().day, SfQ.top().year);
			s.countSwordfish = s.countSwordfish-amount;
			s.isClosed = false;
			SfQ.pop();
			SfQ.push(s);
			cout << "DEBUG: have " << s.countSwordfish << " units left." << endl;
		        cout << "Swordfish[8(" << s.countSwordfish << ")" << s.month << "/" << s.day << "/" << s.year << "]" << "o" <<endl;
			   test4 = SfQ;
		           int x = test4.size();
		           for(int i = 0; i < x-1; i++){
			       test4.pop();
			       cout << "Swordfish[8(8)" << test4.top().month << "/" << test4.top().day << "/" << test4.top().year << "]" << "c" <<endl;
			   }

		}
	  }

	}
	}
}
 return 0;
}
