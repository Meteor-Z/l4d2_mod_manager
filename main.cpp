#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>
#include <QMessageBox>
#include <vdf_parser.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (l4d2::Parser::have_this_game(QString("550"))) {
        QString file = l4d2::Parser::get_game_file(QString("550"));
        QMessageBox::information(nullptr, file, file);
    }

    MainWindow windows;
    windows.show();
    return app.exec();
}
