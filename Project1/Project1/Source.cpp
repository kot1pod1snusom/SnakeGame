#include "Header.h"
#include "maps.h"



int logick(char speedchouse, char mapchouse, int storykey, char& hvostcolor, char& hvostout);
void main();
int menu(char speedchouse , char mapchouse);
void lose(int score);
int mapsettings(char speedchouse, char mapchouse);

void kat(int xcount, int ycount, int x, int y, int ax, int ay, int score, vector<int> coorx, vector<int> coory, int dlinahvosta, char mapchouse, vector<vector<char>>& field,  char& hvostcolor, char& hvostout) { //������ ������  
    
    // ����� ����� ������ ������������
    if (mapchouse == 1) 
    {
        map1(field, xcount, ycount, x, y, ax, ay, coorx, coory, hvostout);
    }
    else if (mapchouse == 2)
    {
        map2(field, xcount, ycount, x, y, ax, ay, coorx, coory, hvostout);
    }
    else if (mapchouse == 3)
    {
        map3(field, xcount, ycount, x, y, ax, ay, coorx, coory, hvostout);
    }
    else if (mapchouse == 4)
    {
        map4(field, xcount, ycount, x, y, ax, ay, coorx, coory, hvostout);
    }

    // ����� ����
    for (size_t i = 0; i < field.size(); i++)
    {
        for (size_t j = 0; j < field[i].size(); j++)
        {
            if (field[i][j] == 'a')
            {
                SetConsoleTextAttribute(hand, Red);
                cout << field[i][j]; //����� ����  
                SetConsoleTextAttribute(hand, White);
                j++;
            }
            else if (field[i][j] == 1)
            {
                SetConsoleTextAttribute(hand, LightWhite);
                cout << field[i][j]; //����� ����  
                SetConsoleTextAttribute(hand, White);
                j++;
            }
            else if (field[i][j] == hvostout)
            {
                if (hvostcolor == '1') // ��������� ������ �������������
                {
                    SetConsoleTextAttribute(hand, White); //����� �����
                }
                else if (hvostcolor == '2')
                {
                    SetConsoleTextAttribute(hand, (rand() % 14) + 1); //��� �����
                }
                cout << field[i][j];
                SetConsoleTextAttribute(hand, White);
                j++;
            }
            cout << field[i][j]; //����� ����  
        }
        cout << endl;
    }


    cout << "���� " << score << endl;

}
void move(char& tempmove, int& x, int& y, int mapchouse) { // ������� ��������

    if (_kbhit())
    {
        switch (_getch()) //������� ������� � ������ �����������  
        {
            
        case 'w':
            if (tempmove != 2)
            {
                y -= 1;
                tempmove = 1;
            }
            break;
        case 's':
            if (tempmove != 1)
            {
                y += 1;
                tempmove = 2;
            }
            break;
        case 'd':
            if (tempmove != 4)
            {
                x += 1;
                tempmove = 3;
            }
            break;
        case 'a':
            if (tempmove != 3)
            {
                x -= 1;
                tempmove = 4;
            }
            break;
        default:
            break;
        }
    }
    else //���� ��� �������, �� ������ ��������� �� ��������� ����������� ������  
    {
        switch (tempmove)
        {
        case 1:
            y -= 1;

            break;
        case 2:
            y += 1;

            break;
        case 3:
            x += 1;

            break;
        case 4:
            x -= 1;

            break;
        default:
            break;
        }
    }

    // ��� ���� - ������������ ������ ������ �� ��������������� ������� ���, ��� ��� ������. �������� ��� ������ ��������� ��������� ������
    if (mapchouse == 2) 
    {

        if (x == 0 && (y > 7 && y < 13))
        {
            x += 18;
        }
        else if (x == 19 && (y > 7 && y < 13))
        {
            x -= 18;
        }

        if (y == 0 && (x > 6 && x < 13))
        {
            y += 18;
        }
        else if (y == 19 && (x > 6 && x < 13))
        {
            y -= 18;
        }
    }
    else if (mapchouse == 4)
    {
        if (y == 0 && (x >= 14 && x <= 26))
        {
            y += 19;

        }
        else if (y == 19 && (x >= 14 && x <= 26))
        {
            y -= 19;
        }
        else if (x == 0  && (y >= 7 && y <= 12))
        {
            x += 38;
        }
        else if (x == 39 && (y >= 7 && y <= 12))
        {
            x -= 38;
        }
    }
}
int kolisia(int dlinahvosta, vector<int> coorx, vector<int> coory, int x, int y,vector<vector<char>> field) { // ������� ��������
    int lose = 0; //���������� �������� ����� (1) ��� ��� (0) 
   
    for (size_t i = 2; i < dlinahvosta; i++) //����� �������� ������
    {
        if (coorx[i] == x && coory[i] == y)
        {
            lose = 1;
        }
    }

    char k = ' '; //������ ������ � ����
    for (size_t i = 0; i < field.size(); i++)
    {   
        for (size_t j = 0; j < field[i].size(); j++)
        {
            if (x == j && i == y)
            {
                k = field[i][j];
            }

            if (k == '|' || k == '-') // ���� ������ ������ ��������� �����
            {
                lose = 1;
            }
        }
    }
    return lose;
}


