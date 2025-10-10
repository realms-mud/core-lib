//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Cargo Systems");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magically expanded cargo holds with "
        "protective wards and dimensional enhancement.");
    addSpecification("research type", "points");
    addSpecification("research cost", 5);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 10]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("carpentry", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-warding.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting capacity", 500);
    addSpecification("bonus crafting protection", 4);
}
