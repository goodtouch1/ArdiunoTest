#include "Ardiuno.h"
#include <SoftwareSerial.h> \\Bluetooth giris cikis tanımı
SoftwareSerial mySerial(4, 6); //HC-06'nın Rx , Tx bacakları tanımlandı
#define FIREBASE_HOST "https://arduinounotest-ce531-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "eCz0OSLAHB7kaWKqeNWd0NtcZ1MTTha3D0yXDyaL"
int kirmizi = 8;
int sari = 9;
int yesil = 10;
int onay ;
string acik = "on";
string kapali = "off";
void setup() {
  // put your setup code here, to run once:
  setupPinsMode();
  Serial.begin(9600);
  Serial.print("Tamamlandı");
  mySerial.begin(9600);,

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(kirmizi, HIGH);          // Kirmizi led baslatildi
  Firebase.setString("kirmizi",acik);   //Firebase kirmizi dalina "on" degeri gönderildi  
  delay(20000);                  // 20 saniye kirmizi yaniyor
  digitalWrite(kirmizi,LOW);      //Kirmizi led sonlandirildi
  Firenbase.setString("kirmizi",kapali);    //Firabase kirmizi dalina "off" degeri gönderildi
  digitalWrite(sari, HIGH);  //Sari led baslatildi
  delay(1500);            //1,5 saniye bekle  
  digitalWrite(sari, LOW);   //Sari led sonlandirildi
  digitalWrite(yesil, HIGH); //Yesil led baslatildi
  delay(20000);             //20 saniye yesil yaniyor
  digitalWrite(yesil, LOW); //Yesil led sonlandirildi
}
void setupPinsMode(){
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}
