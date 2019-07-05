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
  Morsemorse(13);
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
      Morsedot();
      m++;
    }
    else if(text[i]=='-' and text[i+1]!=' ')
    {
      Morsedash();
      m++;                                                                                                                                                                                                                              
    }
    else if(text[i]='*')
      m++;
    else if(text[i]!=' ' and text[i+1]==' ')  
      Morsew_space();
    if(m%4==0)
    {
      Morsec_space();
      m=0;
    }
  }
   if(text[i]=='.' )
     Morsedot(); 
   else if(text[i]=='-')
     Morsedash();

}
int _dottime=250;
int _pin;
void Morsemorse(int pin)
{
  pinMode(pin,OUTPUT);
  _pin=pin;
  _dottime=250;
}

void Morsedot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morsedash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*3);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morsec_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}

void Morsew_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}
