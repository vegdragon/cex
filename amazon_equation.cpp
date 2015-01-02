#include <iostream>
#include <cstring>

using namespace std;

/************************************************************************/
/**
 Args:
 array[]: the inputted array
 final: the target value
 length: the element length
*/

void createEquationAndPrint(int array[], int length, int final){
  //Your Code is here
  static int maxlen = -1;
  static char * strEquation = NULL;

  // remember array length
  if (maxlen<len)
  {
    maxlen = len;
  }

  if (NULL == strEquation)
  {
    strEquation = new char[maxlen*2+2];
  }

  switch(length)
  {
  case 1:
    // exit recursive loop, calculate result
    break;
  case 2:
    // calculate plus result

    // calculate minus result

    break;
  default:

  }



  cout<<"Invalid";
 }



int splitAndConvert(char* strings,int array[]){
  char*tokenPtr = strtok(strings," ");
  int i=0;
  while(tokenPtr!=NULL){
  array[i] = atoi(tokenPtr);
  i++;
  tokenPtr=strtok(NULL," ");
 }
 return i;
}

int main(){
 char line[1000] = {0} ;
 while(gets(line)){
  int array[30] = {0};
  int length = splitAndConvert(line,array);
  if(length==0){
   break;
  }
  createEquationAndPrint(array, length-1, array[length-1]);
  cout<<endl;
 }
 return 0; 
} 
