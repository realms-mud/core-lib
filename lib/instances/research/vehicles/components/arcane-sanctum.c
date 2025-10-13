//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Sanctums");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magically shielded chambers for "
        "arcane crew members and magical research while traveling.");
    addSpecification("research type", "points");
    addSpecification("research cost", 6);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 12]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("carpentry", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-cargo.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting henchman bonus", 2);
    addSpecification("bonus crafting vehicle protection", 6);
}
