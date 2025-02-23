/*
 * This file is part of the xTuple ERP: PostBooks Edition, a free and
 * open source Enterprise Resource Planning software suite,
 * Copyright (c) 1999-2018 by OpenMFG LLC, d/b/a xTuple.
 * It is licensed to you under the Common Public Attribution License
 * version 1.0, the full text of which (including xTuple-specific Exhibits)
 * is available at www.xtuple.com/CPAL.  By using this software, you agree
 * to be bound by its terms.
 */

#ifndef __CSVATLASLIST_H__
#define __CSVATLASLIST_H__

#include <QString>

#include "ui_csvatlaslist.h"

class CSVAtlasList : public QDialog, Ui::CSVAtlasList
{
  Q_OBJECT

  public:
    CSVAtlasList(QWidget *parent = 0, Qt::WindowFlags f = Qt::WindowFlags {});
    virtual ~CSVAtlasList();

    virtual QString selectedAtlas()   const;

  protected slots:
    void languageChange();
    void sFillList();
    void sAtlasSelected();
  private:
};

#endif

