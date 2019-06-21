/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef UTILS_H
#define UTILS_H

#include <QMutex>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>

void outputMessage( QtMsgType type, const QMessageLogContext &context, const QString &msg );


QJsonObject str2Json( QString & data );


#endif /* UTILS_H */


/**
 * Moidfy History:
 * $Log
 */
