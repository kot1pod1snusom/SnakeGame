#include "Header.h"
#include "maps.h"



int logick(char speedchouse, char mapchouse, int storykey, char& hvostcolor, char& hvostout);
void main();
int menu(char speedchouse , char mapchouse);
void lose(int score);
int mapsettings(char speedchouse, char mapchouse);

void kat(int xcount, int ycount, int x, int y, int ax, int ay, int score, vector<int> coorx, vector<int> coory, int dlinahvosta, char mapchouse, vector<vector<char>>& field,  char& hvostcolor, char& hvostout) { //Фунция вывода  
    
    // какую карту выбрал пользователь
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

    // Вывод поля
    for (size_t i = 0; i < field.size(); i++)
    {
        for (size_t j = 0; j < field[i].size(); j++)
        {
            if (field[i][j] == 'a')
            {
                SetConsoleTextAttribute(hand, Red);
                cout << field[i][j]; //Вывод поля  
                SetConsoleTextAttribute(hand, White);
                j++;
            }
            else if (field[i][j] == 1)
            {
                SetConsoleTextAttribute(hand, LightWhite);
                cout << field[i][j]; //Вывод поля  
                SetConsoleTextAttribute(hand, White);
                j++;
            }
            else if (field[i][j] == hvostout)
            {
                if (hvostcolor == '1') // Сравнение выбора пользователся
                {
                    SetConsoleTextAttribute(hand, White); //Хвост белый
                }
                else if (hvostcolor == '2')
                {
                    SetConsoleTextAttribute(hand, (rand() % 14) + 1); //РГБ хвост
                }
                cout << field[i][j];
                SetConsoleTextAttribute(hand, White);
                j++;
            }
            cout << field[i][j]; //Вывод поля  
        }
        cout << endl;
    }


    cout << "Счет " << score << endl;

}
void move(char& tempmove, int& x, int& y, int mapchouse) { // Функция движения

    if (_kbhit())
    {
        switch (_getch()) //Нажатие клавиши и задача направления  
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
    else //Если нет нажатия, то змейка двигается по заданному направлению дальше  
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

    // Все ниже - телепортация головы змейки на противоположную сторону там, где нет стенок. Сделанно при помощи изменение координат головы
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
int kolisia(int dlinahvosta, vector<int> coorx, vector<int> coory, int x, int y,vector<vector<char>> field) { // Функция коллизии
    int lose = 0; //Переменная проиграл игрок (1) или нет (0) 
   
    for (size_t i = 2; i < dlinahvosta; i++) //Игрок коснулся хвоста
    {
        if (coorx[i] == x && coory[i] == y)
        {
            lose = 1;
        }
    }

    char k = ' '; //Голова яблока в чаре
    for (size_t i = 0; i < field.size(); i++)
    {   
        for (size_t j = 0; j < field[i].size(); j++)
        {
            if (x == j && i == y)
            {
                k = field[i][j];
            }

            if (k == '|' || k == '-') // Если голова яблока коснулась стены
            {
                lose = 1;
            }
        }
    }
    return lose;
}


void preobrazovanie(char& mapchouse, char speedchouse, int& x, int& y, int& xcount, int& ycount, float& speed, int storykey, int& maxhvost) {
    switch (mapchouse) //Конвертация размера поля в координаты и задавание координат спавна головы змейки  
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

    switch (speedchouse) //Конвертация сложности в число int, которое будет использоваться в Sleep  
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

    if (storykey == 1) // Для сюжетного режима конвертация в зависимости от карты
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

void applespawn(int& ax, int& ay, vector<int> coorx, vector<int> coory, int xcount, int ycount, vector<vector<char>> field) { // Генерация яблока
here: //СЮда мы возвращаеся если яблоко заспавнилось там где не надо
    ax = rand() % (xcount - 3) + 2; // Генерация x координаты яблкоа
    ay = rand() % (ycount - 3) + 2; // Генерация у координаты яблока

    for (size_t i = 0; i < coorx.size(); i++)
    {
        if (ax == coorx[i] && ay == coory[i]) // Проверка касания яблока с хвостом
        {
            goto here;
        }
    }

    
    for (size_t i = 0; i < field.size(); i++)
    {
        for (size_t j = 0; j < field.size(); j++)
        {
            if (field[i][j] == '-' || '|') // Если координата - стена
            {
                if (ax == j && ay == i) // И если яблоко в ней заспавнилось
                {
                    goto here; //Все по новой
                }
            }
        }
    }

  
}

int logick(char speedchouse, char mapchouse, int storykey, char& hvostcolor, char& hvostout) { //Логика  
    float speed = 0; //Скорость 
    int xcount = 20; //Длина поля  
    int ycount = 20; //Ширина поля  
    int x = 10; //х координата головы змеи  
    int y = 10; //у координата головы змеи  
    int maxhvost = -1; 
    preobrazovanie(mapchouse, speedchouse, x, y, xcount, ycount, speed, storykey, maxhvost); //Данные, полученные игроков, преобразуются в значения для использования
    Sleep(speed);
    char tempmove = 0; //Является направление змейки  
    int ax = rand() % (xcount - 3) + 2;
    int ay = rand() % (ycount - 3) + 2;
    int score = 0; //счет игрока  
    int dlinahvosta = 0;
    vector<int> coorx; //Массив с x координатами хвоста змеи
    vector<int> coory; //Массив с y координатами хвоста змеи
    vector<vector<char>> field; //Массив поля 
    while (true)
    {
        field.clear(); //Чистка массива поля
        if (ax == x && ay == y) //Если игрок "съел" яблоко
        {
            applespawn(ax, ay, coorx, coory, xcount, ycount,field); // Проверка на касание с другими предметами яблока

            score += 10;
            dlinahvosta++;
            coorx.push_back(x);
            coory.push_back(y);
        }
        kat(xcount, ycount, x, y, ax, ay, score, coorx, coory, dlinahvosta, mapchouse, field, hvostcolor, hvostout); //Функция отвечает за вывод
        if (storykey > 0)
        {
            cout << "Цель - " << maxhvost * 10 << " очков" << endl;
        }
        
        
        move(tempmove, x, y, mapchouse); //Функция отвечает за движение головы змеи
        Sleep(speed); //При помощи этой строки делается сложность (ну я хз как еще сказать, не бейте)


        int lose = kolisia(dlinahvosta, coorx, coory, x, y, field);
        if (lose == 1) // Если колизия дала положительный результат (1) (игрок коснулся стены)
        {
            return score; // То он проиграл
        }

    
        for (int i = dlinahvosta - 1; i > 0; i--) // Здесь образуется хвост, координаты каждого ребра которого находятся в массиве
        {

            coorx[i] = coorx[i - 1];
            coory[i] = coory[i - 1];
            coorx[0] = x;
            coory[0] = y;

        }

        if (dlinahvosta == maxhvost) // Если игрок набрал нужное количство яблок для прохождение далее
        {
            return -1;
        }


        system("cls");
    }
}



int settings(char& speedchouse, char mapchouse, char& hvostcolor, char& hvostout) { //Функция настроек  
    system("cls");
    cout << "Настройки" << endl;
    cout << "Введите 1 чтобы поменять карту " << endl;
    cout << "Введите 2 если хотите поменять сложность игры (скорость змейки)" << endl;
    cout << "Введите 3 чтобы кастомезировать змейку змейки " << endl;
    cout << "Введите 4 для выхода в главное меню " << endl;
    int pc;
    cin >> pc;
    int pchouse = 0;
    if (pc == 1)
    {
        int pchouse = mapsettings(speedchouse, mapchouse); 
    }
    else if (pc == 2)
    {
        cout << "1 - легко\n 2 - средне\n 3 - сложно\n 4 - солс" << endl;
        cin >> speedchouse; //Ввод пользователя выбранного варианта 
    }
    else if (pc == 3)
    {
        cout << "1 - Поменять символ хвоста змейки" << endl;
        cout << "2 - Выбрать цвет хвоста " << endl;
        char da;
        cin >> da;
        if (da == '1')
        {
            cout << "Сейчас символ хвоста змейки - "  << hvostout << endl;
            cout << "Введите новый символ хвоста змейки " << endl;
            cin >> hvostout;
        }
        else if (da == '2')
        {
            cout << "1 - Хвост только белого цвета" << endl;
            cout << "2 - РГБ змейка " << endl;
            cin >> hvostcolor;
        }
        
    }
    else if (pc == 4)
    {
        return pchouse; 
    }
    return 0;
}

int mapsettings(char speedchouse, char mapchouse) { //Функция настроек карты
    int pc = 0; // Выбор игрока
    int pchouse = 0;
    while (pc != 6)
    {

        system("cls");
        int maptemp = mapchouse; // Переменная для вывода номера карты
        cout << "Сейчас выбранна карта номер " << maptemp << endl;
        cout << "Какую карту хотите выбрать? " << endl;
        cout << "1 - Пустая карта " << endl;
        cout << "2 - Карта с перегородкой посередине" << endl;
        cout << "3 - Карты с 4 стенками " << endl;
        cout << "4 - Карта с 4 стенками и перегородкой" << endl;
        cout << "5 - Предпосмотр карт" << endl;
        cout << "6 - Вернуться в меню " << endl;
        cin >> pc; // Ввод пользователся
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
            cout << "Какую карту хотите посмотреть? " << endl;
            cout << "1 - Пустая карта\n2 - Карта с перегородкой\n3 - Карта с 4 стенками\n4 - Карта с 4 стнеками и перегородкой " << endl;
            char temp; //Выбор пользователя
            cin >> temp; // Ввод пользователся
            vector<vector<char>> field; // Вектор поля
            system("cls");
            if (temp == '1') // В ниже функциях функция вектор поля будет заполняться
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
                    cout << field[i][j]; //Вывод поля
                }
                cout << endl;
            }
            cout << "Введите любую букву или число чтобы продолжить " << endl; 
            cin >> temp; //Ввод чтобы пользователь выбрал когда надо продолжить
        }
    }

    menu(speedchouse, mapchouse);
    return 0;
}

