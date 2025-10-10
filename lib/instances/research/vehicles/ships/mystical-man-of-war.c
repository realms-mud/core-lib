//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystical Man-of-War");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct massive warships enhanced with "
        "mystical wards and arcane artillery, feared on all seas.");
    addSpecification("research type", "points");
    addSpecification("research cost", 8);
    addPrerequisite("carpentry", (["type":"skill", "value" : 12]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 10]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("engineering", (["type":"skill", "value" : 6]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 10]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c", 
        (["type":"research"]));
}
