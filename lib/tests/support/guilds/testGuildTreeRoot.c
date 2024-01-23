//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addPrerequisite("long sword", (["type":"skill", "value" : 10]));
    addSpecification("source", "test");
    addSpecification("name", "Spiffy guild tree root");
    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus long sword", 2);
}
