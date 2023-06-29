#pragma once



int map1(vector<vector<char>>& field, int xcount, int ycount, int x, int y, int ax, int ay, vector<int> coorx, vector<int> coory, char hvsotout) {//Функция заполнения поля  

    for (size_t iy = 0; iy < 25; iy++)
    {
        vector<char> vec; // Временный вектор для заполнения общего вектора поля  
        if (iy == 0 || iy == 25 - 1)
        {
            for (size_t i = 0; i < 25; i++)
            {
                vec.push_back('-'); //Верхние и нижние границы поля  

            }
        }
        else
        {

            for (size_t jx = 0; jx < 25; jx++)
            {
                int count = 0;
                if (jx == 0 || jx == 25 - 1)
                {
                    vec.push_back('|'); //Боковые границы поля  
                }
                else if (iy == y && jx == x)
                {
                    vec.push_back(1); //Голова змеи  
                }
                else if (iy == ay && jx == ax)
                {

                    vec.push_back('a'); //Яблоко  
                }
                else
                {
                    for (size_t i = 1; i < coorx.size(); i++)
                    {
                        if (coorx[i] == jx && coory[i] == iy)
                        {
                            vec.push_back(hvsotout);
                            count++;
                        }
                    }
                    if (count == 0)
                    {
                        vec.push_back(' ');

                    }

                }
            }

        }


        field.push_back(vec); //Добавление временного вектора в обший массив поля  
    }
    return 0;
}
void map1test(vector<vector<char>>& field) {
    for (size_t iy = 0; iy < 25; iy++)
    {
        vector<char> vec; // Временный вектор для заполнения общего вектора поля  
        if (iy == 0 || iy == 25 - 1)
        {
            for (size_t i = 0; i < 25; i++)
            {
                vec.push_back('-'); //Верхние и нижние границы поля  

            }
        }
        else
        {

            for (size_t jx = 0; jx < 25; jx++)
            {
                int count = 0;
                if (jx == 0 || jx == 25 - 1)
                {
                    vec.push_back('|'); //Боковые границы поля  
                }
                else
                {
                    vec.push_back(' ');
                }
            }

        }
        field.push_back(vec);
    }
}
int map2(vector<vector<char>>& field, int xcount, int ycount, int x, int y, int ax, int ay, vector<int> coorx, vector<int> coory, char hvsotout) {//Функция заполнения поля  

    for (size_t iy = 0; iy < ycount; iy++)
    {
        vector<char> vec; // Временный вектор для заполнения общего вектора поля  
        if (iy == 0 || iy == ycount - 1)
        {
            for (size_t i = 0; i < xcount; i++)
            {
                if (i < 7 || i > 12)
                {
                    vec.push_back('-'); //Верхние и нижние границы поля 
                }
                else
                {
                    vec.push_back(' ');
                }
            }
        }
        else
        {

            for (size_t jx = 0; jx < xcount; jx++)
            {
                int count = 0;
                if ((jx == 0 || jx == xcount - 1) && (iy < 8 || iy > 12))
                {
                    vec.push_back('|'); //Боковые границы поля  
                }
                else if (iy == y && jx == x)
                {
                    vec.push_back(1); //Голова змеи  
                }
                else if (iy == 9 && (jx > 4 && jx < 15))
                {
                    vec.push_back('-');
                }
                else if (iy == ay && jx == ax)
                {

                    vec.push_back('a'); //Яблоко  
                }
                else
                {
                    for (size_t i = 1; i < coorx.size(); i++)
                    {
                        if (coorx[i] == jx && coory[i] == iy)
                        {
                            vec.push_back(hvsotout);
                            count++;
                        }
                    }
                    if (count == 0)
                    {
                        vec.push_back(' ');

                    }

                }
            }

        }


        field.push_back(vec); //Добавление временного вектора в обший массив поля  
    }
    return 0;
}
void map2test(vector<vector<char>> field) {
    for (size_t iy = 0; iy < 20; iy++)
    {
        vector<char> vec; // Временный вектор для заполнения общего вектора поля  
        if (iy == 0 || iy == 20 - 1)
        {
            for (size_t i = 0; i < 20; i++)
            {
                if (i < 7 || i > 12)
                {
                    vec.push_back('-'); //Верхние и нижние границы поля 
                }
                else
                {
                    vec.push_back(' ');
                }
            }
        }
        else
        {
            for (size_t jx = 0; jx < 20; jx++)
            {
                int count = 0;
                if ((jx == 0 || jx == 20 - 1) && (iy < 8 || iy > 12))
                {
                    vec.push_back('|'); //Боковые границы поля  
                }
                else if (iy == 9 && (jx > 4 && jx < 15))
                {
                    vec.push_back('-');
                }
                else
                {

                    if (count == 0)
                    {
                        vec.push_back(' ');

                    }

                }
            }

        }
        field.push_back(vec);
    }
}
void map3test(vector<vector<char>>& field) {
    for (size_t iy = 0; iy < 20; iy++)
    {
        vector<char> vec; // Временный вектор для заполнения общего вектора поля  
        if (iy == 0 || iy == 20 - 1)
        {
            for (size_t i = 0; i < 40; i++)
            {
                vec.push_back('-'); //Верхние и нижние границы поля  
            }
        }
        else
        {

            for (size_t jx = 0; jx < 40; jx++)
            {
                int count = 0;
                if (jx == 0 || jx == 40 - 1)
                {
                    vec.push_back('|'); //Боковые границы поля  
                }
                else if (iy == 3 && (jx > 5 && jx < 10))
                {
                    vec.push_back('-');
                }
                else if (jx == 6 && (iy >= 3 && iy < 6))
                {
                    vec.push_back('|');
                }
                else if (iy == 16 && (jx > 5 && jx < 10))
                {
                    vec.push_back('-');
                }
                else if (jx == 6 && (iy >= 14 && iy < 17))
                {
                    vec.push_back('|');
                }
                else if (iy == 3 && (jx >= 30 && jx < 34))
                {
                    vec.push_back('-');
                }
                else if (jx == 33 && (iy >= 3 && iy < 6))
                {
                    vec.push_back('|');
                }
                else if (iy == 16 && (jx >= 30 && jx < 34))
                {
                    vec.push_back('-');
                }
                else if (jx == 33 && (iy >= 14 && iy < 17))
                {
                    vec.push_back('|');
                }
                else
                {
                    vec.push_back(' ');
                }
            }

        }
        field.push_back(vec);
    }
}
int map3(vector<vector<char>>& field, int xcount, int ycount, int x, int y, int ax, int ay, vector<int> coorx, vector<int> coory, char hvsotout) {//Функция заполнения поля  

    for (size_t iy = 0; iy < 20; iy++)
    {
        vector<char> vec; // Временный вектор для заполнения общего вектора поля  
        if (iy == 0 || iy == 20 - 1)
        {
            for (size_t i = 0; i < 40; i++)
            {
                vec.push_back('-');
            }
        }
        else
        {

            for (size_t jx = 0; jx < 30; jx++)
            {
                int count = 0;
                if (jx == 0 || jx == 40 - 1)
                {
                    vec.push_back('|'); //Боковые границы поля  
                }
                else if (iy == y && jx == x)
                {
                    vec.push_back(1); //Голова змеи  
                }
                else if (iy == 3 && (jx > 5 && jx < 10))
                {
                    vec.push_back('-');
                }
                else if (jx == 6 && (iy >= 3 && iy < 6))
                {
                    vec.push_back('|');
                }
                else if (iy == 16 && (jx > 5 && jx < 10))
                {
                    vec.push_back('-');
                }
                else if (jx == 6 && (iy >= 14 && iy < 17))
                {
                    vec.push_back('|');
                }
                else if (iy == 3 && (jx >= 30 && jx < 34))
                {
                    vec.push_back('-');
                }
                else if (jx == 33 && (iy >= 3 && iy < 6))
                {
                    vec.push_back('|');
                }
                else if (iy == 16 && (jx >= 30 && jx < 34))
                {
                    vec.push_back('-');
                }
                else if (jx == 33 && (iy >= 14 && iy < 17))
                {
                    vec.push_back('|');
                }
                else if (iy == ay && jx == ax)
                {

                    vec.push_back('a'); //Яблоко  
                }
                else
                {
                    for (size_t i = 1; i < coorx.size(); i++)
                    {
                        if (coorx[i] == jx && coory[i] == iy)
                        {
                            vec.push_back(hvsotout);
                            count++;
                        }
                    }
                    if (count == 0)
                    {
                        vec.push_back(' ');

                    }

                }
            }

        }


        field.push_back(vec); //Добавление временного вектора в обший массив поля  
    }
    return 0;
}
void map4test(vector<vector<char>>& field) {
    for (size_t iy = 0; iy < 20; iy++)
    {
        vector<char> vec; // Временный вектор для заполнения общего вектора поля  
        if (iy == 0 || iy == 20 - 1)
        {
            for (size_t i = 0; i < 40; i++)
            {
                if (i < 14 || i > 26)
                {
                    vec.push_back('-'); //Верхние и нижние границы поля 
                }
                else
                {
                    vec.push_back(' ');
                }
            }
        }
        else
        {

            for (size_t jx = 0; jx < 40; jx++)
            {
                int count = 0;
                if ((jx == 0 || jx == 40 - 1) && (iy < 7 || iy > 12))
                {
                    vec.push_back('|'); //Боковые границы поля  
                }

                else if (iy == 3 && (jx > 5 && jx < 10))
                {
                    vec.push_back('-');
                }
                else if (jx == 6 && (iy >= 3 && iy < 6))
                {
                    vec.push_back('|');
                }
                else if (iy == 16 && (jx > 5 && jx < 10))
                {
                    vec.push_back('-');
                }
                else if (jx == 6 && (iy >= 14 && iy < 17))
                {
                    vec.push_back('|');
                }
                else if (iy == 3 && (jx >= 30 && jx < 34))
                {
                    vec.push_back('-');
                }
                else if (jx == 33 && (iy >= 3 && iy < 6))
                {
                    vec.push_back('|');
                }
                else if (iy == 16 && (jx >= 30 && jx < 34))
                {
                    vec.push_back('-');
                }
                else if (jx == 33 && (iy >= 14 && iy < 17))
                {
                    vec.push_back('|');
                }
                else if (iy == 10 && (jx >= 7 && jx <= 32))
                {
                    vec.push_back('-');
                }
                else
                {
                    vec.push_back(' ');
                }
            }

        }
        field.push_back(vec);
    }
}
void map4(vector<vector<char>>& field, int xcount, int ycount, int x, int y, int ax, int ay, vector<int> coorx, vector<int> coory, char hvsotout) {
    for (size_t iy = 0; iy < 20; iy++)
    {
        vector<char> vec; // Временный вектор для заполнения общего вектора поля  
        if (iy == 0 || iy == 20 - 1)
        {
            for (size_t i = 0; i < 40; i++)
            {
                if (i < 14 || i > 26)
                {
                    vec.push_back('-'); //Верхние и нижние границы поля 
                }
                else
                {
                    vec.push_back(' ');
                }
            }
        }
        else
        {

            for (size_t jx = 0; jx < 40; jx++)
            {
                int count = 0;
                if ((jx == 0 || jx == 40 - 1) && (iy < 7 || iy > 12))
                {
                    vec.push_back('|'); //Боковые границы поля  
                }
                else if (iy == y && jx == x)
                {
                    vec.push_back(1); //Голова змеи  
                }
                else if (iy == 3 && (jx > 5 && jx < 10))
                {
                    vec.push_back('-');
                }
                else if (jx == 6 && (iy >= 3 && iy < 6))
                {
                    vec.push_back('|');
                }
                else if (iy == 16 && (jx > 5 && jx < 10))
                {
                    vec.push_back('-');
                }
                else if (jx == 6 && (iy >= 14 && iy < 17))
                {
                    vec.push_back('|');
                }
                else if (iy == 3 && (jx >= 30 && jx < 34))
                {
                    vec.push_back('-');
                }
                else if (jx == 33 && (iy >= 3 && iy < 6))
                {
                    vec.push_back('|');
                }
                else if (iy == 16 && (jx >= 30 && jx < 34))
                {
                    vec.push_back('-');
                }
                else if (jx == 33 && (iy >= 14 && iy < 17))
                {
                    vec.push_back('|');
                }
                else if (iy == 10 && (jx >= 7 && jx <= 32))
                {
                    vec.push_back('-');
                }
                else if (iy == ay && jx == ax)
                {
                    vec.push_back('a'); //Яблоко  
                }
                else
                {
                    for (size_t i = 1; i < coorx.size(); i++)
                    {
                        if (coorx[i] == jx && coory[i] == iy)
                        {
                            vec.push_back(hvsotout);
                            count++;
                        }
                    }
                    if (count == 0)
                    {
                        vec.push_back(' ');

                    }
                }
            }

        }
        field.push_back(vec);
    }
}