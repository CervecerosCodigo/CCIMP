#ifndef AUTO_GAMMA_DIALOG_H
#define AUTO_GAMMA_DIALOG_H

#include <QDialog>
#include "gui/ccimp_dialog.h"
#include "img_tools/image_tool.h"
#include "parameters/parameters.h"
#include "parameters/using_no_parameters.h"


namespace Ui {
class auto_gamma_dialog;
}

class auto_gamma_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit auto_gamma_dialog(QWidget *parent = 0);
    ~auto_gamma_dialog();

signals:
  void signalAccepted();

public slots:

  void slotAcceptPressed(){
      signalAccepted();               //Pressed OK
  }

private:
    Ui::auto_gamma_dialog *ui;
    void resetting_values() override;
};

#endif // AUTO_GAMMA_DIALOG_H
