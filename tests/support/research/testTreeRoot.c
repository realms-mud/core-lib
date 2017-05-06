//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    passiveResearchItem::init();
    addPrerequisite("long sword", (["type":"skill", "value" : 10]));
    addSpecification("name", "Spiffy tree root");
    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus long sword", 2);
}

