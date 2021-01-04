//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addPrerequisite("long sword", (["type":"skill", "value" : 10]));
        addSpecification("name", "Spiffy guild tree root");
        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
        addSpecification("bonus long sword", 2);
    }
}
