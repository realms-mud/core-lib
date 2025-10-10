//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Basic Boatbuilding");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct simple boats, canoes, and other "
        "basic watercraft for river and lake travel.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addPrerequisite("carpentry", (["type":"skill", "value" : 2]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 1]));
    addPrerequisite("/lib/instances/research/vehicles/craftVehicles.c", 
        (["type":"research"]));
}
