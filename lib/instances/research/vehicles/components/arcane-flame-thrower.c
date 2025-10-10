//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Flame Throwers");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical devices that project streams "
        "of arcane fire at enemies, causing devastating damage.");
    addSpecification("research type", "points");
    addSpecification("research cost", 8);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 15]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("engineering", (["type":"skill", "value" : 6]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-cannon.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting weapon class", 12);
    addSpecification("bonus crafting structure", 6);
}
