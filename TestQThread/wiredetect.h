#ifndef WIREDETECT_H
#define WIREDETECT_H

#include <QObject>

class WireDetect : public QObject
{
    Q_OBJECT
public:
    explicit WireDetect(QObject *parent = nullptr);

signals:

public slots:
};

#endif // WIREDETECT_H