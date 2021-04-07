//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Khed-arun");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "arcane techniques of imbuing the chainmail with their own essence. "
        "This is a skill mastered by the great smiths of Khazurath.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("lib/instances/research/crafting/armor/chainmail/khazuraths-legacy.c", 
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 42]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 42]));

    addSpecification("limited by", (["crafting type":"chainmail"]));

    addSpecification("bonus crafting value multiplier", 10);
    addSpecification("bonus crafting magical enchantment", 3);
}
