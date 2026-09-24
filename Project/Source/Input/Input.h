#pragma once
#include <array>

namespace Input
{
    enum class Key {
        Up,
        Down,
        Left,
        Right,
        W,
        A,
        S,
        D,
        Space,
        Z,
        X,
        C,
        V,
        Count
    };

    void Init();
    void Update();

    bool IsPress(Key key);
    bool IsTrigger(Key key);
    bool IsRelease(Key key);
}
