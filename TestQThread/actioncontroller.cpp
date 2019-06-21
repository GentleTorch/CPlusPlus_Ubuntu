/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#include "actioncontroller.h"

ActionController::ActionController( QObject *parent ) : QObject( parent )
{
}

/**
 * method: setIP
 *
 * @brief: TODO
 * @param str TODO
 * @return TODO
 */

void ActionController::setIP( QString str )
{
    m_ip = str;
}

/**
 * method: setPort
 * @brief: TODO
 * @param num TODO
 * @return TODO
 */
void ActionController::setPort( unsigned short num )
{
    m_port = num;
}

/**
 * method: run
 * @brief: TODO
 * @return TODO
 */
void ActionController::run()
{
    m_server_manager.setHttpAcceptedCallback([]( const QPointer<JQHttpServer::Session> & session )
    {
        QString url = session->requestUrl();
        qDebug() << url;

        if( !url.compare( QString( "/pc_vas/CruiseControl" ) ) )
        {
            qDebug() << "got right url";
        }
        else
        {
            qDebug() << "unsupported url";
            session->replyText( QString( "url:%1\ndata:%2" ).arg( session->requestUrl(), QString( session->requestBody() ) ) );
            return;
        }

        QString data		= { session->requestBody().toStdString().c_str() };
        QJsonObject controlObj	= str2Json( data );
        qDebug() << controlObj;

        bool isSpin		= false;
        bool isDetect		= false;
        bool isAutoFocus	= false;
        double thresh		= 0.9;

        if( controlObj.contains( QString( "CameraSpin" ) ) )
        {
            QVariant var	= controlObj["CameraSpin"].toString();
            isSpin		= var.toBool();
/*            emit varSpin( isSpin ); */
        }

        if( controlObj.contains( QString( "CameraDetect" ) ) )
        {
            QVariant var	= controlObj["CameraDetect"].toString();
            isDetect	= var.toBool();
            emit varDetect( isDetect );
        }

        if( controlObj.contains( QString( "AutoFocus" ) ) )
        {
            QVariant var	= controlObj["AutoFocus"].toString();
            isAutoFocus	= var.toBool();
/*            emit varAutoFocus(isAutoFocus) */
        }

        if( controlObj.contains( QString( "ThresholdScore" ) ) )
        {
            QString str	= controlObj["ThresholdScore"].toString();
            thresh		= str.toDouble();
                /*emit varThresh(thresh) */
        }

        qDebug() << "isSpin: " << isSpin << ", isDetect: " << isDetect << ", isAutoFocus: " << isAutoFocus << ", thresh: " << thresh;

        /*here we reply the msg */
        session->replyText( QString( "url:%1\ndata:%2" ).arg( session->requestUrl(), QString( session->requestBody() ) ) );
    } );
    qDebug() << "listen:" << m_server_manager.listen( QHostAddress( m_ip ), m_port, ":/server.crt", ":/server.key" );
}

/**
 *
 * Moidfy History:
 * $Log
 */
