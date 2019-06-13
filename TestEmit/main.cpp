/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#include <QCoreApplication>
#include <QMetaType>
#include <unistd.h>
#include "producer.h"
#include "consumer.h"


/**
 * method: main
 * @brief: TODO
 * @param argc TODO
 * @param argv TODO
 * @return TODO
 */
int main( int argc, char *argv[] )
{
    QCoreApplication a( argc, argv );

    qDebug() << "Main id: " << QThread::currentThreadId();

    qRegisterMetaType<Mat>( "Mat" );
    qRegisterMetaType<Mat>( "Mat&" );

/*    Mat		tmp = imread( "openvino_test.png" ); */

/*    TransimitData	sender, receiver; */


/*
 *    QObject::connect( &sender, &TransimitData::sendData, &receiver, &TransimitData::recvData );
 *    for( int i = 0; i < 10000000; i++ )
 *    {
 *        qDebug() << "num: " << i;
 *        sender.sendData( tmp );
 *        usleep( 30000 );
 *    }
 */

    Producer	source;
    Consumer	dest;

    QThread		one, two;
    source.moveToThread( &one );
    dest.moveToThread( &two );

    QObject::connect( &source, &Producer::sendData, &dest, &Consumer::recvData );
    QObject::connect( &one, &QThread::started, &source, &Producer::run );

    two.start();
    one.start();

    return a.exec();
}

/**
 * Moidfy History:
 * $Log
 */
