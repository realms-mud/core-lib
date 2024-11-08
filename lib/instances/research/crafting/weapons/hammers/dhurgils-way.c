//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dhurgil's Way");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "advanced techniques mastered by the great smiths of Dhurgil.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/hammers/dhurgils-tradition.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 31]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 25]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 25]));

    addSpecification("limited by", (["crafting type":"hammer"]));

    addSpecification("bonus crafting value multiplier", 20);
    addSpecification("bonus gem crafting", 5);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus weapon smithing", 5);
}
