#ifndef EMITSIGNALBASE_H
#define EMITSIGNALBASE_H

#include <QObject>

class CEmitSignalBase : public QObject
{
    Q_OBJECT
public:
    explicit CEmitSignalBase(QObject *parent = nullptr);
    virtual void emitAsignal() = 0;
signals:
    void myTestSignal(const QString &str);
protected:
    QString m_str;
public slots:
};

#endif // EMITSIGNALBASE_H
