/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#include "repository.h"

Repository::Repository()
{
    m_queue_max_size = 10;
}

/**
 * method: addData
 * @brief: TODO
 * @param str TODO
 * @return TODO
 */
void Repository::addData( QString str )
{
    m_queue_mutex.lock();

    if( m_queue.count() > m_queue_max_size )
    {
        m_queue_not_full.wait( &m_queue_mutex );
    }

    m_queue.enqueue( str );
    m_queue_not_empty.wakeAll();

    qDebug() << str;
    m_queue_mutex.unlock();
}

/**
 * method: getData
 * @brief: TODO
 * @return TODO
 */
QString Repository::getData()
{
    m_queue_mutex.lock();
    if( m_queue.isEmpty() )
    {
        m_queue_not_empty.wait( &m_queue_mutex );
    }

    QString str = m_queue.dequeue();
    qDebug() << "Consume: " << str;

    m_queue_not_full.wakeAll();
    m_queue_mutex.unlock();
    return str;
}

/**
 * Moidfy History:
 * $Log
 */
