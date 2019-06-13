/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include <unistd.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;


/**
 * CLASS:  Producer
 * TODO: DESCRIPTION
 */
class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer( QObject *parent = nullptr );


    /**
     * method: produce
     * @brief: TODO
     *
     */
    void produce()
    {
        Mat tmp = imread( "openvino_test.png" );
        for( int i = 0; i < 1000000; i++ )
        {
            qDebug() << "Producer id: " << QThread::currentThreadId();
            sendData( tmp );
            usleep( 30000 );
        }
    }

signals:

    void sendData( Mat frame );


public slots:


    /**
     * method: run
     * @brief: TODO
     *
     */
    void run()
    {
        produce();
    }
};

#endif /* PRODUCER_H *//**
        * Moidfy History:
        * $Log
        */


/**
 * Moidfy History:
 * $Log
 */
