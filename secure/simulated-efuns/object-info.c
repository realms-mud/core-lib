//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/object_info.h"

#if ! __EFUN_DEFINED__(set_heart_beat)
/////////////////////////////////////////////////////////////////////////////
public nomask int set_heart_beat(int flag)
{
    int ret = 1;
    object previousObject = efun::previous_object();
    int heartBeat = efun::object_info(previousObject, OC_HEART_BEAT);

    if (!flag == !heartBeat)
    {
        ret = 0;
    }
    efun::configure_object(previousObject, OC_HEART_BEAT, flag);

    return 1;
}

#endif

#if ! __EFUN_DEFINED__(file_name)
/////////////////////////////////////////////////////////////////////////////
public nomask varargs string file_name(object ob)
{
    return object_name(ob);
}
#endif

#if ! __EFUN_DEFINED__(query_once_interactive)

/////////////////////////////////////////////////////////////////////////////
public nomask int query_once_interactive(object ob)
{
    return efun::object_info(ob, OI_ONCE_INTERACTIVE);
}

#endif
