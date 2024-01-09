//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Daedrun's Legacy");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "arcane techniques mastered by the great smith Daedrun.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/swords/daedruns-way.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 33]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 30]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 25]));
    addPrerequisite("physics", (["type":"skill", "value" : 21]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 30]));

    addSpecification("limited by", (["crafting type":({ "sword", "dagger" })]));

    addSpecification("bonus crafting value multiplier", 20);
    addSpecification("bonus crafting enchantments", 1);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus metal crafting", 3);
    addSpecification("bonus weapon smithing", 3);
}
