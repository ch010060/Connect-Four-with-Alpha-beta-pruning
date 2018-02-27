#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include "PngTexture.h"

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>    
#include <cstring>    

#define N 8
using namespace std;
int Nowi=0,Nowj=0;

int data[N][N];
int logo,chess1,chess2,begingame,begingame1,begingame2;
int end0,end1,end2;
int num[10],state[5],mul;
int change=0;int winner;
bool endd=0,round=0;
void draw(int x, int y, int width, int height, int image);
void setMap() //設定棋盤
{
	 for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
           data[i][j]=0;
}

bool gameEnd()  //判定是否遊戲結束
	{
		int count=0;

		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(data[i][j]!=0)
					count++;

		else if(count==64)
		{
			cout<<"NO ONE WIN!!\n";
			return true;
		}
		else
			return false;	
	}

bool win()    //確認玩家是否勝利
{
	int win1=0,win2=0,by5_win1=0,by5_win2=0;
	for(int i=0;i<N;i++)
    {
		for (int j=0;j<=3;j++)
		{
			for(int col_check=j;col_check<(j+5);col_check++)
			{
				if(data[i][col_check]==2)
					by5_win1++;
				if(data[i][col_check]==1)
					by5_win2++;
			}
			if(by5_win1==5||by5_win2==5)
				break;
			by5_win1=0;
		    by5_win2=0;
	    }
	    if(by5_win1==5||by5_win2==5)
		break;
		by5_win1=0;
		by5_win2=0;
	}
		

	for(int i=0;i<N;i++)
    {
		for (int j=0;j<=4;j++)
		{
			for(int col_check=j;col_check<(j+4);col_check++)
			{
				if(data[i][col_check]==1)
					win1++;
				if(data[i][col_check]==2)
					win2++;
			}
			if(win1==4||win2==4)
				break;
			win1=0;
		    win2=0;
	    }
	    if(win1==4||win2==4)
		break;
		win1=0;
		win2=0;
	}

	if((win1==4&&by5_win2!=5)||by5_win1==5)
    {
		cout<<"Player1 Win!\n";
		endd=1;winner=1;
		return true;
	}
    else if((win2==4&&by5_win1!=5)||by5_win2==5)
    {
		cout<<"Player2 Win!\n";
		endd=1;winner=2;
		return true;
	}
	else
		return false;

}

bool win2()  //確認玩家是否勝利
{
	int win1=0,win2=0;

	 for(int j=0;j<N;j++)
    {
		for (int i=0;i<=4;i++)
		{
			for(int row_check=i;row_check<(i+4);row_check++)
			{
				if(data[row_check][j]==1)
					win1++;
			    if(data[row_check][j]==2)
					win2++;
			}
			if(win1==4||win2==4)
				break;
			win1=0;
		    win2=0;
	    }
	    if(win1==4||win2==4)
		break;
		win1=0;
		win2=0;
	}

	if(win1==4)
    {
		endd=1;winner=1;
		cout<<"Player1 Win!\n";
		return true;
	}
    else if(win2==4)
    {
		endd=1;winner=2;
		cout<<"Player2 Win!\n";
		return true;
	}
	else
		return false;

}

bool win3()  //確認有玩家是否勝利
{
	int win1=0,win2=0,by5_win1=0,by5_win2=0;

	for(int i=N-1;i>3;i--)
    {
		for (int j=0;j<=3;j++)
		{
			for(int row_check=i,col_check=j;(row_check>(i-5))&&(col_check<(j+5));row_check--,col_check++)
			{
				if(data[row_check][col_check]==2)
					by5_win1++;
				if(data[row_check][col_check]==1)
					by5_win2++;
			}
			if(by5_win1==5||by5_win2==5)
				break;
			by5_win1=0;
		    by5_win2=0;
	    }
	    if(by5_win1==5||by5_win2==5)
		break;
		by5_win1=0;
		by5_win2=0;
	}



	for(int i=N-1;i>2;i--)
    {
		for (int j=0;j<=4;j++)
		{
			for(int row_check=i,col_check=j;(row_check>(i-4))&&(col_check<(j+4));row_check--,col_check++)
			{
				if(data[row_check][col_check]==1)
					win1++;
				if(data[row_check][col_check]==2)
					win2++;
			}
			if(win1==4||win2==4)
				break;
			win1=0;
		    win2=0;
	    }
	    if(win1==4||win2==4)
		break;
		win1=0;
		win2=0;
	}


	if((win1==4&&by5_win2!=5)||by5_win1==5)
    {
		endd=1;winner=1;
		cout<<"Player1 Win!\n";
		return true;
	}
    else if((win2==4&&by5_win1!=5)||by5_win2==5)
    {
		endd=1;winner=2;
		cout<<"Player2 Win!\n";
		return true;
	}
	else
		return false;
}

