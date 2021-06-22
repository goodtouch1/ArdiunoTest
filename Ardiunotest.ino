#include "Ardiuno.h"
#include <SoftwareSerial.h> \\Bluetooth giris cikis tanımı
SoftwareSerial mySerial(4, 6); //HC-06'nın Rx , Tx bacakları tanımlandı
#define WIFI_SSID "TurkTelekom_ZTUVF"
#define WIFI_PASSWORD "EB12.bexyz"
int kirmizi = 8;
int sari = 9;
int yesil = 10;
int onay ;
FirebaseData firebaseData;
FirebaseJson json;
void setup() {
  // put your setup code here, to run once:
  setupPinsMode();
  Serial.begin(9600);
  Serial.print("Tamamlandı");
  mySerial.begin(9600);,

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(kirmizi, HIGH);   // Kirmizi led baslatıldı
  delay(20000);                  // 20 saniye kirmizi yaniyor
  onay = digitalRead(kirmizi);
  if(onay == true){
    mySerial.print(onay);
  }
  digitalWrite(kirmizi,LOW);     //Kirmizi led sonlandırıldı
  digitalWrite(sari, HIGH);  //Sari led baslatıldı
  delay(1500);            //1,5 saniye bekle  
  digitalWrite(sari, LOW);   //Sari led sonlandırıldı
  digitalWrite(yesil, HIGH); //Yesil led baslatıldı
  delay(20000);             //20 saniye yesil yaniyor
  digitalWrite(yesil, LOW); //Yesil led sonlandırıldı
}
void setupPinsMode(){
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}
