#include <iostream>
#include "stackarray.cpp"
#include "stacklist.cpp"
#include <cstring>

char reconverter(int k)
{
    char id=0;
    switch(k)
    {
        case -1:
            id=' ';
            break;
        case 1:
            id='(';
            break;
        case 2:
            id=')';
            break;

        case 3:
            id='[';
            break;
        case 4:
            id=']';
            break;

        case 5:
            id='{';
            break;
        case 6:
            id='}';
            break;
    }
    return id;
}

int converter(char k)
{
    int id=0;
    switch(k)
    {
        case '(':
            id=1;
            break;
        case ')':
            id=2;
            break;

        case '[':
            id=3;
            break;
        case ']':
            id=4;
            break;

        case '{':
            id=5;
            break;
        case '}':
            id=6;
            break;

    }
    return id;
}


template <class T>
int work(T ST1,const std::string input)
{
    time_t t1 = clock();

    int temp;
    int code=0;
    for (int i=0; i<input.length() &&(code==0);i++)
    {
        temp=converter(input[i]);
        //ST1->Show();
        if (temp==0)
            code=0;
        else {
            if (temp % 2 == 1)
            {
                if(ST1->Push(temp)==0)
                    code=0;
                else
                    code =-1;
            }
            else {
                int st1=ST1->Pop();

                if(st1==temp-1)
                    code=0;
                else
                    code =-1;
            }
        }
    }


    if(ST1->IsEmpty()!=0)
        code =-1;

    std::cout << "          Время выполнения проверки: "  << clock() -t1<< "ms"<<std::endl;
    std::cout << "          Использованная память: "  << ST1-> Size()<<"byte " <<std::endl;


    std::cout << "Результат проверки: ";
    if(code==0)
        std::cout << "Правильная последовательность скобок" << std::endl;
    else
        std::cout << "Неправильная последовательность скобок" << std::endl;
    

    return code;
}

int main() {

    StackArray ST1= StackArray();
    StackList ST2= StackList();
    std::string input;
    std::string input2;
    int code;

    //std::cout << "Введите скобочную последовательность для проверки" << std::endl;
    //std::cin>>input;

    //std::cout << "Проверка последовательности при помощи стека с использованием массива" << std::endl;
    //code=work(&ST1,input);

    //std::cout << "Проверка последовательности при помощи стека с использованием списка" << std::endl;
    //code=work(&ST2,input);


    //ST2.ShowADD();
    int id_of_work=0;
    while(id_of_work!=-1) {
        std::cout << std::endl;
        std::cout << "Для редактирования стека нажмите 1 и введите дополнительные элементы последовательности"
                  << std::endl;
        std::cout << "Для печати стека нажмите 2" << std::endl;
        std::cout << "Для добавления элемента в стек нажмите 3 и введите символ (только скобки)" << std::endl;
        std::cout << "Для удаления элемента из стека нажмите 4" << std::endl;
        std::cout << "Для вывода адресов нажмите 5" << std::endl;
        std::cout << "Для выхода нажмите -1 или любое другое число " << std::endl;


        std::cin >> id_of_work;
        switch (id_of_work) {
            case (1): {
                std::cout << "Введите элементы" << std::endl;
                std::cin >> input;

                std::cout << "Проверка последовательности при помощи стека с использованием массива" << std::endl;
                code = work(&ST1, input);

                std::cout << "Проверка последовательности при помощи стека с использованием списка" << std::endl;
                code = work(&ST2, input);
                ST2.ShowADD();

                break;
            }

            case (2): {
                std::cout << "Печать стека-массива (Добавление в конец массива)" << std::endl;
                ST1.Show();
                std::cout << "Печать стека-списка (Добавление в начало списка)" << std::endl;
                ST2.Show();
                break;
            }
            case (3): {
                std::cout << "Добавление скобки. Укажите скобку" << std::endl;
                char in;
                std::cin >> in;

                int temp = converter(in);
                if (temp == 0)
                    std::cout << "Ошибка" << std::endl;
                else {
                    ST1.Push(temp);
                    ST2.Push(temp);
                }
                break;
            }
            case (4): {

                    std::cout << "Извлечено из списка-массива:" << reconverter(ST1.Pop()) << std::endl;
                    std::cout << "Извлечено из списка-списка: " << reconverter(ST2.Pop()) << std::endl;
                    break;

            }
            case (5): {

                ST2.ShowADD();
                break;

            }


            default:
                id_of_work = -1;

        }
    }



    return 0;
}