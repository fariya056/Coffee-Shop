void splashscreen(void)
{
FILE *fpt;
char ch;
fpt=fopen("splash.txt","r");
if(fpt==NULL)
{
printf("File not found");
}
c=fgetc(fpt);
while(ch!=EOF)
{
printf("%c",ch);
ch=fgetc(fpt);
}
fclose(fpt);
}