//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rengil's Legacy");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "arcane techniques mastered by the great smith Rengil.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/swords/rengils-way.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 28]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 15]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 13]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 12]));
    addPrerequisite("physics", (["type":"skill", "value" : 15]));
    addPrerequisite("mathematics", (["type":"skill", "value" : 12]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 20]));

    addSpecification("limited by", (["crafting type":({ "sword", "dagger" })]));

    addSpecification("bonus crafting value multiplier", 20);
    addSpecification("bonus crafting enchantments", 1);
    addSpecification("bonus metal crafting", 5);
    addSpecification("bonus gem crafting", 3);
}
