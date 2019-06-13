/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;


/**
 * CLASS:  Consumer
 * TODO: DESCRIPTION
 */
class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer( QObject *parent = nullptr );

signals:

public slots:


    /**
     * method: recvData
     * @brief: TODO
     * @param frame TODO
     */
    void recvData( Mat frame )
    {
        qDebug() << "Consumer id: " << QThread::currentThreadId();
        qDebug() << "-----get data: " << frame.size().height << "--" << frame.size().width;
    }
};

#endif /* CONSUMER_H */


/**
 * Moidfy History:
 * $Log
 */
