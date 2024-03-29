// 魔方大作业.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
char cube[7][10];    // 从1开始计数，顺序为F B L R D U

void cr(int nn)//顺时针旋转一个面
{
	char tran[3];
	tran[1] = cube[nn][1];     tran[2] = cube[nn][4];
	cube[nn][1] = cube[nn][7];  cube[nn][4] = cube[nn][8];
	cube[nn][7] = cube[nn][9];  cube[nn][8] = cube[nn][6];
	cube[nn][9] = cube[nn][3];  cube[nn][6] = cube[nn][2];
	cube[nn][3] = tran[1];      cube[nn][2] = tran[2];
}
void ccr(int nn) //逆时钟旋转一个面
{
	char tran[3];
	tran[1] = cube[nn][1];     tran[2] = cube[nn][4];
	cube[nn][1] = cube[nn][3];  cube[nn][4] = cube[nn][2];
	cube[nn][3] = cube[nn][9];  cube[nn][2] = cube[nn][6];
	cube[nn][9] = cube[nn][7];  cube[nn][6] = cube[nn][8];
	cube[nn][7] = tran[1];      cube[nn][8] = tran[2];

}
//定义12种操作
void R(){
	char tran[5];  tran[1] = cube[1][3];     tran[2] = cube[1][6];    tran[3] = cube[1][9];
	cube[1][3] = cube[5][3];  cube[1][6] = cube[5][6];  cube[1][9] = cube[5][9];
	cube[5][3] = cube[2][7];  cube[5][6] = cube[2][4];  cube[5][9] = cube[2][1];
	cube[2][7] = cube[6][3];  cube[2][4] = cube[6][6];  cube[2][1] = cube[6][9];
	cube[6][3] = tran[1];     cube[6][6] = tran[2];     cube[6][9] = tran[3];
	cr(4);
		cout << "R ";
}
void Ri() {
	char tran[5];  tran[1] = cube[1][3];     tran[2] = cube[1][6];    tran[3] = cube[1][9];
	cube[1][3] = cube[6][3];  cube[1][6] = cube[6][6];  cube[1][9] = cube[6][9];
	cube[6][3] = cube[2][7];  cube[6][6] = cube[2][4];  cube[6][9] = cube[2][1];
	cube[2][7] = cube[5][3];  cube[2][4] = cube[5][6];  cube[2][1] = cube[5][9];
	cube[5][3] = tran[1];     cube[5][6] = tran[2];     cube[5][9] = tran[3];
	ccr(4);
	cout << "Ri ";
}
void D() {
	for (int i = 7; i <= 9; i++)
	{
		char tran;
		tran = cube[1][i];
		cube[1][i] = cube[3][i];
		cube[3][i] = cube[2][i];
		cube[2][i] = cube[4][i];
		cube[4][i] = tran;
	}
	cr(5);
	cout << "D ";
}
void Di() {
	for (int i = 7; i <= 9; i++)
	{
		char tran;
		tran = cube[1][i];
		cube[1][i] = cube[4][i];
		cube[4][i] = cube[2][i];
		cube[2][i] = cube[3][i];
		cube[3][i] = tran;
	}
	ccr(5);

	cout << "Di ";
}
void  L(){
	char tran[5];  tran[1] = cube[1][1];     tran[2] = cube[1][4];    tran[3] = cube[1][7];
	cube[1][1] = cube[6][1];  cube[1][4] = cube[6][4];  cube[1][7] = cube[6][7];
	cube[6][1] = cube[2][9];  cube[6][4] = cube[2][6];  cube[6][7] = cube[2][3];
	cube[2][9] = cube[5][1];  cube[2][6] = cube[5][4];  cube[2][3] = cube[5][7];
	cube[5][1] = tran[1];     cube[5][4] = tran[2];     cube[5][7] = tran[3];
	cr(3);
	cout << "L ";
}
void Li() {
	char tran[5];  tran[1] = cube[1][1];     tran[2] = cube[1][4];    tran[3] = cube[1][7];
	cube[1][1] = cube[5][1];  cube[1][4] = cube[5][4];  cube[1][7] = cube[5][7];
	cube[5][1] = cube[2][9];  cube[5][4] = cube[2][6];  cube[5][7] = cube[2][3];
	cube[2][9] = cube[6][1];  cube[2][6] = cube[6][4];  cube[2][3] = cube[6][7];
	cube[6][1] = tran[1];     cube[6][4] = tran[2];     cube[6][7] = tran[3];
	ccr(3);
	cout << "Li ";
}
void B() {
	char tran[5]; tran[1] = cube[6][1]; tran[2] = cube[6][2]; tran[3] = cube[6][3];
	cube[6][1] = cube[4][3]; cube[6][2] = cube[4][6]; cube[6][3] = cube[4][9];
	cube[4][3] = cube[5][9]; cube[4][6] = cube[5][8]; cube[4][9] = cube[5][7];
	cube[5][9] = cube[3][7]; cube[5][8] = cube[3][4]; cube[5][7] = cube[3][1];
	cube[3][7] = tran[1];    cube[3][4] = tran[2];    cube[3][1] = tran[3];
	cr(2);
	cout << "B ";
}
void Bi() {
	char tran[5]; tran[1] = cube[6][3]; tran[2] = cube[6][2]; tran[3] = cube[6][1];
	cube[6][3] = cube[3][1]; cube[6][2] = cube[3][4]; cube[6][1] = cube[3][7];
	cube[3][1] = cube[5][7]; cube[3][4] = cube[5][8]; cube[3][7] = cube[5][9];
	cube[5][7] = cube[4][9]; cube[5][8] = cube[4][6]; cube[5][9] = cube[4][3];
	cube[4][9] = tran[1];    cube[4][6] = tran[2];    cube[4][3] = tran[3];
	ccr(2);
	cout << "Bi ";
}
void F() {
	char tran[5]; tran[1] = cube[6][9]; tran[2] = cube[6][8]; tran[3] = cube[6][7];
	cube[6][9] = cube[3][3]; cube[6][8] = cube[3][6]; cube[6][7] = cube[3][9];
	cube[3][3] = cube[5][1]; cube[3][6] = cube[5][2]; cube[3][9] = cube[5][3];
	cube[5][1] = cube[4][7]; cube[5][2] = cube[4][4]; cube[5][3] = cube[4][1];
	cube[4][7] = tran[1];    cube[4][4] = tran[2];    cube[4][1] = tran[3];
	cr(1);
	cout << "F ";
}
void Fi() {
	char tran[5]; tran[1] = cube[6][7]; tran[2] = cube[6][8]; tran[3] = cube[6][9];
	cube[6][7] = cube[4][1]; cube[6][8] = cube[4][4]; cube[6][9] = cube[4][7];
	cube[4][1] = cube[5][3]; cube[4][4] = cube[5][2]; cube[4][7] = cube[5][1];
	cube[5][3] = cube[3][9]; cube[5][2] = cube[3][6]; cube[5][1] = cube[3][3];
	cube[3][9] = tran[1];    cube[3][6] = tran[2];    cube[3][3] = tran[3];
	ccr(1);
	cout << "Fi ";
}
void U() {
	for (int i = 1; i <= 3; i++)
	{
		char tran;
		tran = cube[1][i];
		cube[1][i] = cube[4][i];
		cube[4][i] = cube[2][i];
		cube[2][i] = cube[3][i];
		cube[3][i] = tran;
	}
	cr(6);
	cout << "U ";
}
void Ui() {
	for (int i = 1; i <= 3; i++)
	{
		char tran;
		tran = cube[1][i];
		cube[1][i] = cube[3][i];
		cube[3][i] = cube[2][i];
		cube[2][i] = cube[4][i];
		cube[4][i] = tran;
	}
	ccr(6);
	cout << "Ui ";
}


