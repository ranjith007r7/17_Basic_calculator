
#include<LiquidCrystal_I2C.h>
#include<Keypad.h>

const byte ROWS =4;
const byte COLS =4;

char keys[ROWS] [COLS] = {

  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};

byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LiquidCrystal_I2C lcd(0x20, 4,5,6,0,1,2,3,7,NEGATIVE);

int getNumber(){

char key =0;
while (key == 0 || (key >'9' && key < '0'))  //select only numbers
  {
    key =kpd.getKey();
    delay(5);

}
return key -'0'; // convert number in character form to integer form by subtracting ascii of '0'
}

char getOperation()
{
  char key = 0;
  while (key == 0 || (key > 'D' && key < 'A' )) // select only A,B,C or D
  {
    key = kpd.getKey();
    delay(5);
  }
  switch (key)
  {
    case 'A':
        return '+';
    case 'B':
        return '-';
    case 'C':
        return 'x';
    case 'D':
        return '/';
  }
}

void setup() {
  lcd.begin (16,2);

}

void loop() {
  lcd.clear();
  lcd.print("Enter first num");
  lcd.setCursor(0,1);
  lcd.print("number");
  int num1 = getNumber();

  lcd.clear();
  lcd.print("Enter second num");
  lcd.setCursor(0,1);
  lcd.print("number");
  int num2 = getNumber();

  lcd.clear();
  lcd.print("Enter operation");
  lcd.setCursor(0,1);
  lcd.print("A=+ B=- C=x D=/");
  char operation = getOperation();

  int result = 0;
  bool error = false;
  switch (operation)
  {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case 'x':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0){
          result = num1 / num2;
        }
        else{
          error = true;
        }
        
        break;
    

  }

lcd.clear();
String expression = String(num1) + operation + String(num2) + " = " + String(result);


if (!error)
{
  lcd.print(expression.c_str());

}
else{
  lcd.print("Invalid operation");
}
lcd.setCursor(0,1);
lcd.print("Press any key to restart");
while (kpd.getKey() == 0)
{
  delay(5);
}
 
}
