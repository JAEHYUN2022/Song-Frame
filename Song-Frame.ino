char rx_dummy;  // 문자를 하나씩 받을 곳
int rx_cnt;  // 문자 개수를 세어서 rx_buffer의 배열 개수를 정해줌
char rx_buffer[13] ;  // rx_dummy 로부터 문자를 받아 총 최대13개 배열로 문자를 저장하고 있음
char rx_temp0[13]; //rx_buffer로부터 문자들을 그대로 받음
char rx_temp1[13]; // 밑에서 Index, cX, cY 등을 읽어내기위한 배열
int rx_complete; // 통신이 끝남을 알리기 위함
int rx_flag;  // 통신이 시작됬음을 알림
int Index;
int cX;
int cY;
int nCounter = 0;
int cnt = 2;
int cnt1 = 0;

void setup() {
  Serial1.begin(9600);
  Serial2.begin(9600); // Arduino - LCD
  Serial.begin(9600);
  Serial2.write("$i,1,0,ukulele.bmp#");
  Serial2.write("$i,1,1,creativeminds.bmp#");
  Serial2.write("$i,1,2,anewbeginning.bmp#");
  Serial2.write("$i,1,3,littleidea.bmp#");
  Serial2.write("$i,1,4,jazzfrenchy.bmp#");
  Serial2.write("$i,1,5,Arrow.bmp#");
  Serial2.write("$s,3#");
  Serial2.write("$l,0,255,255,255#");
  Serial2.write("$1,2,0,0,480,272,1#");

  Serial2.write("$i,4,2,90,20,300,170#");
  Serial2.write("$i,4,5,90,201,300,60#");
  Serial2.write("$s,6#");

}

