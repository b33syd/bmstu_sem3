//
// Created by alexey on 24.10.16.
//
#include <iostream>
#define LIMIT 10
class StackArray
{

private:
        int pos;
        int maxlen;
        int *array;


        int newmem()
        {
            if(maxlen*2>=LIMIT) {
                std::cout << "Error: Full stack" << std::endl;
                return 1;
            }

            int *temparray=new int[maxlen*2];
            for (int i = 0; i <maxlen ; ++i) {
                temparray[i]=array[i];
            }
            maxlen*=2;
            delete[] array;
            array=temparray;
            return 0;
        }

public :
        StackArray()
        {
            pos=-1;
            maxlen=10;
            array=new int[maxlen];
        }

         ~StackArray()
         {
             pos=-1;
             maxlen=-1;
             try
             {
                 delete[](array);
             }
             catch (...){}

         }

        int Push(int val)
        {
            if(pos<0)
            {
                pos=-1;
            }
            pos++;
            if(pos==maxlen)
                if(newmem()==1)
                    return 1;
            array[pos]=val;
            return 0;

        }
    char reconverter(int k)
    {
        char id=0;
        switch(k)
        {
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

        int Pop()
        {
            int val;
            if(pos>=0)
            {
                val = array[pos];
                pos--;
            }
            else
            {
                val=-1;
                std::cout<<"Error: Empty stack"<<std::endl;
            }

            return val;
        }

        void Show()
        {
            for (int i = 0; i <=pos; ++i) {
                std::cout<<reconverter(array[i])<<" ";
            }
            std::cout<<std::endl;
        }

        int Size()
        {
            return sizeof(*array)*maxlen;
        }


    int IsEmpty()
    {
        if(pos==-1)
            return 0;
        else
            return -1;
    }



};


