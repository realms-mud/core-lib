//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Vessels");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct magically-enhanced vessels that "
        "incorporate arcane energies for propulsion and protection.");
    addSpecification("research type", "points");
    addSpecification("research cost", 5);
    addPrerequisite("carpentry", (["type":"skill", "value" : 6]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 4]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 8]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/boats/basic-boatbuilding.c", 
        (["type":"research"]));
}
