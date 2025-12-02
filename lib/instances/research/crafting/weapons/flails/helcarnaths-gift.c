//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Helcarnath's Gift");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "master techniques of imbuing the flail with their own essence. "
        "This is a skill mastered by the great smiths of Helcarnath.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/flails/feir-an-wol.c", 
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 45]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 40]));

    addSpecification("limited by", (["crafting type":"flail"]));

    addSpecification("bonus crafting magical enchantment", 2);
    addSpecification("bonus crafting enchantments", 1);
}
