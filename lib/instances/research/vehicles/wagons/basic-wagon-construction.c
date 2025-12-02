//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Basic Wagon Construction");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct simple wagons, carts, and other "
        "basic wheeled vehicles for land transport.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addPrerequisite("carpentry", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/craftVehicles.c", 
        (["type":"research"]));
}
