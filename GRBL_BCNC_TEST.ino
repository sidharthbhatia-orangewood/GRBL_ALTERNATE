#include<SoftwareSerial.h>

SoftwareSerial debug(2, 3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  debug.begin(115200);

}

int x, y, z = 0.00;

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.find('?'))
  {
    Serial.println("<Idle|MPos:0.000,0.000,0.000|FS:0,0>");

    //    delay(3000);
    //    Serial.println("<Idle|MPos:10.000,0.000,0.000|FS:0,0>");
    while (1)
    {
      if (Serial.find("G91G0"))
      {
        debug.println("found G91G0");
        while (!Serial.available());
        char val = char(Serial.read());
        debug.print("val=");
        debug.println(val);
        if (val == 'X')
        {
          debug.println("found val=x");
          while (!Serial.available());
          String x_val = "";
          char x_char = char(Serial.read());
          debug.print("x_char=");
          debug.println(x_char);
          while (x_char != '.')
          {
            debug.println("x_char!= .");
            x_val += x_char;
            while (!Serial.available());
            {
              x_char = Serial.read();
              debug.print("x_char=");
              debug.println(x_char);
            }
          }
          x = x + x_val.toInt();
          String ret_strng = "<Idle|MPos:";
          ret_strng += String(x);
          ret_strng += ".000,";
          ret_strng += String(y);
          ret_strng += ".000,";
          ret_strng += String(z);
          ret_strng += ".000";
          ret_strng += "|FS:0,0>";
          debug.print("ret_strng=");
          debug.println(ret_strng);

          Serial.println("ok");
          Serial.println("[GC:G0 G54 G17 G21 G91 G94 M5 M9 T0 F0 S0]");
          Serial.println("ok");
          Serial.println("ok");
          Serial.println(ret_strng);
        }

        if (val == 'Y')
        {
          debug.println("found val=y");
          while (!Serial.available());
          String y_val = "";
          char y_char = char(Serial.read());
          debug.print("y_char=");
          debug.println(y_char);
          while (y_char != '.')
          {
            debug.println("y_char!= .");
            y_val += y_char;
            while (!Serial.available());
            {
              y_char = Serial.read();
              debug.print("y_char=");
              debug.println(y_char);
            }
          }
          y = y + y_val.toInt();
          String ret_strng = "<Idle|MPos:";
          ret_strng += String(x);
          ret_strng += ".000,";
          ret_strng += String(y);
          ret_strng += ".000,";
          ret_strng += String(z);
          ret_strng += ".000";
          ret_strng += "|FS:0,0>";
          debug.print("ret_strng=");
          debug.println(ret_strng);

          Serial.println("ok");
          Serial.println("[GC:G0 G54 G17 G21 G91 G94 M5 M9 T0 F0 S0]");
          Serial.println("ok");
          Serial.println("ok");
          Serial.println(ret_strng);
        }

        if (val == 'Z')
        {
          debug.println("found val=z");
          while (!Serial.available());
          String z_val = "";
          char z_char = char(Serial.read());
          debug.print("z_char=");
          debug.println(z_char);
          while (z_char != '.')
          {
            debug.println("z_char!= .");
            z_val += z_char;
            while (!Serial.available());
            {
              z_char = Serial.read();
              debug.print("z_char=");
              debug.println(z_char);
            }
          }
          z = z + z_val.toInt();
          String ret_strng = "<Idle|MPos:";
          ret_strng += String(x);
          ret_strng += ".000,";
          ret_strng += String(y);
          ret_strng += ".000,";
          ret_strng += String(z);
          ret_strng += ".000";
          ret_strng += "|FS:0,0>";
          debug.print("ret_strng=");
          debug.println(ret_strng);

          Serial.println("ok");
          Serial.println("[GC:G0 G54 G17 G21 G91 G94 M5 M9 T0 F0 S0]");
          Serial.println("ok");
          Serial.println("ok");
          Serial.println(ret_strng);
        }
        while (Serial.available())
        {
          Serial.read();
        }
      }
    }
  }
}
