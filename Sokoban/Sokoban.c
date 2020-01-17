#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "Sokoban.h"

void Gotoxy(int x, int y)  //定位光标
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Hide() //隐藏光标
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    //COORD coord;
    CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
    SetConsoleCursorInfo(hout, &cursor_info);
}

void EasyMap(int Map[20][20], int* n, int* m, char* ch) //简单关卡
{
    static int cs = 0;
    int guan;
    if (*ch == '*')
    {
        guan = cs;
        if (guan > 0)
            guan--;
        *ch = '!';
    }
    else 
    {
        guan = cs;
        cs++;
    }

    *n = point[guan].x;
    *m = point[guan].y;
    for (unsigned int i = 0; i < *n; i++)
    {
        for (unsigned int j = 0; j < *m; j++)
        {
            Map[i][j] = Maps[guan][i][j];
        }
    }
}

void MiddleMap(int Map[20][20], int* n, int* m, char* ch)//中等关卡
{
    static int cs = 0;
    int guan;
    //fscanf(fp1, "%d", &guanshu2);
    //fclose(fp1);//关闭文件
    if (*ch == '*') 
    {
        guan = cs;
        if (guan > 0)
            guan--;
        *ch = '!';
    }
    else 
    {
        guan = cs;
        cs++;
        //guan=guanshu2;
        //guanshu2++;
    }

    *n = point[guan + 10].x;
    *m = point[guan + 10].y;
    for (unsigned int i = 0; i < *n; i++)
    {
        for (unsigned int j = 0; j < *m; j++)
        {
            Map[i][j] = Maps[guan + 10][i][j];
        }
    }
}

void DifficultyMap(int Map[][20], int* n, int* m, char* ch) //困难关卡
{
    static int css = 0;
    int guan;
    if (*ch == '*') 
    {
        guan = css;
        if (guan > 0)
            guan--;
        *ch = '!';
    }
    else
    {
        guan = css;
        css++;
    }

    *n = point[guan + 20].x;
    *m = point[guan + 20].y;
    for (unsigned int i = 0; i < *n; i++)
    {
        for (unsigned int j = 0; j < *m; j++)
        {
            Map[i][j] = Maps[guan + 20][i][j];
        }
    }
}

void SelectMap(int Map[][20], int* n, int* m, char* ch, int guan) //选关地图
{
    if (guan > 0)guan--;

    *n = point[guan].x;
    *m = point[guan].y;
    for (unsigned int i = 0; i < *n; i++)
    {
        for (unsigned int j = 0; j < *m; j++)
        {
            Map[i][j] = Maps[guan][i][j];
        }
    }
}

void MenuTwo(char* ch) //菜单二
{
    while (1) 
    {
        system("cls");
        Hide();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        int s;
        printf("\n\n\n\n\n\n\n");
        printf("         ------------------------------------\n\n");
        printf("\t\t   (1):简单关卡\n\n");
        printf("\t\t   (2):中等关卡\n\n");
        printf("\t\t   (3):困难关卡\n\n");
        printf("\t\t   (4):退出页面\n\n");
        printf("         ------------------------------------\n\n");
        printf("\t\t    请输入序号。\n");
        s = _getch();
        while (s < '1' || s>'4') 
        {
            printf("输入有误，请重新输入:");
            s = _getch();
        }
        if (s == '1')
            EasyGame(ch);
        else if (s == '2')
            MiddleGame(ch);
        else if (s == '3')
            DifficultyGame(ch);
        else if (s == '4')
            MenuOne(ch);
    }
}

