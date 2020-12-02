/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
#ifndef Q_ZOSC_H
#define Q_ZOSC_H

#include "qczmq.h"

class QT_CZMQ_EXPORT QZosc : public QObject
{
    Q_OBJECT
public:

    //  Copy-construct to return the proper wrapped c types
    QZosc (zosc_t *self, QObject *qObjParent = 0);

    //  Create a new empty OSC message with the specified address string.
    explicit QZosc (const QString &address, QObject *qObjParent = 0);

    //  Create a new OSC message from the specified zframe. Takes ownership of
    //  the zframe.
    static QZosc* fromframe (QZframe *frame, QObject *qObjParent = 0);

    //  Create a new zosc message from memory. Take ownership of the memory
    //  and calling free on the data after construction.
    static QZosc* frommem (char *data, size_t size, QObject *qObjParent = 0);

    //  Destroy an OSC message
    ~QZosc ();

    //  Return chunk data size
    size_t size ();

    //  Return OSC chunk data. Caller does not own the data!
    byte * data ();

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

    //  Create copy of the message, as new chunk object. Returns a fresh zosc_t
    //  object, or null if there was not enough heap memory. If chunk is null,
    //  returns null.
    QZosc * dup ();

    //  Transform zosc into a zframe that can be sent in a message.
    QZframe * pack ();

    //  Transform zosc into a zframe that can be sent in a message.
    //  Take ownership of the chunk.
    QZframe * packx ();

    //  Transform a zframe into a zosc.
    static QZosc * unpack (QZframe *frame);

    //  Dump OSC message to stdout, for debugging and tracing.
    void print ();

    //  Probe the supplied object, and report if it looks like a zosc_t.
    static bool is (void *self);

    //  Return a pointer to the item at the head of the OSC data.
    //  Sets the given char argument to the type tag of the data.
    //  If the message is empty, returns NULL and the sets the
    //  given char to NULL.
    void * first (char *type);

    //  Return the next item of the OSC message. If the list is empty, returns
    //  NULL. To move to the start of the OSC message call zosc_first ().
    void * next (char *type);

    //  Return a pointer to the item at the tail of the OSC message.
    //  Sets the given char argument to the type tag of the data. If
    //  the message is empty, returns NULL.
    void * last (char *type);

    //  Self test of this class.
    static void test (bool verbose);

    zosc_t *self;
};
#endif //  Q_ZOSC_H
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
