//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "River Vessels");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct larger riverine vessels such as "
        "barges, ferries, and other craft designed for river commerce and transport.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("carpentry", (["type":"skill", "value" : 4]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/boats/basic-boatbuilding.c", 
        (["type":"research"]));
}