void Autor(char* ch) //作者。。。
{
    char hh = '!';
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("\n\n\n\n");
    printf("    此游戏非常简陋，虽然我（尔灵尔亿）已经非常努力了，");
    printf("花费我了几天的时间，写这个游戏纯属娱乐和学习，也纯属巧合。");
    printf("之所以要写是因为凑巧从网上看到一个用C语言写推箱子的方法，");
    printf("所以自己就有了一个写一个推箱子的小游戏的想法。经过几天的时间");
    printf("终于写出一个非常简易的推箱子小游戏（这个小游戏现在写了有五十多关了），期间出现的BUG无群无尽，自己是改了又改,");
    printf("到现在为止，肯定是还有好多BUG。通过写这个推箱子小游戏，让我知道了，做一个游戏");
    printf("是多么的难，看这个如此简陋的小游戏，也足足有一千百多行的代码。\n");
    printf("    啊啊啊，又几天了，好烦，按键闪屏的问题真的好麻烦，一直解决不了，太痛苦了，");
    printf("还好用 W S A D 四个键闪屏问题不是太严重。");
    printf("百度一下说什么双缓冲，换成用gotoxy()函数，才能解决闪屏问题，好吧根本不会，能力太低了。唉，就这样吧。\n");
    printf("    版本1.0，只有一个地图，什么都没有。版本1.1，添加了判断通关的功能。版本1.2，增加了多个关卡，修复了多个BUG。");
    printf("版本2.0，添加界面，以及各种模式。版本2.1，再次增加关卡，关卡数到达50关。版本2.2，添加了地图中不同物品以及文字显示不同颜色。");
    printf("版本2.3，增加记录移动步数的功能,修复许多BUG。版本2.4.0，优化了界面。版本2.4.1，修复了在选关模式下记录步数不能重置的问题。");
    printf("版本2.6.1，修复输入密码不能删除的问题。2.6.5版本修复一些BUG。\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\t\t    退出请按   键。\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    Gotoxy(28, 27);
    printf("ESC");
    hh = _getch();
    if (hh == 27)
        Introduction(ch);
}

void Menu(char* ch) {//主菜单
    while (1) 
    {
        system("cls");
        Hide();
        int s;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("\n\n\n\n\n\t       主        菜        单\n\n");
        printf("\n\n\t\t       推箱子\n\n");
        printf("         ------------------------------------\n\n");
        printf("\t\t   (1):开始游戏\n\n");
        printf("\t\t   (2):操作介绍\n\n");
        printf("\t\t   (3):游戏介绍\n\n");
        printf("\t\t   (4):退出游戏\n\n");
        printf("         ------------------------------------\n\n");
        printf("****************第一次请先观看操作介绍****************\n\n");
        printf("\t\t    请输入序号。\n");
        s = _getch();
        while (s < '1' || s>'4') 
        {
            printf("\t\t输入有误，请重新输入。\n");
            s = _getch();
        }
        if (s == '1')
            MenuOne(ch);
        else if (s == '2')
            Operation(ch);
        else if (s == '3')
            Introduction(ch);
        else
        {
            int i = MessageBox(NULL, L"\n确定要退出游戏吗？", L"退出提示", MB_YESNO);
            if (i == IDYES)
                exit(0);
        }

    }
}

void MenuOne(char* ch) {//菜单一
    while (1) 
    {
        system("cls");
        Hide();
        int s;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("\n\n\n\n\n\n\n");
        printf("         ------------------------------------\n\n");
        printf("\t\t   (1):闯关模式\n\n");
        printf("\t\t   (2):选关模式\n\n");
        printf("\t\t   (3):退出页面\n\n");
        printf("         ------------------------------------\n\n");
        printf("\t\t    请输入序号。\n");
        s = _getch();
        while (s < '1' || s>'3')
        {
            printf("\t\t输入有误，请重新输入。\n");
            s = _getch();
        }
        if (s == '1')
            MenuTwo(ch);
        else if (s == '2')
            Select(ch);
        else
            Menu(ch);
    }
}

void Select(char* ch) //选关
{
    system("cls");
    int guan;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t    请\n\n\t\t\t   输入\n\n\t\t\t 所要选择\n\n\t\t      的关卡(1-40关)，\n\n\t\t     输入0回退到前一\n\n\t\t    页面。之后按回车键：");
    scanf_s("%d", &guan);
    while (guan < 0 || guan>40)
    {
        printf("\t\t输入有误，请重新输入。\n");
        scanf_s("%d", &guan);
    }
    if (guan == 0)
        MenuOne(ch);
    SelectGameReady(ch, guan);
}

void SelectGame(char* ch, int guan)
{
    int Map[20][20], n, m;
    memset(Map, -1, sizeof(Map));
    int sum = 0, data = 0, sl = 0;
    while (1)
    {
        SelectMap(Map, &n, &m, ch, guan);
        data = BoxData(Map, &n, &m);
        sl = GroundData(Map, &n, &m);
        while (1) 
        {
            system("cls");//清屏
            sum = DrawMap(Map, &n, &m, &guan);//画图
            sum -= sl;
            if (sum == data) {
                Hide();//隐藏光标
                printf("\n\t\t    恭 喜 通 关！\n\n");
                printf("\t       请稍等,正在重置关卡。\n");
                MyTime();
                break;
            }
            PlayGame(Map, &n, &m, ch);//操作函数
            if (*ch == '*') {
                *bushu = 0;
                //*XianShi=1;
                break;
            }
        }
        if (*ch == '*') 
        {
            *ch = '!';
            break;
        }
    }
}

int SelectGameReady(char* ch, int guan) {//游戏准备
    while (1)
    {
        system("cls");
        Hide();
        int s;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("\n\n\n\n\n\n\n");
        printf("         ------------------------------------\n\n");
        printf("\t\t   (1):游戏开始\n\n");
        printf("\t\t   (2):游戏退出\n\n");
        printf("         ------------------------------------\n\n");
        printf("\t\t    请输入序号。\n");
        s = _getch();
        while (s != '1' && s != '2')
        {
            printf("\t\t输入有误，请重新输入。\n");
            s = _getch();
        }
        if (s == '1')
            SelectGame(ch, guan);
        else
            Select(ch);
    }
    return 0;
}

void Password(char* ch) //密码输入判断
{
    char passwords[10], Passwords[10] = { "123456789" };
    while (1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("    说明：\n\t       输入密码后按回车键。\n\n");
        printf("         ------------------------------------\n\n");
        printf("\t\t (1):输入密码\n\n");
        printf("\t\t (2):退出页面\n\n");
        printf("         ------------------------------------\n\n");
        printf("\t\t    输入序号\n\n");
        //printf("\n\n\n");
        int t = _getch();
        if (t == '1')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//红色
            printf("\t\t密码：");
            int i;
            for (i = 0; i < 100; i++) 
            {
                passwords[i] = _getch();
                if (passwords[i] == 8)
                {
                    i -= 2;
                    printf("\b \b");
                }
                else if (passwords[i] == '\r')
                    break;
                else
                    printf("*");
            }
            passwords[i] = '\0';
            if (strcmp(passwords, Passwords) == 0)
                break;
            else
                MessageBox(NULL, L"\t    密码错误！！！\t\n\t请重新输入密码。\t", L"输入提示", MB_OK);
        }
        else
            Introduction(ch);
    }
}

