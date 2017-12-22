void send_GCODE(String code)
{
  GRBL.println(code);
  debug.print("code=");
  debug.println(code);
  delay(100);
  while (GRBL.available())
  {
    if (GRBL.available())
    {
      debug.print(char(GRBL.read()));
    }
  }
}

