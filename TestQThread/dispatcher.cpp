/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#include "dispatcher.h"

Dispatcher::Dispatcher( QObject *parent ) : QObject( parent )
{
}

/**
 * method: setRepo
 * @brief: TODO
 * @param ptr TODO
 * @return TODO
 */
void Dispatcher::setRepo( Repository *ptr )
{
    repo = ptr;
}

/**
 * method: consumeData
 * @brief: TODO
 * @return TODO
 */
void Dispatcher::consumeData()
{
    /*here we can emit data to other threads, process */
    for( int i = 0; i < 1000000; i++ )
    {
        usleep( 5000 );
        qDebug() << "Consume id: " << QThread::currentThreadId();
        QString str = repo->getData();
        emit	data( str );
    }
}

/**
 * Moidfy History:
 * $Log
 */
