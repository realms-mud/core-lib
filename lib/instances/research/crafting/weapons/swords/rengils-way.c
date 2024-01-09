//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rengil's Way");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "advanced techniques mastered by the great smith Rengil.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/swords/rengils-tradition.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 30]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 15]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 15]));

    addSpecification("limited by", (["crafting type":({ "sword", "dagger" })]));

    addSpecification("bonus crafting value multiplier", 10);
    addSpecification("bonus crafting encumberance reduction", 25);
    addSpecification("bonus blacksmithing", 5);
    addSpecification("bonus metal crafting", 5);
    addSpecification("bonus weapon smithing", 5);
}
