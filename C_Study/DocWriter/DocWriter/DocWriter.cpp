#include "DocWriter.h"
#include <fstream>
#include <iostream>


using namespace std;

DocWriter::DocWriter()
{
	mFileName = "NoName.txt";
	mContent = "There is no content";
}

DocWriter::DocWriter(const string& fileName, const string& content) : mFileName(fileName), mContent(content)
{

}

DocWriter::~DocWriter()
{

}

void DocWriter::SetFileNaMe(const string& fileName)
{
	mFileName = fileName;
}

void DocWriter::SetContent(const string& content)
{
	mContent = content;
}

void DocWriter::Write()
{
	ofstream fout(mFileName.c_str());
	fout << "# content # \n\n";
	fout << mContent;
	fout.close();
}
