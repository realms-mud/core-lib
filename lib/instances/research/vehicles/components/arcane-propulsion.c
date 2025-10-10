//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Propulsion");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical propulsion devices that move "
        "vessels through pure arcane energy without wind or oars.");
    addSpecification("research type", "points");
    addSpecification("research cost", 5);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 10]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("engineering", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-hull-construction.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting speed", 5);
    addSpecification("bonus crafting structure", 3);
}
