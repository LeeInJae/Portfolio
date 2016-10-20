#include "HTMLWriter.h"
#include <fstream>

using namespace std;

HTMLWriter::HTMLWriter()
{
	mFileName = "NoName.html";

	mFontName = "±¼¸²";
	mFontSize = 3;
	mFontColor = "black";
}

HTMLWriter::~HTMLWriter()
{

}

void HTMLWriter::Write()
{
	ofstream fout(mFileName.c_str());
	fout << "<H1>Content</H1>";
	fout << "<Font name ='" << mFontName << " ' size = '" << mFontSize << " ' color = " << mFontColor << " '>";
	fout << mContent;
	fout << "</FONT>";

	fout << "</BODY></HTML>";
	fout.close();
}

void HTMLWriter::SetFont(const string& fontName, int fontSize, const string& fontColor)
{
	mFontName = fontName;
	mFontSize = fontSize;
	mFontColor = fontColor;
}

