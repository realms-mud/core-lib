//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maelith's Tradition");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "techniques mastered by the great smith Maelith.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/chainmail/craftDoubleAxe.c", 
        (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/armor/common/folding.c",
        (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/armor/common/austempering.c",
        (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/armor/common/differential-hardening.c",
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 25]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 25]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 20]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 15]));
    addPrerequisite("physics", (["type":"skill", "value" : 15]));
    addPrerequisite("mathematics", (["type":"skill", "value" : 15]));

    addSpecification("limited by", (["crafting type":"chainmail"]));

    addSpecification("bonus crafting value multiplier", 30);
    addSpecification("bonus crafting encumberance reduction", 10);
    addSpecification("bonus crafting enchantments", 1);
    addSpecification("bonus blacksmithing", 3);
    addSpecification("bonus metal crafting", 3);
    addSpecification("bonus armorer", 3);
}
