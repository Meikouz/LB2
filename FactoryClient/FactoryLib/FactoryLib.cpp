#include "pch.h"
#include <iostream>
#include "FactoryLib.h"

class TextReport : public IReport
{
public:
    void Render() override
    {
        std::cout << "Звiт у форматi TXT сформовано.\n";
    }

    void Release() override
    {
        delete this;
    }
};

class HtmlReport : public IReport
{
public:
    void Render() override
    {
        std::cout << "Звiт у форматi HTML сформовано.\n";
    }

    void Release() override
    {
        delete this;
    }
};

class PdfReport : public IReport
{
public:
    void Render() override
    {
        std::cout << "Звiт у форматi PDF сформовано.\n";
    }

    void Release() override
    {
        delete this;
    }
};

class TextReportCreator : public IReportCreator
{
public:
    IReport* CreateReport() override
    {
        return new TextReport();
    }

    void Release() override
    {
        delete this;
    }
};

class HtmlReportCreator : public IReportCreator
{
public:
    IReport* CreateReport() override
    {
        return new HtmlReport();
    }

    void Release() override
    {
        delete this;
    }
};

class PdfReportCreator : public IReportCreator
{
public:
    IReport* CreateReport() override
    {
        return new PdfReport();
    }

    void Release() override
    {
        delete this;
    }
};

extern "C"
{
    FACTORYLIB_API IReportCreator* CreateTextReportCreator()
    {
        return new TextReportCreator();
    }

    FACTORYLIB_API IReportCreator* CreateHtmlReportCreator()
    {
        return new HtmlReportCreator();
    }

    FACTORYLIB_API IReportCreator* CreatePdfReportCreator()
    {
        return new PdfReportCreator();
    }
}