void color()   //调换颜色
{
	char tran[8]; tran[0] = '0'; tran[7] = '\0';
	for (int i = 1; i <= 6; i++)
	{
		tran[i] = cube[i][5];
	}
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 9; j++)
		{
			if (cube[i][j] == tran[1])
			{
				cube[i][j] = 'G'; continue;
			}
			if (cube[i][j] == tran[2])
			{
				cube[i][j] = 'B'; continue;
			}
			if (cube[i][j] == tran[3])
			{
				cube[i][j] = 'O';  continue;
			}
			if (cube[i][j] == tran[4])
			{
				cube[i][j] = 'R';  continue;
			}
			if (cube[i][j] == tran[5])
			{
				cube[i][j] = 'Y';  continue;
			}
			if (cube[i][j] == tran[6])
			{
				cube[i][j] = 'W';  continue;
			}


	}

}

void cross()
{//G
  while(!(cube[5][2] == 'Y'&&cube[1][8] == 'G')) 
 {  if (cube[1][2] == 'G'&&cube[6][8] == 'Y')
  {
	F();  F(); continue;
   }
   if (cube[1][2] == 'Y'&&cube[6][8] == 'G')
  {
	   U(); L(); Fi();  continue;
   }
   if (cube[5][2] == 'G'&&cube[1][8] == 'Y')
   {
	   F(); F(); continue;
   }
   if ((cube[5][6] == 'G'&&cube[4][8] == 'Y') || (cube[5][6] == 'Y'&&cube[4][8] == 'G'))
   {
	   R(); R(); continue;

   }
   if ((cube[5][8] == 'G'&&cube[2][8] == 'Y') || (cube[5][8] == 'Y'&&cube[2][8] == 'G'))
   {
	   B(); B(); continue;

   }
   if ((cube[5][4] == 'G'&&cube[3][8] == 'Y') || (cube[5][4] == 'Y'&&cube[3][8] == 'G'))
   {
	   L(); L(); continue;

   }


   if ((cube[1][6] == 'G'&&cube[4][4] == 'Y') || (cube[1][6] == 'Y'&&cube[4][4] == 'G'))
   {
	   R();  continue;

   }if ((cube[4][6] == 'G'&&cube[2][4] == 'Y') || (cube[4][6] == 'Y'&&cube[2][4] == 'G'))
   {
	   B();  continue;

   }if ((cube[2][6] == 'G'&&cube[3][4] == 'Y') || (cube[2][6] == 'Y'&&cube[3][4] == 'G'))
   {
	   Bi();  continue;

   }if ((cube[3][6] == 'G'&&cube[1][4] == 'Y') || (cube[3][6] == 'Y'&&cube[1][4] == 'G'))
   {
	   Li();  continue;

   }  
        U();
  }
  //R
  while (!(cube[5][6] == 'Y' && cube[4][8] == 'R'))
  {
	  if (cube[4][2] == 'R'&&cube[6][6] == 'Y')
	  {
		  R();  R(); continue;
	  }
	  if (cube[4][2] == 'Y'&&cube[6][6] == 'R')
	  {
		  Ui(); Bi(); R();  continue;
	  }
	  if ((cube[5][6] == 'R'&&cube[4][8] == 'Y') || (cube[5][6] == 'Y'&&cube[4][8] == 'R'))
	  {
		  R(); R(); continue;

	  }
	  if ((cube[5][8] == 'R'&&cube[2][8] == 'Y') || (cube[5][8] == 'Y'&&cube[2][8] == 'R'))
	  {
		  B(); B(); continue;

	  }
	  if ((cube[5][4] == 'R'&&cube[3][8] == 'Y') || (cube[5][4] == 'Y'&&cube[3][8] == 'R'))
	  {
		  L(); L(); continue;

	  }



	  if ((cube[1][6] == 'R'&&cube[4][4] == 'Y') || (cube[1][6] == 'Y'&&cube[4][4] == 'R'))
	  {
		  R();  continue;

	  }if ((cube[4][6] == 'R'&&cube[2][4] == 'Y') || (cube[4][6] == 'Y'&&cube[2][4] == 'R'))
	  {
		  B();  continue;

	  }if ((cube[2][6] == 'R'&&cube[3][4] == 'Y') || (cube[2][6] == 'Y'&&cube[3][4] == 'R'))
	  {
		  Bi();  continue;

	  }if ((cube[3][6] == 'R'&&cube[1][4] == 'Y') || (cube[3][6] == 'Y'&&cube[1][4] == 'R'))
	  {
		  Li();  continue;

	  }
	  U();
  }
  //B
  while (!(cube[5][8] == 'Y' && cube[2][8] == 'B'))
  {
	  if (cube[2][2] == 'B'&&cube[6][2] == 'Y')
	  {
		  B();  B(); continue;
	  }
	  if (cube[2][2] == 'Y'&&cube[6][2] == 'B')
	  {
		  Ui(); Li(); B();  continue;
	  }
	  if ((cube[5][8] == 'B'&&cube[2][8] == 'Y') || (cube[5][8] == 'Y'&&cube[2][8] == 'B'))
	  {
		  B(); B(); continue;

	  }
	  if ((cube[5][4] == 'B'&&cube[3][8] == 'Y') || (cube[5][4] == 'Y'&&cube[3][8] == 'B'))
	  {
		  L(); L(); continue;

	  }


	  if ((cube[1][6] == 'B'&&cube[4][4] == 'Y') || (cube[1][6] == 'Y'&&cube[4][4] == 'B'))
	  {
		  R(); Ui(); Ri();  continue;

	  }if ((cube[4][6] == 'B'&&cube[2][4] == 'Y') || (cube[4][6] == 'Y'&&cube[2][4] == 'B'))
	  {
		  B();  continue;

	  }if ((cube[2][6] == 'B'&&cube[3][4] == 'Y') || (cube[2][6] == 'Y'&&cube[3][4] == 'B'))
	  {
		  Bi();  continue;

	  }if ((cube[3][6] == 'B'&&cube[1][4] == 'Y') || (cube[3][6] == 'Y'&&cube[1][4] == 'B'))
	  {
		  Li();  continue;

	  }
	  U();
	

  }
  //O
  while (!(cube[5][4] == 'Y' && cube[3][8] == 'O'))
  {
	  if (cube[3][2] == 'O'&&cube[6][4] == 'Y')
	  {
		  L();  L(); continue;
	  }
	  if (cube[3][2] == 'Y'&&cube[6][4] == 'O')
	  {
		  Ui(); Fi(); L(); F(); continue;
	  }
	  if ((cube[5][4] == 'O'&&cube[3][8] == 'Y') || (cube[5][4] == 'Y'&&cube[3][8] == 'O'))
	  {
		  L(); L(); continue;

	  }


	  if ((cube[1][6] == 'O'&&cube[4][4] == 'Y') || (cube[1][6] == 'Y'&&cube[4][4] == 'O'))
	  {
		  R(); Ui(); Ui(); Ri();  continue;

	  }if ((cube[4][6] == 'O'&&cube[2][4] == 'Y') || (cube[4][6] == 'Y'&&cube[2][4] == 'O'))
	  {
		  B(); Ui(); Bi(); continue;

	  }if ((cube[2][6] == 'O'&&cube[3][4] == 'Y') || (cube[2][6] == 'Y'&&cube[3][4] == 'O'))
	  {
		  L(); continue;

	  }if ((cube[3][6] == 'O'&&cube[1][4] == 'Y') || (cube[3][6] == 'Y'&&cube[1][4] == 'O'))
	  {
		  Li();  continue;

	  }
	  U();

  }

}

