String voice;

int light1=2; 
int light2= 3;
int light3= 4;
int light4= 5;
int fan=6;

void allon() {
digitalWrite(light1, HIGH);

digitalWrite(light2, HIGH);
digitalWrite(light3, HIGH);
digitalWrite(light4, HIGH);
digitalWrite(fan, HIGH);

}

void alloff() {

digitalWrite(light1, LOW);

digitalWrite(light2, LOW);

digitalWrite(light3, LOW);

digitalWrite(light4, LOW);
digitalWrite(fan, LOW);

}

void setup() {

Serial.begin(9600);

pinMode(light1, OUTPUT);

pinMode(light2, OUTPUT);
pinMode(light3, OUTPUT);
pinMode(light4, OUTPUT);
pinMode(fan, OUTPUT);

}

void loop() {

while (Serial.available()){ //Check if there is an available byte to read

delay(10); //Delay added to make thing stable

char c = Serial.read(); //Conduct a serial read

if (c == '#') {break;} //Exit the loop when the # is detected after the word

voice += c; //Shorthand for voice = voice + c

}

if (voice.length() > 0) {

Serial.println(voice);

if(voice == "*1") 
{
  allon();
  } //Turn Off All Pins (Call Function)

else if(voice == "*2")
{
  alloff();
  } //Turn On All Pins (Call Function)

//----------Turn On One-By-One----------//

else if(voice == "*3") 
{
  digitalWrite(light1, HIGH);
  }

else if(voice == "*4") 
{
  digitalWrite(light2, HIGH);
  }
  else if(voice == "*5") 
{
  digitalWrite(light3, HIGH);
  }
  else if(voice == "*6") 
{
  digitalWrite(light4, HIGH);
  }
else if(voice == "*7") 
{
  digitalWrite(fan, HIGH);
  }



//----------Turn Off One-By-One----------//
else if(voice == "*8") 
{
  digitalWrite(light1, LOW);}

else if(voice == "*9")
{
  digitalWrite(light2, LOW);
  }
  else if(voice == "*10")
{
  digitalWrite(light3, LOW);
  }
    else if(voice == "*11")
{
  digitalWrite(light4, LOW);
  }
    else if(voice == "*12")
{
  digitalWrite(fan, LOW);
  }

else if(voice == "*13") 
{
  digitalWrite(light1, LOW); 
  digitalWrite(light2, LOW);
  digitalWrite(light3, LOW);
  digitalWrite(light4, LOW);
  digitalWrite(fan, LOW);
  
  }
  else if (voice == "*full speed")
  {
      analogWrite(fan, 255);
 
      }
 
 else if (voice == "*medium speed")
  {
      analogWrite(fan, 191);
     
      }
     else if (voice == "*half speed")
      {
        analogWrite(fan, 127);
       
      }
     else if (voice == "*slow speed")
      {
        analogWrite(fan,64);
        
      }
      
voice="";
}} //Reset the variable after initiating
