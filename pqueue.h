
// - header file for priority printer queue 
// - heaptree priority queue impleneted using an array

// ---------------------------------------------

#include <iostream>
using namespace std;

int const MAX = 11; //11 slots in the array 

class pqueue
{
  private:

  int Q[MAX];   // array holding jobs - only priority numbers are stored
  int count;   // how many jobs are in the array "currently in the array", so the slots occupied can be zero to count-1, THE NEXT EMPTY SLOT IS COUNT 
               // jobs are in slots 0 through count-1

  // Utility functions
  void swap(int, int);  
  void reheapify();  // reheapify after printing Swap,  the 2 locations ,I added   swap Parent anh Child "swap, swap swap" stop when Child is larger then Parent

      // - involves moving the last job to the front and trickling down
  int  getSmallerchild(int);  // return location of the smaller child
                  //- compares L and R children of the given location
  void trickleup();    // trickling up after adding at the rear, after u added to slot count you have to trickle up ,
  //TO DO THAT WE NEED THE LOCATION OF THE PARENT  
  int getParent(int);  // return the parent location given the child loc
  // TO DO THAT WE HAVE TO KNOW WHETHER THE CHILD IS EVEN OR ODD 
  bool even(int);      // is the number even?  Needed to find the parent

public:
    pqueue();
    ~pqueue();
    void insertjob(int);  // supply the job priority number
    void printjob();      // print a job
    void displayAll();    // display all jobs

};
