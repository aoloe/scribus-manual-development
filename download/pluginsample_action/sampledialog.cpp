#include "sampledialog.h"
#include "scribusdoc.h" // for setting the default filename in the dialog

SampleDialog::SampleDialog(QWidget* parent, ScribusDoc* doc, const char* name, bool modal, Qt::WFlags fl)
	: QDialog (parent, fl),
	  m_Doc(doc)
{
	setupUi(this);
	setObjectName(name);
	setModal(modal);

	connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelButton_clicked()));
	// connect(okButton, SIGNAL(clicked()), this, SLOT(okButton_clicked()));
}

SampleDialog::~SampleDialog() {};

void SampleDialog::cancelButton_clicked()
{
	reject();
}

/*
void SampleDialog::okButton_clicked()
{
    // see gtfiledialog.ui for a way to integrate a file manager
    EPUBexport *action = new EPUBexport(m_Doc);
    EPUBExportOptions options;
	// qDebug() << "fileOutput->text()" << fileOutput->text();
    action->do(fileOutput->text(), options);
    delete action;
	reject();
}
*/
