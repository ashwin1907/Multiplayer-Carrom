void update_all()
{			//Updates score at each turn
int j = 0;
int score0,score1, score2, score3;
score0 = score1 = score2 = score3 = 0;
for ( j; j<=N; j++)
	{
	score0 += Status0[j];
	score1 += Status1[j];
	score2 += Status2[j];
	score3 += Status3[j];
	}
char Score0[4], Score1[4], Score2[4], Score3[4];
sprintf ( Score0, "%d", score0 );
sprintf ( Score1, "%d", score1 );
sprintf ( Score2, "%d", score2 );
sprintf ( Score3, "%d", score3 );
if ( players == 2 )
	{
	scor_e[0]->set_text( Score0 );
	scor_e[2]->set_text( Score2 );
	}
if ( players == 4 )
	{
	scor_e[0]->set_text( Score0 );
	scor_e[1]->set_text( Score1 );
	scor_e[2]->set_text( Score2 );
	scor_e[3]->set_text( Score3 );			
	}
}

int is_bot = 0;
char server_name[20];
char my_name[20] = "UnNamed";
char port_no[10];

void update_scores()
{			//Updates score at each turn
int j = 0;
int score0,score1, score2, score3;
score0 = score1 = score2 = score3 = 0;
for ( j; j<=N; j++)
	{
	score0 += Status0[j];
	score1 += Status1[j];
	score2 += Status2[j];
	score3 += Status3[j];
	}
char Score0[4], Score1[4], Score2[4], Score3[4];
sprintf ( Score0, "%d", score0 );
sprintf ( Score1, "%d", score1 );
sprintf ( Score2, "%d", score2 );
sprintf ( Score3, "%d", score3 );
if ( players == 2 )
	{
	scor_e[0]->set_text( Score0 );
	scor_e[2]->set_text( Score2 );
	}
if ( players == 4 )
	{
	scor_e[0]->set_text( Score0 );
	scor_e[1]->set_text( Score1 );
	scor_e[2]->set_text( Score2 );
	scor_e[3]->set_text( Score3 );			
	}
}

void end()
{			//Displayes all the scores and name of the winner at the end of the game
glui->close();
glui = GLUI_Master.create_glui("Game Over", 0, 0, 0);
glui->add_statictext("SCORE COMPARISION");
int score0,score1, score2, score3;
score0 = score1 = score2 = score3 = 0;
int j = 0;
for ( j; j<=N; j++)
	{
	score0 += Status0[j];
	score1 += Status1[j];
	score2 += Status2[j];
	score3 += Status3[j];
	}
char Score0[4], Score1[4], Score2[4], Score3[4];
sprintf ( Score0, "%d", score0 );
sprintf ( Score1, "%d", score1 );
sprintf ( Score2, "%d", score2 );
sprintf ( Score3, "%d", score3 );
GLUI_Panel *panel = glui->add_panel( "Scoreboard" );
if (players == 2)
	{
	if ( score0 >= score2 )
		{
		glui->add_statictext_to_panel( panel, names.player_name0);	
		glui->add_statictext_to_panel( panel, names.player_name1);
		glui->add_column_to_panel(panel, true);
		glui->add_statictext_to_panel( panel, Score0 );
		glui->add_statictext_to_panel( panel, Score2 );	
		glui->add_statictext(" The WINNER is player 1:" );
		glui->add_statictext(names.player_name0 );
		}	
	else
		{
		glui->add_statictext_to_panel( panel, names.player_name1);	
		glui->add_statictext_to_panel( panel, names.player_name0);
		glui->add_column_to_panel(panel, true);
		glui->add_statictext_to_panel( panel, Score2  );
		glui->add_statictext_to_panel( panel, Score0 );	
		glui->add_statictext(" The WINNER is player 2:" );
		glui->add_statictext(names.player_name1 );
		}
	}
else
	{
	int score_max = max ( score0, max ( score1, max ( score2, score3 ) ) );
//	int score_min = min ( score0, min ( score1, min ( score2, score3 ) ) );
	if ( score_max = score0 )
		{
		glui->add_statictext_to_panel( panel, " The WINNER is player 1:" );
		glui->add_statictext_to_panel( panel, names.player_name0 );
		glui->add_statictext_to_panel( panel, " with points :");
		glui->add_statictext_to_panel( panel, Score0);		
		}
	else if ( score_max = score1 )
		{
		glui->add_statictext_to_panel( panel, " The WINNER is player 2:" );
		glui->add_statictext_to_panel( panel, names.player_name1 );
		glui->add_statictext_to_panel( panel, " with points :");
		glui->add_statictext_to_panel( panel, Score1);	
		}
	else if ( score_max = score2 )
		{
		glui->add_statictext_to_panel( panel, " The WINNER is player 3:" );
		glui->add_statictext_to_panel( panel, names.player_name2 );
		glui->add_statictext_to_panel( panel, " with points :");
		glui->add_statictext_to_panel( panel, Score2);	
		}
	else
		{
		glui->add_statictext_to_panel( panel, " The WINNER is player 4:" );
		glui->add_statictext_to_panel( panel, names.player_name3 );
		glui->add_statictext_to_panel( panel, " with points :");
		glui->add_statictext_to_panel( panel, Score3);	
		}
	}
}

