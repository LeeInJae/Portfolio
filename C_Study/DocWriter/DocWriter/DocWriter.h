#ifndef DocWriter_h
#define DocWriter_h

#include <string>
using namespace std;

class DocWriter{
public:
	DocWriter();
	DocWriter(const string& fileName, const string& content);
	~DocWriter();

	void SetFileNaMe(const string& fileName);

	void SetContent(const string& content);

	void Write();

protected:
	string mFileName;
	string mContent;
};
#endif