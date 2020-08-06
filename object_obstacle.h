#define LEFT_ARROW 75
#define RIGHT_ARROW 77
using namespace std;
int x_a=82,i=51,w=42;
void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
class obstacles
{
protected:
    int obs_1=0,obs_2=0,obs_3=0,cnt=0;
    char obs=223;
    bool crash=false;
    void walls()
    {
        for(int j=0;j<47;j++)
        {
            Sleep(20);
            gotoxy(70,j);
            cout<<"|                      |";
            gotoxy(82,42);
            cout<<"^";
        }
        char temp=getch();
    }
    void obstacle_1()
    {
        Sleep(10);
        gotoxy(70,obs_1);
        cout<<"|                      |";
        gotoxy(85,++obs_1);
        cout<<obs<<obs<<obs<<obs<<obs<<obs<<obs<<obs;
        gotoxy(71,47);
        cout<<"                      ";
        for(int k=85;k<=92;k++)
        {
            if(x_a==k && obs_1==42)
            {
                crash=true;         //Crash Detection
            }
        }
        i--;
    }
    void obstacle_2()
    {
        Sleep(10);
        gotoxy(70,obs_2);
        cout<<"|                      |";
        gotoxy(71,++obs_2);
        cout<<obs<<obs<<obs<<obs<<obs<<obs<<obs<<obs;
        gotoxy(71,47);
        cout<<"                      ";
        for(int l=71;l<=78;l++)
        {
            if(x_a==l && obs_2==42)
            {
                crash=true;         //Crash Detection
            }
        }
        i--;
    }
    void obstacle_3()
    {
        Sleep(10);
        gotoxy(70,obs_3);
        cout<<"|                      |";
        gotoxy(80,++obs_3);
        cout<<obs<<obs<<obs<<obs<<obs;
        gotoxy(71,47);
        cout<<"                      ";
        for(int m=80;m<=84;m++)
        {
            if(x_a==m && obs_3==42)
            {
                crash=true;         //Crash Detection
            }
        }
        i--;
    }
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class play: protected obstacles
{
public:
    int s1=0,s2=0,s3=0,score=0;
    char key;
    void run()
    {
        int &rs1=s1,&rs2=s2,&rs3=s3;
        rs1=0;
        rs2=0;
        rs3=0;
        system("cls");
        walls();
        while(crash!=true)
        {
            if(kbhit())
            {
                switch(key=getch())
                {
                    case LEFT_ARROW:
                    {
                        Sleep(5);
                        gotoxy(--x_a,42);
                        cout<<"^";
                        if((x_a==70 && w==42) || (x_a==93 && w==42))
                            crash=true;
                        break;
                    }
                    case RIGHT_ARROW:
                    {
                        Sleep(5);
                        gotoxy(++x_a,42);
                        cout<<" \b\b ^";
                        if((x_a==70 && w==42) || (x_a==93 && w==42))
                            crash=true;
                        break;
                    }
                }
            }
            if(i%2==0)
            {
                obstacle_1();
                gotoxy(x_a,42);
                cout<<"^^\b ";
            }
            if(i%3==0)
            {
                obstacle_2();
                gotoxy(x_a,42);
                cout<<"^^\b ";
            }
            if(i%5==0)
            {
                obstacle_3();
                gotoxy(x_a,42);
                cout<<"^^\b ";
            }
            i--;
            if(i==0)
            {
                i=51;
            }
            if(obs_1==47)
            {
                gotoxy(71,47);
                cout<<"                      ";
                obs_1=0;
                rs1++;
            }
            if(obs_2==47)
            {
                gotoxy(71,47);
                cout<<"                      ";
                obs_2=0;
                rs2++;
            }
            if(obs_3==47)
            {
                gotoxy(71,47);
                cout<<"                      ";
                obs_3=0;
                rs3++;
            }
        }
        crash=false;
        game_over();
    }
    void game_over()
    {
        getch();
        getch();
        system("cls");
                Sleep(200);
                gotoxy(82,25);
                cout<<"Game Over!!!"<<endl<<endl;
                score=s1+s2+s3;
                Sleep(200);
                gotoxy(82,26);
                cout<<"Score= "<<score<<endl;
                Sleep(200);
                gotoxy(82,27);
                cout<<"THANK YOU!!!!";
        string tryo="Wanna try again(y/n): ";
        gotoxy(82,29);
        for(int m=0;m<22;m++)
        {
            Sleep(10);
            cout<<tryo[m];
        }
        char try_again;
        cin>>try_again;
        if(try_again=='y')
        {
            x_a=82;
            obs_1=0;
            obs_2=0;
            obs_3=0;
            run();
        }
    }
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
void mainmain2()
{
    play p;
    //system("mode 300");
    system("color 0E");
    int z;
    gotoxy(60,17);
    string welcome="Welcome!!!! Let's get ready to roll.........";
    for(z=0;z<welcome.length();z++)
    {
        cout<<welcome[z];
        Sleep(20);
    }
    welcome="+ Here you have to dodge the obstacles that come under your way........";
    gotoxy(60,19);
    for(z=0;z<welcome.length();z++)
    {
        cout<<welcome[z];
        Sleep(20);
    }
    welcome="+ Use left and right arrow keys to move your object";
    gotoxy(60,21);
    for(z=0;z<welcome.length();z++)
    {
        cout<<welcome[z];
        Sleep(20);
    }
    welcome="+ And don't try to go out of the track you will regret it........";
    gotoxy(60,23);
    for(z=0;z<welcome.length();z++)
    {
        cout<<welcome[z];
        Sleep(20);
    }
    welcome="+ Now then, let's get started......... ";
    gotoxy(60,25);
    for(z=0;z<welcome.length();z++)
    {
        cout<<welcome[z];
        Sleep(20);
    }
    gotoxy(60,27);
    system("pause");
    p.run();
}
