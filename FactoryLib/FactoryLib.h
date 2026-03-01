#pragma once

#ifdef FACTORYLIB_EXPORTS
#define FACTORYLIB_API __declspec(dllexport)
#else
#define FACTORYLIB_API __declspec(dllimport)
#endif

class IReport
{
public:
    virtual ~IReport() = default;

    virtual void Render() = 0;

    virtual void Release() = 0;
};

class IReportCreator
{
public:
    virtual ~IReportCreator() = default;

    virtual IReport* CreateReport() = 0;

    virtual void Release() = 0;
};

extern "C"
{
    FACTORYLIB_API IReportCreator* CreateTextReportCreator();
    FACTORYLIB_API IReportCreator* CreateHtmlReportCreator();
    FACTORYLIB_API IReportCreator* CreatePdfReportCreator();
}