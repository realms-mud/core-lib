//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/interactive_info.h"

private object isInteractive = 0;

/////////////////////////////////////////////////////////////////////////////
public void ToggleInteractive(object user)
{
    isInteractive = user;
}

/////////////////////////////////////////////////////////////////////////////
public int interactive(object user)
{
    return isInteractive == user;
}

/////////////////////////////////////////////////////////////////////////////
public mixed interactive_info(object user, int value)
{
    mixed ret = 0;

    if (isInteractive == user)
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
#include "/secure/master/destruct.c"
