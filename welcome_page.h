//to set the console to full screen mode
#if       _WIN32_WINNT < 0x0500
#undef  _WIN32_WINNT
#define _WIN32_WINNT   0x0500
#endif
#include <windows.h>
#include"menu.h"
using namespace std;
class menu
{
    public:
            HANDLE hstdout;
            int index;
            int key;

             menu(){
            hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
            index=1;
         }
            void showmenu()
            {
                key=0;
                system("cls");
                while(key!=13){
                gotoxy(60,3);
                colorit(15);
                cout<<"         ======================================";
                gotoxy(80,4);
                cout<<" GAME CONSOLE";//cout<<key<<"---"<<index;
                gotoxy(60,5);
                cout<<"         ======================================";
                gotoxy(85,7);
                colorit(15);
                if(index==1){colorit(12);}
                cout<<"GAMES";
                gotoxy(85,9);
                colorit(15);
                if(index==2){colorit(12);}
                cout<<"ABOUT";
                gotoxy(85,11);
                colorit(15);
                if(index==3){colorit(12);}
                cout<<"EXIT";
                colorit(7);
                  gotoxy(73,40);
                cout<<"(Use Arrow key to Navigate )";

                /////////////UP=224/72 Down=224/80 Enter=13
                key=getch();
                if(key==80){index++;}
                else if(key==72){index--;}
                if(index==4){index=1;}
                if(index==0){index=3;}
                }
                if(index==1)
                {
                    mainmain3();
                    system("color 0F");
                        startit();

                }
                else if (index==2)
                {
                    showabout();
                }
                else if (index==3)
                {

                }
            }

            void startit()
            {
                showmenu();

            }

            void showabout(){
                system("cls");
                key=0;
                while(key!=13 & key!=8){
                gotoxy(3,3);colorit(12);
                cout<<"============================";
                gotoxy(3,4);
                cout<<"|         ABOUT US         |";
                gotoxy(3,5);
                cout<<"============================";
                gotoxy(3,6);colorit(15);
                cout<<"Written in  c++.";
                gotoxy(3,7);
                cout<<"Developed using Codeblocks IDE.";
                gotoxy(3,10);
                cout<<"Developed by :";
                gotoxy(15,11);
                cout<<"Tejas Ladhani";
                gotoxy(32,11);
                cout<<"Rudra Chauhan";
                gotoxy(15,12);
                cout<<"19IT058";
                gotoxy(32,12);
                cout<<"19IT025";
                key=getch();
                }
                showmenu();
            }

            void colorit(int col){//12=red, 15=white---------------->this.colorit(12);  this.colorit(15);
                SetConsoleTextAttribute( hstdout, col );
            }

};
//to remove the scroll bar
void remove_scrollbar()
{

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

void welcome_main()
{
    remove_scrollbar();
    system("mode con COLS=700");
    ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
    SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
    menu m;
    m.startit();
    }
