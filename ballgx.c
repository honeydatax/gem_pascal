#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>

int x;
int y;
char color;


int screenptr;
long get_ttimer();
void sounds(sound1,sound2);
void draws(draw1);
int screen13();
int hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor);
int rect(rectx,recty,rectx1,recty1,rectcolor);
void cls13(cls1);
int getptr();
void sleep(sleep1);
void refresh();
int max(number1,number2);
int min(number1,number2);

void main(){
	int c;
	int d;
	long l;
	long ll;
	char b=1;
	int x1;
	int y1;
	int y2;
	int x2;
	int xx;
	int yy;

	long t1;
	long t2;
	long t3;
	
	int t=screen13();
screenptr=getptr();

	cls13(4);
	refresh();
	color=4;
	sounds(300,3);
	x1=0;
    y1=0;
    x2=0;
    y2=0;
    xx=10;
    yy=10;
    t3=1;
    do{
        t1=get_ttimer();
        t1=t1+t3;
        x=x2;
        y=y2;

        draws(4);
        x=x1;
        y=y1;

        draws(1);
       refresh();
        y2=y1;
        x2=x1;
        x1=x1+xx;
        y1=y1+yy;
        if (x1>300){
        	x1=300;
        xx=-10;
        sounds(300,3);
        	}
                if (x1<20){
        	x1=20;
        xx=10;
        sounds(300,3);
        	}
        if (y1>180){
        	y1=180;
        yy=-10;
        sounds(300,3);
        	}
                if (y1<20){
        	y1=20;
        yy=10;
        sounds(300,3);
        	}

        
    do{
    t2=get_ttimer();
    }while(!(kbhit() || t1<t2));
    }while(!kbhit());
	

}


int screen13()
{
	union REGS r1;
	union REGS r;
	r.h.ah=0;
	r.h.al=0x13;
	int86(0x10,&r,&r1);
	return r1.x.ax;
	}

int hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor)
{

	int ir;
	int xx ;
int yy;
int xx1;
int yy1;
int xxx;
int yyy;
int r;
	
	int xxa;
	xx=hlinex;
	yy=hliney;
	xx1=hlinex1;
	yy1=hliney1;
	if (xx>319) xx=319;
	if (xx1>319) xx1=319;
	if (yy>199) yy=199;
	if (yy1>199) yy1=199;
	if (xx<0) xx=0;
	if (xx1<0) xx1=0;
	if (yy<0) yy=0;
	if (yy1<0) yy1=0;
	if (xx<=xx1 && yy==yy1) {
		xxa=xx1-xx;
		if (xxa<1) xxa=1;
		yyy=yy1-yy;
		
	
			
	xxx=yy*320+xx;
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=xxa;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	movedata(__get_ds(),&hlinecolor,__get_cs(),0x86,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0x82]";
	asm "mov dx,[0x86]";
	
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop es";
	asm "mov al,dl";
	asm "xor dx,dx";

asm "label2:";
asm "cld";
asm "rep";
asm "stosb";
	asm "pop ds";
			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
	}


int rect(rectx,recty,rectx1,recty1,rectcolor)
{
	int ir;
	int ny;
	int nx;
	int xx ;
int yy;
int xx1;
int yy1;
int xxx;
int yyy;
int r;
	
	int xxa;
	xx=rectx;
	yy=recty;
	xx1=rectx1;
	yy1=recty1;
	if (xx>319) xx=319;
	if (xx1>319) xx1=319;
	if (yy>199) yy=199;
	if (yy1>199) yy1=199;
	if (xx<0) xx=0;
	if (xx1<0) xx1=0;
	if (yy<0) yy=0;
	if (yy1<0) yy1=0;
	if (xx<=xx1 && yy<=yy1) {
		xxa=xx1-xx;
		if (xxa<1) xxa=1;
		yyy=yy1-yy;
		nx=320-xxa;
	
			
	xxx=yy*320+xx;
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=xxa;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	ir=nx;
	movedata(__get_ds(),&ir,__get_cs(),0x86,2);
	ir=yyy;
	movedata(__get_ds(),&ir,__get_cs(),0x88,2);
	movedata(__get_ds(),&rectcolor,__get_cs(),0x8a,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0x82]";
	asm "mov si,[0x86]";
	asm "mov dx,[0x8a]";
	asm "mov bx,[0x88]";
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop es";
	asm "mov al,dl";
	asm "xor dx,dx";
	asm "push cx";
	asm "label4:";
	asm "pop cx";
	asm "push cx";
asm "label5:";
asm "cld";
asm "rep";
asm "stosb";
	asm "clc";
	asm "add di,si";
asm "dec bx";
asm "cmp bx,dx";
	asm "jnz label4";
	asm "pop ax";
	asm "pop ds";
			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
	}

void sleep(sleep1){
		unsigned long i;
		unsigned long ii;
		unsigned long iii;
		iii=(long) sleep1;
		movedata(0x40,0x6c,__get_ds(),&i,4);
		i=iii+i;
		do
		{
			movedata(0x40,0x6c,__get_ds(),&ii,4);
			}while (ii<i) ;
	
		
		
		}
		
void cls13(cls1)
{
	int i;
	i=screenptr;
	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	i=320*200+1;
	movedata(__get_ds(),&i,__get_cs(),0x82,2);
	movedata(__get_ds(),&cls1,__get_cs(),0x84,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov cx,[0x82]";
	asm "mov dx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop es";
	asm "mov al,dl";
	asm "xor dx,dx";
	asm "mov di,dx";	
asm "label1:";
asm "cld";
asm "rep";
asm "stosb";
	
	asm "pop ds";
	
	}


	long get_ttimer(){
		long i;
		movedata(0x40,0x6c,__get_ds(),&i,4);
		return  i;
		}
		
		int max(number1,number2){
		int r ;
		if ( number1>number2){
			r=number1;
			}else{
				r=number2;
				}
		return r;
		}
	
	
	int min(number1,number2){
		int r ;
		if ( number1<number2){
			r=number1;
			}else{
				r=number2;
				}
		return r;
		}
	
	
	void sounds(sound1,sound2){
		int r;
		long f1;
		long f2;
		int i1;
		int i2;
		int i;
		 f1 = 1193181 /sound1;
		f2=f1;
		f1=f1 & 0xffff0000;
		f1=f1>>16;
		f2=f2 & 0xffff;
		i1=(int) f1;
		i2=(int)f2;
		
		movedata(__get_ds(),&i1,__get_cs(),0x80,2);
		movedata(__get_ds(),&i2,__get_cs(),0x82,2);
		
	i=0x61;
	movedata(__get_ds(),&i,__get_cs(),0x84,2);
	i=0x43;
	movedata(__get_ds(),&i,__get_cs(),0x86,2);
	i=0xb6;
	movedata(__get_ds(),&i,__get_cs(),0x88,2);
	i=3;
	movedata(__get_ds(),&i,__get_cs(),0x8a,2);
	i=0xfc;
	movedata(__get_ds(),&i,__get_cs(),0x8c,2);
		asm "push ds";
		
		asm "push cs";
		asm "pop ds";
		
		asm "mov dx,[0x84]";
		asm "mov ah,[0x8a]";
		asm "in al,dx";
		
		asm "or al,ah";
		asm "out dx,al";
		asm "mov dx,[0x86]";
		asm "mov al,[0x88]";
		asm "out dx,al";
		asm "dec dx";
		asm "mov ax,[0x82]";
		asm "out dx,al";
		asm "mov al,ah";
		asm "out dx,al";
		asm "pop ds";
		

		sleep(sound2);
		
		i=0x61;
	movedata(__get_ds(),&i,__get_cs(),0x84,2);
	i=0x43;
	movedata(__get_ds(),&i,__get_cs(),0x86,2);
	i=0xb6;
	movedata(__get_ds(),&i,__get_cs(),0x88,2);
	i=3;
	movedata(__get_ds(),&i,__get_cs(),0x8a,2);
	i=0xfc;
	movedata(__get_ds(),&i,__get_cs(),0x8c,2);
		
		asm "push ds";
		asm "push cs";
		asm "pop ds";
		
	    asm "mov dx,[0x84]";
		asm "in al,dx";
		asm "and al,[0x8c]";
		asm "out dx,al";
		
		asm "pop ds";
		
		
		}

void draws(draw1){
rect(x-10,y-20,x+10,y+20,draw1);
rect(x-20,y-10,x+20,y+10,draw1);
}




	int getptr(){
		
		int r;
		
		asm "push ds";
		asm "push cs";
		asm "pop ds";
		asm "mov ax,ss";
		asm "mov [0x80],ax";
		asm "pop ds";
		
	    movedata(__get_cs(),0x80,__get_ds(),&r,2);
		return r+0x2000;
		
		}

void refresh()
{
	int i;
i=0xa000;

	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	i=320*200+1;
	movedata(__get_ds(),&i,__get_cs(),0x82,2);
	i=screenptr;
	movedata(__get_ds(),&i,__get_cs(),0x84,2);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov bx,[0x84]";
	asm "mov cx,[0x82]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop es";
	asm "push bx";
	asm "pop ds";
	asm "xor dx,dx";
	asm "mov si,dx";
	asm "mov di,dx";
	asm "mov al,cl";
	
asm "label10:";
asm "cld";
asm "rep";
asm "movsb";
	asm "pop ds";
	
	}
