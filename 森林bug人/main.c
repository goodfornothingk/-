#include <graphics.h>
//using namespace ege;

int main()
{
	initgraph(640, 480);
	//���û滭��ɫΪ��ɫ
	setcolor(EGERGB(0xFF, 0x0, 0x0));
	//���ñ�����ɫΪ��ɫ
	setbkcolor(WHITE);
	//��Բ
	circle(320, 240, 100);

	getch();

	closegraph();
	return 0;
}
