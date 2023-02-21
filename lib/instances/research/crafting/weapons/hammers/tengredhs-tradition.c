//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tengredh's Tradition");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "techniques mastered by the great smith Tengredh.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/hammers/craftDoubleAxe.c", 
        (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/weapons/common/folding.c",
        (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/weapons/common/austempering.c",
        (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/weapons/common/differential-hardening.c",
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 25]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 20]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 20]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 20]));

    addSpecification("limited by", (["crafting type":"hammer"]));

    addSpecification("bonus crafting value multiplier", 30);
    addSpecification("bonus crafting encumberance reduction", 10);
    addSpecification("bonus crafting enchantments", 1);
    addSpecification("bonus blacksmithing", 3);
    addSpecification("bonus metal crafting", 3);
    addSpecification("bonus weapon smithing", 3);
}