void firstfloor()
{//GR
	while (!(cube[5][3]=='Y'&&cube[1][9] == 'G'&&cube[4][7] == 'R'))
	{  
		if ((cube[1][3] == 'G' || cube[1][3] == 'R' || cube[1][3] == 'Y') && (cube[6][9] == 'G' || cube[6][9] == 'R' || cube[6][9] == 'Y') && (cube[4][1] == 'G' || cube[4][1] == 'R' || cube[4][1] == 'Y'))
		{
			R(); U(); Ri(); Ui(); continue;
      	}
		
		
		if ((cube[1][9] == 'G' || cube[1][9] == 'R' || cube[1][9] == 'Y') && (cube[4][7] == 'G' || cube[4][7] == 'R' || cube[4][7] == 'Y') && (cube[5][3] == 'G' || cube[5][3] == 'R' || cube[5][3] == 'Y'))
		{
			R(); U(); Ri(); Ui(); continue;
		}
		if ((cube[4][9] == 'G' || cube[4][9] == 'R' || cube[4][9] == 'Y') && (cube[2][7] == 'G' || cube[2][7] == 'R' || cube[2][7] == 'Y') && (cube[5][9] == 'G' || cube[5][9] == 'R' || cube[5][9] == 'Y'))
		{
			B(); U(); Bi(); Ui();; continue;
		}
		if ((cube[2][9] == 'G' || cube[2][9] == 'R' || cube[2][9] == 'Y') && (cube[3][7] == 'G' || cube[3][7] == 'R' || cube[3][7] == 'Y') && (cube[5][7] == 'G' || cube[5][7] == 'R' || cube[5][7] == 'Y'))
		{
			L(); U(); Li(); Ui(); continue;
		}
		if ((cube[3][9] == 'G' || cube[3][9] == 'R' || cube[3][9] == 'Y') && (cube[1][7] == 'G' || cube[1][7] == 'R' || cube[1][7] == 'Y') && (cube[5][1] == 'G' || cube[5][1] == 'R' || cube[5][1] == 'Y'))
		{
			F(); U(); Fi(); Ui(); continue;
		}
		U();
     }
	//RB
	while (!(cube[5][9] == 'Y'&&cube[4][9] == 'R'&&cube[2][7] == 'B'))
	{
		if ((cube[4][3] == 'B' || cube[4][3] == 'R' || cube[4][3] == 'Y') && (cube[6][3] == 'B' || cube[6][3] == 'R' || cube[6][3] == 'Y') && (cube[2][1] == 'B' || cube[2][1] == 'R' || cube[2][1] == 'Y'))
		{
			B(); U(); Bi(); Ui(); continue;
		}


		if ((cube[1][9] == 'B' || cube[1][9] == 'R' || cube[1][9] == 'Y') && (cube[4][7] == 'B' || cube[4][7] == 'R' || cube[4][7] == 'Y') && (cube[5][3] == 'B' || cube[5][3] == 'R' || cube[5][3] == 'Y'))
		{
			R(); U(); Ri(); Ui(); continue;
		}
		if ((cube[4][9] == 'B' || cube[4][9] == 'R' || cube[4][9] == 'Y') && (cube[2][7] == 'B' || cube[2][7] == 'R' || cube[2][7] == 'Y') && (cube[5][9] == 'B' || cube[5][9] == 'R' || cube[5][9] == 'Y'))
		{
			B(); U(); Bi(); Ui();; continue;
		}
		if ((cube[2][9] == 'B' || cube[2][9] == 'R' || cube[2][9] == 'Y') && (cube[3][7] == 'B' || cube[3][7] == 'R' || cube[3][7] == 'Y') && (cube[5][7] == 'B' || cube[5][7] == 'R' || cube[5][7] == 'Y'))
		{
			L(); U(); Li(); Ui(); continue;
		}
		if ((cube[3][9] == 'B' || cube[3][9] == 'R' || cube[3][9] == 'Y') && (cube[1][7] == 'B' || cube[1][7] == 'R' || cube[1][7] == 'Y') && (cube[5][1] == 'B' || cube[5][1] == 'R' || cube[5][1] == 'Y'))
		{
			F(); U(); Fi(); Ui(); continue;
		}
		U();

	}//BO
	while (!(cube[5][7] == 'Y'&&cube[2][9] == 'B'&&cube[3][7] == 'O'))
	{
		if ((cube[2][3] == 'O' || cube[2][3] == 'B' || cube[2][3] == 'Y') && (cube[6][1] == 'O' || cube[6][1] == 'B' || cube[6][1] == 'Y') && (cube[3][1] == 'O' || cube[3][1] == 'B' || cube[3][1] == 'Y'))
		{
			L(); U(); Li(); Ui(); continue;
		}


		if ((cube[1][9] == 'B' || cube[1][9] == 'O' || cube[1][9] == 'Y') && (cube[4][7] == 'B' || cube[4][7] == 'O' || cube[4][7] == 'Y') && (cube[5][3] == 'B' || cube[5][3] == 'O' || cube[5][3] == 'Y'))
		{
			R(); U(); Ri(); Ui(); continue;
		}
		if ((cube[4][9] == 'B' || cube[4][9] == 'O' || cube[4][9] == 'Y') && (cube[2][7] == 'B' || cube[2][7] == 'O' || cube[2][7] == 'Y') && (cube[5][9] == 'B' || cube[5][9] == 'O' || cube[5][9] == 'Y'))
		{
			B(); U(); Bi(); Ui();; continue;
		}
		if ((cube[2][9] == 'B' || cube[2][9] == 'O' || cube[2][9] == 'Y') && (cube[3][7] == 'B' || cube[3][7] == 'O' || cube[3][7] == 'Y') && (cube[5][7] == 'B' || cube[5][7] == 'O' || cube[5][7] == 'Y'))
		{
			L(); U(); Li(); Ui(); continue;
		}
		if ((cube[3][9] == 'B' || cube[3][9] == 'O' || cube[3][9] == 'Y') && (cube[1][7] == 'B' || cube[1][7] == 'O' || cube[1][7] == 'Y') && (cube[5][1] == 'B' || cube[5][1] == 'O' || cube[5][1] == 'Y'))
		{
			F(); U(); Fi(); Ui(); continue;
		}
		U();
	}
	//OG
	while (!(cube[5][1] == 'Y'&&cube[3][9] == 'O'&&cube[1][7] == 'G'))
	{
		if ((cube[3][3] == 'G' || cube[3][3] == 'O' || cube[3][3] == 'Y') && (cube[6][7] == 'G' || cube[6][7] == 'O' || cube[6][7] == 'Y') && (cube[1][1] == 'G' || cube[1][1] == 'O' || cube[1][1] == 'Y'))
		{
			F(); U(); Fi(); Ui(); continue;
		}


		if ((cube[1][9] == 'G' || cube[1][9] == 'O' || cube[1][9] == 'Y') && (cube[4][7] == 'G' || cube[4][7] == 'O' || cube[4][7] == 'Y') && (cube[5][3] == 'G' || cube[5][3] == 'O' || cube[5][3] == 'Y'))
		{
			R(); U(); Ri(); Ui(); continue;
		}
		if ((cube[4][9] == 'G' || cube[4][9] == 'O' || cube[4][9] == 'Y') && (cube[2][7] == 'G' || cube[2][7] == 'O' || cube[2][7] == 'Y') && (cube[5][9] == 'G' || cube[5][9] == 'O' || cube[5][9] == 'Y'))
		{
			B(); U(); Bi(); Ui();; continue;
		}
		if ((cube[2][9] == 'G' || cube[2][9] == 'O' || cube[2][9] == 'Y') && (cube[3][7] == 'G' || cube[3][7] == 'O' || cube[3][7] == 'Y') && (cube[5][7] == 'G' || cube[5][7] == 'O' || cube[5][7] == 'Y'))
		{
			L(); U(); Li(); Ui(); continue;
		}
		if ((cube[3][9] == 'G' || cube[3][9] == 'O' || cube[3][9] == 'Y') && (cube[1][7] == 'G' || cube[1][7] == 'O' || cube[1][7] == 'Y') && (cube[5][1] == 'G' || cube[5][1] == 'O' || cube[5][1] == 'Y'))
		{
			F(); U(); Fi(); Ui(); continue;
		}
		U();
	}

}

