//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("another quest");
    setDescription("Describe me!");
    addState("blah", "blah");
    addFinalState("blah", "success");
    setInitialState("blah");
}
