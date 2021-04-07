//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Kheled's Way");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "advanced techniques mastered by the great dwarven smith Kheled.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("lib/instances/research/crafting/weapons/axes/kheleds-tradition.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 23]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 21]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 21]));

    addSpecification("limited by", (["crafting type":"axe"]));

    addSpecification("bonus crafting value multiplier", 10);
    addSpecification("bonus crafting encumberance reduction", 25);
    addSpecification("bonus blacksmithing", 5);
    addSpecification("bonus metal crafting", 5);
    addSpecification("bonus weapon smithing", 5);
}
