//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Binding");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft bindings that allow elementals to "
        "pull or propel vehicles through elemental magic.");
    addSpecification("research type", "points");
    addSpecification("research cost", 7);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 14]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("sewing", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-propulsion.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting speed", 6);
    addSpecification("bonus crafting structure", 4);
}
