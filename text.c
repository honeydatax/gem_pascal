#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>
#include <string.h>

int screenptr;
int screen13();
int hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor);
void cls13(cls1);
int getptr();
void refresh();
int vlines(vlinex,vliney,vlinex1,vliney1,vlinecolor);
int drawtext(drawtextx,drawtexty,drawtextcolor,drawtextvalue);
int rects(rectsx,rectsy,rectsx1,rectsy1,rectscolor);

void main(){
	int c;
	int d;
	long l;
	long ll;
	char *b="IM LOVE MARINA.";

int a;
int e;	
	int t=screen13();


screenptr=getptr();

	cls13(4);
e=4;

for (a=0;a<319;a=a+8){
vlines(a,0,a,199,1);
if (a<200) hlines(0,a,319,a,1);
}

refresh();
for (e=0;e<200/8-1;e++){
drawtext(e,e,1,b);
rects(e*8,e*8,(strlen(b)+e)*8,(e+1)*8,4);
}
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



int vlines(vlinex,vliney,vlinex1,vliney1,vlinecolor)
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
	xx=vlinex;
	yy=vliney;
	xx1=vlinex1;
	yy1=vliney1;

        if (xx>319) xx=319;
	if (xx1>319) xx1=319;
	if (yy>199) yy=199;
	if (yy1>199) yy1=199;
	if (xx<0) xx=0;
	if (xx1<0) xx1=0;
	if (yy<0) yy=0;
	if (yy1<0) yy1=0;
	if (xx==xx1 && yy<=yy1) {
		xxa=xx1-xx;
yyy=yy1-yy;		
if (yyy<1) yyy=1;
		
		
	
			
	xxx=yy*320+xx;
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=yyy;

	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	ir=320;
	movedata(__get_ds(),&ir,__get_cs(),0x86,2);
	movedata(__get_ds(),&vlinecolor,__get_cs(),0x88,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0x82]";
	asm "mov dx,[0x88]";
	asm "mov bx,[0x86]";	
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "mov al,dl";
	asm "mov dx,bx";
	asm "xor bx,bx";

asm "label22:";

asm "mov [di],al";
asm "clc";
asm "add di,dx";
asm "dec cx";
asm "cmp cx,bx";
asm "jnz label22";
	asm "pop ds";
			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
	}




int drawtext(drawtextx,drawtexty,drawtextcolor,drawtextvalue)
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
	xx=drawtextx;
	yy=drawtexty;
        if (xx>319) xx=319;

	if (yy>199) yy=199;

	if (xx<0) xx=0;

	if (yy<0) yy=0;

	if (xx<320/8 && yy<200/8) {
	

ir=xx;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=yy;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=0x13;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	ir=1;
	movedata(__get_ds(),&ir,__get_cs(),0x86,2);
	ir=0;
	movedata(__get_ds(),&ir,__get_cs(),0x88,2);
	ir=drawtextcolor;
	movedata(__get_ds(),&ir,__get_cs(),0x8a,2);
	ir=strlen(drawtextvalue);
	movedata(__get_ds(),&ir,__get_cs(),0x8c,2);

	movedata(__get_ds(),&drawtextvalue,__get_cs(),0x8e,2);



	asm "push es";
	asm "push ds";
	asm "push ds";
	asm "pop es";
	asm "push bp";
	asm "push di";
	asm "push si";

	asm "push cs";
	asm "pop ds";
	asm "mov dh,[0x80]";
	asm "mov dl,[0x82]";	
        asm "mov bh,[0x88]";	
        asm "mov bl,[0x8a]";
	asm "mov cx,[0x8c]";
	asm "mov ax,[0x8e]";
	asm "push ax";
	asm "pop bp";
	asm "mov ah,[0x84]";
	asm "mov al,[0x86]";



asm "int 0x10";
	asm "pop si";
	asm "pop di";
	asm "pop bp";

	asm "pop ds";
	asm "pop es";			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
	}


int rects(rectsx,rectsy,rectsx1,rectsy1,rectscolor)
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
	xx=rectsx;
	yy=rectsy;
	xx1=rectsx1;
	yy1=rectsy1;
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
	ir=0xa000;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=xxa;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	ir=nx;
	movedata(__get_ds(),&ir,__get_cs(),0x86,2);
	ir=yyy;
	movedata(__get_ds(),&ir,__get_cs(),0x88,2);
	movedata(__get_ds(),&rectscolor,__get_cs(),0x8a,1);
	asm "push es";
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
	asm "push ax";
	asm "pop es";
	asm "pop ds";
	asm "mov al,dl";
	asm "xor dx,dx";
	asm "push cx";
	asm "label40:";
	asm "pop cx";
	asm "push cx";
asm "label50:";
asm "push ax";
asm "xor ax,ax";
asm "mov ah,[di]";
asm "cmp ah,al";
asm "jnz label51";
asm "pop ax";
asm "mov [di],al";
asm "jmp label52";
asm "label51:";
asm "pop ax";
asm "label52:";
asm "inc di";
asm "dec cx";
asm "cmp cx,dx";
asm "jnz label50";
	asm "clc";
	asm "add di,si";
asm "dec bx";
asm "cmp bx,dx";
	asm "jnz label40";
	asm "pop ax";
	asm "pop ds";
	asm "pop es";
			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
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


