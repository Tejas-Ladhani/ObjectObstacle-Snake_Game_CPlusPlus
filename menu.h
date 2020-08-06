#include"object_obstacle.h"
#include"snake_game.h"
using namespace std;
class meno
{
    public:
            int slt;
            void table()
            {   system("color 4E");
                gotoxy(72,19);
                cout<<"***********************************************";
                for(int i=20;i<=32;i++)
                {
                        gotoxy(72,i);
                        cout<<"*                                             *";
                }
                gotoxy(72,33);
                cout<<"***********************************************";
                menu();
            }

            void menu()
            {
                string game_play="Which game do you want to play............";
                gotoxy(74,21);
                for(int temp=0;temp<game_play.length();temp++)
                {
                    cout<<game_play[temp];
                    Sleep(20);
                }
                Sleep(100);
                gotoxy(80,23);
                cout<<"1. The Snake Game";
                Sleep(100);
                gotoxy(80,25);
                cout<<"2. Dodge King";
                Sleep(100);
                gotoxy(80,27);
                cout<<"3. Back to Main Menu";
                Sleep(100);
                gotoxy(80,29);
                cout<<"4. Exit from the program";
                Sleep(100);
                gotoxy(80,31);
                cout<<"Choose: ";
                cin>>slt;
                select_game();
            }

                void select_game()
                {
                    switch(slt)
                    {
                        case 1:
                        {
                            system("cls");
                            mainmain1();
                            system("cls");
                            break;
                        }
                        case 2:
                        {
                            system("cls");
                            mainmain2();
                            system("cls");
                            break;
                        }
                        case 3:
                        {
                            break;
                        }
                        case 4:
                        {
                            exit(0);
                        }
                    }
                        if(slt!=3)
                        table();
                }
            };

        int mainmain3()
        {
            system("cls");
            meno m;
            m.table();
            return 3;
        }
