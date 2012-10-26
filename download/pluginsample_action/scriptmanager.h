#ifndef SAMPLE_H
#define SAMPLE_H

#include <QObject>

class ScribusDoc; // you mostly want to act on the current document; if it's not the case remove this line

class Sample : public QObject
{
    Q_OBJECT

public:
	Sample(ScribusDoc* doc); // you mostly want to act on the current document; if it's not the case remove the parameter
	~Sample();

private:
	ScribusDoc* doc; // you mostly want to act on the current document; if it's not the case remove this line
};

#endif // SAMPLE_H
