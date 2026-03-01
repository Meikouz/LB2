#include <iostream>
#include "FactoryLib.h"

void UseFactory(IReportCreator* creator)
{
    IReport* report = creator->CreateReport();
    report->Render();

    // Важливо: звільнення через Release(), щоб delete був у DLL
    report->Release();
    creator->Release();
}

int main(){
	setlocale(LC_ALL, "Ukr");

    std::cout << "Демонстрація патерну 'Фабричний метод' (DLL).\n";

    UseFactory(CreateTextReportCreator());
    UseFactory(CreateHtmlReportCreator());
    UseFactory(CreatePdfReportCreator());

    std::cout << "Готово.\n";
    return 0;
}