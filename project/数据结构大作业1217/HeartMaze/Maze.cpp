#include<bits/stdc++.h>
//#include "stdafx.h"
#include "Maze.h"

bool visited[N][M];
bool mask[N][M];//mask��initMaze�����������ÿո�Ӷ���clearMask����ǽ�ﵽ��ͨ��Ч��(�˴��Ĵ�ͨΪ��ͨ�ո�����ǽ)
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
	initHeart();//���������������ͼ��
	srand((unsigned)time(NULL));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (area[i][j] && !(area[i][j - 1] && area[i][j + 1] && area[i - 1][j] && area[i + 1][j]))
				maze[i][j] = OUTWALL;//ǽ
			else if (area[i][j] && i % 2 == 0 && j % 2 == 0)
				maze[i][j] = ROAD;//�ո�
			else if (area[i][j])
				maze[i][j] = INWALL;//ǽ
			else
				maze[i][j] = EMPTYWALL;//�ո�
			visited[i][j] = false;
			mask[i][j] = true;//�ո���mask����Ϊ�ո���֮������ǽ
		}
	}
	in.x = 1;
	in.y = 6;
	out.x = 27;
	out.y = 36;
	maze[in.x][in.y] = maze[out.x][out.y] = ROAD;//���ȶ��ó����
	SqQueue S;
	Block start;
	initQueue(S);
	start.x = 2;
	start.y = 6;
	enQueue(S, start);//������ν�?
	visited[start.x][start.y] = true;
	clearMask(start.x, start.y);//һ���жϾŹ���
	while (!isEmpty(S))
	{
		Block curBlock;
		deQueue(S, curBlock);
		for (int i = 0; i < 4; i++)
		{
			int nextBlockX = curBlock.x + di[i][0] * 2;//diΪ��ά������?�����ж�����Ϊ����//�����
			int nextBlockY = curBlock.y + di[i][1] * 2;
			if (inMaze(nextBlockX, nextBlockY) && maze[nextBlockX][nextBlockY] == ROAD && !visited[nextBlockX][nextBlockY])
			{
				Block nextBlock;
				nextBlock.x = nextBlockX;
				nextBlock.y = nextBlockY;
				enQueue(S, nextBlock);
				maze[curBlock.x + di[i][0]][curBlock.y + di[i][1]] = ROAD;//��Ϊһ��ǽռ�����ֽڣ�����Ҫ��ROAD��һ�����ֽ�
				visited[nextBlockX][nextBlockY] = true;
				clearMask(nextBlockX, nextBlockY);//���mask��־/������ǽ//��ʵ��mask��false��ԭ�����ó����ڽ���updateMazeʱ����mask�ո���и���wall�����
				updateMaze(maze);//һ�ν�������˴��Թ�����//������updataMazeɾ�������������Թ�
			}
		}
	}
	for (int i = 0; i < N; i++)///��������ǽ�����//Ϊ�δ˴�������ǽ���������զ��һ��while������ԭ��
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == OUTWALL)
			{
				mask[i][j] = false;//���´˴�mask�Է�ֹ�ո�//��initMaze����������ǽ//��Ϊ�˺�������mask=false;�����wall���ж�
				updateMaze(maze);//�˴�ɾ���������Թ�
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
		if (inMaze(curBlockX, curBlockY) && maze[curBlockX][curBlockY] == ROAD)//�����in��ʼѭ��
		{
			initBlock(block, curBlockX, curBlockY, EAST);//��block�������ֵ����EAST��ʼ//��֤��//��������ʱ������if��ʱ�ط��ϣ�����·ʱһֱ��EAST�ߡ�,y++����YΪ����
			push(S, block);//block��ջ,//�����ж�ջ�Ƿ�Ϊ��

			maze[curBlockX][curBlockY] = block.di;//�����·�update�������ͷ�����ÿտ�//�˴����м�Ϊ�Ҽ�ͷ
			updateMaze(maze);//

			if (curBlockX == out.x&&curBlockY == out.y)
			{
				printf("\nѰ·�ɹ�\n��%d��", step);
				Sleep(100000);//�����󱣳ֽ������
				system("cls");
				return;//ѱ¹�ɹ�ֱ�ӽ��������ǽ���ѭ�������ʧ��
			}
			curBlockX = nextBlockX(block.x, block.di);//���´���y��
			curBlockY = nextBlockY(block.y, block.di);//������EAST�н�
			step++;
		}
		else//������Χ����������ͨ·����ǽ
		{
			pop(S, block);//�����ж�ջ�Ƿ�Ϊ��//��Ϊ��ջ�õ���һ��������������л��жϷ����ͷ

			if (block.di < NORTH)
			{
				block.di++;//����ͷ�ж�
				maze[block.x][block.y] = block.di;//���´�ʱ��ͷ����
				push(S, block);
				curBlockX = nextBlockX(block.x, block.di);
				curBlockY = nextBlockY(block.y, block.di);
				updateMaze(maze);//kongzhi sudu?
			}
			else//��·��Ϊ�߹���Ϊ�տ� block.di >= NORTH , ��ôNORTH��ʲô��?��ͷ�� ׷�ݵ����ĸ��������ȿ�ʼ��EAST�Ҽ�ͷ//����NORTHΪ�߽���������ΪNOTH=9Ϊmax��С�ڵ���9��Ϊ��ͷ��������ѱ¹��ֻ��Ϊ�տ�BACK
			{
				maze[block.x][block.y] = BACK;
				updateMaze(maze);//�˴�ɾ��������
				step--;//������ɾ����һ��
			}
		}
	} while (!isEmpty(S));///�����//���������˶�û�дﵽ�յ���֤��ѱ¹ʧ��
	printf("Ѱ·ʧ��");
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
				printf("��");
			else if (maze[i][j] == OUTWALL)
				printf("��");
			else if (maze[i][j] == EMPTYWALL)//�������β�������Ŀղ���
				printf("  ");
			else if (maze[i][j] == ROAD)
				printf("  ");
			else if (maze[i][j] == BACK)
				printf("��");
			else if (maze[i][j] == EAST)
				printf("��");
			else if (maze[i][j] == SOUTH)
				printf("��");
			else if (maze[i][j] == WEST)
				printf("��");
			else if (maze[i][j] == NORTH)
				printf("��");
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

void clearMask(int x, int y)//��Χ�ǾŹ���
{
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (inMaze(i, j))//��������������ж��Ƿ����ǽ������������mask=true������ո�
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
