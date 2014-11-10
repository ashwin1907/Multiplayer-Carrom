struct sh_para
{
double ini_x;
double ini_y;
double fin_x;
double fin_y;
int hole;
};

int is_ball_on_board ( int i )
{
if ( Arr[i].radius < 0 )
	return 0;
else
	return 1;
}

double pos = 0.7;
double hole_arr0[4][2] = { { - 0.89, 0.89 }, { 0.89, 0.89 }, { 0.89, - 0.89 }, { - 0.89, - 0.89 } }; 
double hole_arr1[4][2] = { { 0.89, 0.89 }, { 0.89, - 0.89 }, { - 0.89, - 0.89 }, { - 0.89, 0.89 } }; 
double hole_arr2[4][2] = { { 0.89, - 0.89 }, { - 0.89, - 0.89 }, { - 0.89, 0.89 }, { 0.89, 0.89 } }; 
double hole_arr3[4][2] = { { - 0.89, - 0.89 }, { - 0.89, 0.89 }, { 0.89, 0.89 }, { 0.89, - 0.89 } }; 
double valid_len = 0.6;

sh_para check_for_headshot( int i )
{
sh_para fail;
fail.ini_x = -2.0;
fail.ini_y = -2.0;
fail.fin_x = -2.0;
fail.fin_y = -2.0;
double x2 = Arr[i].x;
double y2 = Arr[i].y;
//////////////////////////////////////////////////////////////////////
if ( turn == 0 )
{
if ( ( ( - pos - 0.09 ) <= y2 ) &&  ( y2<= ( - pos + 0.09 ) ) ) //pos - 0.09 <= y2 <= pos + 0.09//-pos - 0.09 <= x2 <= -pos + 0.09//pos - 0.09 <= x2 <= pos + 0.09
	return fail;
int j = 0;
for ( j; j<4; j++ )
	{
	double y1 = hole_arr0[j][1];          //   hole_arr2    //  hole_arr1 // hole_arr3
	if  ( ( y2 + pos ) * ( y1 ) < 0 )    //   ( y2 - pos ) * ( - y1 ) < 0   //  ( x2 + pos ) * x1 < 0 //  ( x2 - pos ) * ( x1 ) < 0
		continue; 
	double x1 = hole_arr0[j][0];          //   hole_arr2    // hole_arr1  // hole_arr3
	double x = x2 + ( - pos - y2 ) * ( x2 - x1 ) / ( y2 - y1 );//replace -pos by pos//y = y2 + ( y2 - y1 ) * ( - pos - x2 ) / ( x2 - x1 )//replace -pos by pos
	if (  ( x < valid_len ) && ( x > - valid_len ) )  // y in 1 and 3
		{
		int counter = 0;
		int k = 0;
		for ( k; k<N; k++ )
			{
			double x3 = Arr[k].x;
			double y3 = Arr[k].y;
			if ( ( is_ball_on_board(k) == 0 ) || ( k == i ) || ( ( y3 + pos ) * y1 < 0 ) )//replace pos by -pos//x3 + pos* x1 < 0//replace pos by -pos 
				{counter++; continue;}
			else
				{
				double temp1 = sqrt ( ( y2 - y1 ) * ( y2 - y1 ) + ( x2 - x1 ) * ( x2 - x1 ) );
				double temp2 = x3 * ( y2 - y1 ) - y3 * ( x2 - x1 ) + y1 * x2 - y2 * x1;
				double temp3 = abs ( temp2 ) / temp1;
				if ( temp3 >= 0.09 )
					{counter++; continue;}
				else
					break;
				}
			}
		if ( counter == N ) 
			{
			sh_para a;
			a.ini_x = x;			// a.ini_x = - pos;  // a.ini_x = pos
			a.ini_y = - pos;   //   pos   //  a.ini_y = y; // same
			a.fin_x = hole_arr0[j][0];  // hole_arr2   // hole_arr1 // hole_arr3
			a.fin_y = hole_arr0[j][1];  // hole_arr2   // hole_arr1  // hole_arr3
			a.hole = j;		
			return a;
			}
		}
	else
		continue;
	}
}
//////////////////////////////////////////////////////////////////////////////////
else if ( turn == 1 )
{
if ( ( ( - pos - 0.09 ) <= x2 ) &&  ( x2<= ( - pos + 0.09 ) ) ) //-pos - 0.09 <= x2 <= -pos + 0.09//pos - 0.09 <= x2 <= pos + 0.09
	return fail;
int j = 0;
for ( j; j<4; j++ )
	{
	double x1 = hole_arr1[j][0];          //   hole_arr2    //  hole_arr1 // hole_arr3
	if  ( ( x2 + pos ) * x1 < 0 )    //   ( y2 - pos ) * ( - y1 ) < 0   //  ( x2 + pos ) * x1 < 0 //  ( x2 - pos ) * ( x1 ) < 0
		continue; 
	double y1 = hole_arr1[j][1];          //   hole_arr2    // hole_arr1  // hole_arr3
	double y = y2 + ( - pos - x2 ) * ( y2 - y1 ) / ( x2 - x1 );//replace -pos by pos//y = y2 + ( y2 - y1 ) * ( - pos - x2 ) / ( x2 - x1 )//replace -pos by pos
	if (  ( y < valid_len ) && ( y > - valid_len ) )  // y in 1 and 3
		{
		int counter = 0;
		int k = 0;
		for ( k; k<N; k++ )
			{
			double x3 = Arr[k].x;
			double y3 = Arr[k].y;
			if ( ( is_ball_on_board(k) == 0 ) || ( k == i ) || ( ( x3 + pos ) * x1 < 0 ) )//replace pos by -pos//x3 + pos* x1 < 0//replace pos by -pos 
				{counter++; continue;}
			else
				{
				double temp1 = sqrt ( ( y2 - y1 ) * ( y2 - y1 ) + ( x2 - x1 ) * ( x2 - x1 ) );
				double temp2 = x3 * ( y2 - y1 ) - y3 * ( x2 - x1 ) + y1 * x2 - y2 * x1;
				double temp3 = abs ( temp2 ) / temp1;
				if ( temp3 >= 0.09 )
					{counter++; continue;}
				else
					break;
				}
			}
		if ( counter == N ) 
			{
			sh_para a;
			a.ini_x = - pos;			// a.ini_x = - pos;  // a.ini_x = pos
			a.ini_y = y;   //   pos   //  a.ini_y = y; // same
			a.fin_x = hole_arr1[j][0];  // hole_arr2   // hole_arr1 // hole_arr3
			a.fin_y = hole_arr1[j][1];  // hole_arr2   // hole_arr1  // hole_arr3
			a.hole = j;					
			return a;
			}
		}
	else
		continue;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
else if ( turn == 2 )
{
if ( ( ( pos - 0.09 ) <= y2 ) &&  ( y2<= ( pos + 0.09 ) ) ) 
	return fail;
int j = 0;
for ( j; j<4; j++ )
	{
	double y1 = hole_arr2[j][1];          //   hole_arr2    //  hole_arr1 // hole_arr3
	if  ( - ( y2 - pos ) * ( - y1 ) < 0 )    //   ( y2 - pos ) * ( - y1 ) < 0   //  ( x2 + pos ) * x1 < 0 //  ( x2 - pos ) * ( x1 ) < 0
		continue; 
	double x1 = hole_arr2[j][0];          //   hole_arr2    // hole_arr1  // hole_arr3
	double x = x2 + ( pos - y2 ) * ( x2 - x1 ) / ( y2 - y1 );//replace -pos by pos//y = y2 + ( y2 - y1 ) * ( - pos - x2 ) / ( x2 - x1 )//replace -pos by pos
//	printf("j : %d    x : %f\n", j, x );
	if (  ( x < valid_len ) && ( x > - valid_len ) )  // y in 1 and 3
		{
		int counter = 0;
		int k = 0;
		for ( k; k<N; k++ )
			{
			double x3 = Arr[k].x;
			double y3 = Arr[k].y;
			if ( ( is_ball_on_board(k) == 0 ) || ( k == i ) || ( ( y3 - pos ) * y1 < 0 ) )//replace pos by -pos//x3 + pos* x1 < 0//replace pos by -pos 
				{counter++; continue;}
			else
				{
				double temp1 = sqrt ( ( y2 - y1 ) * ( y2 - y1 ) + ( x2 - x1 ) * ( x2 - x1 ) );
				double temp2 = x3 * ( y2 - y1 ) - y3 * ( x2 - x1 ) + y1 * x2 - y2 * x1;
				double temp3 = abs ( temp2 ) / temp1;
				if ( temp3 >= 0.09 )
					{counter++; continue;}
				else
					break;
				}
			}
		if ( counter == N ) 
			{
			sh_para a;
			a.ini_x = x;			// a.ini_x = - pos;  // a.ini_x = pos
			a.ini_y = pos;   //   pos   //  a.ini_y = y; // same
			a.fin_x = hole_arr2[j][0];  // hole_arr2   // hole_arr1 // hole_arr3
			a.fin_y = hole_arr2[j][1];  // hole_arr2   // hole_arr1  // hole_arr3
			a.hole = j;		
			return a;
			}
		}
	else
		continue;
	}
}
/////////////////////////////////////////////////////////////////////////////////
else if ( turn == 3 )
{
if ( ( ( pos - 0.09 ) <= x2 ) &&  ( x2<= ( pos + 0.09 ) ) ) //pos - 0.09 <= y2 <= pos + 0.09//-pos - 0.09 <= x2 <= -pos + 0.09//pos - 0.09 <= x2 <= pos + 0.09
	return fail;
int j = 0;
for ( j; j<4; j++ )
	{
	double x1 = hole_arr3[j][0];          //   hole_arr2    //  hole_arr1 // hole_arr3
	if  ( ( x2 - pos ) * ( x1 ) < 0 )    //   ( y2 - pos ) * ( - y1 ) < 0   //  ( x2 + pos ) * x1 < 0 //  ( x2 - pos ) * ( x1 ) < 0
		continue; 
	double y1 = hole_arr3[j][1];          //   hole_arr2    // hole_arr1  // hole_arr3
	double y = y2 + ( pos - x2 ) * ( y2 - y1 ) / ( x2 - x1 );//replace -pos by pos//y = y2 + ( y2 - y1 ) * ( - pos - x2 ) / ( x2 - x1 )//replace -pos by pos
	if (  ( y < valid_len ) && ( y > - valid_len ) )  // y in 1 and 3
		{
		int counter = 0;
		int k = 0;
		for ( k; k<N; k++ )
			{
			double x3 = Arr[k].x;
			double y3 = Arr[k].y;
			if ( ( is_ball_on_board(k) == 0 ) || ( k == i ) || ( ( x3 - pos ) * x1 < 0 ) )//replace pos by -pos//x3 + pos* x1 < 0//replace pos by -pos 
				{counter++; continue;}
			else
				{
				double temp1 = sqrt ( ( y2 - y1 ) * ( y2 - y1 ) + ( x2 - x1 ) * ( x2 - x1 ) );
				double temp2 = x3 * ( y2 - y1 ) - y3 * ( x2 - x1 ) + y1 * x2 - y2 * x1;
				double temp3 = abs ( temp2 ) / temp1;
				if ( temp3 >= 0.09 )
					{counter++; continue;}
				else
					break;
				}
			}
		if ( counter == N ) 
			{
			sh_para a;
			a.ini_x = pos;			// a.ini_x = - pos;  // a.ini_x = pos
			a.ini_y = y;   //   pos   //  a.ini_y = y; // same
			a.fin_x = hole_arr3[j][0];  // hole_arr2   // hole_arr1 // hole_arr3
			a.fin_y = hole_arr3[j][1];  // hole_arr2   // hole_arr1  // hole_arr3
			a.hole = j;		
			return a;
			}
		}
	else
		continue;
	}
}


return fail;
}

sh_para check_for_cutshot( int i )
{
sh_para fail;
fail.ini_x = -2.0;
fail.ini_y = -2.0;
fail.fin_x = -2.0;
fail.fin_y = -2.0;
double x2 = Arr[i].x;
double y2 = Arr[i].y;
double x1;
double y1;
sh_para a;


if ( turn == 0 )
{
if ( ( x2 >= 0 ) && ( y2 > - pos + 0.09 ) )      
	{
	x1 = hole_arr0[1][0];
	y1 = hole_arr0[1][1];
	if ( ( -159.0 / 89.0 * x2 + y2 + pos ) >= 0 )
		a.ini_x = - valid_len;
	else
		a.ini_x = valid_len;
	a.hole = 1;
	}

else if ( x2 >=0 )
	{
	x1 = hole_arr0[2][0];
	y1 = hole_arr0[2][1];
	a.ini_x = - valid_len;
	a.hole = 2;
	}
else if ( ( x2 < 0 ) && ( y2 > - pos + 0.09 ) )
	{
	x1 = hole_arr0[0][0];
	y1 = hole_arr0[0][1];
	if ( ( 159.0 / 89.0 * x2 + y2 + pos ) >= 0 )
		a.ini_x = valid_len;
	else
		a.ini_x = - valid_len;
	a.hole = 0;
	}
else
	{
	x1 = hole_arr0[3][0];
	y1 = hole_arr0[3][1];
	a.ini_x = valid_len;
	a.hole = 3;
	}
double dis = sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) );
double d1 = Arr[i].radius + Arr[N].radius;
double x4 = ( x2 * ( dis + d1 ) - d1 * x1 ) / dis;
double y4 = ( y2 * ( dis + d1 ) - d1 * y1 ) / dis;
a.ini_y = - pos;
a.fin_x = x4;
a.fin_y = y4;



}
//////////////////////////////////////////////////////////////////////////
else if ( turn == 1 )
{
if ( ( y2 <= 0 ) && ( x2 + pos - 0.09 >= 0 ) )      
	{
	x1 = hole_arr1[1][0];
	y1 = hole_arr1[1][1];
	if ( ( 159.0 / 89.0 * y2 + x2 + pos ) >= 0 )
		a.ini_y = valid_len;
	else
		a.ini_y = - valid_len;
	a.hole = 1;
	}

else if ( y2 <= 0 )
	{
	x1 = hole_arr1[2][0];
	y1 = hole_arr1[2][1];
	a.ini_y = valid_len;
	a.hole = 2;
	}
else if ( ( y2 > 0 ) && ( x2 + pos - 0.09 >= 0 ) )
	{
	x1 = hole_arr1[0][0];
	y1 = hole_arr1[0][1];
	if ( ( - 159.0 / 89.0 * y2 + x2 + pos ) >= 0 )
		a.ini_y = - valid_len;
	else
		a.ini_y = valid_len;
	a.hole = 0;	
	}
else
	{
	x1 = hole_arr1[3][0];
	y1 = hole_arr1[3][1];
	a.ini_x = - valid_len;
	a.hole = 3;
	}
double dis = sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) );
double d1 = Arr[i].radius + Arr[N].radius;
double x4 = ( x2 * ( dis + d1 ) - d1 * x1 ) / dis;
double y4 = ( y2 * ( dis + d1 ) - d1 * y1 ) / dis;
a.ini_x = - pos;
a.fin_x = x4;
a.fin_y = y4;
}
//////////////////////////////////////////////////////////////////////////////////

