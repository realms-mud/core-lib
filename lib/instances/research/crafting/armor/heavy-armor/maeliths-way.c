//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maelith's Way");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "advanced techniques mastered by the great smith Maelith.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/heavy-armor/maeliths-tradition.c", 
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 30]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 30]));

    addSpecification("limited by", (["crafting type":
        ({ "plate armor", "splint armor", "scale armor" })]));

    addSpecification("bonus crafting value multiplier", 10);
    addSpecification("bonus crafting encumberance reduction", 25);
    addSpecification("bonus crafting enchantments", 1);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus metal crafting", 5);
    addSpecification("bonus armorer", 5);
}
