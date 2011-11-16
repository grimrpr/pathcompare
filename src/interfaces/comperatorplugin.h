#ifndef COMPERATORPLUGIN_H
#define COMPERATORPLUGIN_H

#include <QObject>

class ComperatorPlugin : public QObject
{
    Q_OBJECT
public:
        explicit ComperatorPlugin(QObject *parent = 0);

        void testFunction() const;

Q_SIGNALS:

public Q_SLOTS:

};

#endif // COMPERATORPLUGIN_H
