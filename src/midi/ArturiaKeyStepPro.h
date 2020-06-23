#pragma once

#include "MidiController.h"

class ArturiaKeyStepPro : public MidiController, QObject
{
    Q_OBJECT

    public:
    ArturiaKeyStepPro(QString inputKey, QString outputKey, QString name, int type);
    virtual ~ArturiaKeyStepPro();
    int indexFromNote(QString note);
    QString noteFromIndex(int index);
    ValueControl *key(int index);
};