bool win4()   //確認玩家是否勝利
{
	int win1=0,win2=0,by5_win1=0,by5_win2=0;

	for(int i=0;i<=3;i++)
    {
		for (int j=0;j<=3;j++)
		{
			for(int row_check=i,col_check=j;(row_check<(i+5))&&(col_check<(j+5));row_check++,col_check++)
			{
				if(data[row_check][col_check]==2)
					by5_win1++;
				if(data[row_check][col_check]==1)
					by5_win2++;
				 
			}
			if(by5_win1==5||by5_win2==5)
				break;
			by5_win1=0;
		    by5_win2=0;
	    }
	    if(by5_win1==5||by5_win2==5)
		break;
		by5_win1=0;
		by5_win2=0;
	}



	for(int i=0;i<=4;i++)
    {
		for (int j=0;j<=4;j++)
		{
			for(int row_check=i,col_check=j;(row_check<(i+4))&&(col_check<(j+4));row_check++,col_check++)
			{
				if(data[row_check][col_check]==1)
					win1++;
				if(data[row_check][col_check]==2)
					win2++;
				 
			}
			if(win1==4||win2==4)
				break;
			win1=0;
		    win2=0;
	    }
	    if(win1==4||win2==4)
		break;
		win1=0;
		win2=0;
	}


	if((win1==4&&by5_win2!=5)||by5_win1==5)
    {
		endd=1;winner=1;
		cout<<"Player1 Win!\n";
		return true;
	}
    else if((win2==4&&by5_win1!=5)||by5_win2==5)
    {
		endd=1;winner=2;
		cout<<"Player2 Win!\n";
		return true;
	}
	else
		return false;
}

void showMap()   //印出棋盤
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{	
				if(data[i][j]==1)
					cout<<"O"<<" ";
				else if(data[i][j]==2)
					cout<<"X"<<" ";
				else if(data[i][j]==0)
					cout<<"-"<<" ";

			}
			cout<<endl;
		}

		for(int j=0;j<N;j++)
			{	
				cout<<j+1<<' ';
			}

		cout<<endl;
	}
    
void put(int player,int chose)    //下棋
	{
		int row=N-1,col;

		col=chose;

		switch(col)
		{
		case 1:
			while(data[row][0]!=0)
			{
				if(row<0)
				{
					cin>>chose;
					put(player,chose);
					break;
				}
				row--;
			}
			data[row][0]=player;
			break;
		case 2:
			while(data[row][1]!=0)
			{
				if(row<0)
				{
					cin>>chose;
					put(player,chose);
					break;
				}
				row--;
			}
			data[row][1]=player;
			break;
		case 3:
			while(data[row][2]!=0)
			{
				if(row<0)
				{
					cin>>chose;
					put(player,chose);
					break;
				}
				row--;
			}
			data[row][2]=player;
			break;
		case 4:
			while(data[row][3]!=0)
			{
				if(row<0)
				{
					cin>>chose;
					put(player,chose);
					break;
				}
				row--;
			}
			data[row][3]=player;
			break;
		case 5:
			while(data[row][4]!=0)
			{
				if(row<0)
				{
					cin>>chose;
					put(player,chose);
					break;
				}
				row--;
			}
			data[row][4]=player;
			break;
		case 6:
			while(data[row][5]!=0)
			{
				if(row<0)
				{
					cin>>chose;
					put(player,chose);
					break;
				}
				row--;
			}
			data[row][5]=player;
			break;
        case 7:
			while(data[row][6]!=0)
			{
				if(row<0)
				{
					cin>>chose;
					put(player,chose);
					break;
				}
				row--;
			}
			data[row][6]=player;
			break;
		case 8:
			while(data[row][7]!=0)
			{
				if(row<0)
				{
					cin>>chose;
					put(player,chose);
					break;
				}
				row--;
			}
			data[row][7]=player;
			break;

			//default:
			  
		}
		
	}

