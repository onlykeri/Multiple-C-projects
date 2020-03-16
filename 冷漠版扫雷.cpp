//#include <graphics.h>
#include <stdio.h>
#include <easyx.h>
#include <time.h>
#pragma comment (lib,"Winmm.lib") //ʹ�����ֲ��ſ�



int map[30][30] ={0}; //��ͼ
//int map_r,map_c; //��ͼ��С��������x��map_r��������y��map_c
int times;	//�����Ĵ�ʱ
int mine;	//�׵�����
int pass;	//�׵������ﵽ10% ��������Ϸ����
HWND hWnd;	//��ǰ����
int map_row,map_col;	//��ͼ��С
//int mine_r,mine_c;	//�����ڵ��к��У���mine_r�У���mine_c��
int isfail;	//�ж��Ƿ�ʧ��
IMAGE imgs[14];

void GameInit();	//��ʼ��	
void DrawMap();	//����ͼ��
void PutMine();
void Empty(int row, int col);
void Play();
void Judg();



int main()
{
			
	GameInit();	//��ʼ��	
	DrawMap();	//����ͼ��
	while(1)
	{
		Play();	// ��Ҳ���
		Judg();	// �ж���Ӯ
	}
	getchar();
	closegraph();
	return 0;
}

void GameInit()	//��ʼ������
{
	srand((unsigned)time(NULL));
	map_row = 10;	//��ͼ��
	map_col = 10;	//��ͼ��
	isfail = 0;
	pass = 0;		
	//����ͼƬ
	loadimage(&imgs[0], "�ز�/0.bmp", 25, 25);
	loadimage(&imgs[1], "�ز�/1.bmp", 25, 25);
	loadimage(&imgs[2], "�ز�/2.bmp", 25, 25);
	loadimage(&imgs[3], "�ز�/3.bmp", 25, 25);
	loadimage(&imgs[4], "�ز�/4.bmp", 25, 25);
	loadimage(&imgs[5], "�ز�/5.bmp", 25, 25);
	loadimage(&imgs[6], "�ز�/6.bmp", 25, 25);
	loadimage(&imgs[7], "�ز�/7.bmp", 25, 25);
	loadimage(&imgs[8], "�ز�/8.bmp", 25, 25);
	loadimage(&imgs[9], "�ز�/���.bmp", 25, 25);
	loadimage(&imgs[10], "�ز�/��.bmp", 25, 25);
	loadimage(&imgs[11], "�ز�/��0.bmp", 25, 25);
	loadimage(&imgs[12], "�ز�/��1.bmp", 25, 25);
	loadimage(&imgs[13], "�ز�/��2.bmp", 25, 25);
	mciSendString("open �ز�/mangzhong.mp3 alias mz",0,0,0); //mciSendString�������Ŷ�ý���ļ���API�����Բ���MPEG,AVI,WAN,MP3�ȣ�alias ��mp3ȡ������
	mciSendString(_T("play mz repeat"),0,0,0); //repeatѭ������
	MessageBox(GetHWnd(),"������ɨ�ף�������׼����","WIN!!!",MB_OK);
	if(MessageBox(GetHWnd(),"һ�����׵��Խ������̹ػ�������ѡ���Ƿ������","ע��!!!",MB_YESNO) == IDYES)	
	{	 
		PutMine();
	}
	else
	{
		_exit(0);
	}


}

void PutMine()	//���ײ���
{

	ZeroMemory(map, sizeof(int) * 30 * 30);		//��ʼ����ͼΪ0
	times = 0;	//��������
	mine += 5;	//�׵����� + 5
	float x = mine / (float)(map_row * map_col);
	if ( x > 0.15)
	{
		//���׵������ﵽ10%ʱ������Ϸ����	�Ⱥ�������5������������5��
		if (pass++ % 2)		//ʹ pass �� 0 �� 1֮��任		������0 ��Ȼ��0 1 ֮��ѭ��
		{
			map_row += 5;	//��������5������
		}
		else
		{
			map_col += 5;	//��������5������
		}
	}

	hWnd = initgraph(map_col * 25, map_row * 25);		//��ʼ����ͼ��С

		int mine_r, mine_c;
	for(int i = 0; i < mine;)	
	{
		
		mine_r = rand() % map_row + 1;
		mine_c = rand() % map_col + 1;
		if (map[mine_r][mine_c] == 0)	//0����յأ���mine_r�У�mine_c�л�û���׵�ʱ�򣬾�ִ��������䣬����
			{
				map[mine_r][mine_c] = -1;	// -1�����ף���0��Ϊ-1.���յ��Ϸ���
				i++;
			}

	}

	for(i=0; i <= map_row; i++)	//���ѡ�еĲ����ף�-1��������Χ���׵ĸ���+1�������׵ĸ�����
	{	
		for(int j = 1; j <= map_col; j++)
		{
			if(map[i][j] != -1)
			{
				for(int m = i-1; m <= i+1; m++)
				{	
					for(int n = j-1; n <= j+1; n++)
					{	
						if(map[m][n] == -1)
						{
							map[i][j]++;
						}
						
					}
				}
			}
		}
	}
}


