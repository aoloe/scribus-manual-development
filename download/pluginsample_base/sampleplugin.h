#ifndef SAMPLEPLUGIN_H
#define SAMPLEPLUGIN_H

#include "pluginapi.h"
#include "scplugin.h"

class QString;
class ScribusDoc;
class ScribusMainWindow;

class PLUGIN_API SamplePlugin : public ScActionPlugin
{
	Q_OBJECT
public:

	// Standard plugin implementation
	SamplePlugin();
	virtual ~SamplePlugin();
	/*!
	\author Ale Rimoldi
	\brief Run a Sample Plugin
	\param doc the current document
	\param filename a file to export to
	\retval bool true
	*/
	virtual bool run(ScribusDoc* doc=0, QString filename = QString::null);
	virtual const QString fullTrName() const;
	virtual const AboutData* getAboutData() const;
	virtual void deleteAboutData(const AboutData* about) const;
	virtual void languageChange();
	virtual void addToMainWindowMenu(ScribusMainWindow *) {};
};

extern "C" PLUGIN_API int scriptmanagerplugin_getPluginAPIVersion();
extern "C" PLUGIN_API ScPlugin* scriptmanagerplugin_getPlugin();
extern "C" PLUGIN_API void scriptmanagerplugin_freePlugin(ScPlugin* plugin);
#endif
