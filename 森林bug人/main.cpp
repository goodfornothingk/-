#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#define vx 260
#define vy 500
#define ax_normal  250
#define ax_special 150
#define ay 1200
#define time 1.0/60
#define widthleft 43
#define widthright 55
#define lengthup 30
#define lengthdown 77
#define pianyi 4
#define edgeleft 50
#define edgeright 1050
#define DOORWIDTH 60
#define DOORHEIGHT 73
#define ICEDOORX 875
#define ICEDOORY 75
#define FIREDOORX 950
#define FIREDOORY 75
PIMAGE ICEDOOR0, ICEDOOR1, ICEDOOR2, ICEDOOR3, ICEDOOR4, FIREDOOR0, FIREDOOR1, FIREDOOR2, FIREDOOR3, FIREDOOR4;
PIMAGE _enter, _back1, _back2, _barrier1, _dead, succeeded;
PIMAGE _start, _explanationbt, _about, _explanation;
PIMAGE _firestill, _fireup, _firedown, _fireleft, _fireright, _firelu, _fireld, _fireru, _firerd;
PIMAGE _icestill, _iceup, _icedown, _iceleft, _iceright, _icelu, _iceld, _iceru, _icerd;
PIMAGE SWITCH, lift;
char A, B, C, D;
int firedoormode = 24, icedoormode = 24;
int barrier = 0, lifty = 350;
double initial_firex[100] = { 100 }, initial_firey[100] = { 500 }, firex = 0, firey = 0, initial_icex[100] = { 100 }, initial_icey[600] = { 600 }, icex = 0, icey = 0;
double firevx = 0, firevy = 0, icevx = 0, icevy = 0;
mouse_msg msg = { 0 };
//�������꣬����һ����������ʮ�أ�ÿ�ؿ�����100�����������
typedef struct model1
{
	int x1 = 0, x2 = 1100, y1 = 699, y2 = 714;//714
}model1_;
model1_ floor[10][100], roof[10][100];
typedef struct model2
{
	int x = 369, y1 = 617, y2 = 621;
}model2_;
model2_ wallleft[10][100], wallright[10][100];
void datainitial()
{
	firedoormode = 24, icedoormode = 24;
	lifty = 350;
	firex = initial_firex[0];
	firey = initial_firey[0];
	icex = initial_icex[0];
	icey = initial_icey[0];
	firevx = 0, firevy = 0, icevx = 0, icevy = 0;
	floor[0][15].y1 = 368, floor[0][15].y2 = 383;
}
void initial()
{
	//��ʼ��ͼƬ
	succeeded = newimage();
	_explanation = newimage();
	_dead = newimage();
	SWITCH = newimage();
	lift = newimage();
	_enter = newimage();
	_back1 = newimage();
	_back2 = newimage();
	_barrier1 = newimage();
	_start = newimage();
	_about = newimage();
	_explanationbt = newimage();
	_icestill = newimage();
	_iceup = newimage();
	_icedown = newimage();
	_iceleft = newimage();
	_iceright = newimage();
	_icelu = newimage();
	_iceld = newimage();
	_iceru = newimage();
	_icerd = newimage();
	_firestill = newimage();
	_fireup = newimage();
	_firedown = newimage();
	_fireleft = newimage();
	_fireright = newimage();
	_firelu = newimage();
	_fireld = newimage();
	_fireru = newimage();
	_firerd = newimage();
	FIREDOOR0 = newimage();
	FIREDOOR1 = newimage();
	FIREDOOR2 = newimage();
	FIREDOOR3 = newimage();
	FIREDOOR4 = newimage();
	ICEDOOR0 = newimage();
	ICEDOOR1 = newimage();
	ICEDOOR2 = newimage();
	ICEDOOR3 = newimage();
	ICEDOOR4 = newimage();
	getimage(succeeded, "res//�ɹ�.jpg");
	getimage(_dead, "res//����.jpg");
	getimage(_explanation, "res//��Ϸ˵��.jpg");
	getimage(lift, "res//����̨.png");
	getimage(SWITCH, "res//�������.png");
	getimage(_enter, "res//�������.jpg");
	getimage(_back1, "res//��ͼ.jpg");
	getimage(_barrier1, "res//��Ϸ�ؿ�1.png");
	getimage(_back2, "res//�������ǵ���Ϸ.jpg");
	getimage(_start, "res//��ʼ��ť.png");
	getimage(_explanationbt, "res//��Ϸ˵��.png");
	getimage(_about, "res//��������.png");
	getimage(_icestill, "res//���޾�.png");
	getimage(_iceup, "res//������.png");
	getimage(_icedown, "res//������.png");
	getimage(_iceright, "res//������.png");
	getimage(_iceleft, "res//������.png");
	getimage(_icelu, "res//��������.png");
	getimage(_iceru, "res//��������.png");
	getimage(_iceld, "res//��������.png");
	getimage(_icerd, "res//��������.png");
	getimage(_firestill, "res//���޾�.png");
	getimage(_fireup, "res//������.png");
	getimage(_firedown, "res//������.png");
	getimage(_fireright, "res//������.png");
	getimage(_fireleft, "res//������.png");
	getimage(_firelu, "res//��������.png");
	getimage(_fireru, "res//��������.png");
	getimage(_fireld, "res//��������.png");
	getimage(_firerd, "res//��������.png");
	getimage(FIREDOOR0, "res//����0.png");
	getimage(FIREDOOR1, "res//����1.png");
	getimage(FIREDOOR2, "res//����2.png");
	getimage(FIREDOOR3, "res//����3.png");
	getimage(FIREDOOR4, "res//����4.png");
	getimage(ICEDOOR0, "res//����0.png");
	getimage(ICEDOOR1, "res//����1.png");
	getimage(ICEDOOR2, "res//����2.png");
	getimage(ICEDOOR3, "res//����3.png");
	getimage(ICEDOOR4, "res//����4.png");
	//�ذ������
	floor[0][1].x1 = 36, floor[0][1].x2 = 369;
	floor[0][2].x1 = 974, floor[0][2].x2 = 1019;
	floor[0][3].x1 = 1010, floor[0][3].x2 = 1060;
	floor[0][4].x1 = 36, floor[0][4].x2 = 505;
	floor[0][5].x1 = 446, floor[0][5].x2 = 919;
	floor[0][6].x1 = 148, floor[0][6].x2 = 575;
	floor[0][7].x1 = 508, floor[0][7].x2 = 1060;
	floor[0][8].x1 = 36, floor[0][8].x2 = 179;
	floor[0][9].x1 = 235, floor[0][9].x2 = 949;
	floor[0][10].x1 = 532, floor[0][10].x2 = 730;
	floor[0][11].x1 = 277, floor[0][11].x2 = 430;
	floor[0][12].x1 = 318, floor[0][12].x2 = 393;
	floor[0][13].x1 = 430, floor[0][13].x2 = 1060;
	floor[0][14].x1 = 0, floor[0][14].x2 = 235;
	floor[0][15].x1 = 10, floor[0][15].x2 = 205;
	floor[0][16].x1 = 730, floor[0][16].x2 = 810;

	//�ذ�������
	floor[0][1].y1 = 605, floor[0][1].y2 = 620;
	floor[0][2].y1 = 655, floor[0][2].y2 = 670;
	floor[0][3].y1 = 609, floor[0][3].y2 = 624;
	floor[0][4].y1 = 508, floor[0][4].y2 = 523;
	floor[0][5].y1 = 553, floor[0][5].y2 = 568;
	floor[0][6].y1 = 380, floor[0][6].y2 = 395;
	floor[0][7].y1 = 408, floor[0][7].y2 = 423;
	floor[0][8].y1 = 196, floor[0][8].y2 = 211;
	floor[0][9].y1 = 284, floor[0][9].y2 = 299;
	floor[0][10].y1 = 250, floor[0][10].y2 = 265;
	floor[0][11].y1 = 151, floor[0][11].y2 = 166;
	floor[0][12].y1 = 108, floor[0][12].y2 = 123;
	floor[0][13].y1 = 151, floor[0][13].y2 = 166;
	floor[0][14].y1 = 196, floor[0][14].y2 = 211;
	floor[0][15].y1 = 368, floor[0][15].y2 = 383;
	floor[0][16].y1 = 240, floor[0][16].y2 = 299;

	//���������
	roof[0][1].x1 = 36, roof[0][1].x2 = 369;
	roof[0][2].x1 = 36, roof[0][2].x2 = 505;
	roof[0][3].x1 = 446, roof[0][3].x2 = 919;
	roof[0][4].x1 = 148, roof[0][4].x2 = 508;
	roof[0][5].x1 = 535, roof[0][5].x2 = 948;
	roof[0][6].x1 = 982, roof[0][6].x2 = 1060;
	roof[0][7].x1 = 36, roof[0][7].x2 = 776;
	roof[0][8].x1 = 777, roof[0][8].x2 = 948;
	roof[0][9].x1 = 277, roof[0][9].x2 = 433;
	roof[0][10].x1 = 433, roof[0][10].x2 = 1060;
	roof[0][11].x1 = 0, roof[0][11].x2 = 1060;
	//����������
	roof[0][1].y1 = 618, roof[0][1].y2 = 633;
	roof[0][2].y1 = 516, roof[0][2].y2 = 534;
	roof[0][3].y1 = 569, roof[0][3].y2 = 584;
	roof[0][4].y1 = 393, roof[0][4].y2 = 408;
	roof[0][5].y1 = 420, roof[0][5].y2 = 435;
	roof[0][6].y1 = 460, roof[0][6].y2 = 475;
	roof[0][7].y1 = 300, roof[0][7].y2 = 315;
	roof[0][8].y1 = 310, roof[0][8].y2 = 325;
	roof[0][9].y1 = 177, roof[0][9].y2 = 192;
	roof[0][10].y1 = 162, roof[0][10].y2 = 177;
	roof[0][11].y1 = 30, roof[0][11].y2 = 45;
	//��ǽ�ں�����
	wallleft[0][1].x = 369; wallleft[0][2].x = 505;
	wallleft[0][3].x = 919; wallleft[0][4].x = 575;
	wallleft[0][5].x = 949; wallleft[0][6].x = 235;
	//��ǽ��������
	wallleft[0][1].y1 = 617, wallleft[0][1].y2 = 621;
	wallleft[0][2].y1 = 496, wallleft[0][2].y2 = 520;
	wallleft[0][3].y1 = 565, wallleft[0][3].y2 = 572;
	wallleft[0][4].y1 = 368, wallleft[0][4].y2 = 392;
	wallleft[0][5].y1 = 297, wallleft[0][5].y2 = 313;
	wallleft[0][6].y1 = 268, wallleft[0][6].y2 = 272;
	//��ǽ�ں�����
	wallright[0][1].x = 974; wallright[0][2].x = 948;
	wallright[0][3].x = 508; wallright[0][4].x = 148;
	wallright[0][5].x = 532; wallright[0][6].x = 277;
	//��ǽ��������
	wallright[0][1].y1 = 667, wallright[0][1].y2 = 687;
	wallright[0][2].y1 = 447, wallright[0][2].y2 = 460;
	wallright[0][3].y1 = 420, wallright[0][3].y2 = 423;
	wallright[0][4].y1 = 392, wallright[0][4].y2 = 396;
	wallright[0][5].y1 = 262, wallright[0][5].y2 = 272;
	wallright[0][6].y1 = 163, wallright[0][6].y2 = 180;
}
//�жϻ���
int judgefiredoor(double X, double Y)
{
	for (int cnt = 0; cnt < 100; cnt++)
	{
		if (X + widthleft >= FIREDOORX && X + widthleft <= FIREDOORX + DOORWIDTH)
			if (Y + lengthdown - 50 <= FIREDOORY + DOORHEIGHT)
				return 1;
	}
	return 0;
}
//�жϱ���
int judgeicedoor(double X, double Y)
{
	for (int cnt = 0; cnt < 100; cnt++)
	{
		if (X + widthleft >= ICEDOORX && X + widthleft <= ICEDOORX + DOORWIDTH)
			if (Y + lengthdown - 50 <= ICEDOORY + DOORHEIGHT)
				return 1;
	}
	return 0;
}
//�жϱ���
int judgeicefloor(double X, double Y)
{
	if (X + widthleft <= 630 && X + widthright >= 545 && Y + lengthdown - pianyi >= 685)return 1;
	return 0;
}
//�ж�d��
int judgepoisonfloor(double X, double Y)
{
	if (X + widthleft >= 695 && X + widthright <= 815 && Y + lengthdown - pianyi >= 540 && Y + lengthdown - pianyi <= 568) return 1;
	return 0;
}
int judgeswitch(double X, double Y)
{
	if (X + widthleft >= 301 && X + widthright <= 337 && Y + lengthdown - pianyi >= 508 && Y + lengthdown - pianyi <= 523)return 1;
	return 0;
}
//�жϻ���
int judgefirefloor(double X, double Y)
{
	if (X + widthleft <= 864 && X + widthright >= 770 && Y + lengthdown - pianyi >= 685) return 1;
	return 0;
}

