void *collide_wall(void *s);
void *collide_balls(void *s);

void *physics(void *ch)
{				//Handles physics of the game and sends/receives relevant information
	if((bot==1 && turn==myturn && clickl==0 && network==1)||(network==0 && turn!=myturn && clickl==0))
	{
		bot_job();
		process=1;
	}
	if(turn!=myturn && process==0 && network==1)
	{
		Arr[N].radius=0.05;
		int n1;
		if(svr==0 || (svr==1 && players==2))
		{
			n1=read(sockfd,&Arr[N],3*sizeof(Arr[N]));
		}
		else
		{
			if(turn==1)
			{
				n1=read(sockfd,&Arr[N],3*sizeof(Arr[N]));
				n1=write(sockfd1,&Arr[N],3*sizeof(Arr[N]));
				n1=write(sockfd2,&Arr[N],3*sizeof(Arr[N]));
			}
			if(turn==2)
			{
				n1=read(sockfd1,&Arr[N],3*sizeof(Arr[N]));
				n1=write(sockfd,&Arr[N],3*sizeof(Arr[N]));
				n1=write(sockfd2,&Arr[N],3*sizeof(Arr[N]));
			}
			if(turn==3)
			{
				n1=read(sockfd2,&Arr[N],3*sizeof(Arr[N]));
				n1=write(sockfd,&Arr[N],3*sizeof(Arr[N]));
				n1=write(sockfd1,&Arr[N],3*sizeof(Arr[N]));
			}
		}
		if(Arr[N].vx!=0 || Arr[N].vy!=0)	
		process=1;
		
	}
	for(int i=0;i<=N;i++)
	{
		if(Arr[i].radius==-1)
		continue;
		Arr[i].x=Arr[i].x+Arr[i].vx*dt;	
		Arr[i].y=Arr[i].y+Arr[i].vy*dt;


		double t1=Arr[i].vx;
		double t2=Arr[i].vy;
		
		if(t1!=0 || t2!=0)
		{
			double c=t1/sqrt(t1*t1+t2*t2);
			double s=t2/sqrt(t1*t1+t2*t2);
			Arr[i].vx=Arr[i].vx-mu*dt*c;
			Arr[i].vy=Arr[i].vy-mu*dt*s;
			if(t1*Arr[i].vx<=0)
			Arr[i].vx=0;
			if(t2*Arr[i].vy<=0)
			Arr[i].vy=0;
		}
	}

	for(int i=0;i<=N;i++)
        {
                
		if(Arr[i].radius==-1)
		continue;
		pthread_t thread1, thread2;
		int *j;
		j=&i;
		int iret1 = pthread_create( &thread1, NULL, collide_wall, (void*) j);
		int iret2 = pthread_create( &thread2, NULL, collide_balls, (void*) j);
		pthread_join( thread1, NULL);
		pthread_join( thread2, NULL);
               
        }
	if(Status_current[N]==1)
	{
		for(int k=0;k<N;k++)
		{
			if(Status_current[k]==10 || Status_current[k]==20)
			{
				Status_current[N]=2;
				break;
			}
		}
	}
	int flag=0;
	for(int i=0;i<=N;i++)
	{
		if(Arr[i].radius!=-1 && (Arr[i].vx!=0 || Arr[i].vy!=0))
		{
			flag++;
			break;
		}
	}
	if(process==1 && flag==0)
	{	
		if(M==1 && Arr[0].radius!=-1)
		{
			foul=1;
		}
		process=0;
		if(players==4)
		turn=(turn+1)%4;
		else if(players==2)
		turn=(turn+2)%4;
		clickl=0;
		rules();
		flag2=1;
	}
}



