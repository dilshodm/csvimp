/*
 * This file is part of the xTuple ERP: PostBooks Edition, a free and
 * open source Enterprise Resource Planning software suite,
 * Copyright (c) 1999-2018 by OpenMFG LLC, d/b/a xTuple.
 * It is licensed to you under the Common Public Attribution License
 * version 1.0, the full text of which (including xTuple-specific Exhibits)
 * is available at www.xtuple.com/CPAL.  By using this software, you agree
 * to be bound by its terms.
 */

#ifndef __CSVIMPPLUGIN_H__
#define __CSVIMPPLUGIN_H__

#include <QObject>
#include <QtGlobal>
#include "csvimpplugininterface.h"

#include "csvtoolwindow.h"

class CSVImpPlugin : public QObject, public CSVImpPluginInterface
{
  Q_OBJECT
  Q_INTERFACES(CSVImpPluginInterface)
#if QT_VERSION >= 0x050000
  Q_PLUGIN_METADATA(IID "org.xtuple.Plugin.CSVImpPluginInterface/0.4")
#endif

  public:
    CSVImpPlugin(QObject *parent = 0);

    virtual QMainWindow *getCSVAtlasWindow(QWidget *parent = 0, Qt::WindowFlags flags = Qt::WindowFlags {});
    virtual QMainWindow *getCSVToolWindow(QWidget *parent = 0, Qt::WindowFlags flags = Qt::WindowFlags {});
    virtual bool    importCSV();
    virtual bool    isInteractive();
    virtual QString lastError();
    virtual bool    openAtlas(QString filename = QString(), bool useDb = false);
    virtual bool    openCSV(QString filename = QString());
    virtual void    setAtlasDir(QString dirname);
    virtual bool    setAtlasMap(const QString mapname);
    virtual void    setCSVDir(QString dirname);
    virtual bool    setFirstLineHeader(bool isheader);
    virtual void    setInteractive(bool isinteractive);

  protected slots:
    virtual void cleanupDestroyedObject(QObject *object);

  protected:
    QString         _atlasdir;
    CSVAtlasWindow *_atlaswindow;
    QString         _csvdir;
    CSVToolWindow  *_csvtoolwindow;
    bool            _firstLineIsHeader;
    YAbstractMessageHandler *_msghandler;
};

#endif
