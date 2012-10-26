#ifndef SCRIPTMANAGERDIALOG_H
#define SCRIPTMANAGERDIALOG_H

#include "ui_sampledialog.h"

class ScribusDoc;

class SampleDialog : public QDialog, Ui::SampleDialog
{
	Q_OBJECT
	public:
		SampleDialog( QWidget* parent = 0, ScribusDoc* doc = 0, const char* name = 0, bool modal = FALSE, Qt::WFlags fl = 0 );
		~SampleDialog();
	private:
		//! \brief a parent doc reference
		ScribusDoc* m_Doc;
	private slots:
		void cancelButton_clicked();
		// void exportButton_clicked();

};

#endif // SCRIPTMANAGERDIALOG_H

