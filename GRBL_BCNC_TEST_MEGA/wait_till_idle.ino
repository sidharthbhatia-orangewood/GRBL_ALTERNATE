void wait_till_idle()
{
  while (1)
  {
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

    int x = return_val.indexOf("<Idle|MPos:");
    debug.print("x Idle=");
    debug.println(x);

    if (x != -1)
    {
      break;
    }

    x = return_val.indexOf("<Run|MPos:");
    debug.print("x Run=");
    debug.println(x);
    
    if(x != -1)
    {
      return_val = return_val.substring(x);
      return_val = return_val.substring(0, return_val.indexOf('>'));
      return_val += '>';

      debug.print("Parsed string=");
      debug.println(return_val);

      debug.println("Sending it back to BCNC");
      BCNC.println(return_val);
    }
  }
  debug.println("IDLE");
}

