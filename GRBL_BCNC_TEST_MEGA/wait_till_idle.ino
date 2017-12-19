void wait_till_idle()
{
  while (1)
  {
    GRBL.println("?");
    delay(100);
    if (GRBL.find("<Idle|"))
      break;
  }
  debug.println("IDLE");
}

