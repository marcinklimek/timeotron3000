#include <EasyButton.h>
#include <MD_MAXPanel.h>
#include "sys_fixed_single_all.h"

// Turn on debug statements to the serial output
#define  DEBUG  0

#if  DEBUG
#define PRINT(s, x) { Serial.print(F(s)); Serial.print(x); }
#define PRINTS(x)   Serial.print(F(x))
#define PRINTD(x)   Serial.print(x, DEC)

#else
#define PRINT(s, x)
#define PRINTS(x)
#define PRINTD(x)

#endif

#define START_PIN 15
#define STOP_PIN 13

EasyButton button_start(START_PIN);
EasyButton button_stop(STOP_PIN);

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
const MD_MAX72XX::moduleType_t HARDWARE_TYPE = MD_MAX72XX::FC16_HW;
const uint8_t X_DEVICES = 4;
const uint8_t Y_DEVICES = 2;

#define CLK_PIN   4  // or SCK
#define DATA_PIN  16  // or MOSI
#define CS_PIN    5  // or SS

// Arbitrary pins
MD_MAXPanel mp = MD_MAXPanel(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, X_DEVICES, Y_DEVICES);

// We always wait a bit between updates of the display
#define  DELAYTIME  250  // in milliseconds

unsigned long timer;
int is_running = 0;

void start()
{
  char buff[10];

  for(int val = 0; val < 10; val++)
  {
    snprintf (buff, sizeof(buff), "%d%d.%d ", val, val, val); 
    mp.update(false);
    mp.clear();  
    mp.drawText(0, mp.getYMax(), buff, MD_MAXPanel::ROT_0);
    mp.update(true);  
    delay(DELAYTIME);
  }
}

void text()
{
  char buff[10];
  float val = (millis() - timer)/ 1000.0f;

  if (val > 99)
    timer = millis();
  
  int val_int = (int) val;
  int val_fra = (int) ((val - (float)val_int) * 10);   
  snprintf (buff, sizeof(buff), "%02d.%01d ", val_int, val_fra); //
  mp.update(false);
  mp.clear();  
  mp.drawText(0, mp.getYMax(), buff, MD_MAXPanel::ROT_0);
  mp.update(true);
}


void onStop() 
{
  if ( is_running  )
    is_running = false;
}

void onStart() 
{
  if ( is_running == false )
  {
    is_running = true;
    timer = millis();
  }
}

void setup(void)
{
  mp.begin();

  Serial.begin(115200);
  PRINTS("\n[START]");

  mp.setFont(sys_fixed_single_all);
  PRINT(" - Font height: ", mp.getFontHeight());  

  start();

  timer = millis();

  button_stop.begin();
  button_start.begin();
  
  button_stop.onPressed(onStop);
  button_start.onPressed(onStart);
}

void loop(void)
{
  button_start.read();
  button_stop.read();

  if ( is_running )
  {
    text();
    if ( button_stop.isPressed() )
    {
      is_running = false;
    }
  }
}
 
