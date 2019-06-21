/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#include "nestdetect.h"

NestDetect::NestDetect( QObject *parent ) : QObject( parent )
{
}

/**
 * method: processData
 * @brief: TODO
 * @param str TODO
 * @return TODO
 */
void NestDetect::processData( QString str )
{
    /*here we receive one data, process detection, then if the result has what we need, emit to other thread */
    qDebug() << "NestDetect id: " << QThread::currentThreadId();
    QString result = QString( "=======" ) + str + QString( "Nest!!!" );
    qDebug() << result;
}

/**
 * method: setDetect
 * @brief: TODO
 * @param val TODO
 * @return TODO
 */
void NestDetect::setDetect( bool val )
{
    m_mutex.lock();
    isDetect = val;
    m_mutex.unlock();
}

/**
 * method: getDetect
 * @brief: TODO
 * @return TODO
 */
bool NestDetect::getDetect()
{
    m_mutex.lock();
    bool tmp = isDetect;
    m_mutex.unlock();
    return tmp;
}

/**
 * method: setThresh
 * @brief: TODO
 * @param val TODO
 * @return TODO
 */
void NestDetect::setThresh( double val )
{
    m_mutex.lock();
    thresh = val;
    m_mutex.unlock();
}

/**
 * method: getThresh
 * @brief: TODO
 * @return TODO
 */
double NestDetect::getThresh()
{
    m_mutex.lock();
    double tmp = thresh;
    m_mutex.unlock();
    return tmp;
}

/**
 * Moidfy History:
 * $Log
 */
