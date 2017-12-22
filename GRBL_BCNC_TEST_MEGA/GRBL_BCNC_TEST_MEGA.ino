#include <LinkedList.h>

#define BCNC Serial
#define GRBL Serial1
#define debug Serial2

int GCodes_len = 0;
//String GCODE="";

LinkedList<String> GCodes_array = LinkedList<String>();

void setup()
{
  BCNC.begin(115200);
  GRBL.begin(115200);
  debug.begin(115200);

//  while(1)
//  {
//    GRBL.println("?");
//    delay(1000);
//    while(GRBL.available())
//    {
//      debug.print(char(GRBL.read()));
//    }
//  }
}

void loop()
{
  while (!BCNC.find('?'));
  GRBL_status_update();

  wait_for_GCodes();


//for (int i = 0; i < GCodes_array.size(); i++)
    for (int i = 0; i < GCodes_len; i++)
    {
      send_GCODE(GCodes_array.get(i));
      wait_till_idle();
      BCNC.println("ok");
      BCNC.println("ok");
      GRBL_status_update();

      debug.print("i=");
      debug.println(i);
    }
}
