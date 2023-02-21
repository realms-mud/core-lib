//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Kheled's Fury");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "amazing techniques mastered by Eledhel's great smith Bergon.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/heavy-armor/bergons-legacy.c", 
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 35]));

    addSpecification("limited by", (["crafting type":
        ({ "plate armor", "splint armor", "scale armor" })]));

    addSpecification("bonus crafting value multiplier", 30);
    addSpecification("bonus crafting armor class", 1);
}
