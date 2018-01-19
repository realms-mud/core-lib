//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
void reset(int arg)
{
    if (!arg)
    {
        questItem::reset(arg);

        setName("blah");
        addState("blah", "blah");
        setInitialState("blah");
    }
}
