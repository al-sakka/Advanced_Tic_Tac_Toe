#include <QtTest/QtTest>
#include "F:\QT\workspace\Advanced_Tic_Tac_Toe\src\ui\game_screen\game_screen.h"

class TestGameScreen : public QObject {
    Q_OBJECT

private slots:
    void initTestCase() {

        QVERIFY(true);
    }

    void testSetMode() {
        QVERIFY(true);
    }

    void testSetUsername() {
        QVERIFY(true);
    }

    void testHandleResetButtonClicked() {
        QVERIFY(true);
    }

    void testCheckDraw() {
        QVERIFY(true);
    }

    void testCheckWinner() {
        QVERIFY(true);
    }

    void testHandleButtonClick() {
        QVERIFY(true);
    }

    void cleanupTestCase() {

        QVERIFY(true);
    }
};

QTEST_MAIN(TestGameScreen)
#include "test_gamelogic.moc"
