#pragma once

#ifdef FACTORYLIB_EXPORTS
#define FACTORYLIB_API __declspec(dllexport)
#else
#define FACTORYLIB_API __declspec(dllimport)
#endif

// ----- Product -----
class IReport
{
public:
    virtual ~IReport() = default;

    // Поведінка продукту
    virtual void Render() = 0;

    // Важливо для DLL: видалення об'єкта відбувається всередині DLL
    virtual void Release() = 0;
};

// ----- Creator (Factory Method) -----
class IReportCreator
{
public:
    virtual ~IReportCreator() = default;

    // Factory Method
    virtual IReport* CreateReport() = 0;

    // Важливо для DLL
    virtual void Release() = 0;
};

// Експортовані функції для створення конкретних фабрик (3 реальні фабрики)
extern "C"
{
    FACTORYLIB_API IReportCreator* CreateTextReportCreator();
    FACTORYLIB_API IReportCreator* CreateHtmlReportCreator();
    FACTORYLIB_API IReportCreator* CreatePdfReportCreator();
}