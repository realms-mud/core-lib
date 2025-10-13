//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Levitation Matrix");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical devices that allow vehicles "
        "to float above the ground or water through levitation magic.");
    addSpecification("research type", "points");
    addSpecification("research cost", 8);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 15]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 10]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("engineering", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-propulsion.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle speed", 8);
    addSpecification("bonus crafting vehicle structure", 5);
    addSpecification("bonus crafting vehicle protection", 3);
}