bool canMove(int j)    //判斷是否可以下此步
{
	if(data[0][j]==0)
		return true;
	else
		return false;
}
void playerMove(int j,int player)   //試下這步
{
	for(int i=N-1;i>=0;i--)
	{
	   if(data[i][j]==0)
		{
			data[i][j]=player;
			Nowi=i;
			Nowj=j;
			break;
		}
	}
}
void playerUnmove(int j,int player)   //還原這步
{
	for(int i=0;i<N;i++)
	{
		if(data[i][j]!=0)
		{
			data[i][j]=0;
			break;
		}
	}
}

//winCheck()~winCheck4()試用來判定雙方輸贏的function並回傳值(用在alpha-beta)

int winCheck()
{
	int score=0,score5=0,win1=0,win2=0,ck_5win1=0,ck_5win2=0;

	      
	      for(int j=0;j<=3;j++)
		  {
			for(int col_check=j;col_check<(j+5);col_check++)
			{

				if(data[Nowi][col_check]==1)
					ck_5win1++;
				if(data[Nowi][col_check]==2)
					ck_5win2++;
				if(ck_5win1==5)
                {	
	               score5=score5+2000;
	            }
				if(ck_5win2==5)
                {	
	               score5=score5-2000;
	            }

			}
			ck_5win1=0;
			ck_5win2=0;
		  }
  
	  if(score5!=0)
		 return score5;


	      for(int j=0;j<=4;j++)
		  {
			for(int col_check=j;col_check<(j+4);col_check++)
			{
				if(data[Nowi][col_check]==1)
					win1++;
				if(data[Nowi][col_check]==2)
					win2++;
				if(win1==4)
                {	
	              score=score-1000;
	            }
				if(win2==4)
                {	
	              score=score+900;
	            }

			}
			win1=0;
			win2=0;
		  }


	if(score>900)
		score=-1000;
	return score;

}

int winCheck2()
{
	int score=0,score5=0,win1=0,win2=0,ck_5win1=0,ck_5win2=0;


	for(int i=0;i<=3;i++)
	{

      for(int row_check=i;row_check<(i+5);row_check++)
	    {

				if(data[row_check][Nowj]==1)
					ck_5win1++;
			    if(data[row_check][Nowj]==2)
					ck_5win2++;
				if(ck_5win1==5)
                {	
	             score5=score5+2000;
	            }
				if(ck_5win2==5)
                {	
	             score5=score5-2000;
				}

	    }

	  ck_5win1=0;
	  ck_5win2=0;
	    
	}

	if(score5!=0)
		return score5;
	
	for(int i=0;i<=4;i++)
	{

      for(int row_check=i;row_check<(i+4);row_check++)
	    {

				if(data[row_check][Nowj]==1)
					win1++;
			    if(data[row_check][Nowj]==2)
					win2++;
				if(win1==4)
                {	
	              score=score-1000;
	            }
				if(win2==4)
                {	
	              score=score+900;
				}

	  }

	  win1=0;
	  win2=0;
	    
	}


	if(score>900)
		score=-1000;
    return score;

}

int winCheck3()
{
	int score=0,score5=0,win1=0,win2=0,ck_5win1=0,ck_5win2=0;


	for(int i=0;i<=3;i++)
	{
	  for(int j=0;j<=3;j++)
	  {
	   for(int col_check=j,row_check=i;(col_check<(j+5))&&(row_check<(i+5));col_check++,row_check++)
		 {
			if(data[row_check][col_check]==1)
					ck_5win1++;
			if(data[row_check][col_check]==2)
					ck_5win2++;
			if(ck_5win1==5)
              {	
	            score5=score5+2000;
	          }
		    if(ck_5win2==5)
              {	
	            score5=score5-2000;
	          }

	   }

	   ck_5win1=0;
	   ck_5win2=0;
      }
	   
	  ck_5win1=0;
	  ck_5win2=0;
	}

	if(score5!=0)
		return score5;

	
	for(int i=0;i<=4;i++)
	{
	  for(int j=0;j<=4;j++)
	  {
	   for(int col_check=j,row_check=i;(col_check<(j+4))&&(row_check<(i+4));col_check++,row_check++)
		 {
			if(data[row_check][col_check]==1)
					win1++;
			if(data[row_check][col_check]==2)
					win2++;
			if(win1==4)
              {	
	             score=score-1000;
	          }
		    if(win2==4)
              {	
	             score=score+900;
	          }

		}

	   win1=0;
	   win2=0;
      }
	   
	  win1=0;
	  win2=0;
	}


	if(score>900)
		score=-1000;

	return score;

}

