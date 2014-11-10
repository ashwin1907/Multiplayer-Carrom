
void processMousePassiveMotion(int x, int y)
{
	if ( bot == 1 )
		return;
	if(flag10==0)
	return;
	if(turn!=myturn)
	return;
	if(clickl==2)
	return;
	Arr[N].radius=0.05;
	float x1 = (2.0/L) * x - 1.0; 
	float y1 = (-2.0/L) * y + 1.0;
	if(turn==2)
	{	
		x1=-x1;
		y1=-y1;
	}
	if(turn==1)
	{	
		float tmp=y1;
		y1=-x1;
		x1=tmp;
	}
	if(turn==3)
	{
		float tmp=y1;
		y1=x1;
		x1=-tmp;
	}
	if (clickl==0 && (turn==0 || turn==2))
	{
		if(turn==0)
		Arr[N].y=-d;
		else
		Arr[N].y=d;
		if(x1<=d-0.1 && x1>=0.1-d)
		Arr[N].x=x1;
		else if(x1<=d-0.1)
		Arr[N].x=-d+0.1;
		else
		Arr[N].x=-0.1+d;
		if(network==1)
		{
			int n1=write(sockfd,&Arr[N],sizeof(Arr[N]));
			if(svr==1 && players==4)
			{
				n1=write(sockfd1,&Arr[N],sizeof(Arr[N]));
				n1=write(sockfd2,&Arr[N],sizeof(Arr[N]));
			}
		}
	}
	if (clickl==0 && (turn==1 || turn==3))
	{
		if(turn==1)
		Arr[N].x=-d;
		else
		Arr[N].x=d;
		if(y1<=d-0.1 && y1>=0.1-d)
		Arr[N].y=y1;
		else if(y1<=d-0.1)
		Arr[N].y=-d+0.1;
		else
		Arr[N].y=-0.1+d;
		if(network==1)
		{
			int n1=write(sockfd,&Arr[N],sizeof(Arr[N]));
			if(svr==1 && players==4)
			{
				n1=write(sockfd1,&Arr[N],sizeof(Arr[N]));
				n1=write(sockfd2,&Arr[N],sizeof(Arr[N]));
			}
		}
	}
	else if(clickl==1)
	{
		float xx=x1-Arr[N].x;
		float yy=y1-Arr[N].y;
		float actlen=sqrt(xx*xx+yy*yy);
		bool check;
		if(turn==0)
		check=y1<-0.7;
		else if(turn==1)
		check=x1<-0.7;
		else if(turn==2)
		check=y1>0.7;
		else
		check=x1>0.7;
		if(check)
		{
		if(actlen>aimlen)
		{
			mousex=Arr[N].x+aimlen*xx/actlen;
			mousey=Arr[N].y+aimlen*yy/actlen;
		}
		else
		{
			mousex=x1;
			mousey=y1;
		}
		}
		else
		{
		if(actlen>aimlen_back)
		{
			mousex=Arr[N].x+aimlen_back*xx/actlen;
			mousey=Arr[N].y+aimlen_back*yy/actlen;
		}
		else
		{
			mousex=x1;
			mousey=y1;
		}
		}
	}
	glutPostRedisplay();
}

void processMouse(int button, int state, int x, int y)
{
	if ( bot == 1 )
		return;
	if(flag10==0)
	return;
	if(turn!=myturn)
	return;
	Arr[N].radius=0.05;
	float x1 = (2.0/L) * x - 1.0; 
	float y1 = (-2.0/L) * y + 1.0;
	int flag=0;
	for(int i=0;i<N;i++)
	{
		if(Arr[i].radius==-1)
		continue;
		double dis=sqrt((Arr[i].x-Arr[N].x)*(Arr[i].x-Arr[N].x)+(Arr[i].y-Arr[N].y)*(Arr[i].y-Arr[N].y));
		if(dis<=Arr[i].radius+Arr[N].radius)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	return;
	if(turn==2)
	{	
		x1=-x1;
		y1=-y1;
	}
	if(turn==1)
	{	
		float tmp=y1;
		y1=-x1;
		x1=tmp;
	}
	if(turn==3)
	{
		float tmp=y1;
		y1=x1;
		x1=-tmp;
	}
	for(int i=0;i<=N;i++)
	{
		if(Arr[i].radius!=-1 && (Arr[i].vx!=0 || Arr[i].vy!=0))
		{
			if(clickl==2)
			return;
		}
	}
	if(state==GLUT_DOWN)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			clickl++;
			float xx=x1-Arr[N].x;
			float yy=y1-Arr[N].y;
			float actlen=sqrt(xx*xx+yy*yy);
			bool check;
			if(turn==0)
			check=y1<-0.7;
			else if(turn==1)
			check=x1<-0.7;
			else if(turn==2)
			check=y1>0.7;
			else
			check=x1>0.7;
			if(check)
			{
			if(actlen>aimlen)
			{
				mousex=Arr[N].x+aimlen*xx/actlen;
				mousey=Arr[N].y+aimlen*yy/actlen;
			}
			else
			{
				mousex=x1;
				mousey=y1;
			}
			}
			else
			{
			if(actlen>aimlen_back)
			{
				mousex=Arr[N].x+aimlen_back*xx/actlen;
				mousey=Arr[N].y+aimlen_back*yy/actlen;
			}
			else
			{
				mousex=x1;
				mousey=y1;
			}
		}
		}	
		else if(button==GLUT_RIGHT_BUTTON && clickl<=1)
		{
			clickl=0;
		}
	if(clickl==2)
	{
		process++;
		Arr[N].vx=8*(Arr[N].x-mousex);
		Arr[N].vy=8*(Arr[N].y-mousey);
		if(network==1)
		{
			int n1 = write(sockfd,&Arr[N],sizeof(Arr[N]));
			if(svr==1 && players==4)
			{
				n1=write(sockfd1,&Arr[N],sizeof(Arr[N]));
				n1=write(sockfd2,&Arr[N],sizeof(Arr[N]));
			}
		}
	}
	}
	glutPostRedisplay();
	
}