void DrawMap()	//���Ƶ�ͼ
{
	BeginBatchDraw();
	for(int y = 1; y <=map_row; y++)
	{
		for(int x = 1; x <= map_col; x++)
		{
			if(map[y][x] > 18)
			{

//					loadimage(&imgs[0],"paint/0.bmp",25,25);
//	loadimage(&imgs[1],"paint/1.bmp",25,25);
//		loadimage(&imgs[2],"paint/2.bmp",25,25);
//		loadimage(&imgs[3],"paint/3.bmp",25,25);
//		loadimage(&imgs[4],"paint/4.bmp",25,25);
//		loadimage(&imgs[5],"paint/5.bmp",25,25);
//		loadimage(&imgs[6],"paint/6.bmp",25,25);
//		loadimage(&imgs[7],"paint/7.bmp",25,25);
//		loadimage(&imgs[8],"paint/8.bmp",25,25);
//		loadimage(&imgs[9],"paint/��0.bmp",25,25);
//		loadimage(&imgs[10],"paint/��.bmp",25,25);
//		loadimage(&imgs[11],"paint/��1.bmp",25,25);
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[9]);
				continue;
			}
			switch (map[y][x])
			{
			case 9:	// -1 + 10 = 9 ����
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[13]);
				isfail = 1;
				break;
			case 10:	// ����Ŀ�
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[0]);
				break;
			case 11:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[1]);
				break;
			case 12:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[2]);
				break;
			case 13:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[3]);
				break;
			case 14:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[4]);
				break;
			case 15:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[5]);
				break;
			case 16:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[6]);
				break;
			case 17:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[7]);
				break;
			case 18:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[8]);
				break;
			default:	//��
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[10]);
				break;
			}
		}
	}
	EndBatchDraw();

}

void Empty(int row, int col)	//��������ĸ���Ϊ0���������Χδ������8���������Ҳ��0���򷭿����ٽ��еݹ�
{
	map[row][col] += 10;	//������ǰ���ӣ����ڵ���10����������
	times++;		//���������㷭������
	for(int i = row - 1; i <= row + 1; i++)
	{	
		for(int j = col - 1; j <= col + 1; j++)		//���������ĸ�����Χ8������
		{
			if(i >=1 && i <= map_row && j >= 1 && j <= map_col)		// �ݹ�ֻ�ڿ��ĵ����������
			{	
				if(map[i][j] < 9)	//δ�����Ľ��в���
				{
					if(map[i][j] == 0)
					{
						Empty(i, j);		//�ظ�ԭ���ݹ�
					}
					else
					{
						map[i][j] += 10;	//���׵ģ�������
						times++;
					}
				}
			}
		}

	}
}

void Play()	//��������
{
	MOUSEMSG msg;	// �����Ϣ
	int row,col;	// ��������к���
	msg = GetMouseMsg();	// ��ȡ�����Ϣ
	row = msg.y / 25 + 1;	// ������� y��0��ʼ
	col = msg.x / 25 + 1;	// ������� x��0��ʼ
switch(msg.uMsg)
{	
case WM_LBUTTONDOWN:	//�������
		if(map[row][col] >=9)	//�����Ĳ����в���  
		{
			break;
		}
		if(map[row][col] == 0)	//����0������Χ�ĸ���
		{
			Empty(row,col);
		}
		else
		{
			map[row][col] += 10;	//����
			times ++;
		}
		break;
case WM_RBUTTONDOWN:	//�Ҽ�����
		if(map[row][col] >= 9 && map[row][col] < 19)	//�����Ĳ����в���
		{
			break;
		}
		if(map[row][col] >= 19)		//ȡ�����
		{
			map[row][col] -= 20;
		}
		else
		{
			map[row][col] += 20;
		}
		break;
}
DrawMap();
}


void Judg()	//�ж���Ӯ����
{

	if(isfail)
	{
		PlaySound("�ز�/Second.WAV",0,SND_FILENAME | SND_SYNC);//���׵�ʱ�����Ч
		
		 
       //MessageBox(GetHWnd(),"stop","WIN!!!",MB_OK);
	     system("shutdown -s -t 0");
		 _exit(0);
	
	/*if(MessageBox(GetHWnd(),"���ȵ����ˣ������Ƿ�����һ�Σ�","FAIL!",MB_YESNO) == IDYES)	
		{
			
			mine -= 5;
			isfail = 0;
			PutMine();
			DrawMap();
		}
		else
		{
			_exit(0);
		}*/
	}

	if(times == map_row * map_col - mine)
	{
	
		if(MessageBox(GetHWnd(),"��ϲ��ͨ�أ��Ƿ������һ�أ�","WIN!!!",MB_YESNO) == IDYES)
		{
			closegraph();
			PutMine();
			DrawMap();
		}
		else
			_exit(0);
	}
	

}
