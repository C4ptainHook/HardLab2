#include "DataParser.h"
#include "Printer.h"
#include "Directory.h"
#include <windows.h>
int main(int argc, char*argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    std::string fileGuider;
    char path[] = "C:\\Users\\boyko\\Desktop\\Education\\Current Sem\\OOP\\Wolf\\examples_2\\var0";
    char* ppath = path;
    Directory::GetPath(ppath);
    try {
        fileGuider = Directory::DirProcess(Directory::GetPath(ppath), ppath);
    }
    catch(const EmptyFileException& ex) {
      std::cerr<<ex.what();
        return 1;
    }
    DataParser parser(fileGuider);
    try{ parser.ParseData();}
    catch(const FileContentException& ex) {
        std::cerr<<ex.whatHappened();
    }
    Counter counter;
    counter.Process_parsedData(parser.GetData());
    Printer::Write_Result_toFile(counter, ppath);
}
