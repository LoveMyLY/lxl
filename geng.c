#include <stdio.h>
int main()
{
  int i,A,B,C,D,E,n,s;
  A=B=C=D=E=0;
  printf("Enter n:");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  {
    printf("Enter grade %d:",i+1);
    scanf("%d",&s);
    switch(s/10)
     {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:E++;break;
        case 6:D++;break;
        case 7:C++;break;
        case 8:B++;break;
        case 9:
        case 10:A++;break;
      }
  }
  printf("The number of A(90~100):%d\n",A);
  printf("The number of B(80~89):%d\n",B);
  printf("The number of C(70~79):%d\n",C);
  printf("The number of D(60~69):%d\n",D);
  printf("The number of E(0~59):%d\n",E);
  return 0;
}
