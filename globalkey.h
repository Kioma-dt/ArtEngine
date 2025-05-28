#ifndef GLOBALKEY_H
#define GLOBALKEY_H

#include <QObject>
#include <windows.h>

class GlobalKey : public QObject
{
    Q_OBJECT
public:
    explicit GlobalKey(QObject* parent = nullptr);
    ~GlobalKey();

    void installHook();
    void uninstallHook();

private:
    static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
    static HHOOK keyboardHook;
    static GlobalKey* instance;

    bool ctrlPressed = false;
    bool shiftPressed = false;

signals:
    void SignalHotKeyPressed();

};

#endif // GLOBALKEY_H
