#include <iostream>
#include <fstream>
#include "BT.cpp"
#include <unistd.h>

using namespace std;
int rand_int(int n) {
    srand(time(0));
    return (int) ((rand() / (double) RAND_MAX) * (double) n);
}

void read_from_file(BT<int> &tree)
{
    ifstream inp;
    inp.open("/home/alexey/repos/bmstu_sem3/TiSD/Tisd6//file1");
    if(!inp.is_open()) { cout << "Cannot open file" << endl; return; }
    int x;
    while(inp >> x) {
        tree.insert(x);
    }
    inp.close();
}

void time_compare(BT<int> &tree){
    int t1,t2,t3,t4;
    ofstream inp;

    inp.open("/home/alexey/repos/bmstu_sem3/TiSD/Tisd6/file1",ios::in);
    inp.seekp(0, ios::end);
    int add=rand_int(1000);
    t1=clock();
    inp<<add<<endl;
    t2=clock();
    inp.flush();
    inp.close();

    t3=clock();
    tree.insert(add);
    t4=clock();
    cout << "Время добавления в файл "<< t2-t1<<endl;
    cout << "Время добавления в дерево "<< t4-t3<<endl;

}

int main(int argc, char* argv[]) {
    int a,tmp,b,col;
    BT<int> tree;
    char c;

    read_from_file(tree);
    while(true)
    {
        cout << "**************************************************************" << endl;
        cout << "Выберите одно из действий:" << endl;
        cout << "1: Отобразить дерево (graphviz)" << endl;
        cout << "2: Отобразить дерево (tree)" << endl;
        cout << "3: Добавить число в дерево" << endl;
        cout << "4: Удалить число из дерева" << endl;
        cout << "5: Поиск числа" << endl;
        cout << "6: Сравнение времени добавления числа" << endl; //TODO
        cout << "7: Вывести количество элеметов на уровне" << endl;
        cout << "8: Обход дерева" << endl;
        cout << "9: Закончить работу" << endl;
        cin >> a;
        switch(a) {
            case 1:
                tree.printer();
                system("/bin/bash /home/alexey/repos/bmstu_sem3/TiSD/Tisd6/file.sh");
                break;
            case 2:
                tree.show_as_tree(); break;
            case 3:
                //Вставка
                cout << "Введите число: " << endl;
                cin >> tmp;
                tree.insert(tmp);
                break;
            case 4:
                //Удаление
                cout << "Введите число: " << endl;
                cin >> tmp;
                if(tree.remove(tmp)) {
                    cout << "Число удалено" << endl;
                }
                else {
                    cout << "Дерево не содержит числа" << endl;
                }
                break;
            case 5:
                //Поиск
                cout << "Введите число " << endl;
                cin >> tmp;
                if(tree.find(tmp)) {
                    cout << "Число есть в дереве" << endl;
                }
                else {
                    cout << "Дерево не содержит числа" << endl;
                }
                break;
            case 6:
                time_compare(tree);
                break;
            case 7:
                tree.levels();
                break;
            case 8:
                cout << "1: Сверху вниз (корень, левый, правый) - префиксный обход" << endl;
                cout << "2: Слева направо (левый, корень, правый) - инфиксный обход (сортировка)" << endl;
                cout << "3: Сверху вниз (левый, правый, корень) - постфиксный обход" << endl;
                cin >> b;
                switch(b) {
                    case 1: tree.RootLeftRight(); break;
                    case 2: tree.LeftRootRight(); break;
                    case 3: tree.LeftRightRoot(); break;
                    default: cout << "Error command" << endl; break;
                }
                break;
            case 9:
                return 0;
            default:
                cout << "Команда не найдена";
                break;
        }
    }

}