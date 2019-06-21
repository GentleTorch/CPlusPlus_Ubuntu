/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#include "producer.h"

Producer::Producer( QObject *parent ) : QObject( parent )
{
}

/**
 * method: setRepo
 * @brief: TODO
 * @param ptr TODO
 * @return TODO
 */
void Producer::setRepo( Repository *ptr )
{
    repo = ptr;
}

/**
 * method: produceData
 * @brief: TODO
 * @return TODO
 */
void Producer::produceData()
{
    for( int i = 0; i < 1000000; i++ )
    {
        usleep( 10000 );
        qDebug() << "Produce id: " << QThread::currentThreadId();
        QString str = QString( "Produce: %1" ).arg( i );
        repo->addData( str );
    }

    /*once stop the producing, send a signal to end */
}

/**
 * Moidfy History:
 * $Log
 */
