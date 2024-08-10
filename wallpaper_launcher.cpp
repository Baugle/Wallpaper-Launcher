#include "wallpaper_launcher.h"
#include "./ui_wallpaper_launcher.h"

#include <iostream>
#include <string>
#include <Windows.h>

#include<shobjidl.h>

#include  <direct.h>

#include <wchar.h>



void OpenFolder(const std::string &path);

using namespace std;



Wallpaper_Launcher::Wallpaper_Launcher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Wallpaper_Launcher)
{
    ui->setupUi(this);
}

Wallpaper_Launcher::~Wallpaper_Launcher()
{
    delete ui;
}



void Wallpaper_Launcher::on_pushButton_clicked()//打开启动项文件夹功能
{

    OpenFolder("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup");


}



std::wstring StringToWString(const std::string &str)//Comes from CSDN
{
    std::wstring wContext = L"";
    int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
    WCHAR* buffer = new WCHAR[len + 1];
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
    buffer[len] = '\0';
    wContext.append(buffer);
    delete[] buffer;

    return wContext;
}

void OpenFolder(const std::string &path)
{
#ifdef  _UNICODE
    std::wstring tmp = StringToWString(path);
    LPCWSTR dir = tmp.c_str();
    ShellExecute(NULL, NULL, dir, NULL, NULL, SW_SHOWNORMAL);
#elif _MBCS
    LPCSTR dir = path.c_str();
    ShellExecute(NULL, NULL, dir, NULL, NULL, SW_SHOWNORMAL);
#endif
}

void Wallpaper_Launcher::on_pushButton_2_clicked()//创建启动项功能
{

    TCHAR pBuf[MAX_PATH];                     //存放路径的变量
    GetCurrentDirectory(MAX_PATH, pBuf);
    //char EXEPATH[100] = pBuf.c_str()+"\\Wallpaper_Launcher.exe";
    TCHAR EXENAME[60]= L"\\Wallpaper_Launcher.exe";
    wstring wstr1(pBuf);
    wstring wstr2(EXENAME);
    wstring EXEPATH = wstr1 + wstr2;

    //MessageBoxA(0, EXEPATH.c_str(), "消息", 3);
    HRESULT hr = CoInitialize(NULL);
    if (SUCCEEDED(hr))
    {
        IShellLink *pisl;
        hr = CoCreateInstance(CLSID_ShellLink, NULL,
                              CLSCTX_INPROC_SERVER, IID_IShellLinkW, (void**)&pisl);
        if (SUCCEEDED(hr))
        {
            IPersistFile* pIPF;

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////

            //这里是我们要创建快捷方式的原始文件地址
            pisl->SetPath(EXEPATH.c_str());
            hr = pisl->QueryInterface(IID_IPersistFile, (void**)&pIPF);
            if (SUCCEEDED(hr))
            {

                /////////////////////////////////////////////////////////////////////////////////////////////////////////////

                //这里是我们要创建快捷方式的目标地址


                pIPF->Save(L"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Wallpaper_Launcher.lnk", FALSE);
                pIPF->Release();
            }
            pisl->Release();
        }
        CoUninitialize();
    }
    MessageBoxA(0, "操作完成，可能因环境配置不同导致无法正常写入启动项", "消息", 3);
}


void Wallpaper_Launcher::on_pushButton_3_clicked()
{

    abort();
}

