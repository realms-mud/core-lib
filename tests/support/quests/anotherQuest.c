//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
void init()
{
    questItem::init();

    setName("another quest");
    addState("blah", "blah");
    addFinalState("blah", "success");
    setInitialState("blah");
}
