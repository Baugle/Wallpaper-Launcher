#ifndef WALLPAPER_LAUNCHER_H
#define WALLPAPER_LAUNCHER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Wallpaper_Launcher;
}
QT_END_NAMESPACE

class Wallpaper_Launcher : public QMainWindow
{
    Q_OBJECT

public:
    Wallpaper_Launcher(QWidget *parent = nullptr);
    ~Wallpaper_Launcher();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Wallpaper_Launcher *ui;
};
#endif // WALLPAPER_LAUNCHER_H
