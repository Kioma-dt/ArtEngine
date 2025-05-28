#ifndef GLOBALKEY_H
#define GLOBALKEY_H

#include <QObject>
#include <windows.h>

struct HotKey{
    bool ctrl;
    bool alt;
    bool shift;
    Qt::Key key;
};

class GlobalKey : public QObject
{
    Q_OBJECT
public:
    explicit GlobalKey(QObject* parent = nullptr);
    ~GlobalKey();

    void installHook();
    void uninstallHook();
    void setCurrentHotKey(HotKey hotKey);

private:
    static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
    static HHOOK keyboardHook;
    static GlobalKey* instance;
    static HotKey currentHotKey;
    static int qtKeyToVk(Qt::Key key);

    bool ctrlPressed = false;
    bool altPressed = false;
    bool shiftPressed = false;

signals:
    void SignalHotKeyPressed();

};

#endif // GLOBALKEY_H
