//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Warding");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical wards that shield vehicles "
        "from both physical and magical harm.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 8]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-wagon-frame.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle protection", 8);
}