void collision(struct Coin* A,struct Coin* B,double d1, double K)
{			//Handles collision between 2 coins using conservation of momentum

        double x1=(*A).x;
        double y1=(*A).y;
        double x2=(*B).x;
        double y2=(*B).y;
        double vx1=(*A).vx;
        double vy1=(*A).vy;
        double vx2=(*B).vx;
        double vy2=(*B).vy;
        double c=(y2-y1)/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        double s=(x2-x1)/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double ux2=vx2*c-vy2*s;
	double ux1=vx1*c-vy1*s;
	double p1=vy1*c+vx1*s;
	double p2=vy2*c+vx2*s;
	double uy1=((p1*(1-K*E))+(p2*K*(1+E)))/(1+K);
	double uy2=((p1*(1+E))+(p2*(K-E)))/(1+K);
	double t1=uy1*c-ux1*s;
	double t2=ux1*c+uy1*s;
	double t3=uy2*c-ux2*s;
	double t4=ux2*c+uy2*s;

        (*A).vy=t1;
        (*A).vx=t2;
        (*B).vy=t3;
        (*B).vx=t4;

        double x11=x1+(*A).vx*dt;
        double y11=y1+(*A).vy*dt;
        double x22=x2+(*B).vx*dt;
        double y22=y2+(*B).vy*dt;
        
        double d2=(x11-x22)*(x11-x22)+(y11-y22)*(y11-y22);
	if(d2<d1*d1)
        {
		(*A).x=(*A).x-vx1*dt;
		(*A).y=(*A).y-vy1*dt;
		(*B).x=(*B).x-vx2*dt;
		(*B).y=(*B).y-vy2*dt;
        }

}
void *collide_wall(void *s)
{			//Checks and handles collision between a coin and a wall and also checks for pocketed coins
	int *k=(int*)s;
	int i=*k;
	struct Coin* A;
	A=&Arr[i];
	float x1=0.95-Rh;
	float y1=0.95-Rh;
	float x2=-0.95+Rh;
	float y2=0.95-Rh;
	float x3=-0.95+Rh;
	float y3=-0.95+Rh;
	float x4=0.95-Rh;
	float y4=-0.95+Rh;
	float dsq1=(x1-(*A).x)*(x1-(*A).x)+(y1-(*A).y)*(y1-(*A).y);
	float dsq2=(x2-(*A).x)*(x2-(*A).x)+(y2-(*A).y)*(y2-(*A).y);
	float dsq3=(x3-(*A).x)*(x3-(*A).x)+(y3-(*A).y)*(y3-(*A).y);
	float dsq4=(x4-(*A).x)*(x4-(*A).x)+(y4-(*A).y)*(y4-(*A).y);
	float Dsq=Rh*Rh-(*A).radius*(*A).radius;
	if(dsq1<=Dsq || dsq2<=Dsq || dsq3<=Dsq || dsq4<=Dsq)
	{
		if(i==N)
		{
			(*A).radius=-1;
			foul=1;
			Arr[N].vx=0;
			Arr[N].vy=0;
			Arr[N].collision_no=-5;
		}
		else
		{
			(*A).radius=-1;
			M--;
			(*A).collision_no=-5;
			(*A).vx=0;
			(*A).vy=0;
			if(i==0)
			{
				Status_current[in_curr++]=50;
				Status_current[N]=1;
			}
			else if(i%2==0)
			{
				Status_current[in_curr++]=20;
			
			}
			else
			Status_current[in_curr++]=10;
		}
		return s;
	}
        if((*A).x-(*A).radius<=-0.95)
        {
	    if((*A).vx<0)
	    {
		(*A).collision_no=-1;
                   	(*A).vx=-(*A).vx*EW;
	    }

               }
		if((*A).x+(*A).radius>=0.95)
		{
		    if((*A).vx>0)
		    {
			(*A).collision_no=-2;
                    	(*A).vx=-(*A).vx*EW;
		    }
		}
                if((*A).y-(*A).radius<=-0.95)
                {
		    if((*A).vy<0)
		    {
			(*A).collision_no=-3;
			(*A).vy=-(*A).vy*EW;
		    }
                }
		if((*A).y+(*A).radius>=0.95)
		{
		    if((*A).vy>0)
		    {
			(*A).collision_no=-4;
			(*A).vy=-(*A).vy*EW;
		    }
                }
}
void *collide_balls(void *s)
{			//Checks for collision between two coins.
	int *k=(int*)s;
	int i=*k;
	struct Coin* A;
		A=&Arr[i];
	for(int j=i+1;j<=N;j++)
                {
                    struct Coin *B;
		    B=&Arr[j];
		    if((*B).radius==-1)
	   	    continue;
                    double dis=sqrt(((*A).x-(*B).x)*((*A).x-(*B).x)+((*A).y-(*B).y)*((*A).y-(*B).y));
		    double K=1;
		    if(j==N)
		    K=mass_ratio;
                    if(dis<=(*A).radius+(*B).radius)
		    {
			float dot_pro=((*A).x-(*B).x)*((*A).vx-(*B).vx)+((*A).y-(*B).y)*((*A).vy-(*B).vy);
			if(dot_pro<0)
			{
                    		collision(A,B,(*A).radius+(*B).radius,K);
				(*A).collision_no=j;
				(*B).collision_no=i;
			}
                    }
                }
}



