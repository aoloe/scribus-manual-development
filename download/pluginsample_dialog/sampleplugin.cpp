/***************************************************************************
                          epubexplugin.cpp  -  description
                             -------------------
    begin                : Wed Oct 14 18:00:00 CEST 2012
    copyright            : (C) 2012 by Ale Rimoldi
    email                : a.l.e@ideale.ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "sampleplugin.h"
#include "sampledialog.h"
#include "scribuscore.h"
#include "scribusdoc.h"
int sampleplugin_getPluginAPIVersion()
{
	return PLUGIN_API_VERSION;
}

ScPlugin* sampleplugin_getPlugin()
{
	SamplePlugin* plug = new SamplePlugin();
	Q_CHECK_PTR(plug);
	return plug;
}

void sampleplugin_freePlugin(ScPlugin* plugin)
{
	SamplePlugin* plug = dynamic_cast<SamplePlugin*>(plugin);
	Q_ASSERT(plug);
	delete plug;
}

SamplePlugin::SamplePlugin() : ScActionPlugin()
{
	// Set action info in languageChange, so we only have to do
	// it in one place.
	languageChange();
}

SamplePlugin::~SamplePlugin()
{
};

void SamplePlugin::languageChange()
{
	// Note that we leave the unused members unset. They'll be initialised
	// with their default ctors during construction.
	// Action name
	m_actionInfo.name = "Script Manager";
	// Action text for menu, including accel
	m_actionInfo.text = tr("Script &Manager...");
	// Menu
	// m_actionInfo.menu = "FileExport";
	m_actionInfo.menu = "Extras"; // TODO: we can't add it to the scripter menu... is there a way to do it'

	m_actionInfo.enabledOnStartup = true;
	m_actionInfo.needsNumObjects = -1;
}

const QString SamplePlugin::fullTrName() const
{
	return QObject::tr("Script Manager");
}

const ScActionPlugin::AboutData* SamplePlugin::getAboutData() const
{
	AboutData* about = new AboutData;
	about->authors = "Ale Rimoldi <a.l.e@ideale.ch>";
	about->shortDescription = tr("Manages Python Scripts");
	about->description = tr("Allows to download python scripts from user defined repositories.");
	about->license = "GPL";
	Q_CHECK_PTR(about);
	return about;
}

void SamplePlugin::deleteAboutData(const AboutData* about) const
{
	Q_ASSERT(about);
	delete about;
}

bool SamplePlugin::run(ScribusDoc* doc, QString target)
{
	Q_ASSERT(target.isNull());
	SampleDialog *dlg = new SampleDialog(doc->scMW(), doc, "dlg", true, 0);
	if (dlg)
	{
		dlg->exec();
		delete dlg;
		return true;
	}
	else
		return false;
}
