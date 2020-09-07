#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>


#define SW1 2
#define SW2 4
#define MAGNET 3

#define R  9
#define G  10
#define B  11

int skullledcnt = 0;
int hijackledcnt = 0;

int skullcnt = 0;
int hijackcnt = 0;


void setup() {
  // put your setup code here, to run once:
   pinMode(SW1, INPUT);
   pinMode(SW2, INPUT);
   pinMode(MAGNET, INPUT);
   pinMode(R, OUTPUT);
   pinMode(G, OUTPUT);
   pinMode(B, OUTPUT);
   //attachInterrupt(digitalPinToInterrupt(MAGNET), sound, FALLING); // 인터럽트 함수 호출 
   Serial.begin (9600);
   mp3_set_serial (Serial);      //set Serial for DFPlayer-mini mp3 module
   delay(1);                     // delay 1ms to set volume
   mp3_set_volume (22);          // value 0~30
   delay(200); 
   mp3_play(1); //전원이 켜지면 들리는 사운드.
    for(int i = 0 ;i<=255; i++){ 
     setColor(i, 0 ,0);
     delay(5);
    } 
   for(int i = 255;i >= 0; i--){ 
      setColor(i, 0, 0);
      delay(5);
    }
}

void setColor(int red, int green, int blue){
  analogWrite(R, red);
  analogWrite(G, green);
  analogWrite(B, blue); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int Rvalue = 0;
  int Gvalue = 0;
  int Bvalue = 0;
  
  if(digitalRead(SW1) == LOW){
    hijackledcnt = 0;
    skullledcnt = 1;
    hijackcnt = 0;
    mp3_play(2); //스컬폼 변신 대기음
    skullcnt = 1; //변신 대기 플래그로 전환
  }
  if(skullledcnt == 1){
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       if(digitalRead(MAGNET) == LOW) {
         setColor(0, 0, 0);
         skullledcnt = 0;
         break;
       }
       if(digitalRead(SW2) == LOW ) break;
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       if(digitalRead(MAGNET) == LOW) {
         setColor(0, 0, 0);
         skullledcnt = 0;
         break;
       }
       if(digitalRead(SW2) == LOW ) break;
       delay(1);
     }
  }
  
  if((digitalRead(MAGNET) == LOW) && skullcnt == 1){
    mp3_play(3); // 변신음
//    set
    for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     // BGM 만 나옴
     delay(2000);
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(500);
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(1000);
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(500);
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(500);
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(10);
     }
    skullcnt = 2; //필살기 대기 플래그로 전환
  }
  if((digitalRead(MAGNET) == LOW) && skullcnt == 2){
    mp3_play(6); // 필살기 음
    for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(500);
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(0, 0 ,i);
       delay(1);
     }
     for(int i = 255;i >= 0; i--){ 
       setColor(0, 0, i);
       delay(1);
     }
     for(int i = 0 ;i<=255; i++){ 
       setColor(0, 0 ,i);
       delay(1);
     }
     for(int i = 255;i >= 0; i--){ 
       setColor(0, 0, i);
       delay(10);
     }     
  }
  
  if(digitalRead(SW2) == LOW){
    skullledcnt = 0;
    hijackledcnt = 1;
    skullcnt = 0;
    mp3_play(4); //하이잭 폼 변신 대기음
    hijackcnt = 1; //변신 대기 플래그로 전환
  }
  if(hijackledcnt == 1){
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       if(digitalRead(MAGNET) == LOW) {
         //setColor(0, 0, 0);
         hijackledcnt = 0;
         break;
       }
       if(digitalRead(SW1) == LOW ) break;
       delay(10);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       if(digitalRead(MAGNET) == LOW ) {
         //setColor(0, 0, 0);
         hijackledcnt = 0;
         break;
       }
       if(digitalRead(SW1) == LOW ) break;
       delay(10);
     }
     
  }
  
  if((digitalRead(MAGNET) == LOW) && hijackcnt == 1){
    mp3_play(5); // 변신음
    for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(500);
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     // BGM 만 나옴
     
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(10);
     }
     delay(10);
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(500);
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(1000);
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(500);
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(500);
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(10);
     }
    //delay(9000); // 음성 출력 딜레이
    hijackcnt = 2; //필살기 대기 플래그로 전환
  }
  if((digitalRead(MAGNET) == LOW) && hijackcnt == 2){
    mp3_play(6); // 필살기 음
    for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
     delay(500);
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(i, 0 ,0);
       delay(1);
     }
      for(int i = 255;i >= 0; i--){ 
       setColor(i, 0, 0);
       delay(1);
     }
     for(int i = 0 ;i<=150; i++){ 
       setColor(0, 0 ,i);
       delay(1);
     }
     for(int i = 255;i >= 0; i--){ 
       setColor(0, 0, i);
       delay(1);
     }
     for(int i = 0 ;i<=255; i++){ 
       setColor(0, 0 ,i);
       delay(1);
     }
     for(int i = 255;i >= 0; i--){ 
       setColor(0, 0, i);
       delay(10);
     }     
  }
}

/*void sound(){
  if((digitalRead(MAGNET) == LOW) && skullcnt == 1){
    mp3_play(3); // 변신음
    delay(9000); // 음성 출력 딜레이
    skullcnt = 2; //필살기 대기 플래그로 전환
  }
  if((digitalRead(MAGNET) == LOW) && skullcnt == 2){
    mp3_play(6); // 필살기 음
    delay(2000); // 음성 출력 딜레이
  }
  
  if(digitalRead(SW2) == LOW){
    skullcnt = 0;
    Rvalue = 255;
    mp3_play(4); //하이잭 폼 변신 대기음
    delay(1000);
    hijackcnt = 1; //변신 대기 플래그로 전환
  }
  if((digitalRead(MAGNET) == LOW) && hijackcnt == 1){
    mp3_play(5); // 변신음
    delay(9000); // 음성 출력 딜레이
    hijackcnt = 2; //필살기 대기 플래그로 전환
  }
  if((digitalRead(MAGNET) == LOW) && hijackcnt == 2){
    mp3_play(6); // 필살기 음
    delay(2000); // 음성 출력 딜레이
  }
}*/
