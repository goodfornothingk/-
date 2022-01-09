#include <graphics.h>
//using namespace ege;

int main()
{
	initgraph(640, 480);
	//设置绘画颜色为红色
	setcolor(EGERGB(0xFF, 0x0, 0x0));
	//设置背景颜色为白色
	setbkcolor(WHITE);
	//画圆
	circle(320, 240, 100);

	getch();

	closegraph();
	return 0;
}
