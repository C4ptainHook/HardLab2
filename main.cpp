#include "DataParser.h"
#include "Printer.h"
#include "Directory.h"
#include <windows.h>
int main(int argc, char*argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    char path[] = "C:\\Users\\boyko\\Desktop\\Education\\Current Sem\\OOP\\Wolf\\examples_2\\var0";
    char* ppath = path;
    Directory::GetPath(ppath);
    DataParser parser(Directory::DirProcess(Directory::GetPath(ppath), ppath));
    parser.ParseData();
    Counter counter;
    counter.Process_parsedData(parser.GetData());
    Printer::Write_Result_toFile(counter, ppath);
}
