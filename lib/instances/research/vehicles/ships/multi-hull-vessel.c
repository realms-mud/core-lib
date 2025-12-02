//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Multi-Hull Vessels");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct vessels with multiple hulls, such as "
        "catamarans, providing increased stability and speed.");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addPrerequisite("carpentry", (["type":"skill", "value" : 5]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 3]));
    addPrerequisite("engineering", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/boats/river-vessels.c", 
        (["type":"research"]));
}
