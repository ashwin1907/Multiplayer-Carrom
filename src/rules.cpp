void place_center(char ch)
{			//Places a coin at the center of the board where the space is available
	int init=0;
	int final=N-1;
	if(ch=='b')
	init=1;
	else if(ch=='w')
	init=2;
	else if(ch=='q')
	final=0;
	for(int k=init;k<=final;k+=2)
	{
	if(Arr[k].radius==-1)
	{
	Arr[k].radius=0.04;
	Arr[k].vx=0;
	Arr[k].vy=0;
	float x1,y1;
	float l=0;
	while(1)
	{
	int flag1=0;
	float theta=0;
	for(int t=0;t<8;t++)
	{
	x1=l*cos(theta);
	y1=l*sin(theta);
	int flag=0;
	for(int i=0;i<N;i++)
	{
	if(i==k)
	continue;
	float dis=sqrt((x1-Arr[i].x)*(x1-Arr[i].x)+(y1-Arr[i].y)*(y1-Arr[i].y));
	if(dis<2*Arr[k].radius)
	flag=1;
	}
	if(flag==0)
	{
	Arr[k].x=x1;
	Arr[k].y=y1;
	flag1=1;
	break;
	}
	theta=theta+M_PI/4;
	}	
	l=l+2.1*(Arr[k].radius);
	if(flag1==1)
	break;							
}	
break;
}
}
}

int* Status0;
int* Status1;
int* Status2;
int* Status3;
int* Status_current;
int in_curr=0;
int foul=0;
int process=0;
int network;
int turn=0;

void rules()
{			//Defines the rules for the game
	int *chng;
	if(players==4)
	{
	if(turn==1)
	chng=Status0;
	else if(turn==2)
	chng=Status1;
	else if(turn==3)
	chng=Status2;
	else
	chng=Status3;
	}
	else if(players==2)
	{
		if(turn==2)
		chng=Status0;
		else
		chng=Status2;
	}
	if(in_curr!=0)
	{
		int j=0;
		for(int i=0;i<N;i++)
		{
			if(chng[i]==0)
			{
				if(Status_current[N]==2)
				{
					chng[i]=50;
					Status_current[N]=0;
					continue;
				}
				if(Status_current[j]!=50)
				chng[i]=Status_current[j];
				j++;
				if (j>in_curr)
				break;
			}
		}
		if(players==4 && foul==0)
		{
			if(turn!=0)
			turn--;
			else
			turn=3;
		}
		else if (players==2 && foul==0)
		{
			if(turn==0)
			turn=2;
			else
			turn=0;
		}
		int in=0;
		int value=10;
		while(chng[N]<0)
		{
			if(chng[in]==value)
			{
				if(value==10)
				place('b');
				else if(value==20)
				place('w');
				else if(value==50)
				place('q');
				chng[N]+=chng[in];
				chng[in]=0;
				M++;
			}
			in++;
			if(in==N)
			{
				in=0;
				if(value==50)
				break;
				value+=10;
				if(value==30)
				value=50;
			}
		}
		if(chng[N]>0)
		chng[N]=0;
	}
	else if(in_curr==0 && Status_current[N]==1)
	{
		Status_current[N]=0;
		place('q');
		M++;
	}
	if(foul==1)
	{
		foul=0;
		if(Status_current[N]==1)
		{
			place('q');
			M++;
			Status_current[N]=0;
		}
		int w=-1,b=-1,q=-1;
		for(int i=0;i<N;i++)
		{
			if(chng[i]==10)
			b=i;
			else if(chng[i]==20)
			w=i;
			else if(chng[i]==50)
			q=i;
		}
		if(b!=-1)
		{
			chng[b]=0;
			place('b');
			M++;
		}
		else if(w!=-1)
		{
			chng[w]=0;
			place('w');
			M++;
		}
		else if(q!=-1)
		{
			chng[q]=0;
			place('q');
			M++;
		}
		else
		{
			chng[N]-=10;
		}
		
	}
	for(int i=0;i<N;i++)
	{		
		Status_current[i]=0;
	}
	in_curr=0;
	int sum1=0,sum2=0;
	for(int i=0;i<=N;i++)
	{
		sum1+=Status0[i];
		sum2+=Status2[i];
	}
}
void place(char ch)
{			//Places a coin at the center of the board where the space is available
	int init=0;
	int final=N-1;
	if(ch=='b')
	{
		init=1;
	}
	else if(ch=='w')
	{
		init=2;
	}
	else if(ch=='q')
	{
		final=0;
	}
	for(int k=init;k<=final;k+=2)
	{
		if(Arr[k].radius==-1)
		{
			Arr[k].radius=0.04;
			Arr[k].vx=0;
			Arr[k].vy=0;
			float x1,y1;
			float l=0;
			while(1)
			{
				int flag1=0;
				float theta=0;
				for(int t=0;t<8;t++)
				{
					x1=l*cos(theta);
					y1=l*sin(theta);
					int flag=0;
					for(int i=0;i<N;i++)
					{
						if(i==k)
						continue;
						float dis=sqrt((x1-Arr[i].x)*(x1-Arr[i].x)+(y1-Arr[i].y)*(y1-Arr[i].y));
						if(dis<2*Arr[k].radius)
						flag=1;
					}
					if(flag==0)
					{
						Arr[k].x=x1;
						Arr[k].y=y1;
						flag1=1;
						break;
					}
					theta=theta+M_PI/4;
				}	
				l=l+2.1*(Arr[k].radius);
				if(flag1==1)
				break;							
			}	
			break;
		}
	}

}
