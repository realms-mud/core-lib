//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Helcarnath's Way");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "advanced techniques mastered by the great smiths of Helcarnath.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("lib/instances/research/crafting/weapons/flails/helcarnaths-tradition.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 31]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 25]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 25]));

    addSpecification("limited by", (["crafting type": "flail"]));

    addSpecification("bonus crafting value multiplier", 20);
    addSpecification("bonus gem crafting", 5);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus weapon smithing", 5);
}