int winCheck4()
{
	int score=0,score5=0,win1=0,win2=0,ck_5win1=0,ck_5win2=0;



	for(int i=N-1;i>=4;i--)
	{

		for(int j=0;j<=3;j++)
		{
    	   for(int col_check=j,row_check=i;(col_check<(j+5))&&(row_check>(i-5));col_check++,row_check--)
	       {
			   if(data[row_check][col_check]==1)
					ck_5win1++;
			   if(data[row_check][col_check]==2)
					ck_5win2++;
			   if(win1==5)
			   {	
	             score5=score5+2000;
	           }
			   if(win2==5)
               {	
	             score5=score5-2000;
	           }

		   }
		   
		   ck_5win1=0;
		   ck_5win2=0;

		}
      ck_5win1=0;
	  ck_5win2=0;
   
	}

	if(score5!=0)
		return score5;
	

	for(int i=N-1;i>=3;i--)
	{

		for(int j=0;j<=4;j++)
		{
    	   for(int col_check=j,row_check=i;(col_check<(j+4))&&(row_check>(i-4));col_check++,row_check--)
	       {
			   if(data[row_check][col_check]==1)
					win1++;
			   if(data[row_check][col_check]==2)
					win2++;
			   if(win1==4)
			   {	
	             score=score-1000;
	           }
			   if(win2==4)
               {	
	             score=score+900;
	           }

	        }
		   
		   win1=0;
		   win2=0;

		}
      win1=0;
	  win2=0;
   
	}


	if(score>900)
		score=-1000;

	return score;

}

int heuristic()   //評估函數
{
	int score=0;

	for(int i=0;i<N;i++)              //讓電腦盡量往中間下
    {
      int rowscore=(N/2)-i;
	  if(rowscore>0) 
      rowscore+=1;
      if(rowscore<0) 
      rowscore=(-rowscore);
      rowscore=(N/2)-rowscore;

      for(int j=0;j<N;j++)
      {
         int colscore=(N/2)-j;
		   if(colscore>0)
			  colscore+=1;
           if(colscore<0) 
              colscore=(-colscore);
           colscore=(N/2)-colscore;
           if(data[i][j]==1)
               score -=(rowscore+colscore);
           else if(data[i][j]==2)
               score +=(rowscore+colscore);
      }
	}
	

	//下面程式碼是檢查雙方是否有多排雙三的情形，己方越多越會下此，敵方越多會去阻擋防止敵方太多排三子的情況

	int win1=0,win2=0;
	
	for(int row_check=Nowi,col_check=Nowj;col_check<(Nowj+3);col_check++)
	{
		 if(col_check<0||col_check>7)
			 continue;

	     if(data[row_check][col_check]==1)
					win1++;
		 if(data[row_check][col_check]==2)
					win2++;
		 if(win1==3)
         {	
	            score=score-50;
	     }
		 if(win2==3)
         {	
	            score=score+35;
	     }
	}
   
    win1=0;
	win2=0;

	for(int row_check=Nowi,col_check=Nowj;col_check>(Nowj-3);col_check--)
	{
		 if(col_check<0||col_check>7)
			 continue;

	     if(data[row_check][col_check]==1)
					win1++;
		 if(data[row_check][col_check]==2)
					win2++;
		 if(win1==3)
         {	
	            score=score-50;
	     }
		 if(win2==3)
         {	
	            score=score+35;
	     }
	}
		
    win1=0;
	win2=0;

	for(int row_check=Nowi,col_check=Nowj;row_check<(Nowi+3);row_check++)
	{
		 if(row_check<0||row_check>7)
			 continue;

	     if(data[row_check][col_check]==1)
					win1++;
		 if(data[row_check][col_check]==2)
					win2++;
		 if(win1==3)
         {	
	           score=score-45;
	     }
		 if(win2==3)
         {	
	           score=score+35;
	     }
	}

	win1=0;
	win2=0;

	for(int row_check=Nowi,col_check=Nowj;row_check>(Nowi-3);row_check--)
	{
		 if(row_check<0||row_check>7)
			 continue;

	     if(data[row_check][col_check]==1)
					win1++;
		 if(data[row_check][col_check]==2)
					win2++;
		 if(win1==3)
         {	
	            score=score-45;
	     }
		 if(win2==3)
         {	
	            score=score+35;
	     }
	}

	win1=0;
	win2=0;


	for(int row_check=Nowi,col_check=Nowj;row_check<(Nowi+3),col_check<(Nowj+3);col_check++,row_check++)
	{
		 if(row_check<0||row_check>7||col_check<0||col_check>7)
			 continue;

	     if(data[row_check][col_check]==1)
					win1++;
		 if(data[row_check][col_check]==2)
					win2++;
		 if(win1==3)
         {	
	            score=score-50;
	     }
		 if(win2==3)
         {	
	            score=score+35;
	     }
	}


	win1=0;
	win2=0;

	for(int row_check=Nowi,col_check=Nowj;row_check>(Nowi-3),col_check>(Nowj-3);col_check--,row_check--)
	{
		 if(row_check<0||row_check>7||col_check<0||col_check>7)
			 continue;

	     if(data[row_check][col_check]==1)
					win1++;
		 if(data[row_check][col_check]==2)
					win2++;
		 if(win1==3)
         {	
	            score=score-50;
	     }
		 if(win2==3)
         {	
	            score=score+35;
	     }
	}



	win1=0;
	win2=0;

	for(int row_check=Nowi,col_check=Nowj;row_check<(Nowi+3),col_check>(Nowj-3);col_check--,row_check++)
	{
		 if(row_check<0||row_check>7||col_check<0||col_check>7)
			 continue;

	     if(data[row_check][col_check]==1)
					win1++;
		 if(data[row_check][col_check]==2)
					win2++;
		 if(win1==3)
         {	
	            score=score-50;
	     }
		 if(win2==3)
         {	
	            score=score+35;
	     }
	}


	win1=0;
	win2=0;

	for(int row_check=Nowi,col_check=Nowj;row_check>(Nowi-3),col_check<(Nowj+3);col_check++,row_check--)
	{
		 if(row_check<0||row_check>7||col_check<0||col_check>7)
			 continue;

	     if(data[row_check][col_check]==1)
					win1++;
		 if(data[row_check][col_check]==2)
					win2++;
		 if(win1==3)
         {	
	           score=score-50;
	     }
		 if(win2==3)
         {	
	           score=score+35;
	     }
	}
		
	return score;

}

