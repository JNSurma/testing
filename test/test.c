#include <stdio.h>
#include <string.h>

char *binbin(int n);
int main()
{
 int input;
 int x=0;
 char unsplitbin[17], splitbin[20];
 printf("Type a value 0 to 65535: ");
 scanf("%d",&input);

 strcpy(unsplitbin, binbin(input));
 for(int y=0;y<16;y++){
  splitbin[x] = unsplitbin[y];
  if((y+1)%4 == 0 && y != 0){
//printf("\nx:%d  y:%d  bin: %s split: %s",x,y,unsplitbin, splitbin);
   x++;
   splitbin[x] = ' ';
  }
//  splitbin[x] = unsplitbin[y];
  x++; 
 }
 splitbin[x]='\0';
 printf("%d is %X hex and binary %s\n",input,input,splitbin);
 return(0);
}
char *binbin(int n)
{
 static char bin[17];
 int x;
 for(x=0;x<16;x++)
 {
 bin[x] = n & 0x8000 ? '1' : '0';
 n <<= 1;
 }
 bin[x] = '\0';
 return(bin);
}
/*end of test*/