void secondfloor()
{//GR
	while (!(cube[1][6] == 'G'&&cube[4][4] == 'R'))
	{
		if (cube[1][2] == 'G'&&cube[6][8] == 'R')
		{
			U(); R(); Ui(); Ri(); Ui(); Fi(); U(); F();
			continue;
	     }

		if (cube[4][2] == 'R'&&cube[6][6] == 'G')
		{
			Ui(); Fi(); U(); F(); U(); R(); Ui(); Ri();
			continue;
		}



		if (cube[1][6] == 'R'&&cube[4][4] == 'G')
		{
			Ui(); Fi(); U(); F(); U(); R(); Ui(); Ri();
			continue;

		}
		if ((cube[4][6] == 'G'&&cube[2][4] == 'R') || (cube[4][6] == 'R'&&cube[2][4] == 'G'))
		{
			U(); B(); Ui(); Bi(); Ui(); Ri(); U(); R();
			continue;
		}
		if ((cube[2][6] == 'G'&&cube[3][4] == 'R') || (cube[2][6] == 'R'&&cube[3][4] == 'G'))
		{
			U(); L(); Ui(); Li(); Ui(); Bi(); U(); B();
			continue;
		}
		if ((cube[3][6] == 'G'&&cube[1][4] == 'R') || (cube[3][6] == 'R'&&cube[1][4] == 'G'))
		{
			U(); F(); Ui(); Fi(); Ui(); Li(); U(); L();
			continue;
		}
		U();
	}

//RB
	while (!(cube[4][6] == 'R'&&cube[2][4] == 'B'))
	{
		if (cube[4][2] == 'R'&&cube[6][6] == 'B')
		{
			U(); B(); Ui(); Bi(); Ui(); Ri(); U(); R();
			continue;
		}

		if (cube[2][2] == 'B'&&cube[6][2] == 'R')
		{
			Ui(); Ri(); U(); R(); U(); B(); Ui(); Bi();
			continue;
		}


		if (cube[4][6] == 'B'&&cube[2][4] == 'R')
		{
			U(); B(); Ui(); Bi(); Ui(); Ri(); U(); R();
			continue;
		}
		if ((cube[2][6] == 'B'&&cube[3][4] == 'R') || (cube[2][6] == 'R'&&cube[3][4] == 'B'))
		{
			U(); L(); Ui(); Li(); Ui(); Bi(); U(); B();
			continue;
		}
		if ((cube[3][6] == 'B'&&cube[1][4] == 'R') || (cube[3][6] == 'R'&&cube[1][4] == 'B'))
		{
			U(); F(); Ui(); Fi(); Ui(); Li(); U(); L();
			continue;
		}
		U();

	}

//BO
	while (!(cube[2][6] == 'B'&&cube[3][4] == 'O'))
	{
		if (cube[2][2] == 'B'&&cube[6][2] == 'O')
		{
			U(); L(); Ui(); Li(); Ui(); Bi(); U(); B();
			continue;
		}
		if (cube[3][2] == 'O'&&cube[6][4] == 'B')
		{
			Ui(); Bi(); U(); B(); U(); L(); Ui(); Li();
			continue;
		}


		if (cube[2][6] == 'O'&&cube[3][4] == 'B')
		{
			U(); L(); Ui(); Li(); Ui(); Bi(); U(); B();
			continue;
		}
		if ((cube[3][6] == 'B'&&cube[1][4] == 'O') || (cube[3][6] == 'B'&&cube[1][4] == 'O'))
		{
			U(); F(); Ui(); Fi(); Ui(); Li(); U(); L();
			continue;
		}
		U();

	}
//OG
	while (!(cube[3][6] == 'O'&&cube[1][4] == 'G'))
	{
		if (cube[3][2] == 'O'&&cube[6][4] == 'G')
		{
			U(); F(); Ui(); Fi(); Ui(); Li(); U(); L();
			continue;
		}

		if (cube[1][2] == 'G'&&cube[6][8] == 'O')
		{
			Ui(); Li(); U(); L(); U(); F(); Ui(); Fi();
			continue;
		}

			if (cube[3][6] == 'G'&&cube[1][4] == 'O')
		{
			U(); F(); Ui(); Fi(); Ui(); Li(); U(); L();
			continue;
		}
		U();


	}


}

