void setuo() {
   Serial.begin(9600);
   wifiAutoSelector.add("DirectoMX", "qwerty1979");
   wifiAutoSelector.add("Invitados", "1234554321");
 }

 void loop() {
   if(WiFi.status() != WL_CONNECTED) {
     Serial.print("Connecting wifi ");
     if(-1 < wifiAutoSelector.scanAndConnect()) {
       int connectedIndex = wifiAutoSelector.getConnectedIndex();
       Serial.print("to '");
       Serial.print(wifiAutoSelector.getSSID(connectedIndex));
       Serial.println("'. Done.");
     }else{
       Serial.println("failed.");
     }
   }
   delay(1000);
 }