int alphabeta(int depth,int alpha,int beta,int player)  //alpha-beta
{
	
	 int a=0,b=0,c=0,d=0; 
	 
		  if(a=winCheck())               //判斷是否有人會贏，有就會在此回傳，己方勝900，敵方勝-1000
		   return a;
		  if(b=winCheck2())
		   return b;
		  if(c=winCheck3())
		   return c;
		  if(d=winCheck4())
		   return d;


	  if(depth==0)
	  {
		  return heuristic();
	  }

	
	if(player==2)
	{
		for(int move=0;move<8;move++)
		 if(canMove(move))
		 {
			 playerMove(move,2);
			 int score=alphabeta(depth-1,alpha,beta,player-1);
			 playerUnmove(move,2);
			 if(score>alpha)
				 alpha=score;
			 if(alpha>=beta)
				 break;
		 }
		 return alpha;
	}
    else if(player==1)
	{
		for(int move=0;move<8;move++)
		 if(canMove(move))
		 {
			 playerMove(move,1);
			 int score=alphabeta(depth-1,alpha,beta,player+1);
			 playerUnmove(move,1);
			 if(score<beta)
				 beta=score;
			 if(alpha>=beta)
				 break;
		 }
		 return beta;
	}
	else
		return 0;
}

int determineMove(int player)  //決定該走哪步
{
	int maxScore=-10000;
	int maxValuetomove=0;

	for(int move=0;move<8;move++)
	{
		if(canMove(move))    //判斷可否下此步
		{
			playerMove(move,player);      //試下這步
			int score=alphabeta(5,-10000,10000,1);    //利用alpha-beta求這步的分數
			cout<<"Score= "<<score<<"\n";
			if(score>=maxScore)           //利用分數判定是否取代前一個想下的步
			{
				maxScore=score;
				maxValuetomove=move;
			}
			playerUnmove(move,player);    //還原這步
		}
	}
	return maxValuetomove;            //回傳決定的步
}

