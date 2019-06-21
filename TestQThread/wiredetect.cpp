/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#include "wiredetect.h"

WireDetect::WireDetect( QObject *parent ) : QObject( parent )
{
    m_queue_size = 5;
}

/**
 * method: processData
 * @brief: TODO
 * @param str TODO
 * @return TODO
 */
void WireDetect::processData( QString str )
{
    /*here we accumulate the data to the specified num, then we process them at once */

    m_queue.enqueue( str );

    if( m_queue.count() >= m_queue_size )
    {
        qDebug() << "WireDetect id: " << QThread::currentThreadId();
        while( !m_queue.empty() )
        {
            QString str = m_queue.dequeue();
            qDebug() << "--------" << str;
        }
    }
}

/**
 * Moidfy History:
 * $Log
 */
