#ifndef AUTO_LEVEL_DIALOG_H
#define AUTO_LEVEL_DIALOG_H

#include <QDialog>
#include "gui/ccimp_dialog.h"
#include "img_tools/image_tool.h"
#include "parameters/parameters.h"
#include "parameters/using_no_parameters.h"


namespace Ui {
class auto_level_dialog;
}

class auto_level_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit auto_level_dialog(QWidget *parent = 0);
    ~auto_level_dialog();

signals:
  void signalAccepted();

public slots:

  void slotAcceptPressed(){
      signalAccepted();               //Pressed OK
  }

private:
    Ui::auto_level_dialog *ui;
    void resetting_values() override;
};

#endif // AUTO_LEVEL_DIALOG_H
