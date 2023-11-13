#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include"SplashScreen.h"
#include"Login"
int main()
{
int choose;
SplashScreen();
sleep(5);
system("CLS");
printf("Press 1 to register\nPress 2 to login");
scanf("%d",&c);
if(choose==1)
{
    system("CLS");
    regi(); 
}
else if(choose==0)
{
    system(CLS);
    login();
return 0;
}