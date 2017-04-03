#ifndef PROPERTYSPY_H
#define PROPERTYSPY_H
#include <QMetaObject>
#include <QObject>
#include <QSignalMapper>

class PropertySpy : public QObject
{
    Q_OBJECT
public:
    explicit PropertySpy(QObject *parent = 0);

    Q_INVOKABLE void spy(QObject * object);
signals:

public slots:
    void onPropertyChanged();

private:
};

#endif // PROPERTYSPY_H