else if ( turn == 2 )
{
if ( ( x2 <= 0 ) && ( y2 < pos - 0.09 ) )      
	{
	x1 = hole_arr2[1][0];
	y1 = hole_arr2[1][1];
	if ( ( 159.0 / 89.0 * x2 - y2 + pos ) >= 0 )
		a.ini_x = valid_len;
	else
		a.ini_x = - valid_len;
	a.hole = 1;
	}
else if ( x2 <=0 )
	{
	x1 = hole_arr2[2][0];
	y1 = hole_arr2[2][1];
	a.ini_x = valid_len;
	a.hole = 2;
	}
else if ( ( x2 > 0 ) && ( y2 < pos - 0.09 ) )
	{
	x1 = hole_arr2[0][0];
	y1 = hole_arr2[0][1];
	if ( ( - 159.0 / 89.0 * x2 - y2 + pos ) >= 0 )
		a.ini_x = - valid_len;
	else
		a.ini_x = valid_len;
	a.hole = 0;
	}
else
	{
	x1 = hole_arr2[3][0];
	y1 = hole_arr2[3][1];
	a.ini_x = - valid_len;
	a.hole = 3;
	}
double dis = sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) );
double d1 = Arr[i].radius + Arr[N].radius;
double x4 = ( x2 * ( dis + d1 ) - d1 * x1 ) / dis;
double y4 = ( y2 * ( dis + d1 ) - d1 * y1 ) / dis;
a.ini_y = pos;
a.fin_x = x4;
a.fin_y = y4;
}
else
{
if ( ( y2 >= 0 ) && ( x2 < pos - 0.09 ) )      
	{
	x1 = hole_arr3[1][0];
	y1 = hole_arr3[1][1];
	if ( ( -159.0 / 89.0 * y2 - x2 + pos ) >= 0 )
		a.ini_y = - valid_len;
	else
		a.ini_y = valid_len;
	a.hole = 1;
	}
else if ( y2 >=0 )
	{
	x1 = hole_arr3[2][0];
	y1 = hole_arr3[2][1];
	a.ini_y = - valid_len;
	a.hole = 2;
	}
else if ( ( y2 < 0 ) && ( x2 < pos - 0.09 ) )
	{
	x1 = hole_arr3[0][0];
	y1 = hole_arr3[0][1];
	if ( ( 159.0 / 89.0 * y2 - x2 + pos ) >= 0 )
		a.ini_y = valid_len;
	else
		a.ini_y = - valid_len;
	a.hole = 0;
	}
else
	{
	x1 = hole_arr3[3][0];
	y1 = hole_arr3[3][1];
	a.ini_y = valid_len;
	a.hole = 3;
	}
double dis = sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) );
double d1 = Arr[i].radius + Arr[N].radius;
double x4 = ( x2 * ( dis + d1 ) - d1 * x1 ) / dis;
double y4 = ( y2 * ( dis + d1 ) - d1 * y1 ) / dis;
a.ini_x = pos;
a.fin_x = x4;
a.fin_y = y4;
}
return a;
}

