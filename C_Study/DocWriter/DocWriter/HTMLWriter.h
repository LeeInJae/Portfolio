#ifndef HTMLWRITER_H
#define HTMLWRITER_H

#include "DocWriter.h"

class HTMLWriter : public DocWriter{
public:
	HTMLWriter();
	~HTMLWriter();

	void Write();

	void SetFont(const string& fontName, int fontSize, const string& fontColor);

protected:
	string	mFontName;
	int		mFontSize;
	string	mFontColor;
};
#endif