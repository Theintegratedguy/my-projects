#include<stdio.h>
#include<conio.h>
#include<math.h>
#define PI 3.14159

float addition(float,float);
float subtraction(float,float);
float division(float,float);
float multiplication(float,float);
float power(float,float);
double mod(double);
float logbase10(float);
float logbasee(float);
double sine(double);
double cosine(double);
double tangent(double);
double cosecant(double);
double secant(double);
double cotangent(double);
void arcsin();
void arccos();
void arctan();
void inversetrigono();
int main()
{float p,q,x,a;
char answer;
int n,y;
printf("rule 1:select the function by entering the number representing them.\n");
printf("rule 2: if you are using a trigonometric function,then enter the value in degrees.\n");
printf("rule 3: you can use only one operation or function at a time.\n");
do{printf("\n1.addition\n 2.subtraction\n 3.multiplication\n 4.division\n 5.exponent\n 6.natural logarithm\n 7.log\n 8.sin\n 9.cos\n 10.tan\n 11.sec\n 12.cosec\n 13.cot\n 14.modulus\n 15.inverse-trigono functions\n");
printf("choose one of the above functions:\n",n);
 scanf("%d",&n);
 printf("-----------------------------------------------------------\n");
 if(n>0 && n<6)
 {printf("enter the two numbers:",p,q);
 scanf("%f %f",&p,&q);
 switch(n)
 {case 1: addition(p,q);break;
  case 2: subtraction(p,q);break;
  case 3: multiplication(p,q);break;
  case 4: division(p,q);break;
  case 5: power(p,q);
  break;
  default:printf("there might be some problem");}}

else if(n>=6 && n<15)
{printf("enter the number to execute the selected function:",x);
scanf("%f",&x);
switch(n)
{case 6:logbasee(x);break;
 case 7:logbase10(x);break;
 case 8:sine(x);break;
 case 9:cosine(x);break;
 case 10:tangent(x);break;
 case 11:secant(x);break;
 case 12:cosecant(x);break;
 case 13:cotangent(x);break;
 case 14:mod(x);break;
 default: printf("there might be something wrong!!");} }

else if(n==15)
{inversetrigono();}
else printf("please enter a no. from the given list\n");

printf("do you want to use the calculator again(y/n)??\n");
fflush(stdin);
scanf("%c",&answer);}
while(answer=='y');

return 0;}


float addition(float p,float q)
{float sum;
sum=p+q;
printf("the sum of the 2 numbers is: %f\n",sum);}

float subtraction(float p,float q)
{float diff;
diff=p-q;
printf("the difference of the two numbers:%f\n",diff);}

float multiplication(float p,float q)
{float product;
product=p*q;
printf("the product is:%f\n",product);}

float division(float a,float b)
{float y;
y=a/b;
printf("result:%f\n",y);}

float logbasee(float n)
{if(n>0)
     printf("the natural log of %f is:%f\n",n,log(n));
else printf("enter a number in the domain of the function");  }

float logbase10(float n)
{if(n>0)
     printf("the log base 10 of %f is:%f\n",n,log10(n));
else printf("enter a number in the domain of the function");}

double sine(double n)
{double radx,y;
radx= n*(PI/180.0);
y=sin(radx);
printf("the sine of the number is:%f\n",y);}

double cosine(double n)
{double radx,y;
 radx=n*(PI/180.0);
 y=cos(radx);
 printf("the cosine of the number is:%f\n",y);}

double tangent(double n)
{double radx,y;
 radx=n*(PI/180.0);
 y=tan(radx);
 printf("the tangent of the number is:%f\n",y);}

double cosecant(double n)
{double radx,y;
 radx=n*(PI/180.0);
 y=1/sin(radx);
 printf("the cosecant of the number is:%f\n",y);}

double secant(double n)
{double radx,y;
 radx=n*(PI/180.0);
 y=1/(cos(radx));
 printf("the secant of the number is:%f\n",y); }

double cotangent(double n)
{double radx,y;
 radx=n*(PI/180.0);
 y=1/(tan(radx));
 printf("the cotangent of the function:%f\n",y);}

double mod(double n)
{float abs;
if(n>0)
    abs=n;
else
    abs= -1*n;

printf("the absolute value of the number is:%f\n",abs);}

float power(float p,float q)
{float powerx;
powerx=pow(p,q);
printf("result: %f\n",powerx);}

void inversetrigono()
{int b;
printf("1.arcsin\t 2.arccos\t 3. arctan\n");
printf("please choose the function you want to go with:",b);
scanf("%d",&b);
if(b>0 && b<4)
{switch(b)
{case 1:arcsin();break;
 case 2:arccos();break;
 case 3: arctan();break;
 default:printf("there might be something wrong with the code");}  }
 else
        printf("please select a valid option");
}

void arcsin()
{float x;
printf("enter the number whose inverse sine has to calculated: ",x);
scanf("%f",&x);
if(x<=1 && x>=-1)
    printf("arcsine of %f =%f\n",x,asin(x));
else
    printf("please enter a number in the domain of the function");}

void arccos()
{float x;
printf("enter the number whose cos inverse has to be calculated: ",x);
scanf("%f",&x);
if(x<=1 && x>=-1)
    printf("arccosine of %f=%f\n",x,acos(x));
else
    printf("please enter a number in the domain of the function");}

void arctan()
{float x;
printf("enter the number whose tan inverse has to be calculated: ",x);
scanf("%f",&x);

printf("arctan of the %f=%f\n",x,atan(x));}
