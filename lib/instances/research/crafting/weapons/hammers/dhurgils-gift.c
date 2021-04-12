//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dhurgil's Gift");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "master techniques of imbuing the hammer with their own essence. "
        "This is a skill mastered by the great smiths of Dhurgil.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/hammers/khel-ma-druek.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 45]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 40]));

    addSpecification("limited by", (["crafting type":"hammer"]));

    addSpecification("bonus crafting magical enchantment", 2);
    addSpecification("bonus crafting enchantments", 1);
}
