#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<Windows.h>
//添加joystick操作api的支持库
#include<MMSystem.h>
using namespace std;
int main(int argc, char* argv[])
{
	JOYINFOEX joyinfoex;//定义joystick信息结构体
	joyinfoex.dwSize = sizeof(JOYINFOEX);//初始化参数
	joyinfoex.dwFlags = JOY_RETURNALL;//初始化参数
	//储存方向键状态：前后左右
	bool button_forward;
	bool button_backward;
	bool button_left;
	bool button_right;

	//储存位置坐标：XYZ
	DWORD X;
	DWORD Y;
	DWORD Z;

	//储存其它按键状态
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
		//读取手柄数量
		UINT joyNums;
		joyNums = joyGetNumDevs();
		//读取手柄信息
		if (joyNums>=1)
		{
			MMRESULT joyreturn = joyGetPosEx(JOYSTICKID1, &joyinfoex);

			//判断键盘状态
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

			//判断XYZ位置
			X = joyinfoex.dwXpos;
			Y = joyinfoex.dwYpos;
			Z = joyinfoex.dwZpos;

			//判断其它按键
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
			
			cout<<"---------按键状态---------"<<endl;
			cout<<"方向键"<<endl;
			cout<<button_forward<<endl;
			cout<<button_backward<<endl;
			cout<<button_left<<endl;
			cout<<button_right<<endl;
			cout<<"XYZ位置"<<endl;
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
		Sleep(50);//读取间隔
        }
	}
	return 0;
}