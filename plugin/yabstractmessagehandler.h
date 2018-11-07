/*
 * This file is part of the xTuple ERP: PostBooks Edition, a free and
 * open source Enterprise Resource Planning software suite,
 * Copyright (c) 1999-2018 by OpenMFG LLC, d/b/a xTuple.
 * It is licensed to you under the Common Public Attribution License
 * version 1.0, the full text of which (including xTuple-specific Exhibits)
 * is available at www.xtuple.com/CPAL.  By using this software, you agree
 * to be bound by its terms.
 */

#ifndef YABSTRACTMESSAGEHANDLER_H
#define YABSTRACTMESSAGEHANDLER_H

#include <QAbstractMessageHandler>
#include <QMutex>
#include <QStringList>

// This class is named YAbstractMessageHandler because there is now an XAbstractMessageHandler in
// qt-client, and having both can cause crashes. Long term solution is to merge the two and put
// them in a new common submodule to replace a lot of the things in openrpt and qt-client
// common dirs. Temporary solution is this renaming.
class YAbstractMessageHandler : public QAbstractMessageHandler
{
  Q_OBJECT
    
  public:
    YAbstractMessageHandler(QObject *parent = 0);
    virtual ~YAbstractMessageHandler();

    virtual void    message(QtMsgType type, const QString &description, const QUrl &identifier = QUrl(), const QSourceLocation &sourceLocation = QSourceLocation());
    virtual void    message(QtMsgType type, const QString title, const QString &description, const QUrl &identifier = QUrl(), const QSourceLocation &sourceLocation = QSourceLocation());
    QStringList     unhandledMessages(QtMsgType *type = 0);

  protected:
    virtual void handleMessage(QtMsgType type, const QString &description, const QUrl &identifier, const QSourceLocation &sourceLocation) = 0;
    virtual void handleMessage(QtMsgType type, const QString title, const QString &description, const QUrl &identifier, const QSourceLocation &sourceLocation) = 0;

    QMutex                            _mutex;
    QList<QPair<QtMsgType, QString> > _unhandledMessage;
};

#endif
