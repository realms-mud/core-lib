//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maegyr-din");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "arcane techniques of imbuing the mace with their own essence. "
        "This is a skill mastered by the great smiths of Serach.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("lib/instances/research/crafting/weapons/maces/serachs-legacy.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 42]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 30]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 35]));

    addSpecification("limited by", (["crafting type":"mace"]));

    addSpecification("bonus crafting value multiplier", 10);
    addSpecification("bonus crafting magical enchantment", 3);
}