int fos=0;bool fall=0;//first or second
int nowscene[8]={0,0,0,0,0,0,0,0};
int nowdec1=3,now1=2;
int nowdec2=3,now2=2;
void game()  //遊戲系統
{

	//	if(fos==1)  //玩家1先下(人先下)
		{
		  int pchose=0;
		  showMap();
			  clock_t start,stop;    //用來計算時間的變數
			  showMap();
			  if(win());     //勝利判斷開始
			  if(win3());
			  if(win4()) ;  			 
			  if(win2());    //勝利判斷結束
			  if(!endd){
			  cout<<"player2 put:\n";
			  start = clock(); 
			  int b=determineMove(2);    //電腦決定下棋位置
			  stop = clock(); 
			  cout <<"運算時間:"<< double(stop - start) / CLOCKS_PER_SEC <<endl;   //印出計算時間
			  cout<<"Computer Choose: "<<b+1<<endl;   //印出決定位置
			 
			  for(int i=7;i>-1;i--){
					if(data[i][b]==0){
						i=7-i;
						now2-=1;
						if(now2<0){
							nowdec2-=1;
							now2=9;
						}
						switch (b)
						{
							case 0:
								draw(0,50*i,50,50,chess2);
								nowscene[0]++;
							break;
							case 1:
								draw(50,50*i,50,50,chess2);
								nowscene[1]++;
							break;
							case 2:
								draw(100,50*i,50,50,chess2);
								nowscene[2]++;
							break;
							case 3:
								draw(150,50*i,50,50,chess2);
								nowscene[3]++;
							break;
							case 4:
								draw(200,50*i,50,50,chess2);
								nowscene[4]++;
							break;
							case 5:
								draw(250,50*i,50,50,chess2);
								nowscene[5]++;
							break;
							case 6:
								draw(300,50*i,50,50,chess2);
								nowscene[6]++;
							break;
							case 7:
								draw(350,50*i,50,50,chess2);
								nowscene[7]++;
							break;
						}
						
					break;
					}
				}
			  put(2,b+1);
			  showMap();
			  if(win());
			  if(win3());
			  if(win4());
			  if(win2());
			  }
		}	
		
}

void init()
{
	glClearColor(0.6, 0.8, 0.9, 0.0);
	gluOrtho2D(-35, 440, -95, 500);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	logo = loadPngTexture("chessboard3.png", 500, 500);
	chess1 = loadPngTexture("chess1.png",100,100);
	chess2 = loadPngTexture("chess2.png",100,100);
	begingame= loadPngTexture("begin.png",200,150);
	begingame1= loadPngTexture("begin1.png",200,150);
	begingame2= loadPngTexture("begin2.png",200,150);
	end0= loadPngTexture("end.png",200,150);
	end1= loadPngTexture("end1.png",200,150);
	end2= loadPngTexture("end2.png",200,150);
	num[0]= loadPngTexture("0.png",50,50);
	num[1]= loadPngTexture("1.png",50,50);
	num[2]= loadPngTexture("2.png",50,50);
	num[3]= loadPngTexture("3.png",50,50);
	num[4]= loadPngTexture("4.png",50,50);
	num[5]= loadPngTexture("5.png",50,50);
	num[6]= loadPngTexture("6.png",50,50);
	num[7]= loadPngTexture("7.png",50,50);
	num[8]= loadPngTexture("8.png",50,50);
	num[9]= loadPngTexture("9.png",50,50);
	state[0]= loadPngTexture("state.png",480,225);
	state[1]= loadPngTexture("state1.png",480,225);
	state[2]= loadPngTexture("state2.png",480,225);
	state[3]= loadPngTexture("state3.png",480,225);
	state[4]= loadPngTexture("state4.png",480,225);
	mul= loadPngTexture("mul.png",50,50);
}

