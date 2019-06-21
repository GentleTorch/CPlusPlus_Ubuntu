/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QString>
#include <QQueue>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>

#include <unistd.h>


/**
 * CLASS:  Repository
 * TODO: DESCRIPTION
 */
class Repository
{
public:

    Repository();

    void addData( QString str );


    QString getData();


private:
    QWaitCondition m_queue_not_empty;
    QWaitCondition m_queue_not_full;
    QMutex m_queue_mutex;
    int m_queue_max_size;
    QQueue<QString> m_queue;
};

#endif /* REPOSITORY_H */


/**
 * Moidfy History:
 * $Log
 */