//�ж��Ƿ��ڵ����б����
int judgefloor(double X, double Y, int i, double V)
{
	for (int cnt = 0; cnt < 50; cnt++)
	{
		if (X + widthleft >= floor[i][cnt].x1 && X + widthright <= floor[i][cnt].x2 && Y + lengthdown - pianyi >= floor[i][cnt].y1 && Y + lengthdown - pianyi <= floor[i][cnt].y2)
			return 1;
	}
	if (V <= 0)
		for (int cnt = 50; cnt < 75; cnt++)
		{
			if (X + widthleft >= floor[i][cnt].x1 && X + widthright <= floor[i][cnt].x2 && Y + lengthdown - pianyi >= floor[i][cnt].y1 && Y + lengthdown - pianyi <= floor[i][cnt].y2)
				return 1;
		}
	if (V >= 0)
		for (int cnt = 75; cnt < 100; cnt++)
		{
			if (X + widthleft >= floor[i][cnt].x1 && X + widthright <= floor[i][cnt].x2 && Y + lengthdown - pianyi >= floor[i][cnt].y1 && Y + lengthdown - pianyi <= floor[i][cnt].y2)
				return 1;
		}
	return 0;
}
//�ж��Ƿ��ײ����
int judgeroof(double X, double Y, int i)
{
	for (int cnt = 0; cnt < 100; cnt++)
	{
		if (X + widthright >= roof[i][cnt].x1 && X + widthleft <= roof[i][cnt].x2 && Y + lengthup - pianyi >= roof[i][cnt].y1 && Y + lengthup - pianyi <= roof[i][cnt].y2)
			return 1;
	}
	return 0;
}
//�ж��Ƿ�ײ��ǽ
int judegewall_left(double X, double Y, int i)
{
	for (int cnt = 0; cnt < 100; cnt++)
	{
		if (X + widthleft - wallleft[i][cnt].x <= 10 && X + widthleft - wallleft[i][cnt].x >= -40)
			if (Y + lengthup <= wallleft[i][cnt].y2 && Y + lengthdown >= wallleft[i][cnt].y1)
				return 1;
	}
	return 0;
}
//�ж��Ƿ�ײ��ǽ
int judegewall_right(double X, double Y, int i)
{
	for (int cnt = 0; cnt < 100; cnt++)
	{
		if (wallright[i][cnt].x - (X + widthright) <= 10 && wallright[i][cnt].x - (X + widthright) >= -40)
			if (Y + lengthup <= wallright[i][cnt].y2 && Y + lengthdown >= wallright[i][cnt].y1)
				return 1;
	}
	return 0;
}
//�������������������ҽ��е��ܶ��ٶ�����ٶȹ�ϵ
void run(double* VX, double* VY, double X, double Y)
{
	if (1)    //��������
	{
		if (*VX > 0)
		{
			if (*VX - ax_normal >= 0)
				*VX -= time * ax_normal;
			else *VX = 0;
		}
		if (*VX < 0)
		{
			if (*VX + ax_normal <= 0)
				*VX += time * ax_normal;
			else *VX = 0;
		}
		if ((judgefloor(X, Y, 0, *VX) == 1 && (*VY < -5) || (*VY == 0)) || (judgefloor(X, Y, 0, *VX) == 0))
		{
			*VY += ay * time;
		}
		else *VY = 0;
		if ((judgeroof(X, Y, 0) == 1) && (*VY < 0))
		{
			*VY = 0;
		}
	}
}
//�����������������뾧���ϵ��ܶ��ٶ���·�̹�ϵ
void svrelation(double* VX, double* VY, double* X, double* Y)
{
	*X += *VX * time;
	*Y += *VY * time;
	if (*VX != 0)*Y -= 1.5;
	else *Y -= 1.0 / 6;
}
//����ͼƬ�任
void changepeople()
{
	int modex = 0, modey = 0;

	//����ͼƬ�л�,�涨�� -1���� 1���� 1���� -1
	if (GetAsyncKeyState('A') & 0x8000)
	{
		modex--;
		if (icex + widthleft >= edgeleft)
		{
			if (judegewall_left(icex, icey, 0) == 0)
				icevx = -vx;
		}
		else icevx = 0;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		modex++;
		if (icex + widthright <= edgeright)
		{
			if (judegewall_right(icex, icey, 0) == 0)
				icevx = vx;
		}
		else icevx = 0;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		modey++;
		if (judgefloor(icex, icey, barrier, icevx) == 1)
		{
			icevy = -vy;
		}
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		modey--;
	}
	//�Ÿ��������
	if (modex == 0 && modey == -1)
	{
		putimage_withalpha(NULL, _icedown, int(icex), int(icey));
	}
	if (modex == 1 && modey == 0)
	{
		putimage_withalpha(NULL, _iceright, int(icex), int(icey));
	}
	if (modex == -1 && modey == 0)
	{
		putimage_withalpha(NULL, _iceleft, int(icex), int(icey));
	}
	if (modex == 1 && modey == -1)
	{
		putimage_withalpha(NULL, _icerd, int(icex), int(icey));
	}
	if (modex == -1 && modey == -1)
	{
		putimage_withalpha(NULL, _iceld, int(icex), int(icey));
	}
	if (modex == 1 && modey == 1)
	{
		putimage_withalpha(NULL, _iceru, int(icex), int(icey));
	}
	if (modex == -1 && modey == 1)
	{
		putimage_withalpha(NULL, _icelu, int(icex), int(icey));
	}
	if (modex == 0 && modey == 1)
	{
		putimage_withalpha(NULL, _iceup, int(icex), int(icey));
	}
	if (modex == 0 && modey == 0)
	{
		putimage_withalpha(NULL, _icestill, int(icex), int(icey));
	}
	modex = 0;
	modey = 0;
	//����ͼƬ�л�,�涨�� -1���� 1���� 1���� -1
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		modex--;
		if (firex + widthleft >= edgeleft)
		{
			if (judegewall_left(firex, firey, 0) == 0)
				firevx = -vx;
		}
		else firevx = 0;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		modex++;
		if (firex + widthright <= edgeright)
		{
			if (judegewall_right(firex, firey, 0) == 0)
				firevx = vx;
		}
		else firevx = 0;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		modey++;
		if (judgefloor(firex, firey, barrier, firevx) == 1)
		{
			firevy = -vy;
		}

	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		modey--;
	}
	//�Ÿ��������
	if (modex == 0 && modey == -1)
	{
		;
		putimage_withalpha(NULL, _firedown, firex, firey);
	}
	if (modex == 1 && modey == 0)
	{
		putimage_withalpha(NULL, _fireright, firex, firey);
	}
	if (modex == -1 && modey == 0)
	{
		putimage_withalpha(NULL, _fireleft, firex, firey);
	}
	if (modex == 1 && modey == -1)
	{
		putimage_withalpha(NULL, _firerd, firex, firey);
	}
	if (modex == -1 && modey == -1)
	{
		putimage_withalpha(NULL, _fireld, firex, firey);
	}
	if (modex == 1 && modey == 1)
	{
		putimage_withalpha(NULL, _fireru, firex, firey);
	}
	if (modex == -1 && modey == 1)
	{
		putimage_withalpha(NULL, _firelu, firex, firey);
	}
	if (modex == 0 && modey == 1)
	{
		putimage_withalpha(NULL, _fireup, firex, firey);
	}
	if (modex == 0 && modey == 0)
	{
		putimage_withalpha(NULL, _firestill, firex, firey);
	}

}
void map1()
{
	msg = { 0 };
	for (; is_run(); delay_fps(60))
	{

		cleardevice();
		putimage(0, 0, _barrier1);
		if (firedoormode && judgefiredoor(firex, firey) == 1)
		{
			if (firedoormode > 18)
				putimage_withalpha(NULL, FIREDOOR3, FIREDOORX, FIREDOORY);
			else if (firedoormode > 12)
				putimage_withalpha(NULL, FIREDOOR2, FIREDOORX, FIREDOORY);
			else if (firedoormode > 6)
				putimage_withalpha(NULL, FIREDOOR1, FIREDOORX, FIREDOORY);
			else
				putimage_withalpha(NULL, FIREDOOR0, FIREDOORX, FIREDOORY);
			if (firedoormode > 1 && judgefiredoor(firex, firey)) firedoormode--;
		}
		if (judgefiredoor(firex, firey) == 0) firedoormode = 24;
		if (icedoormode && judgeicedoor(icex, icey) == 1)
		{
			if (icedoormode > 18)
				putimage_withalpha(NULL, ICEDOOR3, ICEDOORX, ICEDOORY);
			else if (icedoormode > 12)
				putimage_withalpha(NULL, ICEDOOR2, ICEDOORX, ICEDOORY);
			else if (icedoormode > 6)
				putimage_withalpha(NULL, ICEDOOR1, ICEDOORX, ICEDOORY);
			else
				putimage_withalpha(NULL, ICEDOOR0, ICEDOORX, ICEDOORY);
			if (icedoormode > 1 && judgeicedoor(icex, icey)) icedoormode--;
		}
		if (judgeicedoor(icex, icey) == 0) icedoormode = 24;

		changepeople();
		run(&firevx, &firevy, firex, firey);
		run(&icevx, &icevy, icex, icey);
		svrelation(&firevx, &firevy, &firex, &firey);
		svrelation(&icevx, &icevy, &icex, &icey);
		//		xyprintf(0, 0, "X=%4d Y=%4d MSG=%4d FLAG=%4d", msg.x, msg.y, msg.msg, msg.flags);
		putimage_withalpha(NULL, SWITCH, 260, 460);
		putimage_withalpha(NULL, lift, 30, lifty);
		if (judgeicedoor(icex, icey) && judgefiredoor(firex, firey))
		{
			while (1)
			{
				while (mousemsg())
				{
					msg = getmouse();
				}
				if (msg.msg == 16)return;
				putimage(0, 0, succeeded);

				datainitial();
			}

		}
		if (judgeswitch(firex, firey) + judgeswitch(icex, icey) > 0 && lifty <= 450)
		{
			floor[0][15].y1++; floor[0][15].y2++; lifty++;
		}
		if (judgeicefloor(firex, firey) || judgepoisonfloor(firex, firey) || judgepoisonfloor(icex, icey) || judgefirefloor(icex, icey))
		{
			while (1)
			{
				while (mousemsg())
				{
					msg = getmouse();
				}
				if (msg.msg == 16)return;
				putimage(0, 0, _dead);

				datainitial();
			}

		}




		//xyprintf(0, 0, "\nfirevy=%10.10lf ", firevy);
//		if (msg.flags == 1)return;
	}
}
//��Ϸ����ͼ����
void mapmain()
{
	msg = { 0 };
	while (1)
	{
		for (; msg.msg != 16; delay_fps(60))
		{
			while (mousemsg())
			{
				msg = getmouse();
			}

			putimage(0, 0, _back1);

		}
		map1();
		msg = { 0 };
	}

}
void explanation()
{
	msg = { 0 };
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		putimage(0, 0, _explanation);
		if (msg.flags == 1) return;
	}
}
//����������Ϸ����
void about()
{
	msg = { 0 };
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		putimage(0, 0, _back2);
		if (msg.flags == 1) return;
	}
}
//���ؽ�����棬��ͼ����Ϸ�ؿ�����
void welcome()
{
	msg = { 0 };
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		cleardevice();
		putimage(0, 0, _enter);
		if (msg.x >= 425 && msg.x <= 645)
		{
			if (msg.y >= 430 && msg.y <= 480)
			{
				putimage_withalpha(NULL, _start, 380, 405);
				if (msg.flags == 1)
				{
					mapmain();
				}
			}
			else if (msg.y >= 540 && msg.y <= 590)
			{
				putimage_withalpha(NULL, _explanationbt, 385, 517);
				if (msg.flags == 1)
				{
					explanation();
					//msg = { 0 };
				}

			}
			else if (msg.y >= 650 && msg.y <= 700)
			{
				putimage_withalpha(NULL, _about, 380, 623);
				if (msg.flags == 1)
				{
					about();
				}
			}
		}
		//xyprintf(0, 0, "X=%4d Y=%4d MSG=%4d FLAG=%4d", msg.x, msg.y, msg.msg, msg.flags);
	}
}
//����̨�����������߼���ϵ
void operate()
{
	firex = initial_firex[0];
	firey = initial_firey[0];
	icex = initial_icex[0];
	icey = initial_icey[0];
	msg = { 0 };

	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		cleardevice();
		welcome();

	}
}
int main()
{
	initgraph(1100, 740);
	setcaption("ɭ�ֱ�����");
	initial();
	//	mouse();
	operate();
	return 0;
}

