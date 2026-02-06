#include <iot_board.h>
#include <WiFi.h>

//permette di rilevare la connessione e la disconnessione dei dispositivi che si collegano 
//all'esp mostrandone il MAC 


void WiFiEvent(WiFiEvent_t event, WiFiEventInfo_t info) {
  switch (event) {
    
    // --- Un dispositivo si è connesso ---
    case ARDUINO_EVENT_WIFI_AP_STACONNECTED:
      Serial.print("Nuovo dispositivo connesso! MAC: ");
      for(int i = 0; i< 6; i++){
        Serial.printf("%02X", info.wifi_ap_staconnected.mac[i]);
        if(i<5) Serial.print(":");
      }
      Serial.print(" | AID: "); // Association ID
      Serial.println(info.wifi_ap_staconnected.aid);
      break;

    // --- Un dispositivo si è disconnesso ---
    case ARDUINO_EVENT_WIFI_AP_STADISCONNECTED:
      Serial.print("Dispositivo disconnesso. MAC: ");
      for(int i = 0; i< 6; i++){
        Serial.printf("%02X", info.wifi_ap_stadisconnected.mac[i]);
        if(i<5) Serial.print(":");
      }
      Serial.print(" | AID: ");
      Serial.println(info.wifi_ap_stadisconnected.aid);
      break;
      
    default:
      break;
  }
}

void setup(){
  Serial.begin(115200);
  WiFi.onEvent(WiFiEvent);
  WiFi.mode(WIFI_AP);
  WiFi.softAP("MBARE",NULL);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access Point attivo. Indirizzo IP: ");
  Serial.println(IP);
  
}


void loop(){

  
 
}

