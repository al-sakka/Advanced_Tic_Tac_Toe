#include "utilities/main_includes.h"
#include "src/ui/sign_screen/sign_screen.h"
#include "src/ui/replay_screen/replayscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SignScreen w;

    //ReplayScreen R;

    // R.show();

    // launch the registeration screen
    w.show();

    return a.exec();
}
