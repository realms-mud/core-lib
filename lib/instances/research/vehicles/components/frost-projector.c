//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Projectors");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical devices that project freezing "
        "cold and ice shards at enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 10]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-wagon-frame.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting weapon class", 4);
    addSpecification("bonus crafting structure", 2);
}
