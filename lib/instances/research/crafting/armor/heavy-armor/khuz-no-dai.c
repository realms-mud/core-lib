//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Khuz-no-dai");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "advanced techniques of imbuing heavy armor with its own essence. "
        "This is a skill mastered by the great smiths of Khazurath.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/heavy-armor/khed-arun.c", 
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 45]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 45]));

    addSpecification("limited by", (["crafting type":
        ({ "plate armor", "splint armor", "scale armor" })]));

    addSpecification("bonus crafting magical enchantment", 2);
}
