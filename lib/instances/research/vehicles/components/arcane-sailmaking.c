//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Sailmaking");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft sails woven with magical threads "
        "that can catch even the faintest breeze and channel arcane winds.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("sewing", (["type":"skill", "value" : 4]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 3]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 6]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/components/square-sailmaking.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting speed", 4);
}
