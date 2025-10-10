//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Vehicle Components");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "fundamental knowledge required to craft specialized components "
        "for vehicles, enabling customization and enhancement of transportation.");
    addSpecification("research type", "tree root");
    addPrerequisite("carpentry", (["type":"skill", "value" : 1]));
    addPrerequisite("/lib/instances/research/vehicles/craftVehicles.c", 
        (["type":"research"]));
}
