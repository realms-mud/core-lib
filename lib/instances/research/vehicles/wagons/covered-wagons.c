//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Covered Wagons");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct wagons with protective covers, "
        "offering shelter from weather and basic security for cargo and passengers.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("carpentry", (["type":"skill", "value" : 3]));
    addPrerequisite("sewing", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/wagons/basic-wagon-construction.c", 
        (["type":"research"]));
}
