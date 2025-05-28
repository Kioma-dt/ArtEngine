#include "globalkey.h"

HHOOK GlobalKey::keyboardHook = nullptr;
GlobalKey* GlobalKey::instance = nullptr;

GlobalKey::GlobalKey(QObject *parent)
    :QObject(parent)
{
    instance = this;
}

GlobalKey::~GlobalKey()
{
    uninstallHook();
    instance = nullptr;
}

void GlobalKey::installHook()
{
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(nullptr), 0);
}

void GlobalKey::uninstallHook()
{
    if(keyboardHook){
        UnhookWindowsHookEx(keyboardHook);
        keyboardHook = nullptr;
    }
}

LRESULT CALLBACK GlobalKey::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION && lParam) {
        KBDLLHOOKSTRUCT* key = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);

        bool keyDown = (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN);

        if (instance) {
            switch (key->vkCode) {
            case VK_CONTROL:
            case VK_LCONTROL:
            case VK_RCONTROL:
                instance->ctrlPressed = keyDown;
                break;
            case VK_SHIFT:
            case VK_LSHIFT:
            case VK_RSHIFT:
                instance->shiftPressed = keyDown;
                break;
            case VK_F5:
                if (keyDown && instance->ctrlPressed && instance->shiftPressed) {
                    emit instance->SignalHotKeyPressed();
                }
                break;
            }
        }
    }

    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}
