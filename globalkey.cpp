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
    if(!keyboardHook){
        keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(nullptr), 0);
    }
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
        case Qt::Key_Tab: return VK_TAB;
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
        case Qt::Key_Delete: return VK_DELETE;
        case Qt::Key_Insert: return VK_INSERT;
        case Qt::Key_Home: return VK_HOME;
        case Qt::Key_End: return VK_END;
        case Qt::Key_PageUp: return VK_PRIOR;
        case Qt::Key_PageDown: return VK_NEXT;
        case Qt::Key_Left: return VK_LEFT;
        case Qt::Key_Right: return VK_RIGHT;
        case Qt::Key_Up: return VK_UP;
        case Qt::Key_Down: return VK_DOWN;
        case Qt::Key_Comma: return VK_OEM_COMMA;
        case Qt::Key_Period: return VK_OEM_PERIOD;
        case Qt::Key_Semicolon: return VK_OEM_1;
        case Qt::Key_Apostrophe: return VK_OEM_7;
        case Qt::Key_Slash: return VK_OEM_2;
        case Qt::Key_Backslash: return VK_OEM_5;
        case Qt::Key_BracketLeft: return VK_OEM_4;
        case Qt::Key_BracketRight: return VK_OEM_6;
        case Qt::Key_Minus: return VK_OEM_MINUS;
        case Qt::Key_Equal: return VK_OEM_PLUS;
        case Qt::Key_QuoteLeft: return VK_OEM_3;
        case Qt::Key_NumLock: return VK_NUMLOCK;
        case Qt::Key_Enter: return VK_RETURN;
        case Qt::Key_Print: return VK_SNAPSHOT;
        case Qt::Key_ScrollLock: return VK_SCROLL;
        case Qt::Key_Pause: return VK_PAUSE;
        case Qt::Key_CapsLock: return VK_CAPITAL;
        case Qt::Key_VolumeDown: return VK_VOLUME_DOWN;
        case Qt::Key_VolumeUp: return VK_VOLUME_UP;
        case Qt::Key_VolumeMute: return VK_VOLUME_MUTE;
        case Qt::Key_MediaPlay: return VK_MEDIA_PLAY_PAUSE;
        case Qt::Key_MediaStop: return VK_MEDIA_STOP;
        case Qt::Key_MediaNext: return VK_MEDIA_NEXT_TRACK;
        case Qt::Key_MediaPrevious: return VK_MEDIA_PREV_TRACK;
        case Qt::Key_LaunchMail: return VK_LAUNCH_MAIL;
        case Qt::Key_LaunchMedia: return VK_LAUNCH_MEDIA_SELECT;
        case Qt::Key_Launch0: return VK_LAUNCH_APP1;
        case Qt::Key_Launch1: return VK_LAUNCH_APP2;
        case Qt::Key_Exclam: return '1';
        case Qt::Key_At: return '2';
        case Qt::Key_NumberSign: return '3';
        case Qt::Key_Dollar: return '4';
        case Qt::Key_Percent: return '5';
        case Qt::Key_AsciiCircum: return '6';
        case Qt::Key_Ampersand: return '7';
        case Qt::Key_Asterisk: return '8';
        case Qt::Key_ParenLeft: return '9';
        case Qt::Key_ParenRight: return '0';
        case Qt::Key_Underscore: return VK_OEM_MINUS;
        case Qt::Key_Plus: return VK_OEM_PLUS;
        case Qt::Key_BraceLeft: return VK_OEM_4;
        case Qt::Key_BraceRight: return VK_OEM_6;
        case Qt::Key_Bar: return VK_OEM_5;
        case Qt::Key_Colon: return VK_OEM_1;
        case Qt::Key_QuoteDbl: return VK_OEM_7;
        case Qt::Key_Less: return VK_OEM_COMMA;
        case Qt::Key_Greater: return VK_OEM_PERIOD;
        case Qt::Key_Question: return VK_OEM_2;
        case Qt::Key_AsciiTilde: return VK_OEM_3;


        default:
            if (key >= Qt::Key_0 && key <= Qt::Key_9)
                return key;
            if (key >= Qt::Key_A && key <= Qt::Key_Z)
                return key;
            return 0;
        }
    }
}
