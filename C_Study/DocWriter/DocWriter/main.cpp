#include "DocWriter.h"
#include "HTMLWriter.h"
using namespace std;
#include <iostream>

int main(void){
	DocWriter * docW1 = new DocWriter("test.txt", "good programmer yeah!");
	docW1->Write();

	HTMLWriter * htmlW1 = new HTMLWriter();
	htmlW1->SetFileNaMe("test.html");
	htmlW1->SetContent("I muse be a good programmer~!");
	htmlW1->SetFont("Arial", 16, "blue");
	htmlW1->Write();
	
	cout << sizeof(DocWriter) << endl;
	cout << sizeof(HTMLWriter) << endl;

	HTMLWriter * pHtml = new HTMLWriter();
	DocWriter * pDoc = pHtml;
	pDoc->SetContent("hihihihihi");
	pDoc->Write();
	delete docW1;
	delete htmlW1;
	getchar();
	return 0;
}