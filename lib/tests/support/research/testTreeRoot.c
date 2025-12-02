//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addPrerequisite("long sword", (["type":"skill", "value" : 10]));
    addSpecification("description", "This is a description");
    addSpecification("source", "mage guild");
    addSpecification("name", "Spiffy tree root");
    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus long sword", 2);
}
