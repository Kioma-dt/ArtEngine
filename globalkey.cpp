#include "globalkey.h"

HHOOK GlobalKey::keyboardHook = nullptr;
GlobalKey* GlobalKey::instance = nullptr;
HotKey GlobalKey::currentHotKey;

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

void GlobalKey::setCurrentHotKey(HotKey hotKey)
{
    currentHotKey.ctrl = hotKey.ctrl;
    currentHotKey.alt = hotKey.alt;
    currentHotKey.shift = hotKey.shift;
    currentHotKey.key = hotKey.key;
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
            case VK_MENU:
            case VK_LMENU:
            case VK_RMENU:
                instance->altPressed = keyDown;
                break;
            case VK_SHIFT:
            case VK_LSHIFT:
            case VK_RSHIFT:
                instance->shiftPressed = keyDown;
                break;
            default:
                if (keyDown &&
                    instance->ctrlPressed == currentHotKey.ctrl &&
                    instance->altPressed == currentHotKey.alt &&
                    instance->shiftPressed == currentHotKey.shift &&
                    key->vkCode == qtKeyToVk(currentHotKey.key)) {
                    emit instance->SignalHotKeyPressed();
                }
                break;
            }
        }
    }

    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

int GlobalKey::qtKeyToVk(Qt::Key key)
{
    {
        switch (key) {
        case Qt::Key_Control: return VK_CONTROL;
        case Qt::Key_Shift: return VK_SHIFT;
        case Qt::Key_Alt: return VK_MENU;
        case Qt::Key_Meta: return VK_LWIN;
        case Qt::Key_Backspace: return VK_BACK;
        case Qt::Key_Return:    return VK_RETURN;
        case Qt::Key_F1: return VK_F1;
        case Qt::Key_F2: return VK_F2;
        case Qt::Key_F3: return VK_F3;
        case Qt::Key_F4: return VK_F4;
        case Qt::Key_F5: return VK_F5;
        case Qt::Key_F6: return VK_F6;
        case Qt::Key_F7: return VK_F7;
        case Qt::Key_F8: return VK_F8;
        case Qt::Key_F9: return VK_F9;
        case Qt::Key_F10: return VK_F10;
        case Qt::Key_F11: return VK_F11;
        case Qt::Key_F12: return VK_F12;
        case Qt::Key_Period:
        case Qt::Key_Greater: return VK_OEM_PERIOD;
        default:
            if (key >= Qt::Key_0 && key <= Qt::Key_9)
                return key;
            if (key >= Qt::Key_A && key <= Qt::Key_Z)
                return key;
            return 0;
        }
    }
}
