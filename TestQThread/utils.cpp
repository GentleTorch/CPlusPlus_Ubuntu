/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#include "utils.h"


/**
 * method: outputMessage
 * @brief: TODO
 * @param type TODO
 * @param context TODO
 * @param msg TODO
 */
void outputMessage( QtMsgType type, const QMessageLogContext &context, const QString &msg )
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch( type )
    {
        case QtDebugMsg:
            text = QString( "Debug: " );
            break;

        case QtWarningMsg:
            text = QString( "Warning: " );
            break;

        case QtCriticalMsg:
            text = QString( "Critical: " );
            break;

        case QtFatalMsg:
            text = QString( "Fatal: " );
            break;

        case QtInfoMsg:
            text = QString( "Info: " );
            break;
    }

    QString		context_info		= QString( "File: %1, Line: %2, " ).arg( QString( context.file ) ).arg( context.line );
    QString		current_date_time	= QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss ddd" );
    QString		current_date		= QString( "[ %1 ]" ).arg( current_date_time );

    QString		message = QString( "%1 %2 %3 %4" ).arg( text ).arg( context_info ).arg( msg ).arg( current_date );
    QFile		file( "log.txt" );
    file.open( QIODevice::WriteOnly | QIODevice::Append );
    QTextStream	text_stream( &file );
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}

/**
 * method: str2Json
 * @brief: TODO
 * @param data TODO
 * @return TODO
 */
QJsonObject str2Json( QString & objStr )
{
    QJsonParseError json_error;
    QJsonDocument	parse_doucment = QJsonDocument::fromJson( QByteArray::fromStdString(
                                      objStr.
                                      toStdString() ),
                                  &json_error );

    if( (json_error.error != QJsonParseError::NoError)
        || !parse_doucment.isObject() )
    {
        /* throw FssException(400, "JSON Parse ERROR!"); */
        qFatal( "JSON Parse Error!!!" );
    }

    return parse_doucment.object();
}

/**
 * Moidfy History:
 * $Log
 */