void preobrazovanie(char& mapchouse, char speedchouse, int& x, int& y, int& xcount, int& ycount, float& speed, int storykey, int& maxhvost) {
    switch (mapchouse) //����������� ������� ���� � ���������� � ��������� ��������� ������ ������ ������  
    {
    case 1:
        xcount = 25;
        ycount = 25;
        x = 12;
        y = 12;
        break;
    case 2:
        ycount = 20;
        xcount = 20;
        x = 10;
        y = 10;
        break;
    case 3:
        xcount = 40;
        ycount = 20;
        x = 20;
        y = 10;
    case 4:
        xcount = 40;
        ycount = 20;
        x = 20;
        y = 9;
        break;
        break;
    default:
        break;
    }

    switch (speedchouse) //����������� ��������� � ����� int, ������� ����� �������������� � Sleep  
    {
    case '1':
        speed = 300;
        break;
    case '2':
        speed = 50;
        break;
    case '3':
        speed = 1;
        break;
    case '4':
        speed = 0.5;
        break;
    default:
        break;
    }

    if (storykey == 1) // ��� ��������� ������ ����������� � ����������� �� �����
    {
        maxhvost = 40;
        mapchouse = 1;
    }
    else if (storykey == 2)
    {
        maxhvost = 20;
        mapchouse = 2;
    }
    else if (storykey == 3)
    {
        maxhvost = 40;
        mapchouse = 3;
    }
    else if (storykey == 4)
    {
        maxhvost = 35;
        mapchouse = 4;
    }
}

void applespawn(int& ax, int& ay, vector<int> coorx, vector<int> coory, int xcount, int ycount, vector<vector<char>> field) { // ��������� ������
here: //���� �� ����������� ���� ������ ������������ ��� ��� �� ����
    ax = rand() % (xcount - 3) + 2; // ��������� x ���������� ������
    ay = rand() % (ycount - 3) + 2; // ��������� � ���������� ������

    for (size_t i = 0; i < coorx.size(); i++)
    {
        if (ax == coorx[i] && ay == coory[i]) // �������� ������� ������ � �������
        {
            goto here;
        }
    }

    
    for (size_t i = 0; i < field.size(); i++)
    {
        for (size_t j = 0; j < field.size(); j++)
        {
            if (field[i][j] == '-' || '|') // ���� ���������� - �����
            {
                if (ax == j && ay == i) // � ���� ������ � ��� ������������
                {
                    goto here; //��� �� �����
                }
            }
        }
    }

  
}