void error()
{			//Prints error
printf("An unexpected error occured");
}

void func1( int a)
{
glui2->close();
glui->enable();
}

void rules1( int a )
{			//Includes rules defining the GLUI window
glui->disable();
int  Xpos = glutGet((GLenum)GLUT_WINDOW_X);
int  Ypos = glutGet((GLenum)GLUT_WINDOW_Y);
int  Xsize = glutGet((GLenum)GLUT_WINDOW_WIDTH);
int  Ysize = glutGet((GLenum)GLUT_WINDOW_HEIGHT);
glui2 = GLUI_Master.create_glui("Rules", 0, Xpos + Xsize, Ypos - 30); 
glui2->add_statictext( "WELCOME TO COMPUTER GAMES" );
glui2->add_statictext( "RULES" );
glui2->add_statictext( "1 : This carrom game is a variant of the standard Carrom, called Point Carrom." );
glui2->add_statictext( "2 : Players can pocket coins of any color." ); 
glui2->add_statictext( "3 : Black coins are of 10 points, white of 20 points and the queen of 50 points." );
glui2->add_statictext( "3 : Player gets an extra turn if he pockets a coin." );
glui2->add_statictext( "4 : In order to claim the queen (if pocketed), there must be another coin pocketed either along" ); 
glui2->add_statictext( "    with it, or immediately after it. Otherwise, the queen is placed at the center of the board.");
glui2->add_statictext( "5 : If the striker goes into a pocket, it is considered as a foul." );
glui2->add_statictext( "6 : In case of a foul, player is required to place a minimum point coin (whatever he has) at the" );
glui2->add_statictext( "    center of the board.");
glui2->add_statictext( "7 : In case he has no coin, he gets a debt of -10 points and has to pay it as soon as he pockets a coin." );
glui2->add_statictext( "8 : If the striker goes into a pocket along with other coins, player keeps the coins, and it is dealt as" );
glui2->add_statictext( "    a normal foul with usual penalty. However, the player does not get an extra turn as credit for");
glui2->add_statictext( "    for pocketing coins in this case.");
glui2->add_statictext( "9: If there are only 2 coins left on the board, a queen and another coin, and if player pockets" );
glui2->add_statictext( "    the coin other than the queen, it is considered as a foul." );
glui2->add_statictext( "10: The player having maximum points at the end of the game wins." );
glui2->add_button( "Close" , 0, func1 );
}

void idle(int a)
{}

void proceed2(int a)
{		//Opens socket, listens to a port or connects to a port, assigns turns and defines openGL functions
		strcpy(names.player_name0,my_name);
glui->close();
glui = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_RIGHT );
glui->add_statictext( "WELCOME TO COMPUTER GAMES" );
glui->add_statictext( "SCOREBOARD" );
glui->add_separator();

