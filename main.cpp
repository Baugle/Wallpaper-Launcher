#include "wallpaper_launcher.h"


#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <cstdlib>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Wallpaper_Launcher_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Wallpaper_Launcher w;
    w.show();

    //      运行代码：steam://run/431960

    system("start steam://run/431960");
    //system( "steam://run//431960");

    return a.exec();
}
