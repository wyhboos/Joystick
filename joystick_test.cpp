#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<Windows.h>
//���joystick����api��֧�ֿ�
#include<MMSystem.h>
using namespace std;
int main(int argc, char* argv[])
{
	JOYINFOEX joyinfoex;//����joystick��Ϣ�ṹ��
	joyinfoex.dwSize = sizeof(JOYINFOEX);//��ʼ������
	joyinfoex.dwFlags = JOY_RETURNALL;//��ʼ������
	//���淽���״̬��ǰ������
	bool button_forward;
	bool button_backward;
	bool button_left;
	bool button_right;

	//����λ�����꣺XYZ
	DWORD X;
	DWORD Y;
	DWORD Z;

	//������������״̬
	bool botton_1;
	bool botton_2;
	bool botton_3;
	bool botton_4;
	bool botton_5;
	bool botton_6;
	bool botton_7;
	bool botton_8;
	bool botton_9;
	bool botton_10;




	while(1)
	{
		//��ȡ�ֱ�����
		UINT joyNums;
		joyNums = joyGetNumDevs();
		//��ȡ�ֱ���Ϣ
		if (joyNums>=1)
		{
			MMRESULT joyreturn = joyGetPosEx(JOYSTICKID1, &joyinfoex);

			//�жϼ���״̬
			if (joyinfoex.dwPOV == JOY_POVFORWARD)
			{
				button_forward = true;
			}
			if (joyinfoex.dwPOV == JOY_POVBACKWARD)
			{
				button_backward = true;
			}
			if (joyinfoex.dwPOV == JOY_POVLEFT)
			{
				button_left = true;
			}
			if (joyinfoex.dwPOV == JOY_POVRIGHT)
			{
				button_right = true;
			}
			if (joyinfoex.dwPOV == JOY_POVCENTERED)
			{
					button_forward = false;
				    button_backward = false;
					button_left = false;
				  	button_right = false;
			}

			//�ж�XYZλ��
			X = joyinfoex.dwXpos;
			Y = joyinfoex.dwYpos;
			Z = joyinfoex.dwZpos;

			//�ж���������
			if ((joyinfoex.dwButtons & 0b01) == 0b01)
			{
				botton_1 = true;
			}
			else
			{
				botton_1 = false;
			}
			if ((joyinfoex.dwButtons & 0b010) == 0b010)
			{
				botton_2 = true;
			}
			else
			{
				botton_2 = false;
			}
			if ((joyinfoex.dwButtons & 0b0100) == 0b0100)
			{
				botton_3 = true;
			}
			else
			{
				botton_3 = false;
			}
			if ((joyinfoex.dwButtons & 0b01000) == 0b01000)
			{
				botton_4 = true;
			}
			else
			{
				botton_4 = false;
			}
			if ((joyinfoex.dwButtons & 0b010000) == 0b010000)
			{
				botton_5 = true;
			}
			else
			{
				botton_5 = false;
			}
			if ((joyinfoex.dwButtons & 0b0100000) == 0b0100000)
			{
				botton_6 = true;
			}
			else
			{
				botton_6 = false;
			}
			if ((joyinfoex.dwButtons & 0b01000000) == 0b01000000)
			{
				botton_7 = true;
			}
			else
			{
				botton_7 = false;
			}
			if ((joyinfoex.dwButtons & 0b010000000) == 0b010000000)
			{
				botton_8 = true;
			}
			else
			{
				botton_8 = false;
			}
			
			cout<<"---------����״̬---------"<<endl;
			cout<<"�����"<<endl;
			cout<<button_forward<<endl;
			cout<<button_backward<<endl;
			cout<<button_left<<endl;
			cout<<button_right<<endl;
			cout<<"XYZλ��"<<endl;
			cout<<X<<endl;
			cout<<Y<<endl;
			cout<<Z<<endl;
			cout<<"button 1:"<<botton_1<<endl;
			cout<<"button 2:"<<botton_2<<endl;
			cout<<"button 3:"<<botton_3<<endl;
			cout<<"button 4:"<<botton_4<<endl;
			cout<<"button 5:"<<botton_5<<endl;
			cout<<"button 6:"<<botton_6<<endl;
			cout<<"button 7:"<<botton_7<<endl;
			cout<<"button 8:"<<botton_8<<endl;
		Sleep(50);//��ȡ���
        }
	}
	return 0;
}