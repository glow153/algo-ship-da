#include <stdio.h>
typedef unsigned char byte;

byte packetTx[] = {
  (byte)0x02, //stx
  (byte)0xff,
  (byte)101, //device id
  (byte)0xff,
  (byte)0x00, (byte)0x00, //uvi (idx : 4,5)
  (byte)0xff,
  (byte)0x00, (byte)0x00, (byte)0x00, (byte)0x00, //euvb (idx : 7,8,9,10)
  (byte)0xff,
  (byte)0x00, //checksum (idx:12)
  (byte)0x03  //etx
};

void writeEUVB2Packet(float euvb) {
  unsigned long flag = 0xff;
  int integer = (int)euvb;
  long decimal = (long)((euvb - integer) * 10000000L);
  for (int i = 0; i < 3; i++)
    packetTx[10 - i] = (decimal & (flag << 8 * i)) >> 8 * i;
  packetTx[7] = (byte)integer;
}

float readPacket2EUVB(byte* packetRx) {
  byte flag = (byte)0xff;
  int integer = (int)packetRx[7];
  int decimal = 0;
  for (int i = 0; i < 3; i++){
    decimal |= (packetRx[10 - i] & flag) << 8 * i;
  }
  return (float)(integer + (float)(decimal * 0.0000001));
}

void pktToString(byte* packet, int len){
  for(int i=0;i<len;i++){
    printf("%x ",packet[i]);
  }
  printf("\n");
}

int main(void) {
    float euvb = 0.000011927f;
    printf("source euvb : %.10f W/m2\n",euvb);
    writeEUVB2Packet(euvb);
    printf("write to packet : ");
    pktToString(packetTx, 14);
    printf("read from packet euvb : %.10f W/m2\n",readPacket2EUVB(packetTx));
    return 0;
}
