#include<bits/stdc++.h>
//#include "stdafx.h"
#include "Maze.h"

bool visited[N][M];
bool mask[N][M];//mask在initMaze函数中用来置空格从而用clearMask生成墙达到打通的效果(此处的打通为打通空格填入墙)
bool area[N][M];
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

int main()
{
	Maze maze[N][M];
	Block in, out;
	initMaze(maze, in, out);
	findPath(maze, in, out);
	return 0;
}

void initMaze(Maze maze[N][M], Block &in, Block &out)
{
	initHeart();//调用下面的心形满图案
	srand((unsigned)time(NULL));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (area[i][j] && !(area[i][j - 1] && area[i][j + 1] && area[i - 1][j] && area[i + 1][j]))
				maze[i][j] = OUTWALL;//墙
			else if (area[i][j] && i % 2 == 0 && j % 2 == 0)
				maze[i][j] = ROAD;//空格
			else if (area[i][j])
				maze[i][j] = INWALL;//墙
			else
				maze[i][j] = EMPTYWALL;//空格
			visited[i][j] = false;
			mask[i][j] = true;//空格先mask所有为空格再之后生成墙
		}
	}
	in.x = 1;
	in.y = 6;
	out.x = 27;
	out.y = 36;
	maze[in.x][in.y] = maze[out.x][out.y] = ROAD;//事先定好出入口
	SqQueue S;
	Block start;
	initQueue(S);
	start.x = 2;
	start.y = 6;
	enQueue(S, start);//进队如何进?
	visited[start.x][start.y] = true;
	clearMask(start.x, start.y);//一次判断九宫格
	while (!isEmpty(S))
	{
		Block curBlock;
		deQueue(S, curBlock);
		for (int i = 0; i < 4; i++)
		{
			int nextBlockX = curBlock.x + di[i][0] * 2;//di为二维数组了?上面有定义已为数组//待理解
			int nextBlockY = curBlock.y + di[i][1] * 2;
			if (inMaze(nextBlockX, nextBlockY) && maze[nextBlockX][nextBlockY] == ROAD && !visited[nextBlockX][nextBlockY])
			{
				Block nextBlock;
				nextBlock.x = nextBlockX;
				nextBlock.y = nextBlockY;
				enQueue(S, nextBlock);
				maze[curBlock.x + di[i][0]][curBlock.y + di[i][1]] = ROAD;//因为一个墙占两个字节，所以要置ROAD则一次两字节
				visited[nextBlockX][nextBlockY] = true;
				clearMask(nextBlockX, nextBlockY);//清除mask标志/即生成墙//其实把mask置false的原因是让程序在进行updateMaze时跳过mask空格进行各种wall的填充
				updateMaze(maze);//一次结束输出此次迷宫部分//将两份updataMaze删除即可秒生成迷宫
			}
		}
	}
	for (int i = 0; i < N; i++)///最后进行外墙的填充//为何此处进行外墙的填充上面咋不一起？while的条件原因
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == OUTWALL)
			{
				mask[i][j] = false;//更新此处mask以防止空格//在initMaze中用来生成墙//因为此函数中若mask=false;则进行wall的判断
				updateMaze(maze);//此处删除秒生成迷宫
			}
		}
	}
}

