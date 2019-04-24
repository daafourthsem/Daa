1b(i).c

#include <reg51.h>
typedef unsigned char tByte; 
typedef unsigned int tWord; 
void delayMs(tWord); 
sbit key2 = P3^3;
sbit key3 = P3^4;
int main(void)
{
 tByte count=0,i,temp;
 tWord delay = 1000; 
 P0 = 0x00; 
 while(1)
 {
 if(key1 == 0)
 {
 for(count = 0 ; count <= 99 ; count++)
 {
 P0 = (count / 10) << 4 | count % 10;
 delayMs(delay);
 }
 P0=0x00; 
 }
 if(key2 == 0)
 { 
 for(count = 99 ; count >= 0 ; count--)
 {
 P0 = (count / 10) << 4 | count % 10;
 delayMs(delay);
 }
 P0=0x00; 
 } if(key3 == 0)
 {
 while(1)
 {
 for(i = 0; i < 8; i++)
 {
 P0 = 0x01<<i; 
 delayMs(delay);
 }
 }
 }
 }
}
void delayMs(tWord x)
{

 tWord i;
 while(x--)
 for(i=0;i<120;i++);
} 

1b(ii).c
#include<reg51.h>
typedef unsigned char tByte;
typedef unsigned int tWord;
sbit SEL = P1^4;
void delayMs(tWord); 
tByte readInput(void); 
tByte countOnes(tByte); 
int main(void)
{
 tByte temp,count;
 while(1)
 {
 temp = readInput(); 
 count = countOnes(temp); 
 if(count % 2 == 0) 
 P0 = 0xFF; 
 else
 P0 = 0x00; 
 delayMs(1000);
 P0 = count;
 delayMs(1000);
 }
}
tByte countOnes(tByte x)
{
 tByte i,count = 0;
 for(i = 0 ;i < 8 ;i++) 
 {
 if(x & (0x01<<i))
 count++; 
 }
 return count; 
} 

tByte readInput(void)
{

 tByte temp = 0;
 SEL = 0;
 temp = P1 & 0x0F;
 SEL = 1; 
 temp = (P1 & 0x0F) << 4 | temp; 
 return temp; 
 }
void delayMs(tWord x)
{
 tByte i;
 while(x--)
 for(i=0;i<120;i++);
} 


1b(iii).c
#include<reg51.h>
typedef unsigned char tByte;
typedef unsigned int tWord; 
void delayMs(tWord); 
tByte readInput(void); 
sbit SEL = P1^4;
sbit key1 = P3^2;
sbit key2 = P3^3;
sbit key3 = P3^4;
int main(void)
{
 tWord a = 0,b = 0,c = 0; 
 P0 = 0x00; 
 while(1)
 {
 if(!key1)
 {
 
 a = readInput();
 P0 = a;
 delayMs(500);
 P0 = 0x00;
 delayMs(500);
 }
 if(!key2)
 {
 
 b = readInput();
 P0 = b;
 delayMs(500);
 P0 = 0x00;
 delayMs(500);
 } 
 if(!key3)
 {
 
 c = a*b;
 P0 = c & 0xFF;
 delayMs(1000);
 P0 = c >> 8;
 delayMs(1000);
 P0 = 0x00;
 }
 }
}
tByte readInput(void)
{

 tByte temp = 0;
 SEL = 0; 
 temp = P1 & 0x0F;
 SEL = 1; 
 temp = (P1 & 0x0F) << 4 | temp; 
 return temp;

}
void delayMs(tWord x)
{
 tByte i;
 while(x--)
 for(i=0;i<120;i++);
} 


2b.c
#include <reg52.h>
typedef unsigned char tByte; 
typedef unsigned int tWord; 
sbit DAT = P0^0;
sbit CLK = P0^1;
void delayMs(tWord); 
void writeSeg(tByte); 
int main(void)
{
 int i = 0;
 tByte help[4] = {0x89,0x86,0xC7,0x8C};
tByte fire[4] = {0x8E,0xCF,0xAF,0x86};

 P0 = 0x00;
 while(1)
 {
 for(i=0;i<4;i++)
 writeSeg(help[i]);
 delayMs(1000);
 for(i=0;i<4;i++)
 writeSeg(fire[i]);
 delayMs(1000);
 }
}
void writeSeg(tByte x)
{
 tByte i;
 for(i = 0; i < 8; i++)
 {
 if(x & (0x80>>i)) 
 DAT = 1; 
 else
 DAT = 0;
 CLK = 0; 
 CLK = 1;
 }
} 
void delayMs(tWord x)
{
 
 tWord i;
 while(x--)
 for(i=0;i<75;i++);
}

