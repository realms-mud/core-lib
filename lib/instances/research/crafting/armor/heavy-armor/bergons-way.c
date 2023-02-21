//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bergon's Way");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "advanced techniques mastered by Eledhel's great smith Bergon.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/heavy-armor/bergons-tradition.c", 
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 25]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 22]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 22]));

    addSpecification("limited by", (["crafting type":
        ({ "plate armor", "splint armor", "scale armor" })]));

    addSpecification("bonus crafting value multiplier", 10);
    addSpecification("bonus crafting encumberance reduction", 25);
    addSpecification("bonus blacksmithing", 5);
    addSpecification("bonus metal crafting", 5);
    addSpecification("bonus armorer", 5);
}
