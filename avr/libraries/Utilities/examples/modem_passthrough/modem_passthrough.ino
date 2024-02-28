
#define Serial1_7000   // SIM7000A/C/E/G
#define BAUDRATE 9600  // MUST be below 19200 (for stability) but 9600 is more stable

// For SIM7000 BoSL board
// #define PWRKEY 38
// #define DTR 44         // Connect with solder jumper
// #define SIM_BUF_EN 25  // Connect with solder jumper
// #define BOSL_RX 0xFF   //need to update  // Microcontroller RX
// #define BOSL_TX 0xFF   //need to update // Microcontroller TX

//Declaring variables to store results
int a;
unsigned long previous;
// uint8_t x;
bool answer;
char response[512];
char cmd[512];

void setup() {
  bool answer;
  Serial.begin(BAUDRATE);
  Serial1.begin(BAUDRATE);

  Serial.println("initialising sim");


  simOn();
  simInit();
  // answer = sendATcmd(F("AT+CGNSINF"), "+CGNSINF: 1,1",1000);
}

uint8_t i = 0;
bool Scmd = 0;

void loop() {

  i = 0;
  Scmd = 0;
  memset(cmd, '\0', 100);
  // delay(100);


  while (Serial.available() > 0) {
    Scmd = 1;
    cmd[i] = (char)Serial.read();
    i++;
    if (Serial.available() == 0) {
      delay(50);
    }
  }

  if (Scmd) {
    Serial1.write(cmd);
    Serial1.println();
    Serial.print("sending: ");
    Serial.println(cmd);

    Scmd = 0;
  }

  while (Serial1.available() != 0) {
    Serial.print((char)Serial1.read());
  }
}



bool sendATcmd(String ATcommand, char* expected_answer1, unsigned int timeout) {
  a = 0;
  do {
    a++;

    Serial.println(ATcommand);
    answer = 0;

    previous = 0;

    memset(response, '\0', 100);  // Initialize the string

    delay(100);

    while (Serial1.available() > 0) {
      Serial1.read();  // Clean the input buffer
    }

    Serial1.println(ATcommand);  // Send the AT command


    size_t x = 0;
    previous = millis();

    // this loop waits for the answer
    do {
      if (Serial1.available() != 0) {
        response[x] = Serial1.read();
        x++;
        // check if the desired answer is in the response of the module
        if (strstr(response, expected_answer1) != NULL) {
          answer = 1;
        }
      }



      // Waits for the asnwer with time out
    } while ((answer == 0) && ((millis() - previous) < timeout));

    if (expected_answer1 == "0") {
      answer = 1;
    }

    Serial.println(response);


  } while (answer == 0 && a < 5);

  a = 0;
  return answer;
}



void simInit() {

  simOn();

  sendATcmd(F("AT+IPR=9600"), "OK", 1000);

  sendATcmd(F("ATE0"), "OK", 1000);

  sendATcmd(F("AT&W0"), "OK", 1000);
}

void simOn() {
  pinMode(SIM_PWRKEY, OUTPUT);


  pinMode(SIM_BUF_EN, OUTPUT);
  digitalWrite(SIM_BUF_EN, HIGH);

  digitalWrite(SIM_PWRKEY, LOW);
  // See spec sheets for your particular module
  delay(100);  // For SIM7000

  digitalWrite(SIM_PWRKEY, HIGH);
}


///////////////////////////////////////////////////////////////
void simOff() {
  //  TX / RX pins off to save power

  digitalWrite(SIM_BUF_EN, LOW);  // do we need this?

  digitalWrite(SIM_PWRKEY, LOW);
  // See spec sheets for your particular module
  delay(3000);  // For SIM7000
  digitalWrite(SIM_PWRKEY, HIGH);
}
