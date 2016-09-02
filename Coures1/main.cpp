#include <iostream>
using namespace std;

class Time {
 private:
  int hours_;
  int minutes_;
  int seconds_;
 public:
  void set(int h, int m, int s) {hours_ = h; minutes_ = m; seconds_ = s; return;}
  void increment();
  void decrement();
  void display();
};

void Time::increment() {
  seconds_++;
  minutes_ += seconds_/60;//every 60s, 1 min
  hours_ += minutes_/60;//every 60 min, 1 hour
  seconds_ %= 60; //remain
  minutes_ %= 60;
  hours_ %= 24;
  return;
}

void Time::decrement(){
	seconds_--;
	if (seconds_<0)
	{
		seconds_+=60;
		minutes_--;
	}
	if (minutes_<0)
	{
		minutes_+=60;
		hours_--;
	}
	if (hours_<0)
	{
		hours_+=24;
	}
    return;
}

void Time::display() {
  cout << (hours_ % 12 ? hours_ % 12:12) << ':'
       << (minutes_ < 10 ? "0" :"") << minutes_ << ':'
       << (seconds_ < 10 ? "0" :"") << seconds_
       << (hours_ < 12 ? " AM" : " PM") << endl;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Copy1(int& a, int& b, int& c);
void Copy2(int a, int b, int c); 
void Copy3(int *a, int *b, int *c);
void DoIt(int &foo, int goo);

void Unknown(int *p, int num);
void HardToFollow(int *p, int q, int *num);

int main() {
	int x = 1, y = 3, z = 7;
	//Demo value passing
	//Copy1(x,y,z);
	//Copy3(&x,&y,&z); //a simple way to pass value by reference in C++
	//cout << "x="<< x << ", y="<< y << ", z="<< z;
	
    //picture of memory
    /*int *foo, *goo;
    foo = new int;
    *foo = 1;
    goo = new int;
    *goo = 3;
    *foo = *goo + 3; //*foo=6

    foo = goo; //point to the same memoey '3'
    *goo = 5; // same memoey '5'
    *foo = *goo + *foo; //'10'
    DoIt(*foo, *goo); //'10','10'
    cout<<(*foo)<<endl;
    cout<<(*goo)<<endl;*/

    //Class and object
    /*Time timer;
    timer.set(23,59,58);
    for (int i = 0; i < 5; ++i)
    {
    	timer.increment();
    	timer.display();
    	cout<<endl;
    }
    for (int i = 0; i < 5; ++i)
    {
    	timer.decrement();
    	timer.display();
    	cout<<endl;
    }*/

    //practice with pointer
  /*int *q;
  int trouble[3];

  trouble[0] = 1;// 1,X,X
  q = &trouble[1];
  *q = 2;//1,2
  trouble[2] = 3;//1,2,3

  HardToFollow(q, trouble[0], &trouble[2]);//address '2', 1, address '3'
  //1, 1, 3
  Unknown(&trouble[0], *q); //

  cout << *q << " " << trouble[0] << " " << trouble[2];
  */
  
  return 0;
}


//Passing parameters by reference
//passing the address of the variable
//Any modification that we do to the local 
//variable actually modifies the original variable passed in. 
void Copy1(int& a, int& b, int& c){
	a *= 2;
	b *= 2;
    c *= 2;
}

//pass the variables "by value",
//Any changes made to the variable in the function modify the copy. 
//They do not modify the original variable.
void Copy2(int a, int b, int c){
	a *= 2;
	b *= 2;
    c *= 2;
} 

//C++ provides a simpler way of passing values to functions by reference
void Copy3(int *a, int *b, int *c){
	*a *= 2;
	*b *= 2;
    *c *= 2;
} 

void DoIt(int &foo, int goo){
  foo = goo + 3;// 13 10
  goo = foo + 4;// 13 17
  foo = goo + 3;// 20 14
  goo = foo;// 20 20
}

void Unknown(int *p, int num) {           //*p  num 1 , 1
  int *q;                               

  q = &num; //q point to address of 'num'
  *p = *q + 2; //pointee p = num + 2        3   1
  num = 7;//num = 7, *q = 7, *p = num + 2   3   7
}

void HardToFollow(int *p, int q, int *num) { //*p q *num  *2,1,*3 (tr 1,0,2)
  *p = q + *num; //pointee p = q + pointee     4  1  3
  *num = q;//pointee num = q                   4  1  1
  num = p;//num point to p pintee              4  1  4                1 0 1
  p = &q;//p point to q                        1  1  1
  Unknown(num, *p);                          //1  1  3
}