int logick(char speedchouse, char mapchouse, int storykey, char& hvostcolor, char& hvostout) { //������  
    float speed = 0; //�������� 
    int xcount = 20; //����� ����  
    int ycount = 20; //������ ����  
    int x = 10; //� ���������� ������ ����  
    int y = 10; //� ���������� ������ ����  
    int maxhvost = -1; 
    preobrazovanie(mapchouse, speedchouse, x, y, xcount, ycount, speed, storykey, maxhvost); //������, ���������� �������, ������������� � �������� ��� �������������
    Sleep(speed);
    char tempmove = 0; //�������� ����������� ������  
    int ax = rand() % (xcount - 3) + 2;
    int ay = rand() % (ycount - 3) + 2;
    int score = 0; //���� ������  
    int dlinahvosta = 0;
    vector<int> coorx; //������ � x ������������ ������ ����
    vector<int> coory; //������ � y ������������ ������ ����
    vector<vector<char>> field; //������ ���� 
    while (true)
    {
        field.clear(); //������ ������� ����
        if (ax == x && ay == y) //���� ����� "����" ������
        {
            applespawn(ax, ay, coorx, coory, xcount, ycount,field); // �������� �� ������� � ������� ���������� ������

            score += 10;
            dlinahvosta++;
            coorx.push_back(x);
            coory.push_back(y);
        }
        kat(xcount, ycount, x, y, ax, ay, score, coorx, coory, dlinahvosta, mapchouse, field, hvostcolor, hvostout); //������� �������� �� �����
        if (storykey > 0)
        {
            cout << "���� - " << maxhvost * 10 << " �����" << endl;
        }
        
        
        move(tempmove, x, y, mapchouse); //������� �������� �� �������� ������ ����
        Sleep(speed); //��� ������ ���� ������ �������� ��������� (�� � �� ��� ��� �������, �� �����)


        int lose = kolisia(dlinahvosta, coorx, coory, x, y, field);
        if (lose == 1) // ���� ������� ���� ������������� ��������� (1) (����� �������� �����)
        {
            return score; // �� �� ��������
        }

    
        for (int i = dlinahvosta - 1; i > 0; i--) // ����� ���������� �����, ���������� ������� ����� �������� ��������� � �������
        {

            coorx[i] = coorx[i - 1];
            coory[i] = coory[i - 1];
            coorx[0] = x;
            coory[0] = y;

        }

        if (dlinahvosta == maxhvost) // ���� ����� ������ ������ ��������� ����� ��� ����������� �����
        {
            return -1;
        }


        system("cls");
    }
}



int settings(char& speedchouse, char mapchouse, char& hvostcolor, char& hvostout) { //������� ��������  
    system("cls");
    cout << "���������" << endl;
    cout << "������� 1 ����� �������� ����� " << endl;
    cout << "������� 2 ���� ������ �������� ��������� ���� (�������� ������)" << endl;
    cout << "������� 3 ����� ��������������� ������ ������ " << endl;
    cout << "������� 4 ��� ������ � ������� ���� " << endl;
    int pc;
    cin >> pc;
    int pchouse = 0;
    if (pc == 1)
    {
        int pchouse = mapsettings(speedchouse, mapchouse); 
    }
    else if (pc == 2)
    {
        cout << "1 - �����\n 2 - ������\n 3 - ������\n 4 - ����" << endl;
        cin >> speedchouse; //���� ������������ ���������� �������� 
    }
    else if (pc == 3)
    {
        cout << "1 - �������� ������ ������ ������" << endl;
        cout << "2 - ������� ���� ������ " << endl;
        char da;
        cin >> da;
        if (da == '1')
        {
            cout << "������ ������ ������ ������ - "  << hvostout << endl;
            cout << "������� ����� ������ ������ ������ " << endl;
            cin >> hvostout;
        }
        else if (da == '2')
        {
            cout << "1 - ����� ������ ������ �����" << endl;
            cout << "2 - ��� ������ " << endl;
            cin >> hvostcolor;
        }
        
    }
    else if (pc == 4)
    {
        return pchouse; 
    }
    return 0;
}

int mapsettings(char speedchouse, char mapchouse) { //������� �������� �����
    int pc = 0; // ����� ������
    int pchouse = 0;
    while (pc != 6)
    {

        system("cls");
        int maptemp = mapchouse; // ���������� ��� ������ ������ �����
        cout << "������ �������� ����� ����� " << maptemp << endl;
        cout << "����� ����� ������ �������? " << endl;
        cout << "1 - ������ ����� " << endl;
        cout << "2 - ����� � ������������ ����������" << endl;
        cout << "3 - ����� � 4 �������� " << endl;
        cout << "4 - ����� � 4 �������� � ������������" << endl;
        cout << "5 - ����������� ����" << endl;
        cout << "6 - ��������� � ���� " << endl;
        cin >> pc; // ���� �������������
        if (pc == 1)
        {
            mapchouse = 1;
        }
        else if (pc == 2)
        {
            mapchouse = 2;
        }
        else if (pc == 3)
        {
            mapchouse = 3;
        }
        else if (pc == 4)
        {
            mapchouse = 4;
        }
        else if (pc == 5)
        {
            cout << "����� ����� ������ ����������? " << endl;
            cout << "1 - ������ �����\n2 - ����� � ������������\n3 - ����� � 4 ��������\n4 - ����� � 4 �������� � ������������ " << endl;
            char temp; //����� ������������
            cin >> temp; // ���� �������������
            vector<vector<char>> field; // ������ ����
            system("cls");
            if (temp == '1') // � ���� �������� ������� ������ ���� ����� �����������
            {
                map1test(field);
            }
            else if (temp == '2')
            {
                map2test(field);
            }
            else if (temp == '3')
            {
                map3test(field);
            }
            else if (temp == '4')
            {
                map4test(field);
            }
            for (size_t i = 0; i < field.size(); i++)
            {
                for (size_t j = 0; j < field[i].size(); j++)
                {
                    cout << field[i][j]; //����� ����
                }
                cout << endl;
            }
            cout << "������� ����� ����� ��� ����� ����� ���������� " << endl; 
            cin >> temp; //���� ����� ������������ ������ ����� ���� ����������
        }
    }

    menu(speedchouse, mapchouse);
    return 0;
}

