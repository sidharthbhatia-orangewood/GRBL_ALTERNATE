void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);

  while (!Serial.find('?'));
  Serial.println("<Idle|MPos:5.000,0.000,0.000|FS:0,0>");

  while (!Serial.find("?"));
  Serial1.println("?");
  Serial.end();
  delay(100);

  String return_val = "";
  while (Serial1.available())
  {
    if (Serial1.available())
    {
      return_val += char(Serial1.read());
    }
  }
  Serial2.print("Reply from GRBL=");
  Serial2.println(return_val);

  return_val = return_val.substring(0, return_val.indexOf('>'));
  return_val += '>';

  Serial2.print("Parsed string=");
  Serial2.println(return_val);

  Serial2.print("Sending it back to BCNC");
  Serial.println("ok");
  Serial.println("[GC:G0 G54 G17 G21 G91 G94 M5 M9 T0 F0 S0]");
  Serial.println("ok");
  Serial.println("ok");
  Serial.print("<Idle|MPos:0.000,0.000,0.000|FS:0,0>");

  Serial1.println("G00 X0 Y0 F70");
  delay(100);
  while (Serial1.available())
  {
    if (Serial1.available())
    {
      Serial2.print(char(Serial1.read()));
    }
  }

  Serial1.println("G01 Z-1 F50");
  delay(100);
  while (Serial1.available())
  {
    if (Serial1.available())
    {
      Serial2.print(char(Serial1.read()));
    }
  }

  Serial1.println("G01 X0 Y20 F50");
  delay(100);
  while (Serial1.available())
  {
    if (Serial1.available())
    {
      Serial2.print(char(Serial1.read()));
    }
  }

  while (1)
  {
    Serial1.println("?");
    delay(100);
    if (Serial1.find("<Idle|"))
      break;
  }
  Serial2.println("IDLE");
}

int x, y, z = 0.00;

void loop()
{
}