if ( network == 0 )
{
	myturn=0;
	svr=1;
	players = players * 2 + 2;
	flag10 = 1;
}
else
{
players = players * 2 + 2;
if ( svr == 0)
{
	svr=1;
	myturn=0;
	int newsockfd;
	int portno = atoi(port_no);
	socklen_t clilen;
	bot = is_bot;
	struct sockaddr_in serv_addr, cli_addr;
	newsockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (newsockfd < 0) 
		error("ERROR opening socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(newsockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
		error("ERROR on binding");
	listen(newsockfd,5);
	clilen = sizeof(cli_addr);
	
	sockfd = accept(newsockfd, (struct sockaddr *) &cli_addr,&clilen);
	if (sockfd < 0) 
		error("ERROR on accept");
	if(players==4)
		{
		sockfd1 = accept(newsockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (sockfd1 < 0) 
    			error("ERROR on accept");
		sockfd2 = accept(newsockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (sockfd1 < 0) 
     		   	error("ERROR on accept");
		}
	tur.p=players;
	char temp_name[20];
	if(players==2)
		{
		tur.m=2;
		int n1=write(sockfd,&tur,sizeof(tur));
		n1=read(sockfd,temp_name,20*sizeof(char));
		strcpy(names.player_name1,temp_name);
		n1=write(sockfd,&names,sizeof(names));
		}
	else if(players==4)
		{
		tur.m=1;
		int n1=write(sockfd,&tur,sizeof(tur));
		tur.m=2;
		n1=write(sockfd1,&tur,sizeof(tur));
		tur.m=3;
		n1=write(sockfd2,&tur,sizeof(tur));
		n1=read(sockfd,temp_name,20*sizeof(char));
		strcpy(names.player_name1,temp_name);
		n1=read(sockfd1,temp_name,20*sizeof(char));
		strcpy(names.player_name2,temp_name);
		n1=read(sockfd2,temp_name,20*sizeof(char));
		strcpy(names.player_name3,temp_name);
		n1=write(sockfd,&names,sizeof(names));
		n1=write(sockfd1,&names,sizeof(names));
		n1=write(sockfd2,&names,sizeof(names));
		}
	flag10=1;
}
else
{
	svr=0;
	char sname[20];
	strcpy (sname, server_name);
	int portno = atoi(port_no); 
	bot = is_bot;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
		error("ERROR opening socket");
	server = gethostbyname(sname);
	if (server == NULL)
	{
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
		error("ERROR connecting");
	int n1=read(sockfd,&tur,3*sizeof(tur));
	players=tur.p;
	myturn=tur.m;
	n1=write(sockfd,my_name,20*sizeof(char));
	n1=read(sockfd,&names,sizeof(names));
	flag10=1;
}
}
if (players == 4)
{
GLUI_Panel *panel = glui->add_panel( "Scoreboard" );
glui->add_statictext_to_panel(panel, names.player_name0);
if ( network == 1 )
{
glui->add_statictext_to_panel(panel, names.player_name1);
glui->add_statictext_to_panel(panel, names.player_name2);
glui->add_statictext_to_panel(panel, names.player_name3);
}
else
{
glui->add_statictext_to_panel(panel, "Bot 1");
glui->add_statictext_to_panel(panel, "Bot 2");
glui->add_statictext_to_panel(panel, "Bot 3");
}
glui->add_column_to_panel(panel, true);
scor_e[0] = glui->add_statictext_to_panel(panel, "0");
scor_e[1] = glui->add_statictext_to_panel(panel, "0");
scor_e[2] = glui->add_statictext_to_panel(panel, "0");
scor_e[3] = glui->add_statictext_to_panel(panel, "0");
}
else
{
GLUI_Panel *panel = glui->add_panel( "Scoreboard" );
glui->add_statictext_to_panel(panel, names.player_name0);
if ( network == 1 )
{
glui->add_statictext_to_panel(panel, names.player_name1);
}
else
{
glui->add_statictext_to_panel(panel, "Bot 1");
}
glui->add_column_to_panel(panel, true);
scor_e[0] = glui->add_statictext_to_panel(panel, "0");
scor_e[2] = glui->add_statictext_to_panel(panel, "0");
}
glui->add_separator();
flag_display = 1;
}

void proceed1(int a)
{			//Draws glui screen and takes input form user
glui->close();
if( network == 0 )
{ 	
	glui = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_RIGHT );
	glui->add_statictext( "WELCOME TO COMPUTER GAMES" );
	glui->add_statictext( "CARROM 3.0" );		
	glui->add_separator();
	glui->add_edittext( "Enter Name", GLUI_EDITTEXT_TEXT, my_name, 3, idle );
	glui->add_button( "Start" , 0, proceed2 );
	glui->add_button( "Rules", 1, rules1);
	glui->add_button( "Back", 2, proceed);
	glui->add_button( "Quit", 0, (GLUI_Update_CB)exit );
	glui->add_separator();
}
else if( svr == 0 )
{ 	
	glui = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_RIGHT );
	glui->add_statictext( "WELCOME TO COMPUTER GAMES" );
	glui->add_statictext( "CARROM 3.0" );		
	glui->add_separator();
	GLUI_Listbox *list = glui->add_listbox( "No of Players", &players, 2, idle );
	list->add_item( 0, "2" );
	list->add_item( 1, "4" );
	glui->add_edittext( "Enter Name", GLUI_EDITTEXT_TEXT, my_name, 3, idle );
	glui->add_edittext( "Port Number", GLUI_EDITTEXT_TEXT, port_no, 3, idle );
	GLUI_Panel *obj_panel = glui->add_panel ( "Play Mode" );
	GLUI_RadioGroup *group = glui->add_radiogroup_to_panel( obj_panel, &is_bot, 4, idle );
	glui->add_radiobutton_to_group( group, "Play as Human" );
	glui->add_radiobutton_to_group( group, "Play as Bot" );
	GLUI_Listbox *list2 = glui->add_listbox( "Choose Difficulty Level", &difficulty, 2, idle );
	list2->add_item( 0, "Easy" );
	list2->add_item( 1, "Medium" );
	list2->add_item( 2, "Hard" );	
	glui->add_button( "Create Server" , 0, proceed2 );
	glui->add_button( "Rules", 1, rules1);
	glui->add_button( "Back", 2, proceed);
	glui->add_button( "Quit", 0, (GLUI_Update_CB)exit );
	glui->add_separator();
}
else if( svr == 1 )  
{
	glui = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_RIGHT );
	glui->add_statictext( "WELCOME TO COMPUTER GAMES" );
	glui->add_statictext( "CARROM 3.0" );	
	glui->add_separator();
	glui->add_edittext( "Enter Name", GLUI_EDITTEXT_TEXT, my_name, 3, idle );
	glui->add_edittext( "Server Name", GLUI_EDITTEXT_TEXT, server_name, 3, idle );	
	glui->add_edittext( "Port Number", GLUI_EDITTEXT_TEXT, port_no, 3, idle );
	GLUI_Panel *obj_panel = glui->add_panel ( "Play Mode" );
	GLUI_RadioGroup *group = glui->add_radiogroup_to_panel( obj_panel, &is_bot, 4, idle );
	glui->add_radiobutton_to_group( group, "Play as Human" );
	glui->add_radiobutton_to_group( group, "Play as Bot" );	
	GLUI_Listbox *list2 = glui->add_listbox( "Choose Difficulty Level", &difficulty, 2, idle );
	list2->add_item( 0, "Easy" );
	list2->add_item( 1, "Medium" );
	list2->add_item( 2, "Hard" );
	glui->add_button( "Join Server" , 0, proceed2 );
	glui->add_button( "Rules", 1, rules1);
	glui->add_button( "Back", 2, proceed);
	glui->add_button( "Quit", 0, (GLUI_Update_CB)exit );
	glui->add_separator();
}
else
	error();
}

