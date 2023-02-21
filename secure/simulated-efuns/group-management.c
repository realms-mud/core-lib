//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public string *customGroups(object user)
{
    string *ret = ({});

    if (member(inherit_list(this_object()),
        "/secure/simulated-efuns/testing.c") > -1)
    {
        ret = call_direct(this_object(), "testingGroups");
    }

    return ret;
}
