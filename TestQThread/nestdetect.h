/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef NESTDETECT_H
#define NESTDETECT_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMutex>


/**
 * CLASS:  NestDetect
 * TODO: DESCRIPTION
 */
class NestDetect : public QObject
{
    Q_OBJECT
public:
    explicit NestDetect( QObject *parent = nullptr );

    void setDetect( bool val );


    void setThresh( double val );


    bool getDetect();


    double getThresh();


signals:

public slots:

    void processData( QString str );


    void recvVarDetect( bool val );


    void recvVarThresh( double thresh );


private:
    QMutex m_mutex;
    bool isDetect	= false;
    double thresh	= 0.9;
};

#endif /* NESTDETECT_H *//**
        * Moidfy History:
        * $Log
        */


/**
 * Moidfy History:
 * $Log
 */
