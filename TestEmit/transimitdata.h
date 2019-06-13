/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef TRANSIMITDATA_H
#define TRANSIMITDATA_H

#include <QObject>
#include <QDebug>
#include <QThread>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;


/**
 * CLASS:  TransimitData
 * TODO: DESCRIPTION
 */
class TransimitData : public QObject
{
    Q_OBJECT
public:
    explicit TransimitData( QObject *parent = nullptr );

signals:
    void sendData( Mat frame );


public slots:


    /**
     * method: recvData
     * @brief: TODO
     * @param tmp TODO
     */
    void recvData( Mat frame )
    {
        qDebug() << "ID: " << QThread::currentThreadId();
        qDebug() << "-----get data: " << frame.size().height << "--" << frame.size().width;
    }
};

#endif /* TRANSIMITDATA_H */


/**
 * Moidfy History:
 * $Log
 */
