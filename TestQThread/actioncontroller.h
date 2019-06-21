/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef ACTIONCONTROLLER_H
#define ACTIONCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QString>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>

#include "JQHttpServer.h"
#include "utils.h"


/**
 * CLASS:  ActionController
 * TODO: monitor ip and port, receive the vars
 */
class ActionController : public QObject
{
    Q_OBJECT
public:
    explicit ActionController( QObject *parent = nullptr );

    void setIP( QString str );


    void setPort( unsigned short num );


    void run();


signals:

    void varSpin( bool isSpin );


    void varDetect( bool isDetect );


    void varAutoFocus( bool isAutoFocus );


    void varThresh( double thresh );


public slots:

private:
    QString m_ip;
    unsigned short m_port;
    JQHttpServer::SslServerManage m_server_manager;
};

#endif /* ACTIONCONTROLLER_H *//**
        * Moidfy History:
        * $Log
        */


/**
 * Moidfy History:
 * $Log
 */
