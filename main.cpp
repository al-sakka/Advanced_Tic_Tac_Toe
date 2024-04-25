#include "src/UI/main_screen/main_screen.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("TIC TAC TOE");

    std::string userName = "Sakka";

    mainScreen(userName, &window);


    window.resize(800, 600);
    window.show();

    return app.exec();
}
