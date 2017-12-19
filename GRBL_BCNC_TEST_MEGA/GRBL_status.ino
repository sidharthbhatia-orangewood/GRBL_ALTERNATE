void GRBL_status_update()
{
  while(GRBL.available())
  {
    GRBL.read();
  }
  
  GRBL.println("?");
  delay(100);

  String return_val = "";
  while (GRBL.available())
  {
    if (GRBL.available())
    {
      return_val += char(GRBL.read());
    }
  }
  debug.print("Reply from GRBL=");
  debug.println(return_val);

  int x = return_val.indexOf("<Idle|MPos:");
  debug.print("x=");
  debug.println(x);
  if (x != -1)
  {
    return_val = return_val.substring(x);
    return_val = return_val.substring(0,return_val.indexOf('>'));
    return_val += '>';

    debug.print("Parsed string=");
    debug.println(return_val);

    debug.println("Sending it back to BCNC");
    BCNC.println(return_val);
  }
  else
  {
    debug.println("IDLE NOT FOUND");
  }
}

