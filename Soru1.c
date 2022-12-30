  //#include <reg51.h>
#include <89c51rd2.h>
#include <stdio.h>

#define MOTOR 	P1_7
#define buzzer 	P1_0
#define ledler	P2

int modtablo [7]={0,200,300,450,600,750,800};
int i=0,gecerliguc,ms=21,buzzersure=20,buzzerac=0,buzzer20kere=20,calismasure=0,calismaguc=0; 

void timer_0() interrupt 1
{				
	ms=21;
	while(1){
					if(TF0==1){ 
			TR0=0;
			TF0=0;
			TL0=-50000%256;	// pals'in düþük deðeri
			TH0=-50000/256;	// pals'in yüksek deðeri
						if(ms>0){ 
						TR0=1;
						ms--;
						
						}
						if(ms<=0) {
							TF0=1;
						return;
					} 
				}
			}
		}

	
main ()
{
	ledler=0x00;				// ledler basta tamamen kapali
	buzzer=0;
	P3_6=0;			// tuslari off yapiyoruz ki döngüye girmesin
	P3_7=0;
	P3_4=0;
	P3_5=0;
	MOTOR=0;
	SCON=0x50;
	TMOD=0x21; //T0 16Bit timer
	TH1=0xFD; //9600 baud
	TR1=1;
	TI=1; //seri porttan printf ile veri göndermek için 1 olmalidir.
	ET0=1;
	IT0=1;
	IT1=1;
	EA=1;
	TL0=-50000%256;  //1 byte=8bit  ->256  
	TH0=-50000/256;		// süre saydirma için
	
	while(1){

			if(1==P3_6){
										calismasure=calismasure+5;
				while(1){
						if(0==P3_6){
							break;
					}
				}
			}
			
						if(1==P3_7){
					while(1){
						if(0==P3_7){		
							break;
							}	
						}		
					if(calismasure==0) calismasure=0;
	calismasure=calismasure-5;

			}
		
			if(1==P3_4){					
				while(1){
						if(0==P3_4){
							break;
						}
					}
				
				i++;
				switch(i){									// basilan tusa göre ledleri yakiyor
					case		1:	P2=1;					break;
					case		2:	P2=3;					break;
					case		3:	P2=7;					break;
					case 		4:	P2=15; 				break;
					case 		5:	P2=31;				break;
					case    6:  P2=63;				break;
					case    7: 	i=0; P2=0; 		break;
				}
				gecerliguc=modtablo[i];	
				printf("gecerli guc= %d\n",gecerliguc);				// gecerli olan gücü yaziyor ekrana
			}
							if(1==P3_5){							
				while(1){								// burada tus bas çek  olmasi için bekliyor
						if(0==P3_5){

								if(buzzerac==1){			// eger motor çalisma süresi biterse bu motor kodunda 1 yapiliyor buraya giriyor 
	while(1){
			
				if(buzzer20kere>0){
					buzzer=!buzzer;				// buzzer 20 kere açilip kapaniyor 
					buzzer20kere--;
				TR0=1;
									while(1) 
				{  if(TF0==1){							// 1 saniye sayiyor 
					TF0=0; 
				break;
						}  
					}
				}

			
			else	if(buzzer20kere<=0) {			// eger 20 kez çalistiysa motor ve buzzer 0 yapiliyor
	MOTOR=0;		
	buzzer=0;
				while(1){
					// sonsuz döngüye girip makine çalismaz sekilde bekletiliyor
					}			
				}				
			}
		}
	
	while(1){				// bu sonsuz while motoru belirtilen süre boyunca çalistiriyor

		        MOTOR=1;				// motor çalisiyor
						TR0=1;

				while(1) 
				{  
					if(TF0==1){		// 1 saniye sayip döngüden çikiyor 
					TF0=0; 
					break;
										}  
									}
									calismasure--;  		
									
				if(calismasure<1) {				// süre sayma bitince buraya giriyor
					TR0=0;									//
							printf("islem basarili");  // islem basarili yaziyor
				MOTOR=0;													// motor kapatiliyor
					TF0=0;											
					 buzzerac=1;										// buzzer açiliyor yukarida ki buzzer koduna giriyor bu sayede
					break;													// motor sonsuz while döngüsünden çikiliyor
				}
		
  
								}
							}
						}
					}
				}
			}	