void shoot ( double a, double b, double c, double dd, int e )
{

double tan0 = abs ( ( b - dd ) / ( a - c ) );

double temp1 = 1.0 / sqrt ( 1.0 + tan0 * tan0 );
double temp2 = tan0 * temp1;
double cos0, sin0;
/*
double theta = abs (atan ( (b-dd) / (a-c) ));
cos0 = cos ( theta );
sin0 = sin ( theta );
*/

if ( c >= a )
	cos0 = temp1;
else	
	cos0 = -temp1;
if ( dd >= b )
	sin0 = temp2;
else
	sin0 = -temp2;
 
double d_factor;
if ( difficulty == 2 )
	d_factor = 1.0;
else if ( difficulty == 1)
	{
	srand(time(NULL));
	d_factor = 0.96 + 8.0 * ( rand()%100 ) / 10000; 
	}
else
	{
	srand(time(NULL));
	d_factor = 0.92 + 16.0 * ( rand()%100 ) / 10000; 
	} 

Arr[N].x = a;
Arr[N].y = b;


if ( e < 2 )
{
Arr[N].vx = 6 * aimlen * cos0 * d_factor;
Arr[N].vy = 6 * aimlen * sin0;
}
else
{
Arr[N].vx = 8 * aimlen_back * cos0 * d_factor;
Arr[N].vy = 8 * aimlen_back * sin0;
}
//printf("%f\n %f\n %f\n %f\n", a, b, c, d); 
}

