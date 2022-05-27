#include <ConsentiumThings.h>

#define EspBaud 115200
#define NETWRK_LED 12

unsigned long previousMillis = 0;  

int ledState = LOW; 

ConsentiumThings::ConsentiumThings(){}

void ConsentiumThings::begin(){
    Serial.begin(EspBaud);
    pinMode(NETWRK_LED, OUTPUT);
    
}

void ConsentiumThings::initWiFi(const char* ssid, const char* password){
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Got IP : ");
  Serial.println(WiFi.localIP());
}

void ConsentiumThings::sendREST(const char* key, int sensor_num, String info[],  float data[], long delay_interval_s){ 
  String serverName = "http://consentiuminc.online:80";
  
  unsigned long currentMillis = millis();
  
  long delay_interval_ms = delay_interval_s * 1000;

  if ((currentMillis - previousMillis) >= delay_interval_ms) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;

    if (sensor_num == 1){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      serverName = serverName + "/update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type;
    }
    else if (sensor_num == 2){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      serverName = serverName + "/update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type;
    }
    else if (sensor_num == 3){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];
      serverName = serverName + "/update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type;
    }
    else if (sensor_num == 4){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];
      float sensor_3 = data[3];
      String sensor_3_type = info[3];
      serverName = serverName + "/update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type + "&sensor4=" + (String)sensor_3 + "&info4=" + sensor_3_type;
    }
    else if (sensor_num == 5){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];
      float sensor_3 = data[3];
      String sensor_3_type = info[3];  
      float sensor_4 = data[4];
      String sensor_4_type = info[4]; 
      serverName = serverName + "/update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type + "&sensor4=" + (String)sensor_3 + "&info4=" + sensor_3_type + "&sensor5=" + (String)sensor_4 + "&info5=" + sensor_4_type;
    }
    else if (sensor_num == 6){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];
      float sensor_3 = data[3];
      String sensor_3_type = info[3];  
      float sensor_4 = data[4];
      String sensor_4_type = info[4]; 
      float sensor_5 = data[5];
      String sensor_5_type = info[5]; 
      serverName = serverName + "/update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type + "&sensor4=" + (String)sensor_3 + "&info4=" + sensor_3_type + "&sensor5=" + (String)sensor_4 + "&info5=" + sensor_4_type + "&sensor6=" + (String)sensor_5 + "&info6=" + sensor_5_type;
    }
    else if (sensor_num == 7){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];
      float sensor_3 = data[3];
      String sensor_3_type = info[3];  
      float sensor_4 = data[4];
      String sensor_4_type = info[4]; 
      float sensor_5 = data[5];
      String sensor_5_type = info[5]; 
      float sensor_6 = data[6];
      String sensor_6_type = info[6]; 
      serverName = serverName + "/update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type + "&sensor4=" + (String)sensor_3 + "&info4=" + sensor_3_type + "&sensor5=" + (String)sensor_4 + "&info5=" + sensor_4_type + "&sensor6=" + (String)sensor_5 + "&info6=" + sensor_5_type + "&sensor7=" + (String)sensor_6 + "&info7=" + sensor_6_type;
    }
    http.begin(client, serverName.c_str());
      
    // Send HTTP GET request
    int httpResponseCode = http.GET();
      
    if (httpResponseCode>0) {
        previousMillis = currentMillis;

      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      digitalWrite(NETWRK_LED, ledState);
      String payload = http.getString();
      Serial.println(payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
      // Free resources
    http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
}

