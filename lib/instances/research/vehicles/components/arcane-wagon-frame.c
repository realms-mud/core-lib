//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Wagon Frames");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magically enhanced wagon frames with "
        "arcane runes and crystal inlays for supernatural properties.");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addPrerequisite("carpentry", (["type":"skill", "value" : 5]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 6]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/reinforced-wagon-frame.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart" })]));
    addSpecification("bonus crafting vehicle structure", 8);
    addSpecification("bonus crafting vehicle protection", 3);
}