void animation(char mapchouse) {
    int tempsc = 1; //Переменные с temp нужны только для запуска функции
    int xcount,ycount;
    float temps;
    int x = 0; //Начальная координата головы по x
    int y = 0;//Начальная координата головы по y
    preobrazovanie(mapchouse, '1', x, y, xcount, ycount, temps, 0, tempsc); 


    SetConsoleTextAttribute(hand, White);
    COORD left{ y - 5, x }; // Нижняя голова
    COORD right{ y + 5,x }; // Верхняя голова
    while (left.X != right.X)
    {
        system("cls");
        cout << "Идет загрузка карты...... " << endl;
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
    int score1 = logick(speedchouse, '1', 1, hvostcolor, hvostout); // Первая карта
    if (score1 != -1) // Если игрок не прошел карту (проиграл)
    {
        lose(score1);
    }
    else
    {
        animation(2);
        int score2 = logick(speedchouse, '2', 2, hvostcolor, hvostout); // Вторая карты
        if (score2 != -1) // Если игрок проиграл
        {
            lose(score2);
        }
        else
        {
            animation(3);
            int score3 = logick(speedchouse, '3', 3, hvostcolor, hvostout); // Третья карты ну и тд короче
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

                    cout << "Поздравляю!!! Вы прошли сюжетный режим " << endl;
                    cout << "Вас ожидает подарок через 3";
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
    system("cls"); //Очистка всего лишнего для вывода
    cout << "   1. Цель игры\nВ игре змейка вы должны съесть как можно больше яблок, 1 яблоко - 10 очков\n" << endl;
    cout << "Но не все так просто. Вы не можете врезать в стенки (- , |) или свой хвост (е), который будет увеличиваться " << endl;
    cout << "   2. Управлнение в данной игре стандартное для всех AAA игр, что делает эту игру AAA, а именно" << endl;
    cout << "w - вверх, a - влево, s - вниз, d - вправо" << endl;
    cout << "Управляете вы головой змейки (" << char(1) << "), за которой будет двигаться хвост (e)" << endl;
    cout << "В местах по краям карты, где стена отсутствует, вы можете зайти, и тогда вы переместитесь в провотиположную сторону карты " << endl;
    cout << "   3. Сюжетный режим в змейке условен, это просто набор карт, в которых вы должны набрать определенное количство очков " << endl;
    cout << "1 карта - 400, 2 карта - 200 очков, 3 карта - 400 очков, 4 карта - 350 очков" << endl;
    cout << "Но не смотря на то, что сюжета нет, в конце режима (после прохождение всех карт) вас все равно будет ждать сюрприз " << endl;
    cout << "Введите любой символ, чтобы выйти в главное меню " << endl;
    string lox; // Временная переменная
    cin >> lox; // Ввод, чтобы пользователь сам реишл когда ему надо закрыть эту фунцию
    int pchouse = 0;
    return pchouse;
}

void lose(int score) {
    system("cls"); //Оистка всего лишнего для вывода
    cout << "##      ##    ###     ######  ######## ######## ########  " << endl;
    cout << "##  ##  ##   ## ##   ##    ##    ##    ##       ##     ##  " << endl;
    cout << "##  ##  ##  ##   ##  ##          ##    ##       ##     ##  " << endl;
    cout << "##  ##  ## ##     ##  ######     ##    ######   ##     ##  " << endl;
    cout << "##  ##  ## #########       ##    ##    ##       ##     ##  " << endl;
    cout << "##  ##  ## ##     ## ##    ##    ##    ##       ##     ##  " << endl;
    cout << " ###  ###  ##     ##  ######     ##    ######## ########  " << endl;
    cout << "Вы набрали " << score << " очка(ов)" << endl;
    cout << "Введите любой символ чтобы вернуться в главное меню " << endl;
    cout << "ВНИМАНИЕ!!! Все настройки сбросятся!!!!" << endl;
    int k;
    cin >> k; //Ввод, чтобы меню не сраху вывелось, а когда игрок захочет
    menu('2',1);
}

int menu(char speedchouse, char mapchouse) { //Функция главного меню  
    char hvostcolor = 1; //Выбор пользоваетля цвета змейки
    char hvostout = 'e'; //Символ звеньев змейки
    char pchouse; //Переменная выбора пользователя
    while (true)
    {
        system("cls"); //Очистка консоли от ненужноного для вывода меню
        cout << " #####  #     #    #    #    # #######     #####     #    #     # ####### " << endl;
        cout << "#     # ##    #   # #   #   #  #          #     #   # #   ##   ## #       " << endl;
        cout << "#       # #   #  #   #  #  #   #          #        #   #  # # # # #       " << endl;
        cout << " #####  #  #  # #     # ###    #####      #  #### #     # #  #  # #####    " << endl;
        cout << "      # #   # # ####### #  #   #          #     # ####### #     # #        " << endl;
        cout << "#     # #    ## #     # #   #  #          #     # #     # #     # #        " << endl;
        cout << " #####  #     # #     # #    # #######     #####  #     # #     # #######  " << endl;
        cout << "Введите 1 чтобы начать игру " << endl;
        cout << "Введите 2 чтобы начать сюжетную игру" << endl;
        cout << "Введите 3 чтобы зайти в настройки (тут можно поменять карту) " << endl;
        cout << "Нажмите 4 чтобы посмотреть туториал (да, туториал по змейке) " << endl;
        cout << "Нажмите 5 чтобы выйти из игры" << endl;
        pchouse = 0;
        cin >> pchouse;

        if (pchouse == '1')
        {
            animation(mapchouse); //использование анимации перед игрой
            int score = logick(speedchouse, mapchouse, 0, hvostcolor,hvostout); //Функция самой игры
            lose(score); //Фунция поражения игрока
        }
        else if (pchouse == '2')
        {
            animation(1); //Использование анимации перед стартом игры
            storygame(speedchouse, hvostcolor, hvostout); 
        }
        else if (pchouse == '3')
        {
            pchouse = settings(speedchouse, mapchouse, hvostcolor, hvostout); //Вызов настроек  
        }
        else if (pchouse == '4')
        {
            pchouse = tutorial( speedchouse,  mapchouse); // Фунция с вывод текста
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
