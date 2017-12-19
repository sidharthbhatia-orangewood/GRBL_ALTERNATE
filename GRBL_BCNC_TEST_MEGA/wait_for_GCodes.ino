void wait_for_GCodes()
{
  while (!BCNC.find("G90\n"));
  debug.println("GCODE start");

  String in_str = "";
  while (in_str != "M3" && in_str != "M30")
  {
    in_str = "";
    while (!BCNC.available());
    char input = char(BCNC.read());
    while (input != '\n')
    {
      in_str += input;
      while (!BCNC.available());
      input = char(BCNC.read());
    }
    debug.println(in_str);
    GCodes_array.add(in_str);
  }
  int arraySize = GCodes_array.size();
  debug.print("Total GCode lines=");
  debug.println(arraySize);
  for(int i=0;i<arraySize;i++)
  {
    debug.println(GCodes_array.get(i));
  }
}

