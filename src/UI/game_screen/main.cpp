#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create an instance of the main window
    MainWindow mainWindow;
    mainWindow.show();

    // Start the event loop
    return app.exec();
}