void top1()
{//顶部十字
	while (!(cube[6][2] == 'W'&&cube[6][6] == 'W'&&cube[6][8] == 'W'&&cube[6][4] == 'W'))
	{
		if ((cube[6][6] == 'W'&&cube[6][4] == 'W') || (cube[6][2] == 'W'&&cube[6][8] == 'W'))
		{
			while (!(cube[6][6] == 'W'&&cube[6][4] == 'W'&&cube[1][2]=='W'))
			{
				U();
			}
			F(); R(); U(); Ri(); Ui(); Fi(); continue;
		}

		if ((cube[6][2] == 'W'&&cube[6][6] == 'W') || (cube[6][6] == 'W'&&cube[6][8] == 'W') || (cube[6][8] == 'W'&&cube[6][4] == 'W') || (cube[6][2] == 'W'&&cube[6][4] == 'W'))
		{
			while (!(cube[6][2] == 'W'&&cube[6][4] == 'W'))
			{
				U();
			}

		}

		F(); R(); U(); Ri(); Ui(); Fi();
	}


	//顶层
	while (!(cube[6][1] == 'W'&&cube[6][2] == 'W'&&cube[6][3] == 'W'&&cube[6][4] == 'W'&&cube[6][5] == 'W'&&cube[6][6] == 'W'&&cube[6][7] == 'W'&&cube[6][8] == 'W'&&cube[6][9] == 'W'))
	{
		int sum = 0;
		for (int i = 1; i <= 9; i++)
			if (cube[6][i] == 'W')
				sum++;

		if (sum == 6) 
		{
			while (cube[6][1] != 'W')
			{
				U();
			}
			if (cube[1][1] == 'W')
			{
				Ri(); Ui(); R(); Ui(); Ri(); Ui(); Ui(); R(); continue;
			}
			else {
				F(); U(); Fi(); U(); F(); U(); U(); Fi(); continue;
			}
		
		}
		if (sum == 7)
	    {while(cube[2][3]!='W')   { U(); }
		Ri(); Ui(); R(); Ui(); Ri(); Ui(); Ui(); R(); continue;
		}
		if (sum == 5)
		{while (cube[3][1] != 'W') { U(); }
			Ri(); Ui(); R(); Ui(); Ri(); Ui(); Ui(); R(); continue;
		}
}


}
void top2() {//调整顶层角块顺序

		while(!(cube[1][1] == cube[1][3] && cube[4][1] == cube[4][3] && cube[2][1]==cube[2][3]&&cube[3][1]==cube[3][3]))
		{
			if (cube[1][1] == cube[1][3] || cube[4][1] == cube[4][3] || cube[2][1] == cube[2][3] || cube[3][1] == cube[3][3])
			{ while(cube[4][1]!=cube[4][3])
			    {U(); }
			R(); R(); F(); F(); Ri(); Bi(); R(); F(); F(); Ri(); B(); Ri(); continue;
     		}

			R(); R(); F(); F(); Ri(); Bi(); R(); F(); F(); Ri(); B(); Ri(); continue;
	
     	}


	//调整顶层棱色块顺序
		while (!(cube[1][1] == cube[1][3] && cube[4][1] == cube[4][3] && cube[2][1] == cube[2][3] && cube[3][1] == cube[3][3] && cube[1][2] == cube[1][3] && cube[4][2] == cube[4][3] && cube[2][2] == cube[2][3] && cube[3][2] == cube[3][3] && cube[1][1] == cube[1][2] && cube[4][1] == cube[4][2] && cube[2][1] == cube[2][2] && cube[3][1] == cube[3][2]))
		{
			if ((cube[1][1] == cube[1][3] && cube[1][1] == cube[1][2] && cube[1][2] == cube[1][3]) || (cube[1][1] == cube[1][3] && cube[1][1] == cube[1][2] && cube[1][2] == cube[1][3]) || (cube[2][1] == cube[2][3] && cube[2][1] == cube[2][2] && cube[2][2] == cube[2][3]) || (cube[3][1] == cube[3][3] && cube[3][1] == cube[3][2] && cube[3][2] == cube[3][3]) || (cube[4][1] == cube[4][3] && cube[4][1] == cube[4][2] && cube[4][2] == cube[4][3]))
			{
				while (!(cube[1][1] == cube[1][3] && cube[1][1] == cube[1][2] && cube[1][2] == cube[1][3]))
				{ U();}
				Ri(); Ui(); R(); Ui(); Ri(); Ui(); Ui(); R(); U(); U(); F(); U(); Fi(); U(); F(); U(); U(); Fi(); U(); U(); continue;
			}

			Ri(); Ui(); R(); Ui(); Ri(); Ui(); Ui(); R(); U(); U(); F(); U(); Fi(); U(); F(); U(); U(); Fi(); U(); U(); continue;
		}
		while(cube[1][1]!='G')
		{U(); }

}


void Try()
{
	color();
	cross();
	firstfloor();
	secondfloor();
	top1();
	top2();
}

int main()
{  //输入
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 9; j++)
			cin >> cube[i][j];
    
	for (int j = 1; j <= 9; j++)
		cin >> cube[6][j];
	for (int j = 1; j <= 9; j++)
		cin >> cube[5][j];
	Try();


	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