void Introduction(char* ch)
{
    system("cls");
    Hide();
    int s;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//白色
    printf("\n\n\n\n\n\n\n");
    printf("         ------------------------------------\n\n");
    printf("\t\t (1):游戏名称:推箱子\n\n");
    printf("\t\t (2):游戏简介:->(next)\n\n");
    printf("\t\t (3):完成日期:2018年3月\n\n");
    printf("\t\t (4):作者:尔灵尔亿->(next)\n\n");
    printf("\t\t (5):QQ:2117610943\n\n");
    printf("\t\t (6):版本:%d.%d.%d\n\n", A, B, C);
    printf("\t\t (7):退出页面\n\n");
    printf("         ------------------------------------\n\n");
    printf("\t\t    请输入序号。\n");
    s = _getch();
    while (s != '2' && s != '7' && s != '4') 
    {
        printf("\t\tSorry，此序号没有下一页了。\n");
        s = _getch();
    }
    if (s == '2')
        Gameintor(ch);
    else if (s == '7')
        Menu(ch);
    else if (s == '4') 
    {
        MessageBox(NULL, L"\t          请输入密码。\t\n\t（少于十个数字或字母）\t", L"输入提示", MB_OK);
        Password(ch);
        Autor(ch);
    }

}

void Gameintor(char* ch) {//游戏介绍
    while (1) 
    {
        system("cls");
        Hide();
        char hh = '!';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//红色
        printf("\n\n\n\n\n");
        printf("   《推箱子》是一款经典电子游戏，1982年由日本Thinking Rabbit公司首次发行");
        printf("之后其他游戏开发者争相制作仿制或衍生作品。致使推箱子成为此类游戏的代名词。");
        printf("游戏要求玩家在一个狭小的仓库中，要求把木箱放到指定的位置，稍不小心就会出现");
        printf("t箱子无法移动或者通道被堵住的情况，所以需要巧妙的利用有限的空间和通道，合理");
        printf("t安排移动的次序和位置，才能顺利的完成任务。 \n");
        printf("    推箱子是一个来自日本的古老游戏，目的是在训练玩家的逻辑思考能力。在一个狭");
        printf("小的仓库中，要求把木箱放到指定的位置，稍不小心就会出现箱子无法移动或者通道被堵");
        printf("住的情况，所以需要巧妙的利用有限的空间和通道，合理安排移动的次序和位置，才能顺");
        printf("利的完成任务。\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("        注：游戏关卡来源于经典推箱子关卡。\n\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\t\t  退出请按   键。\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        Gotoxy(26, 21);
        printf("ESC");
        hh = _getch();
        if (hh == 27)
            Introduction(ch);
    }
}

void Operation(char* ch) {//操作介绍
    char hh = '!';
    while (1) 
    {
        system("cls");
        Hide();
        printf("\n\n\n\n\n\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\t\t\t操作说明:\n\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//红色
        printf("   (W):向上移动 (S):向下移动 (A):向左移动 (D):向右移动\n\n");
        printf("      (□):代表箱子 (♀):代表人   (☆):代表目的地\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("\t        *按键盘前请调整好输入法。\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
        printf("\t\t     退出请按   键。\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
        Gotoxy(29, 16);
        printf("ESC");
        hh = _getch();
        if (hh == 27)
            Menu(ch);
    }
}

int BoxData(int Map[][20], int* n, int* m)//计算箱子数
{
    int sum = 0;
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            if (Map[i][j] == 3)
                sum++;
        }
    }
    return sum;
}

int GroundData(int Map[][20], int* n, int* m) //计算箱子开始时就在目的地的数目
{
    int sum = 0;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++) 
        {
            if (Map[i][j] == 7)
                sum++;
        }
    }
    return sum;
}

