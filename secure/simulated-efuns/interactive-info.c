//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/interactive_info.h"

#if ! __EFUN_DEFINED__(query_ip_name)

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string query_ip_name(object player)
{
    string ret = 0;

    if (!player)
    {
        player = efun::this_player();
    }

    if (efun::interactive(player))
    {
        ret = efun::interactive_info(player, II_IP_NAME);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string query_ip_number(object player)
{
    string ret = 0;

    if (!player)
    {
        player = efun::this_player();
    }

    if (efun::interactive(player))
    {
        ret = efun::interactive_info(player, II_IP_NUMBER);
    }
    return ret;
}
#endif

#if ! __EFUN_DEFINED__(query_idle)
/////////////////////////////////////////////////////////////////////////////
public nomask nomask int query_idle(object player)
{
    int ret = 0;

    if (efun::interactive(player))
    {
        ret = efun::interactive_info(player, II_IDLE);
    }
    return ret;
}
#endif
