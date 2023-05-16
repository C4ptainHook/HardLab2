#include "DataParser.h"
#include "Printer.h"
#include "Directory.h"
#include <windows.h>
int main(int argc, char*argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    std::string fileGuider;
    Directory::GetPath(argv[1]);
    try {
        fileGuider = Directory::DirProcess(Directory::GetPath(argv[1]), argv[1]);
    }
    catch(const EmptyFileException& ex) {
      std::cerr<<ex.what();
        return 1;
    }
    DataParser parser(fileGuider);
    parser.ParseData();
    if(!parser.isErrors()) {
        Counter counter;
        counter.Process_parsedData(parser.GetData());
        Printer::Write_Result_toFile(counter, argv[1]);
    }
}
