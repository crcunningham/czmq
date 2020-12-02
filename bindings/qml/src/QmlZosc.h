/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#ifndef QML_ZOSC_H
#define QML_ZOSC_H

#include <QtQml>

#include <czmq.h>
#include "qml_czmq_plugin.h"


class QmlZosc : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNULL READ isNULL)

public:
    zosc_t *self;

    QmlZosc() { self = NULL; }
    bool isNULL() { return self == NULL; }

    static QObject* qmlAttachedProperties(QObject* object); // defined in QmlZosc.cpp

public slots:
    //  Return chunk data size
    size_t size ();

    //  Return OSC chunk data. Caller does not own the data!
    byte *data ();

    //  Return the OSC address string
    const QString address ();

    //  Return the OSC format of the message.
    //    i - 32bit integer
    //    h - 64bit integer
    //    f - 32bit floating point number (IEEE)
    //    d - 64bit (double) floating point number
    //    s - string (NULL terminated)
    //    t = timetag: an OSC timetag in NTP format (uint64_t)
    //    S - symbol
    //    c - char
    //    m - 4 byte midi packet (8 digits hexadecimal)
    //    T - TRUE (no value required)
    //    F - FALSE (no value required)
    //    N - NIL (no value required)
    //    I - Impulse (for triggers) or INFINITUM (no value required)
    //    b - binary blob
    const QString format ();

    //  Retrieve the values provided by the given format. Note that zosc_retr
    //  creates the objects and the caller must destroy them when finished.
    //  The supplied pointers do not need to be initialized. Returns 0 if
    //  successful, or -1 if it failed to retrieve a value in which case the
    //  pointers are not modified. If an argument pointer is NULL is skips the
    //  value. See the format method for a detailed list op type tags for the
    //  format string.
    int retr (const QString &format);

    //  Create copy of the message, as new chunk object. Returns a fresh zosc_t
    //  object, or null if there was not enough heap memory. If chunk is null,
    //  returns null.
    QmlZosc *dup ();

    //  Transform zosc into a zframe that can be sent in a message.
    QmlZframe *pack ();

    //  Dump OSC message to stdout, for debugging and tracing.
    void print ();

    //  Return a pointer to the item at the head of the OSC data.
    //  Sets the given char argument to the type tag of the data.
    //  If the message is empty, returns NULL and the sets the
    //  given char to NULL.
    void *first (char *type);

    //  Return the next item of the OSC message. If the list is empty, returns
    //  NULL. To move to the start of the OSC message call zosc_first ().
    void *next (char *type);

    //  Return a pointer to the item at the tail of the OSC message.
    //  Sets the given char argument to the type tag of the data. If
    //  the message is empty, returns NULL.
    void *last (char *type);
};

class QmlZoscAttached : public QObject
{
    Q_OBJECT
    QObject* m_attached;

public:
    QmlZoscAttached (QObject* attached) {
        Q_UNUSED (attached);
    };

public slots:
    //  Transform zosc into a zframe that can be sent in a message.
    //  Take ownership of the chunk.
    QmlZframe *packx (QmlZosc *selfP);

    //  Transform a zframe into a zosc.
    QmlZosc *unpack (QmlZframe *frame);

    //  Probe the supplied object, and report if it looks like a zosc_t.
    bool is (void *self);

    //  Self test of this class.
    void test (bool verbose);

    //  Create a new empty OSC message with the specified address string.
    QmlZosc *construct (const QString &address);

    //  Create a new OSC message from the specified zframe. Takes ownership of
    //  the zframe.
    QmlZosc *fromframe (QmlZframe *frame);

    //  Create a new zosc message from memory. Take ownership of the memory
    //  and calling free on the data after construction.
    QmlZosc *frommem (char *data, size_t size);

    //  Create a new zosc message from the given format and arguments.
    //  The format type tags are as follows:
    //    i - 32bit integer
    //    h - 64bit integer
    //    f - 32bit floating point number (IEEE)
    //    d - 64bit (double) floating point number
    //    s - string (NULL terminated)
    //    t = timetag: an OSC timetag in NTP format (uint64_t)
    //    S - symbol
    //    c - char
    //    m - 4 byte midi packet (8 digits hexadecimal)
    //    T - TRUE (no value required)
    //    F - FALSE (no value required)
    //    N - NIL (no value required)
    //    I - Impulse (for triggers) or INFINITUM (no value required)
    //    b - binary blob
    QmlZosc *create (const QString &address, const QString &format);

    //  Destroy an OSC message
    void destruct (QmlZosc *qmlSelf);
};


QML_DECLARE_TYPEINFO(QmlZosc, QML_HAS_ATTACHED_PROPERTIES)

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
