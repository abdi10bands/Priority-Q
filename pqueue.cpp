

// =================================================
//  Priority Printer Queue 
// YOUR NAME: Abdiel Verdin
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  // int x=0;
  cout << "Adding: " << j << endl;
  // ** add the job j at the rear (and update count)
  if(count >=  MAX) // **   if possible else display error message. 
    {
      cout<< "Overflow ! "<<endl;
    }

  else
    {
      Q[count]= j ;
      //      x++;
      count ++;
    }
    trickleup(); // moves the job to the right place
       
    
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  for(int i =0; i<=count -1; i++)// ** loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
    {
      cout<<Q[i]<<" ";
    }
} 


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
  int temp;
  temp = Q[loc1];
  
  Q[loc1]= Q[loc2];

  Q[loc2]= temp;                      // ** swap the values in these locations in Q
}

// Purpose: to make the very last job trickle up to the right location. Never do X--. 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  while(x>0) // ** While x is > 0, like we havent gotten to the root yet   
    {
      int Parent = getParent(x);//    compare Q[x] with the parent (*)
      if (Q[Parent] >Q[x] ) //    and if the parent is bigger swap & update x 
	{
	  //  x=Parent; //change 
	  swap(Parent,x); //call 
	  x=Parent; //change update
	}
      else
	return;
    }
   //    to be the parent . Otherwise stop the loop.
  // (*) Call getParent to get the location of the parent
  //            based on the child's location.

}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{  // ** return the parent location based on the child loc
  if(even(childloc))
    {
      return (childloc-2)/2; //even 
    }
  else 
    {
      return (childloc-1)/2; //odd

    }

}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }




// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  X=0;// ** Start X at 0 (the root)
  while(X<count-1)//    while X is within the array:
    {
     int  LocationOfsmallestChild=  getSmallerchild(X);//       Find the location of the smaller child 
     if( LocationOfsmallestChild > count-1) //         (if the location of both children are off the tree, stop the loop).
	break;
      else if(Q[X]>Q[ LocationOfsmallestChild]) //       If the smaller child is smaller than the parent,
       {
	
	 swap(X, LocationOfsmallestChild); //          swap and X becomes the smaller child's location.
	 X=LocationOfsmallestChild;
       }
       else 
	 break;//       else no swaps so stop to loop.
    }
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
// ** return the location of the smaller child)
//    Be careful because one or both of them may be
//    beyond count-1.  Check boundaries before you 
//    compare Q contents!!!!

  int smallestChild; ///hold smallest child location
  int Leftchild,Rightchild;
  //check 
  if((2*i)+2 <= count-1) //if it has enough elements
    {
      Leftchild = (2*i)+1;
      Rightchild = (2*i)+2;
    }
  else if ((2*i)+1<=count-1)//if oonly the  left child is there
    {
      smallestChild = 2*i+1;
      return smallestChild;
    }
  else    // else position smallest
    {
      smallestChild = i;
      return smallestChild;

    }

  if(Q[Leftchild]> Q[Rightchild]) //switch
    {
      smallestChild = Rightchild;
    }
  else
    {
      smallestChild = Leftchild;
    }
  return smallestChild; //retrun result
}


