#include "widget.h"
#include <QApplication>
#include <iostream>
#include <QtCore>
#include <QtGui>
#include <io.h>
//new comment
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

        const int уndBuf=4;
        const int buferSize=1024;
        int remainder = buferSize,length=0,offset=0;
        char bufer[buferSize];

        test.read(bufer,buferSize);

    while(!test.atEnd())
        {
            if (remainder < endBuf)
            {
                for(int j=0; j<remainder;j++)
                {
                    bufer[j]=bufer[buferSize-offset+j];
                }
                test.read(&bufer[remainder],buferSize-remainder);
                offset = 0;
                remainder = buferSize;
            }


            for(int i=0;i<4;i++)
            {

                    h.data[i]=bufer[i+offset];

              }
            remainder=buferSize-offset;
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
                test.read(&bufer[remainder],buferSize-remainder);
                offset = 0;
                remainder = buferSize;
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



