#include "widget.h"
#include <QApplication>
#include <iostream>
#include <QtCore>
#include <QtGui>
#include <io.h>
//new commet
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
using namespace std;

        QFile test("test.dat");//and this

        qDebug() << test.fileName();

        if (!test.open(QIODevice::ReadOnly))
        {
            qDebug() <<"Ошибка открытия" ;
            return 1;
        };
        union head
        {
            struct
            {
             uint size :12;
             uint type :10;
             uint line :6;
             uint none :4;

            };
            char data[4]; 
        };
        head h;

        const int EndBuf=4;
        const int BuferSize=1024;
        int remainder = BuferSize,length=0,offset=0;
        char bufer[BuferSize];

        test.read(bufer,BuferSize);

    while(!test.atEnd())
        {
            if (remainder < EndBuf)
            {
                for(int j=0; j<remainder;j++)
                {
                    bufer[j]=bufer[BuferSize-offset+j];
                }
                test.read(&bufer[remainder],BuferSize-remainder);
                offset = 0;
                remainder = BuferSize;
            }


            for(int i=0;i<4;i++)
            {

                    h.data[i]=bufer[i+offset];

              }
            remainder=BuferSize-offset;
            length=(h.size+1)*4;

            qDebug()<<"\n"<<"Длина сообщения:"<< length ;


          for(int i=0; i<length; i++)
           {
                qDebug("0x%X", bufer[i+offset]);
           }
            if (remainder < length)
            {    
                for(int j=0; j < remainder;j++)
                {
                    bufer[j]=bufer[offset+j];
                }
                test.read(&bufer[remainder],BuferSize-remainder);
                offset = 0;
                remainder = BuferSize;
            }
            else
            {
                offset=offset+length;
                qDebug() << "file readed" << test.pos() << "bytes";
            }
        }

   return app.exec();
       test.close();


        }



