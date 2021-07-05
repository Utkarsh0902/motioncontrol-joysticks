import processing.serial.*;
import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import javax.swing.KeyStroke;
Serial move;         
Serial jump;
String KeyString = "";
int i= 1;
void setup()
{
  System.out.println("Hi");
  size(700, 500);
  move = new Serial(this, "COM3", 115200);
  move.bufferUntil('\n');
  
  jump = new Serial(this, "COM4", 115200);
  jump.bufferUntil('\n');
  // enter the path to launch mario
  launch("E:\\TECHTAINMENT\\JOYSTICK\\Super Mario Bros. (World)\\Mario.NES");
}
void draw(){//Not really necessary
  background(0, 0, 0);
  fill(255, 0, 0);
  text("Press any key", 100, 175);
}

void serialEvent(Serial MyPort) {
 try{
   Robot Arduino = new Robot();
     if(MyPort == move)
           KeyString = move.readStringUntil('\n');
      //KeyString = KeyString.substring(0, KeyString.indexOf(':'));
      if(MyPort == jump)
           KeyString = jump.readStringUntil('\n');
      KeyString=KeyString.substring(0,KeyString.indexOf(':'));
      System.out.println(KeyString);
       switch(KeyString){
     case "f" :
       Arduino.keyPress(KeyEvent.VK_RIGHT);//presses up key.
       delay(10);
       Arduino.keyRelease(KeyEvent.VK_RIGHT);//releases up key
       break;
     case "b" :
       Arduino.keyPress(KeyEvent.VK_LEFT);
       delay(10);
       Arduino.keyRelease(KeyEvent.VK_LEFT);      
       break;
     case "j":
       Arduino.keyPress(KeyEvent.VK_UP);//presses up key.
       delay(80);
       Arduino.keyRelease(KeyEvent.VK_UP);//releases up key
       break;
     case "s":
       Arduino.keyPress(KeyEvent.VK_B);
       delay(10);
       Arduino.keyRelease(KeyEvent.VK_B);
     }
  
  
      /* if(MyPort == jump)
     {
      KeyString = jump.readStringUntil('\n');
      KeyString = KeyString.substring(0, KeyString.indexOf(':'));
      System.out.println(KeyString);
       switch(KeyString){
     case "j" :
       Arduino.keyPress(KeyEvent.VK_UP);//presses up key.
       delay(80);
       Arduino.keyRelease(KeyEvent.VK_UP);//releases up key
       break;
     //case "superjump" :
       //Arduino.keyPress(KeyEvent.VK_UP);
       //delay(200);
       //Arduino.keyRelease(KeyEvent.VK_UP);      
       //break
   }
*/
  
        MyPort.clear();
 }
  
  catch(Exception e) {
    e.printStackTrace();
  }

 }
