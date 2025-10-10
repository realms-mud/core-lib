//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crystal Vessels");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct vessels incorporating crystal "
        "matrices for enhanced magical properties and ethereal beauty.");
    addSpecification("research type", "points");
    addSpecification("research cost", 6);
    addPrerequisite("carpentry", (["type":"skill", "value" : 7]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 5]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 10]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 7]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/boats/arcane-vessels.c", 
        (["type":"research"]));
}
