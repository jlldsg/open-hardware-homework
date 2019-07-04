#include <Morse.h>
Morse morse(13);
String str="";
String text="";
int n=0,t=0,i,x,k=0,m=0;
char MORSE[][4]=
{
  {'.','-','*','*'},//A
  {'-','.','.','.'},//B
  {'-','.','-','.'},//C
  {'-','.','.','*'},//D
  {'.','*','*','*'},//E
  {'.','.','-','.'},//F
  {'-','-','.','*'},//G
  {'.','.','.','.'},//H
  {'.','.','*','*'},//I
  {'.','-','-','-'},//J
  {'-','.','-','*'},//K
  {'.','-','.','.'},//L
  {'-','-','*','*'},//M
  {'-','.','*','*'},//N
  {'-','-','-','*'},//O
  {'.','-','-','.'},//P
  {'-','-','.','-'},//Q
  {'.','-','.','*'},//R
  {'.','.','.','*'},//S
  {'-','*','*','*'},//T
  {'.','.','-','*'},//U
  {'.','.','.','-'},//V
  {'.','-','-','*'},//W
  {'-','.','.','-'},//X
  {'-','.','-','-'},//Y
  {'-','-','.','.'},//Z
};
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  while(Serial.available()>0)
  {
    t=1;
    str +=char(Serial.read());
    n++;
  }
  if(t)
  {
    for(i=0;i<n;i++)
    {
      if(str[i]>=97 and str[i]<=122)
        for(x=0;x<4;x++)
          text +=char(MORSE[int(str[i]-97)][x]);
      else
      {
        text +=' ';
        k++;
      }
    }
  }
  for(i=0;i<4*n+k-1;i++)
  {
    if(text[i]=='.' and text[i+1]!=' ')
    {
      Morse dot();
      m++;
    }
    else if(text[i]=='-' and text[i+1]!=' ')
    {
      Morse dash();
      m++;                                                                                                                                                                                                                              
    }
    else if(text[i]='*')
      m++;
    else if(text[i]!=' ' and text[i+1]==' ')  
      Morse w_space();
    if(m%4==0)
    {
      Morse c_space();
      m=0;
    }
  }
   if(text[i]=='.' )
     Morse dot(); 
   else if(text[i]=='-')
     Morse dash();

}