int DrawMap(int Map[20][20], int* n, int* m, int* guanshu) //画出地图
{
    int sum = 0;
    Hide();
    printf("\n\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
    printf("\t\t     第  %d  关\n\n\n\n", *guanshu);
    for (int i = 0; i < *n; i++) 
    {
        printf("\t\t   ");
        for (int j = 0; j < *m; j++) 
        {
            switch (Map[i][j]) {
            case 1://墻
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//改变颜色函数
                printf("■");
                break;
            case 0://空地
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("  ");
                break;
            case 3://目的地
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                printf("☆");
                break;
            case 4://箱子
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
                printf("□");
                break;
            case 5://人
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                printf("♀");
                break;
            case 7://箱子在目的地 4+3
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                printf("★");
                sum++;
                break;
            case 8://人在目的地  5+3
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                printf("♀");
                break;
            }
        }
        printf("\n");
    }
    if (kongge == 1) 
    {
        printf("\n\t\t     当前步数为%d步。", *bushu);
        if (yanchi == 10) 
        {
            *KonGe = 0;
            *YanChi = 0;
        }
        yanchi++;
        xianshi = 1;
    }
    if (xianshi == 0)
    {
        printf("\n\t\t  按空格键查看当前步数。");
    }
    *XianShi = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\n     按ESC键退出此游戏，之后重新进入从该关重新开始。\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("\n\t   开始游戏前输入法请锁定成英文大写。\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    Gotoxy(12, 23);
    printf("W/↑:上移");
    Gotoxy(32, 23);
    printf("S/↓:下移");
    Gotoxy(12, 25);
    printf("A/←:左移");
    Gotoxy(32, 25);
    printf("D/→:右移");
    return sum;
}

void PlayGame(int Map[20][20], int* n, int* m, char* ch)//游戏控制/*************这个是最重要的**************/
{
    char input;
    int i, j;
    //确定人的位置
    for (i = 0; i < *n; i++) 
    {
        for (j = 0; j < *m; j++) 
        {
            if (Map[i][j] == 5 || Map[i][j] == 8)
                break;
        }
        if (Map[i][j] == 5 || Map[i][j] == 8)
            break;
    }
    input = _getch();//头文件conio.h
    switch (input) 
    {
    case 72:
    case 'W'://上
    case 'w':
        if (Map[i - 1][j] == 0 || Map[i - 1][j] == 3)//人前面是空地或者人前面是目的地
        {
            Map[i - 1][j] += 5;
            Map[i][j] -= 5;
            data++;
        }
        else if (Map[i - 1][j] == 4 || Map[i - 1][j] == 7) //人的前面是箱子的情况
        {
            if (Map[i - 2][j] == 0 || Map[i - 2][j] == 3) 
            {
                Map[i - 2][j] += 4;
                Map[i - 1][j] += 1;
                Map[i][j] -= 5;
                data++;
            }
        }
        break;
    case 80:
    case 'S'://下
    case 's':
        if (Map[i + 1][j] == 0 || Map[i + 1][j] == 3)//人前面是空地或者人前面是目的地
        {
            Map[i + 1][j] += 5;
            Map[i][j] -= 5;
            data++;
        }
        else if (Map[i + 1][j] == 4 || Map[i + 1][j] == 7)//人的前面是箱子的情况
        {
            if (Map[i + 2][j] == 0 || Map[i + 2][j] == 3) 
            {
                Map[i + 2][j] += 4;
                Map[i + 1][j] += 1;
                Map[i][j] -= 5;
                data++;
            }
        }
        break;
    case 75:
    case 'A'://左
    case 'a':
        if (Map[i][j - 1] == 0 || Map[i][j - 1] == 3) //人前面是空地或者人前面是目的地
        {
            Map[i][j - 1] += 5;
            Map[i][j] -= 5;
            data++;
        }
        else if (Map[i][j - 1] == 4 || Map[i][j - 1] == 7) //人的前面是箱子的情况
        {
            if (Map[i][j - 2] == 0 || Map[i][j - 2] == 3) 
            {
                Map[i][j - 2] += 4;
                Map[i][j - 1] += 1;
                Map[i][j] -= 5;
                data++;
            }
        }
        break;
    case 77:
    case 'D'://右
    case 'd':
        if (Map[i][j + 1] == 0 || Map[i][j + 1] == 3) //人前面是空地或者人前面是目的地
        {
            Map[i][j + 1] += 5;
            Map[i][j] -= 5;
            data++;
        }
        else if (Map[i][j + 1] == 4 || Map[i][j + 1] == 7)//人的前面是箱子的情况
        {
            if (Map[i][j + 2] == 0 || Map[i][j + 2] == 3) 
            {
                Map[i][j + 2] += 4;
                Map[i][j + 1] += 1;
                Map[i][j] -= 5;
                data++;
            }
        }
        break;
    case 27:
        *ch = '*';
        break;
    case 32:
        *KonGe = 1;
        break;
    }
}

void MyTime() //倒计时
{
    int t = 0;
    for (int i = 9; i >= 0; i--) 
    {
        Sleep(500);
        Gotoxy(25, 23);
        if (t == 3)
            t = 0;
        if (t == 0)
            printf("%d.  ", i);
        else if (t == 1)
            printf("%d.. ", i);
        else
            printf("%d...", i);
        t++;
    }
}

int GameReady() //游戏准备
{
    system("cls");
    Hide();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//白色
    int s;
    printf("\n\n\n\n\n\n\n");
    printf("         ------------------------------------\n\n");
    printf("\t\t   (1):游戏开始\n\n");
    printf("\t\t   (2):游戏退出\n\n");
    printf("         ------------------------------------\n\n");
    printf("\t\t    请输入序号。\n");
    s = _getch();
    while (s != '1' && s != '2') {
        printf("\t\t输入有误，请重新输入。\n");
        s = _getch();
    }
    return s;
}

void GameOperate(int Map[][20], int* n, int* m, int* js, int* sum, int* data, int* sl, int* guanshu, char* ch)//游戏函数调用
{
    while (1)
    {
        clock_t start, end;
        start = clock();
        *js = 0;
        system("cls");//清屏
        Hide();
        *sum = DrawMap(Map, n, m, guanshu);//画图
        *sum -= *sl;
        if (*sum == *data) 
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t    恭 喜 通 关！\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\n\t\t 通关所用步数为%d步。\n\n", *bushu);
            end = clock();
            printf("\n\t        通关所用时间为%.3lf秒\n\n", (double)(end - start) / 9.56);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            printf("\n\t       请稍等,正在创建下一关。\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            MyTime();
            *bushu = 0;
            break;
        }
        PlayGame(Map, n, m, ch);//操作函数
        if (*ch == '*') 
        {
            int i = MessageBox(NULL, L"\t\n确定要退出游戏吗？\n\n（提示：退出后重新进入从退出的关卡开始）。", L"退出提示", MB_YESNO);
            if (i == IDYES) 
            {
                *bushu = 0;
                *XianShi = 1;
                *js = 1;
                break;
            }
            else 
            {
                *ch = '!';
                continue;
            }
        }
    }
}

void EasyGameOperate(int Map[][20], int* n, int* m, int* js, int* sum, int* data, int* sl, int* guanshu, char* ch)//游戏函数调用
{
    while (1) 
    {
        *js = 0;
        system("cls");//清屏
        Hide();
        *sum = DrawMap(Map, n, m, guanshu);//画图
        *sum -= *sl;
        if (*sum == *data)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\t\t\t\t    恭 喜 通 关！\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            int t = MessageBox(NULL, L"\t      你真棒！！！\n\n\t是否进入下一关？", L"提示", MB_YESNO);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\t\t 通关所用步数为%d步。\n", *bushu);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            printf("\t       请稍等,正在创建下一关。");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            MyTime();
            if (t == IDYES)
            {
                *bushu = 0;
                break;
            }
            else 
            {
                *bushu = 0;
                *XianShi = 1;
                *js = 2;
                break;
            }
        }
        PlayGame(Map, n, m, ch);//操作函数
        if (*ch == '*')
        {
            int i = MessageBox(NULL, L"\t\n确定要退出游戏吗？\n\n（提示：退出后重新进入从退出的关卡开始）。", L"退出提示", MB_YESNO);
            if (i == IDYES)
            {
                *bushu = 0;
                *XianShi = 1;
                *js = 1;
                break;
            }
            else 
            {
                *ch = '!';
                continue;
            }
        }
    }
}

void EasyGame(char* ch)//简单关卡控制
{
    int Map[20][20], n, m, js;
    static int guanshu = 1;
    memset(Map, -1, sizeof(Map));
    int sum = 0, data = 0, sl = 0;
    while (1) 
    {
        int t = GameReady();
        if (t == '2')
            break;
        while (1) 
        {
            EasyMap(Map, &n, &m, ch);
            data = BoxData(Map, &n, &m);
            sl = GroundData(Map, &n, &m);
            EasyGameOperate(Map, &n, &m, &js, &sum, &data, &sl, &guanshu, ch);
            int s;
            if (js == 0) 
            {
                guanshu++;
                if (guanshu < 11)
                    s = 1;
                else 
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("恭喜你已经通过全部简单关卡,接下来有中等关卡等待你去挑战\n");
                    Gotoxy(19, 26);
                    printf("！！！！！！");
                }
            }
            else if (js == 1)
                break;
            else if (js == 2) {
                *ch = '*';
                continue;
            }
            if (s == '2')
                break;
        }
    }
}

