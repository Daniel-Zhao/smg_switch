#include <reg52.h>

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit k1=P3^2;	 //定义P27口是k1

sbit LSA=P2^2;    //定义控制位选的I/O口
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 flag;
u8 code smgduan[8]={0x06,0x7f,0x5b,0x06,0x3f,0x06,0x4f,0x06};   //学号数字
u8 code smgduan_1[8]={0x5b,0x3f,0x06,0x6f,0x06,0x3f,0x3f,0x06,};//日期数字

void delay(u8 i)     //延时函数，i=1时，大概延时10um
{
	while(i--);
}
void display()
{
	u8 i;
	if(flag==0)
	{
		delay(100);   //消除抖动 一般大约10ms
	   for(i=0;i<8;i++)
 	   {
  	   switch(i)	 //位选，选择点亮的数码管，
		   {
			  case(0):
				  LSA=1;LSB=1;LSC=1; break;//显示第7位
			  case(1):
				  LSA=0;LSB=1;LSC=1; break;//显示第6位
			  case(2):
				  LSA=1;LSB=0;LSC=1; break;//显示第5位
			  case(3):
			  	LSA=0;LSB=0;LSC=1; break;//显示第4位
			  case(4):
			  	LSA=1;LSB=1;LSC=0; break;//显示第3位
		  	case(5):
				  LSA=0;LSB=1;LSC=0; break;//显示第2位
		  	case(6):
			  	LSA=1;LSB=0;LSC=0; break;//显示第1位
			  case(7):
			  	LSA=0;LSB=0;LSC=0; break;//显示第0位
			  default:break;
	  	}
		  P0=smgduan[i]; //发送段码
	 	  delay(100);   //间隔一段时间扫描
		  P0=0x00;     //消隐，使段选全为0
	  }
  }
		if(flag==1)
		{
			 for(i=0;i<8;i++)
			 {
				switch(i)	 //位选，选择点亮的数码管，
				{
				case(0):
					LSA=1;LSB=1;LSC=1; break;//显示第7位
				case(1):
					LSA=0;LSB=1;LSC=1; break;//显示第6位
				case(2):
					LSA=1;LSB=0;LSC=1; break;//显示第5位
				case(3):
					LSA=0;LSB=0;LSC=1; break;//显示第4位
				case(4):
					LSA=1;LSB=1;LSC=0; break;//显示第3位
				case(5):
					LSA=0;LSB=1;LSC=0; break;//显示第2位
				case(6):
					LSA=1;LSB=0;LSC=0; break;//显示第1位
				case(7):
					LSA=0;LSB=0;LSC=0; break;//显示第0位
				default:break;
				}
				P0=smgduan_1[i]; //发送段码
				delay(100);   //间隔一段时间扫描
				P0=0x00;     //消隐，使段选全为0
			}	
		}	
}

void main()
{	
	P0 = 0x00;
	flag = 0;
	while(1)
	{
		if(k1 == 0)
		{
			delay(100);
			if(k1 == 0)
			{
				flag = flag + 1;
				if(flag == 2)
				{
					flag = 0;
				}
				while(!k1);
			}
		}
		display();
	}
}

