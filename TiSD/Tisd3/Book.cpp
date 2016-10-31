//
// Created by alexey on 30.10.16.
//
#include <iostream>
#include <fstream>
#include "Book.h"


Book::Book() {

}

int Book::GetPages()
{
    return pages;
}

void Book::show()
{
    cout << "Автор: " << author_name << endl;
    cout << "Название: " << book_title << endl;
    cout << "Издательство: " << publisher << endl;
    cout << "Кол-во страниц: "<< pages << endl;

    cout << "Вид литературы: ";
    switch( book_t) {
        case technical:
            cout << "Техническая" << endl;
            book_record.tech.show();
            break;
        case art:
            cout << "Художественная" << endl;
            book_record.art.show();
            break;
    }
};

void Book::create_record() {

    int flag=0;

    cout << "Введите автора: ";
    //cin >>author_name;
    getline(std::cin,author_name,'\n');




    cout << "Введите название: ";
    //cin >>book_title;
    getline(std::cin,book_title,'\n');




    cout << "Введите издательство: ";
    //>publisher;
    getline(std::cin,publisher,'\n');



    {
        char str[LEN_STRING];
        int x;
        do {
            flag = 0;
            cout << "Введите количество страниц: ";
            cin.getline(str,LEN_STRING,'\n');
            char **end = NULL;
            x = strtol(str, end, 10);
            if (x <= 0 || x == LONG_MAX) {
                cout << "Ошибочный ввод" << endl;
                flag = 1;
            } else
                pages = x;
        } while (flag);
    }




    {
        char str[LEN_STRING];
        int x;
        do {
            flag = 0;
            cout << "Выберите вид литературы: \n0- Техническая, \n1- Художественная \n";
            cin.getline(str,LEN_STRING,'\n');
            char ** end = NULL;
            x = strtol(str, end, 10);
            if(x < 0 || x >1) {
                cout << "Ошибочный ввод" << endl;
                flag = 1;
            }
       } while (flag);


        book_t = type_book(x);

        switch(x)
        {
            case 0:
                book_record.tech.create_technical_book();
                break;
            case 1:
                book_record.art.create_art_book();
                break;
            default:
                cout << "Ошибочный ввод" << endl;
        }
    }

}

void art_book::create_art_book() {
    int flag=0;

    char str[LEN_STRING];
    int x;
    do {
        flag = 0;
        cout << "Выберите тип  произведения: \n0- роман, \n1- пьеса, \n2- стихи\n";
        cin.getline(str,LEN_STRING,'\n');
        char ** end = NULL;
        x = strtol(str, end, 10);
        if(x < 0 || x >2) {
            cout << "Ошибочный ввод" << endl;
            flag = 1;
        }
    } while (flag);


    switch(x)
    {
        case 0:
        case 1:
        case 2:
            art =kind_art(x);
            break;
        default:
            cout << "Ошибочный ввод" << endl;
    }


}

void technical_book::create_technical_book() {

    cout << "Введите отрасль: ";

    cin.getline( industry, sizeof industry );
    if(strlen(industry) > LEN_STRING) {
        cout << "Превышено кол-во симоволов!" << endl;

    }

    {
        int flag = 0;
        char str[LEN_STRING];
        int x;
        do {
            flag = 0;
            cout << "Выберите тип  произведения: \n0- отечественная, \n1- переводная\n";
            cin.getline(str,LEN_STRING,'\n');
            char **end = NULL;
            x = strtol(str, end, 10);
            if (x < 0 || x > 1) {
                cout << "Ошибочный ввод" << endl;
                flag = 1;
            }
        } while (flag);

        switch (x) {
            case 0:
            case 1:
                locate = kind_localization(x);
                break;
            default:
                cout << "Ошибочный ввод" << endl;
        }
    }

    {
        int flag = 0;
        char str[LEN_STRING];
        int x;
        do {
            flag = 0;
            cout << "Введите год издания: ";

            cin.getline(str,LEN_STRING,'\n');
            char **end = NULL;
            x = strtol(str, end, 10);
            if (x < 0 || x > 2017) {
                cout << "Ошибочный ввод" << endl;
                flag = 1;
            }
        } while (flag);

        year=x;
    }

}

void art_book::show() {

    cout << "Тип  произведения: ";
    switch(art)
    {
        case  novels:
            cout << "роман" << endl;
            break;
        case   plays:
            cout << "пьеса" << endl;
            break;
        case poems:
            cout << "стихи" << endl;
            break;
    }
}

void technical_book::show() {

    cout << "Отрасль: "<<industry << endl;

    cout << "Тип  произведения: ";
    switch(locate)
    {
        case  patriotic:
            cout << "отечественная" << endl;
            break;
        case  translated:
            cout << "переводная" << endl;
            break;
    }

    cout << "Год издания: "<<year<<endl;

}

void Book::read_from_file(istream &fin) {


    fin >> author_name;
    fin >> book_title;
    fin >> publisher;
    fin >> pages;
    int x;
    fin >>x;
    book_t = type_book(x);

    if(x==0)
    {
        fin >>book_record.tech.industry;
        fin>>x;
        book_record.tech.locate = kind_localization(x);
        fin>>book_record.tech.year;
    }
    else
    {
        int x;
        fin >>x;
        book_record.art.art =kind_art(x);
    }


};



//Вывести список всей переводной лит-ры по указанной отрасли с годом издания не позднее указанного.

bool Book::search(int year,char *ind)
{
    if(book_t!=technical)
        return false;
    if(book_record.tech.locate!=translated)
        return false;

    if(strcmp(book_record.tech.industry,ind)!=0)
        return false;

    if(book_record.tech.year>year)
        return false;

    return true;


}