void proceed(int a)
{			//Draws glui screen and takes input form user
glui->close();
if( network == 0 )
{ 	
	glui = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_RIGHT );
	glui->add_statictext( "WELCOME TO COMPUTER GAMES" );
	glui->add_statictext( "CARROM 3.0" );		
	glui->add_separator();
	GLUI_Panel *obj_panel = glui->add_panel ( "Game Options" );
	glui->add_statictext( "You will be playing against computer" );
	GLUI_Listbox *list1 = glui->add_listbox( "No of Bots", &players, 2, idle );
	list1->add_item( 0, "1" );
	list1->add_item( 1, "3" );
	GLUI_Listbox *list2 = glui->add_listbox( "Choose Difficulty Level", &difficulty, 2, idle );
	list2->add_item( 0, "Easy" );
	list2->add_item( 1, "Medium" );
	list2->add_item( 2, "Hard" );
	glui->add_button( "Proceed" , 0, proceed1 );
	glui->add_button( "Rules", 1, rules1);
	glui->add_button( "Back", 2, initial);
	glui->add_button( "Quit", 0, (GLUI_Update_CB)exit );
	glui->add_separator();
}
else if( network == 1 )
{
	glui = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_RIGHT );
	glui->add_statictext( "WELCOME TO COMPUTER GAMES" );
	glui->add_statictext( "CARROM 3.0" );	
	glui->add_separator();
	GLUI_Panel *obj_panel = glui->add_panel ( "Game Options" );
	GLUI_RadioGroup *group = glui->add_radiogroup_to_panel( obj_panel, &svr, 1, idle );
	glui->add_radiobutton_to_group( group, "Create Server" );
	glui->add_radiobutton_to_group( group, "Join Server" );
	glui->add_button( "Proceed" , 0, proceed1 );
	glui->add_button( "Rules", 1, rules1);
	glui->add_button( "Back", 2, initial);
	glui->add_button( "Quit", 0, (GLUI_Update_CB)exit );
	glui->add_separator();
}
else
	error();
}

void initial(int a)
{				//Displays opening glui screen
glui->close();
glui = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_RIGHT );
glui->add_statictext( "WELCOME TO COMPUTER GAMES" );
glui->add_statictext( "CARROM 3.0" );
glui->add_separator();
GLUI_Panel *obj_panel = glui->add_panel ( "Game Mode" );
GLUI_RadioGroup *group1 = glui->add_radiogroup_to_panel( obj_panel, &network, 1, idle );
glui->add_radiobutton_to_group( group1, "Play Locally" );
glui->add_radiobutton_to_group( group1, "Play On Network" );
glui->add_button( "Proceed" , 0, proceed );
glui->add_button( "Rules", 1, rules1);
glui->add_button( "Quit", 0, (GLUI_Update_CB)exit );
glui->add_statictext( "Developed by:" );
glui->add_statictext( "Mayank Srivastava and Ashwin Kumar" );
glui->add_separator();
glui->set_main_gfx_window( main_window );
}