int head_flag1 = 0;
int head_flag2 = 0;
void bot_job()
{
	Arr[N].radius=0.05;
	head_flag1 = 0;
	head_flag2 = 0;
	int i = 0;
	for (i; i<N; i++)
	{
		if ( is_ball_on_board(i) == 0 )
			continue;
		sh_para a = check_for_headshot(i);
		if ( a.ini_y != - 2.0 )
			{
			shoot( a.ini_x, a.ini_y, a.fin_x, a.fin_y, a.hole );
			head_flag1 = 1;
			break;
			}
	}
	if ( head_flag1 != 1 )
	{
		i = 0;
		for (i; i<N; i++)
		{
			if ( is_ball_on_board(i) == 0 )
				continue;
			sh_para b = check_for_cutshot(i);
			if ( b.ini_y != - 2.0)
				{			
				shoot ( b.ini_x, b.ini_y, b.fin_x, b.fin_y, b.hole );
				head_flag2 = 1;				
				break;			
				}		
			else
				continue;
		}
	}
	if ( head_flag1 !=1 && head_flag2 != 1 )
	{
		i = 0;	
		for ( i; i<N; i++ )
		{
			if ( is_ball_on_board(i) == 0 )
				continue;
			shoot ( 0, - pos, Arr[i].x, Arr[i].y, 0 );
			break;
		}
	}  
	if(network==1)
	{
		int n1=write(sockfd,&Arr[N],sizeof(Arr[N]));
		if(svr==1)
		{
			if(players==4)
			{
				n1=write(sockfd1,&Arr[N],sizeof(Arr[N]));
				n1=write(sockfd2,&Arr[N],sizeof(Arr[N]));
			}
		}
	}
	clickl=2;
}
