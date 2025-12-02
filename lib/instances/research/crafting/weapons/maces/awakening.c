//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Awakening");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "advanced techniques of imbuing the mace with their own essence. "
        "This is a skill mastered by the great smiths of Serach.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/maces/maegyr-din.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 40]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 30]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 33]));

    addSpecification("limited by", (["crafting type": "mace"]));

    addSpecification("bonus crafting magical enchantment", 2);
}
