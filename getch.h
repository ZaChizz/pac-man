char getch()
{
    static INPUT_RECORD cachedInputRecord;

    INPUT_RECORD r;

    if(cachedInputRecord.EventType == 1)
    {
        r = cachedInputRecord;
        if(cachedInputRecord.Event.KeyEvent.wRepeatCount == 0)
            cachedInputRecord.EventType = -1;
        else
            cachedInputRecord.Event.KeyEvent.wRepeatCount--;
    } else {

        DWORD n;

        while(true)
        {

            ReadConsoleInput(GetStdHandle(-10), &r, 1, &n);

            short keyCode = r.Event.KeyEvent.wVirtualKeyCode;

            if(!(r.EventType == 1 && r.Event.KeyEvent.bKeyDown) && keyCode != 0x12) continue;

            char ch = r.Event.KeyEvent.uChar.AsciiChar;

            if(ch == 0 && ((keyCode >= 0x10 && keyCode <= 0x12) || keyCode == 0x14 || keyCode == 0x90 || keyCode == 0x91)) continue;

            if(r.Event.KeyEvent.wRepeatCount > 1)
            {
                r.Event.KeyEvent.wRepeatCount--;
                cachedInputRecord = r;
            }

            break;
        }
    }

    return r.Event.KeyEvent.uChar.AsciiChar;
}
