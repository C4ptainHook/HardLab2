#include "DataParser.h"
#include "Printer.h"
#include "Directory.h"
#include <windows.h>
int main(int argc, char*argv[]) {
    std::vector<std::string> path_bundle;
    SetConsoleOutputCP(CP_UTF8);
    try{path_bundle=Directory::GetPath(argv[1]);}
    catch(const std::filesystem::filesystem_error& ex){
        std::cerr<<ex.what();
        return 1;
    }
    catch(const std::runtime_error& ex){
        std::cerr<<ex.what();
        return 1;
    }
    Directory::DirProcess(argv[1]);
    DataParser parser;
    try{parser.LineSecluder( path_bundle);}
    catch(const EmptyFileException& ex) {
        std::cerr<<ex.what();
    }
    if(!parser.isErrors()) {
        Counter counter;
        counter.Process_parsedData(parser.GetData());
        Printer::Write_Result_toFile(counter, argv[1]);
    }
}
