#include "Input.h"
#include "DxLib.h"

namespace Input
{

    std::array<int, (int)Key::Count> now{};

    std::array<int, (int)Key::Count> prev{};

    static int DxKeyCode(Key key)
    {
        switch (key)
        {
        case Key::Up:    return KEY_INPUT_UP;
        case Key::Down:  return KEY_INPUT_DOWN;
        case Key::Left:  return KEY_INPUT_LEFT;
        case Key::Right: return KEY_INPUT_RIGHT;
        case Key::W:     return KEY_INPUT_W;
        case Key::A:     return KEY_INPUT_A;
        case Key::S:     return KEY_INPUT_S;
        case Key::D:     return KEY_INPUT_D;
        case Key::Space: return KEY_INPUT_SPACE;
        case Key::Z:     return KEY_INPUT_Z;
        case Key::X:     return KEY_INPUT_X;
        case Key::C:     return KEY_INPUT_C;
        case Key::V:     return KEY_INPUT_V;
        }
        return -1;
    }

    void Init()
    {
        now.fill(0);
        prev.fill(0);
    }

    void Update()
    {
        prev = now;

        for (int i = 0; i < (int)Key::Count; i++)
        {
            now[i] = CheckHitKey(DxKeyCode((Key)i));
        }
    }

    bool IsPress(Key key)
    {
        return now[(int)key] != 0;
    }

    bool IsTrigger(Key key)
    {
        return now[(int)key] != 0 && prev[(int)key] == 0;
    }

    bool IsRelease(Key key)
    {
        return now[(int)key] == 0 && prev[(int)key] != 0;
    }
}
