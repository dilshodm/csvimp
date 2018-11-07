/*
 * This file is part of the xTuple ERP: PostBooks Edition, a free and
 * open source Enterprise Resource Planning software suite,
 * Copyright (c) 1999-2018 by OpenMFG LLC, d/b/a xTuple.
 * It is licensed to you under the Common Public Attribution License
 * version 1.0, the full text of which (including xTuple-specific Exhibits)
 * is available at www.xtuple.com/CPAL.  By using this software, you agree
 * to be bound by its terms.
 */

#include "csvatlaslist.h"

#include <QMessageBox>
#include <QSqlError>

#include "xsqlquery.h"

#define DEBUG false

CSVAtlasList::CSVAtlasList(QWidget *parent, Qt::WindowFlags f)
  : QDialog(parent, f)
{
  setupUi(this);
  sFillList();
}

CSVAtlasList::~CSVAtlasList()
{
}

void CSVAtlasList::languageChange()
{
  retranslateUi(this);
}

void CSVAtlasList::sFillList()
{
  QSqlQuery atlq;
  atlq.prepare("SELECT atlas_name FROM atlas ORDER by atlas_name;");
  if (atlq.exec())
    _atlases->clear();
  while(atlq.next())
    _atlases->addItem(atlq.value("atlas_name").toString());
  if (atlq.lastError().type() != QSqlError::NoError)
  {
    QMessageBox::critical(this, tr("Database Error"), atlq.lastError().text());
    return;
  }
}

void CSVAtlasList::sAtlasSelected()
{
  accept();
}

QString CSVAtlasList::selectedAtlas() const
{
  return _atlases->currentText();
}
