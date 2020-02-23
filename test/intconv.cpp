using namespace std;
//#include <stdio.h>
#include <string.h>
#include <iostream>
char *binbin(int n,int size);
int main()
{
 long input;
 int x=0;
 char unsplitbin[65], splitbin[65];
 cout << "Type a value 0 to 2,147,483,647: ";
 cin >> input;

 strcpy(unsplitbin, binbin(input,32));
 for(int y=0;y<32;y++){
  splitbin[x] = unsplitbin[y];
  if((y+1)%4 == 0 && y != 0){
   x++;
   splitbin[x] = ' ';
  }
  x++; 
 }
 splitbin[x]='\0';
// printf("%d is %X hex and binary %s\n",input,input,splitbin);
 cout << input << " is " << hex << input << " hex " << splitbin << " binary" << endl;

int output[4];
  output[0] = input | 0xF000;
  output[1] = input | 0x0F00;
  output[2] = input | 0x00F0;
  output[3] = input | 0x000F;
for(int x=0;x<4;x++){
  cout << binbin(output[x],4) << " ";
}

cout << endl;

return(0);
}
char *binbin(int n, int size)
{
 static char bin[64];
 int x;
 for(x=0;x<size;x++)
 {
 bin[x] = n & 0x8000 ? '1' : '0';
 n <<= 1;
 }
 bin[x] = '\0';
 return(bin);
}