void MiddleGame(char* ch)//中等关卡控制
{
    int Map[20][20], n, m, js;
    static int guanshu = 1;
    memset(Map, -1, sizeof(Map));
    int sum = 0, data = 0, sl = 0;
    while (1) 
    {
        int t = GameReady();
        if (t == '2')
            break;
        while (1) 
        {
            MiddleMap(Map, &n, &m, ch);
            data = BoxData(Map, &n, &m);
            sl = GroundData(Map, &n, &m);
            GameOperate(Map, &n, &m, &js, &sum, &data, &sl, &guanshu, ch);
            int s;
            if (js == 0)
            {
                guanshu++;
                if (guanshu < 11)
                    s = 1;
                else 
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("恭喜你已经通过全部中等关卡,接下来有困难关卡等待你去挑战\n");
                    Gotoxy(19, 26);
                    printf("！！！！！！");
                }
            }
            else if (js == 1)
                break;
            if (s == '2')
                break;
        }
    }
}

void DifficultyGame(char* ch) {//困难关卡控制
    /*
    int Map[20][20],n,m,js;
    static int guanshu=1;
    memset(Map,-1,sizeof(Map));
    int sum=0,data=0,sl=0;
    while(1) {
        int t=gameready();
        if(t=='2')
            break;
        while(1) {
            difficultyMap(Map,&n,&m,ch);
            data=boxdata(Map,&n,&m);
            sl=grounddata(Map,&n,&m);
            gameoperate(Map,&n,&m,&js,&sum,&data,&sl,&guanshu,ch);
            int s;
            if(js==0) {
                guanshu++;
                if(guanshu<11)
                    s=1;
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED |FOREGROUND_INTENSITY);
                    printf("恭喜你已经通过全部关卡！\n");
                    gotoxy(19,26);
                    printf("！！！！！！");
                }
            } else if(js==1)
                break;
            if(s=='2')
                break;
        }
    }
    */
    int Map[20][20], n, m, js;
    static int guanshu = 1;
    memset(Map, -1, sizeof(Map));
    int sum = 0, data = 0, sl = 0;
    while (1)
    {
        int t = GameReady();
        if (t == '2')
            break;
        while (1) 
        {
            DifficultyMap(Map, &n, &m, ch);
            data = BoxData(Map, &n, &m);
            sl = GroundData(Map, &n, &m);
            EasyGameOperate(Map, &n, &m, &js, &sum, &data, &sl, &guanshu, ch);
            int s;
            if (js == 0) 
            {
                guanshu++;
                if (guanshu < 21)
                    s = 1;
                else 
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("恭喜你已经通过全部关卡!\n");
                    Gotoxy(19, 26);
                    printf("！！！！！！");
                }
            }
            else if (js == 1)
                break;
            else if (js == 2) 
            {
                *ch = '*';
                continue;
            }
            if (s == '2')
                break;
        }
    }
}

int main() {//主函数
    char ch = '!';
    system("title 推箱子C语言2.6.5版---尔灵尔亿制作");//设置标题
    system("mode con cols=55 lines=30");//控制窗口大小
    while (1)
    {
        system("cls");//清除屏幕
        Hide();
        Menu(&ch);//菜单一
       
    }
    return 0;
}