3b.c
#include <reg52.h>
typedef unsigned char tByte;
typedef unsigned int tWord;
sbit W3 = P0^7;
sbit W2 = P0^6;
sbit W1 = P0^5;
sbit W0 = P0^4;
no_of_steps_clk = 100 ; 
no_of_steps_anticlk = 100 ;
void delayMs(tByte);
main()
{ while(1)
 { W3=1; W2=0; W1=0; W0=0; delayMs(5); if(--no_of_steps_clk==0) break;
 W3=0; W2=1; W1=0; W0=0; delayMs(5); if(--no_of_steps_clk==0) break;
 W3=0; W2=0; W1=1; W0=0; delayMs(5); if(--no_of_steps_clk==0) break;
 W3=0; W2=0; W1=0; W0=1; delayMs(5); if(--no_of_steps_clk==0) break;
 }
 while(1)
 { W3=0; W2=0; W1=0; W0=1; delayMs(5); if(--no_of_steps_anticlk==0) break;
 W3=0; W2=0; W1=1; W0=0; delayMs(5); if(--no_of_steps_anticlk==0) break;
 W3=0; W2=1; W1=0; W0=0; delayMs(5); if(--no_of_steps_anticlk==0) break;
 W3=1; W2=0; W1=0; W0=0; delayMs(5); if(--no_of_steps_anticlk==0) break;
 }
while(1); 
}
void delayMs(tByte x) 
{
 tWord i;
 while(x--)
 for(i=0;i<300;i++);
} 


4b.c
#include <reg52.h>
typedef unsigned char tByte;
typedef unsigned int tWord;
sbit key1 = P3^2;
sbit key2 = P3^3;
sbit key3 = P3^4;
tByte code dac_datas_sine_fullrectified[ ] =
{128+0, 128+13, 128+26, 128+39, 128+51, 128+63, 128+74, 128+84, 128+94, 128+102,
128+109, 128+116, 128+120, 128+124, 128+126, 128+127, 128+126, 128+124, 128+120,
128+116, 128+109, 128+102, 128+94, 128+84, 128+74, 128+63, 128+51, 128+39, 128+26,
128+13};
tByte code dac_datas_sine_full[ ] =
{128+0, 128+13, 128+26, 128+39, 128+51, 128+63, 128+74, 128+84, 128+94, 128+102,
128+109, 128+116, 128+120, 128+124, 128+126, 128+127, 128+126, 128+124, 128+120,
128+116, 128+109, 128+102, 128+94, 128+84, 128+74, 128+63, 128+51, 128+39, 128+26,
128+13, 128-0, 128-13, 128-26, 128-39, 128-51, 128-63, 128-74, 128-84, 128-94, 128-102,
128-109, 128-116, 128-120, 128-124, 128-126, 128-127, 128-126, 128-124, 128-120, 128- 116,
128-109, 128-102, 128-94, 128-84, 128-74, 128-63, 128-51, 128-39, 128-26,128-13};
tByte code dac_datas_sine_halfrectified [ ] =
{128+0, 128+13, 128+26, 128+39, 128+51, 128+63, 128+74, 128+84, 128+94, 128+102,
128+109, 128+116, 128+120, 128+124, 128+126, 128+127, 128+126, 128+124, 128+120,
128+116, 128+109, 128+102, 128+94, 128+84, 128+74, 128+63, 128+51, 128+39, 128+26,
128+13, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};

 main()
{
tByte i=0,j=0,k=0;
key1=key2=key3=1; 
while(1)
{
 //full rectified 
 if(key1==0)
 while(1) 
 {
 P0 = dac_datas_sine_fullrectified[i++];
 if(i==30) i=0; 
 
 if(key1==0 || key2==0 || key3==0)break; //check for the key press
 };
 //full sine waveform
 if(key2==0)
 while(1)
 {
 P0 = dac_datas_sine_full[j++];
 if(j==60) j=0; 
 if(key1==0 || key2==0 || key3==0)break;
 }
 //half rectified 
 if(key3==0)
 while(1)
 {
 P0 = dac_datas_sine_halfrectified[k++];
 if(k==60) k=0; 
 
 if(key1==0 || key2==0 || key3==0)break;
 };
 }
}

