//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dreadnoughts");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct massive warships representing the "
        "pinnacle of naval engineering, bristling with weapons and armor.");
    addSpecification("research type", "points");
    addSpecification("research cost", 10);
    addPrerequisite("carpentry", (["type":"skill", "value" : 15]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 12]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 10]));
    addPrerequisite("engineering", (["type":"skill", "value" : 8]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 8]));
    addPrerequisite("/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c", 
        (["type":"research"]));
}
