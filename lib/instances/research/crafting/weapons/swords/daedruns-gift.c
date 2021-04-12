//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Daedrun's Gift");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "master techniques of imbuing the blade with their own essence. "
        "This is a skill mastered by the great smith Daedrun.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/swords/enhance-the-essence.c", 
        (["type":"research"]));

    addPrerequisite("weapon smithing", (["type":"skill", "value" : 45]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 35]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 30]));
    addPrerequisite("physics", (["type":"skill", "value" : 25]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 40]));

    addSpecification("limited by", (["crafting type":({ "sword", "dagger" }) ]));

    addSpecification("bonus crafting magical enchantment", 2);
    addSpecification("bonus crafting enchantments", 1);
}
