/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef WIREDETECT_H
#define WIREDETECT_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QQueue>


/**
 * CLASS:  WireDetect
 * TODO: DESCRIPTION
 */
class WireDetect : public QObject
{
    Q_OBJECT
public:
    explicit WireDetect( QObject *parent = nullptr );

signals:

public slots:

    void processData( QString str );


    void recvVarSpin( bool isSpin );


private:

    int m_queue_size;
    QQueue<QString> m_queue;
};

#endif /* WIREDETECT_H *//**
        * Moidfy History:
        * $Log
        */


/**
 * Moidfy History:
 * $Log
 */
