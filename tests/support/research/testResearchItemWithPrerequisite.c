//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/activeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    activeResearchItem::init();
    addPrerequisite("long sword", (["type":"skill", "value" : 10]));
}

