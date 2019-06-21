/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#include <QCoreApplication>
#include "repository.h"
#include "producer.h"
#include "dispatcher.h"
#include "nestdetect.h"
#include "wiredetect.h"
#include "actioncontroller.h"
#include "utils.h"


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

    qInstallMessageHandler( outputMessage );

    qDebug() << "Main id: " << QThread::currentThreadId();

    ActionController controller;
    controller.setIP( "127.0.0.1" );
    controller.setPort( 24684 );
    controller.run();


/*
 * *    Repository	repo;
 * *    Producer	pro;
 * *    pro.setRepo( &repo );
 * *    Dispatcher	mid;
 * *    mid.setRepo( &repo );
 * * /
 */


/*
 *    NestDetect	nest;
 *    WireDetect	wire;
 */


/*
 *    QThread		one, two, three, four;
 *    pro.moveToThread( &one );
 *    mid.moveToThread( &two );
 *    nest.moveToThread( &three );
 *    wire.moveToThread( &four );
 */


/*
 *    QObject::connect( &one, &QThread::started, &pro, &Producer::produceData );
 *    QObject::connect( &two, &QThread::started, &mid, &Dispatcher::consumeData );
 *    QObject::connect( &mid, &Dispatcher::data, &nest, &NestDetect::processData );
 *    QObject::connect( &mid, &Dispatcher::data, &wire, &WireDetect::processData );
 */


/*
 *    one.start();
 *    two.start();
 *    three.start();
 *    four.start();
 */

/*    qDebug() << "End of test";*/

    return a.exec();
}

/**
 * Moidfy History:
 * $Log
 */