void draw(int x, int y, int width, int height, int image){
	
	
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
		glTexCoord2f(0,0);	
		glVertex2i(x, y);
			
		glTexCoord2f(1,0);
		glVertex2i(x+width, y);

		glTexCoord2f(1,1);
		glVertex2i(x+width, y+height);

		glTexCoord2f(0,1);
		glVertex2i(x, y+height);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	draw(-10, -80, 50, 50, chess1);
	draw(300, 410, 50, 50, chess2);
	draw(-10, -10, 420, 415, logo);
	draw(35, -80, 50, 50, mul);
	draw(60,-80,50,50,num[nowdec1]);
	draw(70,-80,50,50,num[now1]);
	draw(345, 410, 50, 50, mul);
	draw(370,410,50,50,num[nowdec2]);
	draw(380,410,50,50,num[now2]);
  
	if(fos==0){
		glColor3f(1,1,1);
		if(change==0)
		glBindTexture(GL_TEXTURE_2D,begingame);
		if(change==1)
		glBindTexture(GL_TEXTURE_2D,begingame1);
		if(change==2)
		glBindTexture(GL_TEXTURE_2D,begingame2);
		glBegin(GL_POLYGON);//要去修改mouse
		glTexCoord2f(0,0);	
		glVertex2i(100,100);
		glTexCoord2f(0,1);	
		glVertex2i(100,300);
		glTexCoord2f(1,1);	
		glVertex2i(300,300);
		glTexCoord2f(1,0);	
		glVertex2i(300,100);
		glEnd();	
		draw(-35,410,160,80,state[0]);
		glutSwapBuffers();
	}
	else{
		for(int i=0;i<8;i++){
			for(int j=0;j<nowscene[i];j++)
			{
				if(i==0)
					if(data[7-j][i]==2)		draw(0,50*j,50,50,chess2);
					else if(data[7-j][i]==1)draw(0,50*j,50,50,chess1);
				if(i==1)
					if(data[7-j][i]==2)draw(50,50*j,50,50,chess2);
					else if(data[7-j][i]==1)draw(50,50*j,50,50,chess1);
				if(i==2)
					if(data[7-j][i]==2)draw(100,50*j,50,50,chess2);
					else if(data[7-j][i]==1)draw(100,50*j,50,50,chess1);
				if(i==3)
					if(data[7-j][i]==2)draw(150,50*j,50,50,chess2);
					else if(data[7-j][i]==1)draw(150,50*j,50,50,chess1);
				if(i==4)
					if(data[7-j][i]==2)draw(200,50*j,50,50,chess2);
					else if(data[7-j][i]==1)draw(200,50*j,50,50,chess1);
				if(i==5)
					if(data[7-j][i]==2)draw(250,50*j,50,50,chess2);
					else if(data[7-j][i]==1)draw(250,50*j,50,50,chess1);
				if(i==6)
					if(data[7-j][i]==2)draw(300,50*j,50,50,chess2);
					else if(data[7-j][i]==1)draw(300,50*j,50,50,chess1);
				if(i==7)
					if(data[7-j][i]==2)draw(350,50*j,50,50,chess2);
					else if(data[7-j][i]==1)draw(350,50*j,50,50,chess1);				
			}
		}
		if(fall&&!endd)
			draw(-35,410,160,80,state[1]);
		else if(!fall&&!endd)
			draw(-35,410,160,80,state[2]);
		else if(winner==1&&endd)
			draw(-35,410,200,100,state[3]);
		else if(winner==2&&endd)
			draw(-35,410,200,100,state[4]);

		if(endd){
			fos=3;
			if(change==0)
				glBindTexture(GL_TEXTURE_2D,end0);
			if(change==1)
				glBindTexture(GL_TEXTURE_2D,end1);
			if(change==2)
				glBindTexture(GL_TEXTURE_2D,end2);
			glBegin(GL_POLYGON);//要去修改mouse
			glTexCoord2f(0,0);	
			glVertex2i(100,100);
			glTexCoord2f(0,1);	
			glVertex2i(100,300);
			glTexCoord2f(1,1);	
			glVertex2i(300,300);
			glTexCoord2f(1,0);	
			glVertex2i(300,100);
			glEnd();	
		}
		glutSwapBuffers();
		if(fall){
			game();
			fall=0;
			glutPostRedisplay();
		}
	}		
}           
void mouse(int buttom,int state,int x,int y)
{	
	if(buttom==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{printf("x:%d y:%d ",x,y);
		if(fos==0){
			if(x>150&&x<343&&y<288&&y>229){fos=1;change=0;}
			else if(x>-150&&x<343&&y>312&&y<372){fos=2;fall=1;change=0;}
			glutPostRedisplay();
		}
		else if(fos==3){
			if(x>150&&x<343&&y<288&&y>229){
				fos=0;fall=0;//first or second
				for(int i=0;i<8;i++){
					nowscene[i]=0;
				}
				endd=0;
				nowdec1=3,now1=2;
				nowdec2=3,now2=2;
				setMap();
			}
			else if(x>-150&&x<343&&y>312&&y<372)exit(0);
			glutPostRedisplay();
		}
		else{
		if(!endd){
			if(fall==0){
				if(gameEnd()){};
					if(x>36&&x<87&&y>105&&y<503){
							for(int i=7;i>-1;i--){
								if(data[i][0]==0){
									fall=1;nowscene[0]++;
									i=7-i;
									now1-=1;
									if(now1<0){
										nowdec1-=1;
										now1=9;
									}
									put(1,1);
									draw(0,50*i,50,50,chess1);							
									break;
								}			
							}	
					}
					else if(x>87&&x<140&&y>105&&y<503){
							for(int i=7;i>-1;i--){
								if(data[i][1]==0){
									fall=1;nowscene[1]++;
									i=7-i;
									now1-=1;
									if(now1<0){
										nowdec1-=1;
										now1=9;
									}
									put(1,2);
									draw(50,50*i,50,50,chess1);							
									break;
								}			
							}	
					}
					else if(x>140&&x<191&&y>105&&y<503){
						for(int i=7;i>-1;i--){
								if(data[i][2]==0){
									fall=1;nowscene[2]++;
									i=7-i;
									now1-=1;
									if(now1<0){
										nowdec1-=1;
										now1=9;
									}
									put(1,3);
									draw(100,50*i,50,50,chess1);							
									break;
								}			
							}	
					}
					else if(x>191&&x<244&&y>105&&y<503){
						for(int i=7;i>-1;i--){
								if(data[i][3]==0){
									fall=1;nowscene[3]++;
									i=7-i;
									now1-=1;
									if(now1<0){
										nowdec1-=1;
										now1=9;
									}
									put(1,4);
									draw(150,50*i,50,50,chess1);							
									break;
								}			
							}	
					}
					else if(x>244&&x<295&&y>105&&y<503){
						for(int i=7;i>-1;i--){
								if(data[i][4]==0){
									fall=1;nowscene[4]++;
									i=7-i;
									now1-=1;
									if(now1<0){
										nowdec1-=1;
										now1=9;
									}
									put(1,5);
									draw(200,50*i,50,50,chess1);							
									break;
								}			
							}	
					}
					else if(x>295&&x<347&&y>105&&y<503){
						for(int i=7;i>-1;i--){
								if(data[i][5]==0){
									fall=1;nowscene[5]++;
									i=7-i;
									now1-=1;
									if(now1<0){
										nowdec1-=1;
										now1=9;
									}
									put(1,6);
									draw(250,50*i,50,50,chess1);							
									break;
								}			
							}	
					}
					else if(x>347&&x<400&&y>105&&y<503){
						for(int i=7;i>-1;i--){
								if(data[i][6]==0){
									fall=1;nowscene[6]++;
									i=7-i;
									now1-=1;
									if(now1<0){
										nowdec1-=1;
										now1=9;
									}
									put(1,7);
									draw(300,50*i,50,50,chess1);							
									break;
								}			
							}	
					}
					else if(x>400&&x<451&&y>105&&y<503){
						for(int i=7;i>-1;i--){
								if(data[i][7]==0){
									fall=1;nowscene[7]++;
									i=7-i;
									now1-=1;
									if(now1<0){
										nowdec1-=1;
										now1=9;
									}
									put(1,8);
									draw(350,50*i,50,50,chess1);							
									break;
								}			
							}	
					}		
				}
		}
		}
		glutPostRedisplay();
	}
}
int ww=500,wh=600;
void myReshape(GLsizei w, GLsizei h)
{   
	display();
}

void option(int x,int y)
{	
	if(fos==0){
	if(x>150&&x<343&&y<288&&y>229)change=1;
	else if(x>-150&&x<343&&y>312&&y<372)change=2;
	else change=0;
	glutPostRedisplay();
	}
	else if(fos==3){
	if(x>150&&x<343&&y<288&&y>229)change=1;
	else if(x>-150&&x<343&&y>312&&y<372)change=2;
	else change=0;
	glutPostRedisplay();
	}
//	if(!round){if(x>26&&x<467&&y>96&&y<514){
//		draw(25,25,50,50,chess1);printf("x:%d y:%d\n",x,y);}}

}
int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("四子棋");	
	glutPassiveMotionFunc(option);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	init();
	glutReshapeFunc(myReshape);
	glutMainLoop();
	
	return 0;
}