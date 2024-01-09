//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maelith's Legacy");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "arcane techniques mastered by the great smith Maelith.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/axes/maeliths-tradition.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 26]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 22]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 22]));

    addSpecification("limited by", (["crafting type":"axe"]));

    addSpecification("bonus crafting value multiplier", 20);
    addSpecification("bonus crafting enchantments", 1);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus metal crafting", 3);
    addSpecification("bonus weapon smithing", 3);
}
