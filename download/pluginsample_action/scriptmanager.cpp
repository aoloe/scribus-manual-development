#include "sample.h"
#include "scribusdoc.h" // you mostly want to act on the current document; if it's not the case remove this line

Sample::Sample(ScribusDoc* doc)
{
	this->doc = doc; // you mostly want to act on the current document; if it's not the case remove this line
}

Sample::~Sample()
{
}
