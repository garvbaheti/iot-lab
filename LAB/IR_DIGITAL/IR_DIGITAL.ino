int ledPin = 12; // choose pin for the LED
int inputPin = 13; // choose input pin (for Infrared sensor) 
int val = 0; // variable for reading the pin status

void setup() 
{ 
   pinMode(ledPin, OUTPUT); // declare LED as output 
   pinMode(inputPin, INPUT); // declare Infrared sensor as input
   Serial.begin(9600);
}

void loop()
{ 
   val = digitalRead(inputPin); // read input value 
   if (val == HIGH)
   { // check if the input is HIGH
      digitalWrite(ledPin, HIGH); // turn LED ON 
      Serial.println("OBJECT DETECTED");  
   } 
   else 
   { 
      digitalWrite(ledPin, LOW); // turn LED OFF 
      Serial.println("NO OBJECT DETECTED");
   } 
}
