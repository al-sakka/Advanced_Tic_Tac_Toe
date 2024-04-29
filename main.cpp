#include "utilities/main_includes.h"
#include "src/ui/sign_screen/sign_screen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SignScreen w;

    // launch the registeration screen
    w.show();

    return a.exec();
}
