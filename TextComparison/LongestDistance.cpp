#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a):(b))

/**
 *  @return 0 if x <= y
 *          1 if x > y
 */
int minIdx (int x, int y)
{
   int idx = -1;
   if (x<=y) idx = 0;
   else idx = 1;

   return idx;
}

int min (int a, int b, int c)
{
  int result = (a<b ? a:b);
  result = result<c ? result:c;

  return result;
}

void snake (int ** matrix, const char * strA, const char * strB)
{
  const int lenA = strlen(strA);
  const int lenB = strlen(strB);
  int lenResult = MAX(lenA, lenB);

  char * strResultA = new char[lenResult+1];
  char * strResultB = new char[lenResult+1];
  strResultA[lenResult] = strResultB[lenResult] = 0;

  int x = lenB;
  int y = lenA;
  int rx = lenResult;
  int ry = lenResult;

  do {
    if (y==0 && x>0) 
    {
      strResultA[ry--] = '_';
      strResultB[rx--] = strB[x];
      x--;
    }
    if (x==0 && y>0)
    {
      strResultA[ry--] = strA[y];
      strResultB[rx--] = '_';
      y--;
    }

    if (strA[y] == strB[x]) 
    { 
      strResultA[ry--] = strA[y];
      strResultB[rx--] = strB[x];
      x--; y--; 
    }
    else {
      int a = matrix[y-1][x-1];
      int b = matrix[y-1][x];
      int c = matrix[y][x-1];

      int idx = minIdx (a, b);
      if (idx == 0) // a <= b
      {
        idx = minIdx (a, c);
        if (idx == 0) // a <=c, scenario a
        { 
          strResultA[ry--] = strA[y];
          strResultB[rx--] = strB[x];        
          x--; y--; 
        }
        else if (idx == 1) // c < a <= b, scenario c
        {
          strResultA[ry--] = '_';
          strResultB[rx--] = strB[x];
          x--; 
        }
      }
      else if (idx == 1) // b < a
      {
         idx = minIdx (b, c);
         if (idx == 0) // scenario b
         { 
           strResultA[ry--] = strA[y];
           strResultB[rx--] = '_';
           y--;
         }
      }
    }
  } while (x>=0 || y>=0);

  cout << strResultA << endl;
  cout << strResultB << endl;

  delete [] strResultA;
  delete [] strResultB;

  return;
}

int longestDistance(const char * strA, const char * strB)
{
  int result = -1;
  const int lenA = strlen(strA);
  const int lenB = strlen(strB);
  int i=0; int j=0;

  int ** matrix = new int*[lenA+1];
  for (i=0;i<=lenA;i++) matrix[i] = new int[lenB+1];

  if (matrix == NULL) goto ret;

  matrix[0][0] = 0;

  for (i=1;i<=lenA;i++) matrix[i][0] = i;
  for (j=1;j<=lenB;j++) matrix[0][j] = j;

  for (i=0;i<lenA;i++)
  {
    for (j=0;j<lenB;j++)
    {
      if (strA[i]==strB[j]) 
        matrix[i+1][j+1] = matrix[i][j];
      else
        matrix[i+1][j+1] = min(matrix[i][j], matrix[i+1][j], matrix[i][j+1]) + 1; 
    }
  }
  result = matrix[lenA][lenB];

  snake (matrix, strA, strB);

  for (i=0;i<=lenA;i++) delete [] matrix[i];
  delete [] matrix;

ret:
  return result;
}

int main()
{
  const char strA[] = "GGATCGA";
  const char strB[] = "GAATTCAGTTA";

  cout<<longestDistance(strA, strB)<<endl;

  return 0;
}
