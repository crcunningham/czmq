/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "qczmq.h"

///
//  Copy-construct to return the proper wrapped c types
QZarmour::QZarmour (zarmour_t *self, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = self;
}


///
//  Create a new zarmour.
QZarmour::QZarmour (QObject *qObjParent) : QObject (qObjParent)
{
    this->self = zarmour_new ();
}

///
//  Destroy the zarmour.
QZarmour::~QZarmour ()
{
    zarmour_destroy (&self);
}

///
//  Get printable string for mode.
const QString QZarmour::modeStr ()
{
    const QString rv = QString (zarmour_mode_str (self));
    return rv;
}

///
//  Encode a stream of bytes into an armoured string.
QString QZarmour::encode (const byte *data, size_t size)
{
    char *retStr_ = zarmour_encode (self, data, size);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Decode an armoured string into a string of bytes.          
//  The decoded output is null-terminated, so it may be treated
//  as a string, if that's what it was prior to encoding.      
byte * QZarmour::decode (const QString &data, size_t *decodeSize)
{
    byte * rv = zarmour_decode (self, data.toUtf8().data(), decodeSize);
    return rv;
}

///
//  Get the mode property.
zarmour_mode_t QZarmour::mode ()
{
    zarmour_mode_t rv = zarmour_mode (self);
    return rv;
}

///
//  Set the mode property.
void QZarmour::setMode (zarmour_mode_t mode)
{
    zarmour_set_mode (self, mode);
    
}

///
//  Return true if padding is turned on.
bool QZarmour::pad ()
{
    bool rv = zarmour_pad (self);
    return rv;
}

///
//  Turn padding on or off. Default is on.
void QZarmour::setPad (bool pad)
{
    zarmour_set_pad (self, pad);
    
}

///
//  Get the padding character.
char QZarmour::padChar ()
{
    char rv = zarmour_pad_char (self);
    return rv;
}

///
//  Set the padding character.
void QZarmour::setPadChar (char padChar)
{
    zarmour_set_pad_char (self, padChar);
    
}

///
//  Return if splitting output into lines is turned on. Default is off.
bool QZarmour::lineBreaks ()
{
    bool rv = zarmour_line_breaks (self);
    return rv;
}

///
//  Turn splitting output into lines on or off.
void QZarmour::setLineBreaks (bool lineBreaks)
{
    zarmour_set_line_breaks (self, lineBreaks);
    
}

///
//  Get the line length used for splitting lines.
size_t QZarmour::lineLength ()
{
    size_t rv = zarmour_line_length (self);
    return rv;
}

///
//  Set the line length used for splitting lines.
void QZarmour::setLineLength (size_t lineLength)
{
    zarmour_set_line_length (self, lineLength);
    
}

///
//  Print properties of object
void QZarmour::print ()
{
    zarmour_print (self);
    
}

///
//  Self test of this class.
void QZarmour::test (bool verbose)
{
    zarmour_test (verbose);
    
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/