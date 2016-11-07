#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int min (int a, int b, int c)
{
  int result = (a<b ? a:b);
  result = result<c ? result:c;

  return result;
}

int longestDistance(const char * strA, const char * strB)
{
  int result = -1;
  const int lenA = strlen(strA);
  const int lenB = strlen(strB);
  int i=0; int j=0;

  int ** matrix = new int*[lenB+1];
  for (i=0;i<=lenB;i++) matrix[i] = new int[lenA+1];

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

  for (i=0;i<=lenB;i++) delete [] matrix[i];
  delete [] matrix;

ret:
  return result;
}

int main()
{
  const char strA[] = "GGATCGA";
  const char strB[] = "GAATTCAGTTA";

  cout<<"LD = ";
  cout<<longestDistance(strA, strB)<<endl;

  return 0;
}
