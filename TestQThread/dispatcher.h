/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>

#include "repository.h"


/**
 * CLASS:  Dispatcher
 * TODO: DESCRIPTION
 */
class Dispatcher : public QObject
{
    Q_OBJECT
public:
    explicit Dispatcher( QObject *parent = nullptr );

    void setRepo( Repository *ptr );


signals:

    void data( QString str );


public slots:

    void consumeData();


private:
    Repository *repo = nullptr;
};

#endif /* DISPATCHER_H *//**
        * Moidfy History:
        * $Log
        */


/**
 * Moidfy History:
 * $Log
 */
