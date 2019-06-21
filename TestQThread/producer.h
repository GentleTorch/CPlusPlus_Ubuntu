/*####################################################################################*//**
*#  @file: stdin
*#  @brief TODO
*#  @author AILab, Faith
*####################################################################################*/
#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>

#include "repository.h"


/**
 * CLASS:  Producer
 * TODO: DESCRIPTION
 */
class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer( QObject *parent = nullptr );

    void setRepo( Repository* ptr );


signals:

public slots:

    void produceData();


private:
    Repository *repo = nullptr;
};

#endif /* PRODUCER_H *//**
        * Moidfy History:
        * $Log
        */


/**
 * Moidfy History:
 * $Log
 */
