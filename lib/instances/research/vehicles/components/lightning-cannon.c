//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lightning Cannons");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical devices that hurl devastating "
        "bolts of lightning at enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 7);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 14]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 7]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-cannon.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting weapon class", 8);
    addSpecification("bonus crafting structure", 4);
}
