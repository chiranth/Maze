
/*Chiranth B R*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<time.h>


struct node
{
	int x,y,z;
	struct node *next;
}*root=NULL;

typedef struct node NODE;

NODE *getnode(int x,int y,int z)
{
	NODE *t=(NODE *)malloc(sizeof(struct node));
	//printf("enter info\n");
	//scanf("%d",&t->info);
	t->x=x;
	t->y=y;
	t->z=z;
	t->next=NULL;
	return(t);
}

void push(int x,int y,int z)
{
	NODE *new;
	new=getnode(x,y,z);
	
	if(root==NULL)
	{
		root=new;
		return;
	}
	new->next=root;
	root=new;
	return;
}

int pop(int *x,int *y,int *z)
{
	//int x;
	NODE *t=root;
	if(root==NULL)
	{
		//printf("stack empty\n");
		return 1;
	}
	//x=root->info;
	*x=root->x;
	*y=root->y;
	*z=root->z;
	root=root->next;
	//printf("the ele popped is %d\n",x);
	free(t);
	return 0;
}

void makepath(int maze[][50][4],int r,int c,char dir,int hr,int hc)
{
	int rd,count=0;
	//visited=2;
	maze[r][c][2]=1;
	switch(dir)
	{
		case 'e':	rd = rand()%4;
					printf("%d\n",rd);
					switch(rd)
					{
							label0:
							case 0:		if(r < hr-1)
										{
											if(maze[r+1][c][2] == 0)
											{					
												maze[r][c][1]=0;
												makepath(maze,r+1,c,'s',hr,hc);
											}
											
										}
										
							case 1:		if(c > 0)
										{
											if(maze[r][c-1][2] == 0)
											{
												maze[r][c-1][0]=0;
												makepath(maze,r,c-1,'w',hr,hc);
											}
										}
									
							case 2:		if(c < hc-1)
										{
											if(maze[r][c+1][2] == 0)
											{
												maze[r][c][0]=0;	
												makepath(maze,r,c+1,'e',hr,hc);
											}
										}
								
							case 3:		if(r > 0)
										{
											if(maze[r-1][c][2] == 0)
											{
												maze[r-1][c][1]=0;
												makepath(maze,r-1,c,'n',hr,hc);
											}
											else
											{
												if(count == 0)
												{
													count++;
													goto label0;
												}
											}
										}
										else
										{
											if(count == 0)
											{
												count++;
												goto label0;
											}
										}
						}
						
						break;

		case 's':	rd=rand()%4;
					printf("%d\n",rd);
					
					switch(rd)
					{
						label1:
						case 0:		if(c > 0)
									{
										if(maze[r][c-1][2] == 0)
										{
											maze[r][c-1][0]=0;
											makepath(maze,r,c-1,'w',hr,hc);
										}
									}
					
						case 1:		if(r < hr-1)
									{
										if(maze[r+1][c][2] == 0)
										{
											maze[r][c][1]=0;
											makepath(maze,r+1,c,'s',hr,hc);
										}
									}	
									
						case 2:		if(r > 0)
									{
										if(maze[r-1][c][2]!=1)
										{
											maze[r-1][c][1]=0;
											makepath(maze,r-1,c,'n',hr,hc);
										}
									}
					
						case 3:		if(c < hc-1)
									{
										if(maze[r][c+1][2]!=1)
										{
											maze[r][c][0]=0;	
											makepath(maze,r,c+1,'e',hr,hc);
										}
										else
										{
											if(count == 0)
											{
												count++;
												goto label1;
											}
										}
									}
					}
					
					break;
					
		case 'w':	rd=rand()%4;
				printf("%d\n",rd);
					switch(rd)
					{
						label2:
						case 0:		if(r > 0)
									{
										if(maze[r-1][c][2] != 1)
										{
											maze[r-1][c][1]=0;
											makepath(maze,r-1,c,'n',hr,hc);
										}
									}
						
						case 1:		if(c < hc-1)
									{
										if(maze[r][c+1][2] != 1)
										{
											maze[r][c][0]=0;	
											makepath(maze,r,c+1,'e',hc,hc);
										}
									}
					
						case 2:		if(r < hr-1)
									{
										if(maze[r+1][c][2] != 1)
										{
											maze[r][c][1]=0;
											makepath(maze,r+1,c,'s',hr,hc);
										}
									}	
									
						case 3:		if(c > 0)
									{
										if(maze[r][c-1][2] != 1)
										{
											maze[r][c-1][0]=0;
											makepath(maze,r,c-1,'w',hr,hc);
										}
										else
										{
											if(count == 0)
											{
												count++;
												goto label2;
											}
										}
									}
									
					}
					
					break;
					
		case 'n':	rd=rand()%4;
		printf("%d\n",rd);
		
					switch(rd)
					{
						label3:
						case 0:		if(c < hc-1)
									{
										if(maze[r][c+1][2]!=1)
										{
											maze[r][c][0]=0;	
											makepath(maze,r,c+1,'e',hr,hc);
										}
									}
					
						case 1:		if(r > 0)
									{
										if(maze[r-1][c][2]!=1)
										{
											maze[r-1][c][1]=0;
											makepath(maze,r-1,c,'n',hr,hc);
										}
									}
					
						case 2:		if(r < hr-1)
								{
									if(maze[r+1][c][2]!=1)
									{
										maze[r][c][1]=0;
										makepath(maze,r+1,c,'s',hr,hc);
									}
								}	
					
						case 3:		if(c > 0)
								{
									if(maze[r][c-1][2]!=1)
									{
										maze[r][c-1][0]=0;
										makepath(maze,r,c-1,'w',hr,hc);
									}
									else
									{
										if(count == 0)
										{
											count++;
											goto label3;
										}
									}
								}
								
					}
						
					break;
			
						
		}
	
}

void drawsolution(FILE * fp,int hr,int hc)
{	
	int x,y,z,v;
	int x1,y1,x2,y2;
	
	x1=hc*20+30;
	x2=x1-20;
	y1=hr*20+10;
	y2=y1;
	
	fprintf(fp,"<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"red\" stroke-width=\"1\" stroke-linecap=\"round\"/>\n",x1,y1,x2,y2);
	fprintf(fp,"<line x1=\"10\" y1=\"30\" x2=\"30\" y2=\"30\" stroke=\"red\" stroke-width=\"1\" stroke-linecap=\"round\"/>\n");
	
	v=pop(&x,&y,&z);
	
	while(v == 0)
	{
		if(z == 0)
		{
			x1=(y+1)*20+10;
			y1=(x+1)*20+10;
			x2=x1+20;
			y2=y1;
		}
		
		if(z == 1)
		{
			x1=(y+1)*20+10;
			x2=x1;
			y1=(x+1)*20+10;
			y2=y1+20;
		}
		
		fprintf(fp,"<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"red\" stroke-width=\"1\" stroke-linecap=\"round\"/>\n",x1,y1,x2,y2);
		v=pop(&x,&y,&z);
	}
		
}

void drawmaze(int maze[][50][4],int hr,int hc,int s,FILE *fp)
{
	int h=hr*20+40;
	int w=hc*20+40;
	int x1,x2,y1,y2,i,j,k;
	
	maze[hr-1][hc-1][0]=0;
		
	fprintf(fp,"<?xml version=\"1.0\"?>");
	fprintf(fp,"<svg width=\"%d\" height=\"%d\" version=\"1.2\" baseProfile=\"tiny\" viewport-fill=\"red\" >\n",w,h);
	fprintf(fp,"<g stroke=\"black\" stroke-width=\"3\" stroke-linecap=\"round\">\n");
	fprintf(fp,"<line x1=\"20\" y1=\"20\" x2=\"%d\" y2=\"20\"/>\n",(hc*20+20));
	fprintf(fp,"<line x1=\"20\" y1=\"40\" x2=\"20\" y2=\"%d\" />\n",(hr*20+20));
	for(i=0;i<hr;i++)
	{
		for(j=0;j<hc;j++)
		{
			if(i==hr-1 && j==hc-1)
			printf("\n\n\n%d\n\n\n",maze[i][j][0]);
			for(k=0;k<2;k++)
			{
				if(maze[i][j][k] == 1)
				{
					fprintf(fp,"<line ");
					
					if(k == 0)
					{
						x1=(j+2)*20;
						y1=(i+1)*20;
						x2=x1;
						y2=y1+20;
					}
					
					if(k == 1)
					{
						x1=(j+1)*20;
						y1=(i+2)*20;
						x2=x1+20;
						y2=y1;
					}
					
					fprintf(fp,"x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" fill=\"none\" />\n",x1,y1,x2,y2);
				}
			}
			
			fprintf(fp,"\n");
			
		}
	}
	if(s == 0)
	{	fprintf(fp,"</g>\n</svg>");
		printf("\n%d\n\n",maze[hr-1][hc-1][0]);
	}
	else
	{
		drawsolution(fp,hr,hc);
		fprintf(fp,"</g>\n</svg>");
	}
	
	fclose(fp);
			
}


void makemaze(int maze[][50][4],int r,int c,int hr,int hc)
{
	int i,j,k;
	
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			for(k=0;k<3;k++)
			{
				if(k==2 || k == 3)
					maze[i][j][k]=0;
				
				else
					maze[i][j][k]=1;
			
			}
	
	maze[0][0][0]=0;
	maze[0][0][2]=1;		
	makepath(maze,0,1,'e',hr,hc);
	
	
}

void findpath(int maze[][50][4],int r, int c,int pr,int pc,int hr,int hc,FILE *fp)
{
	int v,x,y,z;
	
	if(r == hr-1  && c == hc-1 )
	{
		printf("path found");
		drawmaze(maze,hr,hc,1,fp);
		system("display solution.svg");
		exit(0);
	}
	
	if((maze[r][c][0] == 0 && c+1 != pc && maze[r][c+1][3] == 0) || (maze[r][c][0] == 0 && maze[r][c][1] == 1 && maze[r-1][c][1] == 1 && maze[r][c-1][0] == 1))	//going right
	{
		/*if((maze[r][c][0] == 0 && c+1 != pc && maze[r][c][3] == 0) == 0)
		{
			v=pop(&x,&y,&z);
			maze[r][c][3]=0;
		}*/
		push(r,c,0);
		printf("going right %d %d\n",r,c);
		maze[r][c+1][3]=1;
		findpath(maze,r,c+1,r,c,hr,hc,fp);
		v=pop(&x,&y,&z);
	}
	
	if((maze[r][c][1] == 0 && r+1 != pr && maze[r+1][c][3] == 0) || (maze[r][c][1] == 0 && maze[r][c][0] == 1 && maze[r][c-1][0] == 1 && maze[r-1][c][1] == 1 ))		//going down
	{
		/*if((maze[r][c][1] == 0 && r+1 != pr  && maze[r+1][c][3] ==0 ) == 0)
		{
			v=pop(&x,&y,&z);
		}*/
		push(r,c,1);
		printf("going down %d %d\n",r,c);
		maze[r+1][c][3]=1;
		findpath(maze,r+1,c,r,c,hr,hc,fp);
		v=pop(&x,&y,&z);
	}
	
	if(c > 0 )					//going left
	{
		if((maze[r][c-1][0] == 0 && c-1 != pc && maze[r][c-1][3] == 0) || (maze[r][c-1][0] == 0 && maze[r][c][0] == 1 && maze[r][c][1] == 1 && maze[r-1][c][1] == 1))
		{
			/*(if((maze[r][c-1][0] == 0 && c-1 != pc && maze[r][c-1][3] == 0 ) == 0)
			{
				v=pop(&x,&y,&z);
			}*/
			push(r,c-1,0);
			printf("going left %d %d\n",r,c);
			maze[r][c-1][3]=1;
			findpath(maze,r,c-1,r,c ,hr,hc,fp);
			v=pop(&x,&y,&z);
		}
	}
	
	if(r > 0)					//going up
	{
		if((maze[r-1][c][1] == 0 && r-1 != pr && maze[r-1][c][3] == 0) || (maze[r-1][c][1] == 0 && maze[r][c][0] == 1 && maze[r][c][1] == 1 && maze[r][c-1][0] == 1)) 
		{
			/*if((maze[r-1][c][1] == 0 && r-1 != pr  && maze[r-1][c][3] == 0) == 0)
			{
				v=pop(&x,&y,&z);
			}*/
			push(r-1,c,1);
			printf("going up %d %d\n",r,c);
			maze[r-1][c][3]=1;
			findpath(maze,r-1,c,r,c,hr,hc,fp);
			v=pop(&x,&y,&z);
		}
	}
	
	
}
		
void solvemaze(int maze[][50][4],int hr,int hc,FILE *fp)
{
	//int 
	
	findpath(maze,0,0,0,0,hr,hc,fp);

}

	
int main(int argc,char * argv[])
{
	srand(time(NULL));
	
	FILE *fp1,*fp2;
	int r,c,hr,hc;
	int maze[50][50][4];
	
	if(argc < 3)
	{
		printf("format :\n");
		printf("./a.out < no. of rows > < no. of columns >\n");
		exit(0);
	}
	else
	{
		r=atoi(argv[1]);
		c=atoi(argv[2]);
	}
	
	//printf("Enter the no. of rows & colums in tha maze : \n");
	//scanf("%d%d",&r,&c);
	hr=r;
	hc=c;
	//maze[r-1][c-1][0]=0;
	//printf("%d%d%d\n",r-1,c-1,maze[r-1][c-1][0]);
	maze[0][0][0]=0;
	makemaze(maze,r,c,hr,hc);
	
	fp1=fopen("maze.svg","w");
	drawmaze(maze,hr,hc,0,fp1);	
	system("display maze.svg");
	
	fp2=fopen("solution.svg","w");		
	solvemaze(maze,hr,hc,fp2);
	
	
	return 0;
				
}
				
