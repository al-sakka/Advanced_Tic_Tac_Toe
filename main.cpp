#include "utilities/main_includes.h"
#include "src/ui/main_screen/main_screen.h"

#include "src/ui/game_screen/mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainScreen mainScreen;
    mainScreen.setUserName("Sakka");
    mainScreen.setWindowTitle("TIC TAC TOE");
    mainScreen.show();

    // MainWindow mainWindow;
    // mainWindow.show();

    return app.exec();
}
