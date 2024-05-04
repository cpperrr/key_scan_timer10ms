#define R1_IO_1
#define R2_IO_1
#define R3_IO_1
#define R4_IO_1

#define R1_IO_0
#define R2_IO_0
#define R3_IO_0
#define R4_IO_0

#define IO_COL1_IN
#define IO_COL2_IN
#define IO_COL3_IN
#define IO_COL4_IN

void check_key44_task10ms()
{

    static UINT8 i = 0;
    static UINT8 rowkey_state = 0;
    static UINT16 _keyState_value = 0;

    static UINT8 s_swOffCnt[4] = {0};
    static UINT8 s_SwOnCnt[4] = {0};
    static UINT8 s_state_col1[4] = {0};

    switch (rowkey_state)
    {
    case 0:
        R1_IO_0;
        R2_IO_1;
        R3_IO_1;
        R4_IO_1;
        for (i = 0; i < 4; i++)
        {
            // 开关闭合
            if (IO_COL1_IN == 0)
            {

                s_swOffCnt[i] = 0;
                s_SwOnCnt[i]++;
                if (s_SwOnCnt[i] >= 3)
                {
                    s_SwOnCnt[i] = 0;
                    if (s_state_col1[i] == 0)
                    {
                        _keyState_value |= (1 << i);
                        s_state_col1[i] = 1;
                    }
                }
            }
            else
            {
                s_SwOnCnt[i] = 0;
                s_swOffCnt[i]++;

                if (s_swOffCnt[i] >= 3)
                {
                    s_swOffCnt[i] = 0;
                    if (s_state_col1[i] == 1)
                    {

                        s_state_col1[i] = 0;
                    }
                }
            }
        }
        rowkey_state = 1;
        break;
    case 1:
        R1_IO_1;
        R2_IO_0;
        R3_IO_1;
        R4_IO_1;
        for (i = 4; i < 8; i++)
        {
            // 开关闭合
            if (IO_COL1_IN == 0)
            {

                s_swOffCnt[i] = 0;
                s_SwOnCnt[i]++;
                if (s_SwOnCnt[i] >= 3)
                {
                    s_SwOnCnt[i] = 0;
                    if (s_state_col1[i] == 0)
                    {
                        _keyState_value |= (1 << i);
                        s_state_col1[i] = 1;
                    }
                }
            }
            else
            {
                s_SwOnCnt[i] = 0;
                s_swOffCnt[i]++;

                if (s_swOffCnt[i] >= 3)
                {
                    s_swOffCnt[i] = 0;
                    if (s_state_col1[i] == 1)
                    {

                        s_state_col1[i] = 0;
                    }
                }
            }
        }
        rowkey_state = 2;
        break;
    case 2:
        for (i = 8; i < 12; i++)
        {
            // 开关闭合
            if (IO_COL1_IN == 0)
            {

                s_swOffCnt[i] = 0;
                s_SwOnCnt[i]++;
                if (s_SwOnCnt[i] >= 3)
                {
                    s_SwOnCnt[i] = 0;
                    if (s_state_col1[i] == 0)
                    {
                        _keyState_value |= (1 << i);
                        s_state_col1[i] = 1;
                    }
                }
            }
            else
            {
                s_SwOnCnt[i] = 0;
                s_swOffCnt[i]++;

                if (s_swOffCnt[i] >= 3)
                {
                    s_swOffCnt[i] = 0;
                    if (s_state_col1[i] == 1)
                    {

                        s_state_col1[i] = 0;
                    }
                }
            }
        }
        R1_IO_1;
        R2_IO_1;
        R3_IO_0;
        R4_IO_1;
        rowkey_state = 3;
        break;
    case 3:
        for (i = 12; i < 16; i++)
        {
            // 开关闭合
            if (IO_COL1_IN == 0)
            {

                s_swOffCnt[i] = 0;
                s_SwOnCnt[i]++;
                if (s_SwOnCnt[i] >= 3)
                {
                    s_SwOnCnt[i] = 0;
                    if (s_state_col1[i] == 0)
                    {
                        _keyState_value |= (1 << i);
                        s_state_col1[i] = 1;
                    }
                }
            }
            else
            {
                s_SwOnCnt[i] = 0;
                s_swOffCnt[i]++;

                if (s_swOffCnt[i] >= 3)
                {
                    s_swOffCnt[i] = 0;
                    if (s_state_col1[i] == 1)
                    {

                        s_state_col1[i] = 0;
                    }
                }
            }
        }
        R1_IO_1;
        R2_IO_1;
        R3_IO_1;
        R4_IO_0;
        rowkey_state = 0;
        break;
    }

    if (_keyState_value & (1 << 0))
    {
    }
    if (_keyState_value & (1 << 1))
    {
    }
    if (_keyState_value & (1 << 2))
    {
    }
    if (_keyState_value & (1 << 3))
    {
    }
    if (_keyState_value & (1 << 4))
    {
    }
    if (_keyState_value & (1 << 5))
    {
    }

    _keyState_value = 0;
}