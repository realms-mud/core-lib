//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enhance the Essence");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "advanced techniques of imbuing the blade with their own essence. "
        "This is a skill mastered by the great smith Daedrun.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/swords/impart-the-essence.c", 
        (["type":"research"]));

    addPrerequisite("weapon smithing", (["type":"skill", "value" : 40]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 35]));

    addSpecification("limited by", (["crafting type":({ "sword", "dagger" })]));

    addSpecification("bonus crafting magical enchantment", 2);
}
