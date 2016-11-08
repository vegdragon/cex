#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

void printMatrix (int ** matrix, int lenX, int lenY)
{
    for (int y=0;y<lenY;y++)
    {
      for (int x=0;x<lenX;x++) printf("%d\t", matrix[y][x]);
      printf("\n");
    }
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

  printMatrix (matrix, lenB+1, lenA+1);

  do {
    printf ("x=%d, y=%d\n", x, y);
    if (y==0 && x>0) 
    {
      strResultA[ry--] = '_';
      strResultB[rx--] = strB[x-1];
      x--;
      continue;
    }
    if (x==0 && y>0)
    {
      strResultA[ry--] = strA[y-1];
      strResultB[rx--] = '_';
      y--;
      continue;
    }
    
    printf ("strA[y]=%c, strB[x]=%c\n", strA[y-1], strB[x-1]);
    if (strA[y-1] == strB[x-1]) 
    { 
      strResultA[ry--] = strA[y-1];
      strResultB[rx--] = strB[x-1];
      x--; y--;
    }
    else {
      int a = matrix[y-1][x-1];
      int b = matrix[y-1][x];
      int c = matrix[y][x-1];
      int idx = minIdx (a, b);

      printf ("a=%d, b=%d, c=%d\n", a, b, c);
      if (idx == 0) // a <= b
      {
        idx = minIdx (a, c);
        if (idx == 0) // a <=c, scenario a
        {
          printf ("  scenario a\n"); 
          strResultA[ry--] = strA[y-1];
          strResultB[rx--] = strB[x-1];        
          x--; y--; 
        }
        else if (idx == 1) // c < a <= b, scenario c
        {
          printf ("  scenario c\n");
          strResultA[ry--] = '_';
          strResultB[rx--] = strB[x-1];
          x--; 
        }
      }
      else if (idx == 1) // b < a
      {
         idx = minIdx (b, c);
         if (idx == 0) // scenario b
         { 
           printf ("  scenario b\n");
           strResultA[ry--] = strA[y-1];
           strResultB[rx--] = '_';
           y--;
         }
      }
    }
  } while (x>=0 || y>=0);

  cout << strResultA+1 << endl;
  cout << strResultB+1 << endl;

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

  //const char strA[] = "CDE#FG#AB";
  //const char strB[] = "DDEFGAC";
  cout<<longestDistance(strA, strB)<<endl;

  return 0;
}
