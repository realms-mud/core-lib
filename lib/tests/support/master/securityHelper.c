//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/interactive_info.h"

private int isInteractive = 0;

/////////////////////////////////////////////////////////////////////////////
public void ToggleInteractive()
{
    isInteractive = !isInteractive;
}

/////////////////////////////////////////////////////////////////////////////
public int interactive(object user)
{
    return isInteractive;
}

/////////////////////////////////////////////////////////////////////////////
public mixed interactive_info(object user, int value)
{
    mixed ret = 0;

    if (isInteractive)
    {
        switch (value)
        {
            case II_IP_NUMBER:
            {
                ret = "192.168.1.1";
                break;
            }
        }
    }

    return ret;
}

#include "/secure/master/security.c"