void animation(char mapchouse) {
    int tempsc = 1; //���������� � temp ����� ������ ��� ������� �������
    int xcount,ycount;
    float temps;
    int x = 0; //��������� ���������� ������ �� x
    int y = 0;//��������� ���������� ������ �� y
    preobrazovanie(mapchouse, '1', x, y, xcount, ycount, temps, 0, tempsc); 


    SetConsoleTextAttribute(hand, White);
    COORD left{ y - 5, x }; // ������ ������
    COORD right{ y + 5,x }; // ������� ������
    while (left.X != right.X)
    {
        system("cls");
        cout << "���� �������� �����...... " << endl;
        for (size_t j = 0; j < ycount; j++)
        {
            for (size_t i = 0; i < xcount; i++)
            {
                if (j == left.X && i == left.Y)
                {
                    SetConsoleTextAttribute(hand, LightWhite);
                    cout << char(1);
                    SetConsoleTextAttribute(hand, White);
                }
                else if (j == right.X && i == left.Y)
                {
                    SetConsoleTextAttribute(hand, LightWhite);
                    cout << char(1);
                    SetConsoleTextAttribute(hand, White);
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        left.X++; 
        right.X--;
        Sleep(500);
    }
}


void storygame(char speedchouse, char hvostcolor,char hvostout) {
    int score1 = logick(speedchouse, '1', 1, hvostcolor, hvostout); // ������ �����
    if (score1 != -1) // ���� ����� �� ������ ����� (��������)
    {
        lose(score1);
    }
    else
    {
        animation(2);
        int score2 = logick(speedchouse, '2', 2, hvostcolor, hvostout); // ������ �����
        if (score2 != -1) // ���� ����� ��������
        {
            lose(score2);
        }
        else
        {
            animation(3);
            int score3 = logick(speedchouse, '3', 3, hvostcolor, hvostout); // ������ ����� �� � �� ������
            if (score3 != -1)
            {
                lose(score3);
            }
            else
            {
                int score4 = logick(speedchouse, '4', 4, hvostcolor, hvostout);
                if (score4 != -1)
                {
                    lose(score4);
                }
                else
                {

                    cout << "����������!!! �� ������ �������� ����� " << endl;
                    cout << "��� ������� ������� ����� 3";
                    Sleep(1000);
                    cout << "  2";
                    Sleep(1000);
                    cout << "  1";
                    Sleep(1000);
                    ShellExecute(0, 0, L"https://www.youtube.com/watch?v=hHpZ4fqFUIM", 0, 0, SW_SHOW);
                }
            }
        }

    }
}



int tutorial(char speedchouse, char mapchouse) {
    system("cls"); //������� ����� ������� ��� ������
    cout << "   1. ���� ����\n� ���� ������ �� ������ ������ ��� ����� ������ �����, 1 ������ - 10 �����\n" << endl;
    cout << "�� �� ��� ��� ������. �� �� ������ ������� � ������ (- , |) ��� ���� ����� (�), ������� ����� ������������� " << endl;
    cout << "   2. ����������� � ������ ���� ����������� ��� ���� AAA ���, ��� ������ ��� ���� AAA, � ������" << endl;
    cout << "w - �����, a - �����, s - ����, d - ������" << endl;
    cout << "���������� �� ������� ������ (" << char(1) << "), �� ������� ����� ��������� ����� (e)" << endl;
    cout << "� ������ �� ����� �����, ��� ����� �����������, �� ������ �����, � ����� �� ������������� � ��������������� ������� ����� " << endl;
    cout << "   3. �������� ����� � ������ �������, ��� ������ ����� ����, � ������� �� ������ ������� ������������ ��������� ����� " << endl;
    cout << "1 ����� - 400, 2 ����� - 200 �����, 3 ����� - 400 �����, 4 ����� - 350 �����" << endl;
    cout << "�� �� ������ �� ��, ��� ������ ���, � ����� ������ (����� ����������� ���� ����) ��� ��� ����� ����� ����� ������� " << endl;
    cout << "������� ����� ������, ����� ����� � ������� ���� " << endl;
    string lox; // ��������� ����������
    cin >> lox; // ����, ����� ������������ ��� ����� ����� ��� ���� ������� ��� ������
    int pchouse = 0;
    return pchouse;
}

void lose(int score) {
    system("cls"); //������ ����� ������� ��� ������
    cout << "##      ##    ###     ######  ######## ######## ########  " << endl;
    cout << "##  ##  ##   ## ##   ##    ##    ##    ##       ##     ##  " << endl;
    cout << "##  ##  ##  ##   ##  ##          ##    ##       ##     ##  " << endl;
    cout << "##  ##  ## ##     ##  ######     ##    ######   ##     ##  " << endl;
    cout << "##  ##  ## #########       ##    ##    ##       ##     ##  " << endl;
    cout << "##  ##  ## ##     ## ##    ##    ##    ##       ##     ##  " << endl;
    cout << " ###  ###  ##     ##  ######     ##    ######## ########  " << endl;
    cout << "�� ������� " << score << " ����(��)" << endl;
    cout << "������� ����� ������ ����� ��������� � ������� ���� " << endl;
    cout << "��������!!! ��� ��������� ���������!!!!" << endl;
    int k;
    cin >> k; //����, ����� ���� �� ����� ��������, � ����� ����� �������
    menu('2',1);
}

int menu(char speedchouse, char mapchouse) { //������� �������� ����  
    char hvostcolor = 1; //����� ������������ ����� ������
    char hvostout = 'e'; //������ ������� ������
    char pchouse; //���������� ������ ������������
    while (true)
    {
        system("cls"); //������� ������� �� ����������� ��� ������ ����
        cout << " #####  #     #    #    #    # #######     #####     #    #     # ####### " << endl;
        cout << "#     # ##    #   # #   #   #  #          #     #   # #   ##   ## #       " << endl;
        cout << "#       # #   #  #   #  #  #   #          #        #   #  # # # # #       " << endl;
        cout << " #####  #  #  # #     # ###    #####      #  #### #     # #  #  # #####    " << endl;
        cout << "      # #   # # ####### #  #   #          #     # ####### #     # #        " << endl;
        cout << "#     # #    ## #     # #   #  #          #     # #     # #     # #        " << endl;
        cout << " #####  #     # #     # #    # #######     #####  #     # #     # #######  " << endl;
        cout << "������� 1 ����� ������ ���� " << endl;
        cout << "������� 2 ����� ������ �������� ����" << endl;
        cout << "������� 3 ����� ����� � ��������� (��� ����� �������� �����) " << endl;
        cout << "������� 4 ����� ���������� �������� (��, �������� �� ������) " << endl;
        cout << "������� 5 ����� ����� �� ����" << endl;
        pchouse = 0;
        cin >> pchouse;

        if (pchouse == '1')
        {
            animation(mapchouse); //������������� �������� ����� �����
            int score = logick(speedchouse, mapchouse, 0, hvostcolor,hvostout); //������� ����� ����
            lose(score); //������ ��������� ������
        }
        else if (pchouse == '2')
        {
            animation(1); //������������� �������� ����� ������� ����
            storygame(speedchouse, hvostcolor, hvostout); 
        }
        else if (pchouse == '3')
        {
            pchouse = settings(speedchouse, mapchouse, hvostcolor, hvostout); //����� ��������  
        }
        else if (pchouse == '4')
        {
            pchouse = tutorial( speedchouse,  mapchouse); // ������ � ����� ������
        }
        else if (pchouse == '5')
        {
            break;
        }
    }
    return 0;
}




void main() {
    setlocale(0, "RUSSIAN");

   
    menu('2', 1);
    
    
}
