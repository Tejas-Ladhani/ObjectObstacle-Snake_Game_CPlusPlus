using namespace std;
class snake{
private:
        bool gameOver;
        const int width=20;
        const int height=20;
        int x,y;    //for head positions
        int fruitx,fruity;      //for fruit positions
        int score;
        int tailx[100],taily[100];
        int ntail;// to specify the length of the tail
        enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
        eDirection dir;
public:
        snake()
        {   x=y=0;
            fruitx=fruity=0;
            score=0;
            tailx[100]={0};
            taily[100]={0};
            ntail=0;
            gameOver=0;
        }

        void setup()
        {
            gameOver=false;
            dir=STOP;   //so that snake will not move until we press the key
            x=width/2;
            y=height/2;     //so the initial position of the snake starts from the center
            fruitx=rand()%width+1;
            fruity=rand()%height+1;
            score=0;
        }

        void draw()
        {

            for(int i=20;i<width+22;i++)
                {gotoxy(i,0);
                cout<<"\xB2";}

            static int rj;
            for(int i=1;i<height+1;i++)
            {
                    gotoxy(rj,i);
                    cout<<" ";
                for(int j=0;j<width;j++)
                {
                            rj=j;
                            if(j==0)
                            cout<<"\xB2";
                            if(i==y&&j==x)
                                    cout<<"O";
                            else if(i==fruity && j==fruitx)
                                    cout<<"\xE0";
                            else
                            {    bool print=false;
                                for(int k=0;k<ntail;k++)
                                {
                                    if(tailx[k] ==j && taily[k]==i)
                                    {
                                        cout<<"o";print=true;
                                    }
                                }
                                if(!print)
                                cout<<" ";
                            }
                    if(j==width-1)
                    cout<<"\xB2";
                }
                cout<<endl;
            }
                for(int i=20;i<width+22;i++)
                {gotoxy(i,height);
                    cout<<"\xB2";}

                gotoxy(20,height+1);
                cout<<"score :"<<score<<endl;
        }

        void input()
        {

            if(_kbhit()) // it will return non zero number if key on keyboard is pressed
            {

                    switch(_getch()) // _getch() will return the ASCII value of the character pressed.
                     {
                     case 75:
                                dir=LEFT;
                                break;
                     case 77:
                                dir=RIGHT;
                                break;
                    case 72:
                                dir=UP;
                                break;
                    case 80:
                                dir=DOWN;
                                break;
                    case 27:
                        gameOver=true;
                        break;
                    }
            }                   //otherwise it will return 0
}

        void logic()
        {
            int prevX=tailx[0];
            int prevY=taily[0];
            int prev2x,prev2y;
            tailx[0]=x;
            taily[0]=y;
            for(int i=1;i<ntail;i++)    //cz we already have head
            {
                prev2x=tailx[i];
                prev2y=taily[i];
                tailx[i]=prevX;
                taily[i]=prevY;
                prevX=prev2x;
                prevY=prev2y;
            }

            switch(dir)
            {

            case LEFT:
                    x--;
                    break;
            case RIGHT:
                        x++;
                        break;
            case UP:
                    y--;
                    break;
            case DOWN:
                    y++;
                    break;
            default:
                    break;
        }
        //if the head touches the boundary game over
        if((x>width-1|| x<0) ||(y>height-1||y<1))
            gameOver=true;
            //if head touches its body then game over.
            for(int i=0;i<ntail;i++)
            {
                if(tailx[i]==x&&taily[i]==y)
                    gameOver=true;
            }
        if(x==fruitx && y==fruity)
        {

            score+=10;
             fruitx=rand()%width+1;
            fruity=rand()%height+1;
            ntail++;
        }
        }

        void play()
        {

            setup();

            while(!gameOver)
            {
                draw();
               Sleep(100);
              if(dir==UP || dir==DOWN)
                {
                    Sleep(10);
                }
                input();
                logic();
            }
                isgameover();


        }

            void isgameover()
            {
                if(gameOver==true)
                {
                    system("cls");
                    gotoxy(40,15);
                    cout<<"Game over !!";
                    gotoxy(40,16);
                    cout<<"---------------";
                    gotoxy(40,17);
                    cout<<"Your Score :"<<score;
                    gotoxy(40,18);
                    cout<<"---------------";
                    //getch();
                    replay();
            }
        }


        void instruction()
        {
            system("color 0E");
            gotoxy(5,10);
            string str="\n+ Four Arrow-keys : to navigate the snake.\n+ Increase your score(by 10) by feeding the snake.\n+ Don't bang the  snake into the wall OR into its own body.\n+ Press ESC to exit.  ";
            for(int i=0,j=10;i<str.length();i++)
            {
                cout<<str[i];
                if(str[i]=='\n')
                {
                    gotoxy(5,j);
                    j++;
                }
                Sleep(50);
            }
            cout<<endl;
            gotoxy(7,16);
            cout<<"Loading";
            cout<<".";
            Sleep(100);
            cout<<".";
            Sleep(100);
            cout<<".";
            Sleep(100);

            for(int i=0;i<10;i++)
            {
                gotoxy(15,16);
                loading();
            }

            gotoxy(7,20);
            cout<<endl<<"Press any key to continue...";
            getch();
            system("color E0");
    }

        void loading()
        {
             gotoxy(15,16);   cout<<"            ";
            gotoxy(15,16);    cout<<".";
            Sleep(200);         cout<<".";
            Sleep(200);         cout<<".";
            Sleep(200);
        }

        void replay()
        {
            char ch;
            gotoxy(40,19);
            cout<<"Want to play Again(y/n) ? ";
           // getch();
            cin>>ch;
                if(ch=='y'||ch=='Y')
                   {
                       system("cls");
                        ntail=0;
                        score=0;
                        x=width/2;
                        y=height/2;
                        play();
                   }
        }
//END OF THE CLASS
};


void mainmain1()
{


    system("cls");
    snake s;
    s.instruction();
    system("cls");
    s.play();
}