void findPath(Maze maze[N][M], Block in, Block out)
{
	Block block;
	SqStack S;
	initStack(S);
	int curBlockX = in.x;
	int curBlockY = in.y;
	int step = 1;
	do {
		if (inMaze(curBlockX, curBlockY) && maze[curBlockX][curBlockY] == ROAD)//从入口in开始循环
		{
			initBlock(block, curBlockX, curBlockY, EAST);//向block更新最近值，从EAST开始//待证明//符合条件时（根据if此时必符合）即有路时一直向EAST走→,y++所以Y为横轴
			push(S, block);//block入栈,//用来判断栈是否为空

			maze[curBlockX][curBlockY] = block.di;//用于下方update的输出箭头或是置空框//此处运行即为右箭头
			updateMaze(maze);//

			if (curBlockX == out.x&&curBlockY == out.y)
			{
				printf("\n寻路成功\n共%d步", step);
				Sleep(100000);//结束后保持结果秒数
				system("cls");
				return;//驯鹿成功直接结束而不是结束循环后输出失败
			}
			curBlockX = nextBlockX(block.x, block.di);//上下代表y轴
			curBlockY = nextBlockY(block.y, block.di);//继续向EAST行进
			step++;
		}
		else//超出范围或者遇到非通路径即墙
		{
			pop(S, block);//用来判断栈是否为空//因为出栈得到上一步骤的坐标用来切换判断方向箭头

			if (block.di < NORTH)
			{
				block.di++;//换箭头判断
				maze[block.x][block.y] = block.di;//更新此时箭头方向
				push(S, block);
				curBlockX = nextBlockX(block.x, block.di);
				curBlockY = nextBlockY(block.y, block.di);
				updateMaze(maze);//kongzhi sudu?
			}
			else//此路径为走过置为空框 block.di >= NORTH , 那么NORTH是什么鬼?箭头↑ 追溯到从哪个方向最先开始：EAST右箭头//设置NORTH为边界条件是因为NOTH=9为max若小于等于9则为箭头，否则在驯鹿中只能为空框BACK
			{
				maze[block.x][block.y] = BACK;
				updateMaze(maze);//此处删除秒生成
				step--;//不成立删除这一步
			}
		}
	} while (!isEmpty(S));///待理解//数据跑完了都没有达到终点则证明驯鹿失败
	printf("寻路失败");
}

void initBlock(Block &block, int x, int y, int di)
{
	block.x = x;
	block.y = y;
	block.di = di;
}

void showBlock(Maze maze[N][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (mask[i][j] == true)
				printf("  ");
			else if (maze[i][j] == INWALL)
				printf("█");
			else if (maze[i][j] == OUTWALL)
				printf("█");
			else if (maze[i][j] == EMPTYWALL)//即除心形部分往外的空部分
				printf("  ");
			else if (maze[i][j] == ROAD)
				printf("  ");
			else if (maze[i][j] == BACK)
				printf("□");
			else if (maze[i][j] == EAST)
				printf("→");
			else if (maze[i][j] == SOUTH)
				printf("↓");
			else if (maze[i][j] == WEST)
				printf("←");
			else if (maze[i][j] == NORTH)
				printf("↑");
			if (j != 0 && j % (M - 1) == 0)
				printf("\n");
		}
	}
}

void updateMaze(Maze maze[N][M])
{
	hideCursor();
	gotoxy(0, 0);
	showBlock(maze);
	Sleep(DELAY);
}

int nextBlockX(int a, int di)
{
	int x = a;
	switch (di)
	{
		case SOUTH:
			x++;
			break;
		case NORTH:
			x--;
			break;
		default:
			break;
	}
	return x;
}

int nextBlockY(int b, int di)
{
	int y = b;
	switch (di)
	{
		case EAST:
			y++;
			break;

		case WEST:
			y--;
			break;
		default:
			break;
	}
	return y;
}

bool inMaze(int x, int y)
{
	return x >= 0 && x < N&&y >= 0 && y < M;
}

void clearMask(int x, int y)//范围是九宫格
{
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (inMaze(i, j))//符合条件则进行判断是否输出墙，若不符合则mask=true则输出空格
				mask[i][j] = false;
}

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void hideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void initHeart()
{
	int i = 0, j = 0;
	for (float y = 1.2f; y > -1.0f; y -= 0.06f)
	{
		for (float x = -1.1f; x < 1.2f; x += 0.05f)
		{
			float a = x * x + y * y - 1;
			if (a * a * a - x * x * y * y * y <= 0.0f)
				area[i][j] = true;
			else
				area[i][j] = false;
			j++;
		}
		i++;
		j = 0;
	}
}
