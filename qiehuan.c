#include <reg52.h>

typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;

sbit k1=P3^2;	 //����P27����k1

sbit LSA=P2^2;    //�������λѡ��I/O��
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 flag;
u8 code smgduan[8]={0x06,0x7f,0x5b,0x06,0x3f,0x06,0x4f,0x06};   //ѧ������
u8 code smgduan_1[8]={0x5b,0x3f,0x06,0x6f,0x06,0x3f,0x3f,0x06,};//��������

void delay(u8 i)     //��ʱ������i=1ʱ�������ʱ10um
{
	while(i--);
}
void display()
{
	u8 i;
	if(flag==0)
	{
		delay(100);   //�������� һ���Լ10ms
	   for(i=0;i<8;i++)
 	   {
  	   switch(i)	 //λѡ��ѡ�����������ܣ�
		   {
			  case(0):
				  LSA=1;LSB=1;LSC=1; break;//��ʾ��7λ
			  case(1):
				  LSA=0;LSB=1;LSC=1; break;//��ʾ��6λ
			  case(2):
				  LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
			  case(3):
			  	LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
			  case(4):
			  	LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
		  	case(5):
				  LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
		  	case(6):
			  	LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
			  case(7):
			  	LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
			  default:break;
	  	}
		  P0=smgduan[i]; //���Ͷ���
	 	  delay(100);   //���һ��ʱ��ɨ��
		  P0=0x00;     //������ʹ��ѡȫΪ0
	  }
  }
		if(flag==1)
		{
			 for(i=0;i<8;i++)
			 {
				switch(i)	 //λѡ��ѡ�����������ܣ�
				{
				case(0):
					LSA=1;LSB=1;LSC=1; break;//��ʾ��7λ
				case(1):
					LSA=0;LSB=1;LSC=1; break;//��ʾ��6λ
				case(2):
					LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
				case(3):
					LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
				case(4):
					LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
				case(5):
					LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
				case(6):
					LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
				case(7):
					LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
				default:break;
				}
				P0=smgduan_1[i]; //���Ͷ���
				delay(100);   //���һ��ʱ��ɨ��
				P0=0x00;     //������ʹ��ѡȫΪ0
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