void loop() {

  if (Serial.available()) {
    Serial1.write(Serial.read());
  }

  if (Serial2.available() > 0) {

    rx_dummy = Serial2.read();
    if (rx_dummy == '$') {
      rx_flag = 1;
      rx_buffer[0] = rx_dummy;
      rx_cnt = 1;
    }
    else if (rx_dummy == '#') {
      rx_flag = 0;
      rx_buffer[rx_cnt] = rx_dummy;
      strcpy(rx_temp0, rx_buffer);
      rx_cnt = 0;
      rx_complete = 1;
    }
    else if (rx_flag == 1) {
      rx_buffer[rx_cnt] = rx_dummy;
      rx_cnt++;
    }
    if (rx_complete == 1) {
      rx_complete = 0;
      if (rx_temp0[3] == '0') {
        sscanf(rx_temp1, "$t,%d,%d,%d#", & Index, &cX, &cY);
        Serial.println(Index);
        Serial.println(cX);
        Serial.println(cY);
        delay(200);
      }
      else {
        strcpy(rx_temp1, rx_temp0);
      }
    }
  }

  // left
  if ((cX >= 150 && cX <= 170) && (cY > 200 && cY <= 225)) {
    cnt--;
    if (cnt == -1) {
      cnt = 4;
    }
    if (cnt == 0) {
      Serial2.write("$s,3#");
      Serial2.write("$l,0,255,255,255#");
      Serial2.write("$1,2,0,0,480,272,1#");
      Serial2.write("$i,4,0,90,20,300,170#");
      Serial2.write("$i,4,5,90,201,300,60#");
      Serial2.write("$s,6#");
      cX = 0;
      cY = 0;
      if (cnt == 1) {
        Serial2.write("$s,3#");
        Serial2.write("$l,0,255,255,255#");
        Serial2.write("$1,2,0,0,480,272,1#");
        Serial2.write("$i,4,1,90,20,300,170#");
        Serial2.write("$i,4,5,90,201,300,60#");
        Serial2.write("$s,6#");
        cX = 0;
        cY = 0;
      }
      if (cnt == 2) {
        Serial2.write("$s,3#");
        Serial2.write("$l,0,255,255,255#");
        Serial2.write("$1,2,0,0,480,272,1#");
        Serial2.write("$i,4,2,90,20,300,170#");
        Serial2.write("$i,4,5,90,201,300,60#");
        Serial2.write("$s,6#");
        cX = 0;
        cY = 0;
      }
      if (cnt == 3) {
        Serial2.write("$s,3#");
        Serial2.write("$l,0,255,255,255#");
        Serial2.write("$1,2,0,0,480,272,1#");
        Serial2.write("$i,4,3,90,20,300,170#");
        Serial2.write("$i,4,5,90,201,300,60#");
        Serial2.write("$s,6#");
        cX = 0;
        cY = 0;
      }
      if (cnt == 4) {
        Serial2.write("$s,3#");
        Serial2.write("$l,0,255,255,255#");
        Serial2.write("$1,2,0,0,480,272,1#");
        Serial2.write("$i,4,4,90,20,300,170#");
        Serial2.write("$i,4,5,90,201,300,60#");
        Serial2.write("$s,6#");
        cX = 0;
        cY = 0;
      }
    }

    // play
    if ((cX >= 230 && cX <= 255) && (cY > 200 && cY <= 225)) {
      cnt1++;
      if (cnt1 == 0) {
        Serial1.write("ukulele");
      }

      if (cnt1 == 1) {
        Serial1.write("creativeminds");
        cX = 0;
        cY = 0;
      }

      if (cnt1 == 2) {
        Serial1.write("anewbeginning");
        cX = 0;
        cY = 0;
      }

      if (cnt1 == 3) {
        Serial1.write("littleidea");
        cX = 0;
        cY = 0;
      }

      if (cnt1 == 4) {
        Serial1.write("jazzfrenchy");
        cX = 0;
        cY = 0;
      }
    }

    // right
    if ((cX >= 315 && cX <= 335) && (cY >= 200 && cY <= 225)) {
      cnt++;
      if (cnt == 5) {
        cnt = 0;
      }
      if (cnt == 0) {
        Serial2.write("$s,3#");
        Serial2.write("$l,0,255,255,255#");
        Serial2.write("$1,2,0,0,480,272,1#");
        Serial2.write("$i,4,0,90,20,300,170#");
        Serial2.write("$i,4,5,90,201,300,60#");
        Serial2.write("$s,6#");
        cX = 0;
        cY = 0;
        if (cnt == 1) {
          Serial2.write("$s,3#");
          Serial2.write("$l,0,255,255,255#");
          Serial2.write("$1,2,0,0,480,272,1#");
          Serial2.write("$i,4,1,90,20,300,170#");
          Serial2.write("$i,4,5,90,201,300,60#");
          Serial2.write("$s,6#");
          cX = 0;
          cY = 0;
        }
        if (cnt == 2) {
          Serial2.write("$s,3#");
          Serial2.write("$l,0,255,255,255#");
          Serial2.write("$1,2,0,0,480,272,1#");
          Serial2.write("$i,4,2,90,20,300,170#");
          Serial2.write("$i,4,5,90,201,300,60#");
          Serial2.write("$s,6#");
          cX = 0;
          cY = 0;
        }
        if (cnt == 3) {
          Serial2.write("$s,3#");
          Serial2.write("$l,0,255,255,255#");
          Serial2.write("$1,2,0,0,480,272,1#");
          Serial2.write("$i,4,3,90,20,300,170#");
          Serial2.write("$i,4,5,90,201,300,60#");
          Serial2.write("$s,6#");
          cX = 0;
          cY = 0;
        }
        if (cnt == 4) {
          Serial2.write("$s,3#");
          Serial2.write("$l,0,255,255,255#");
          Serial2.write("$1,2,0,0,480,272,1#");
          Serial2.write("$i,4,4,90,20,300,170#");
          Serial2.write("$i,4,5,90,201,300,60#");
          Serial2.write("$s,6#");
          cX = 0;
          cY = 0;
        }
      }
    }
  }
