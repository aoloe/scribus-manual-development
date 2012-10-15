#ifndef SCRIPTMANAGERPLUGIN_H
#define SCRIPTMANAGERPLUGIN_H

#include "pluginapi.h"
#include "scplugin.h"

class QString;
class ScribusDoc;
class ScribusMainWindow;

class PLUGIN_API ScriptManagerPlugin : public ScActionPlugin
{
	Q_OBJECT
public:

	// Standard plugin implementation
	ScriptManagerPlugin();
	virtual ~ScriptManagerPlugin();
	/*!
	\author Ale Rimoldi
	\brief Run the Script manager
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
