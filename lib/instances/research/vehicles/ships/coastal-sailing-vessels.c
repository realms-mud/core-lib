//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Coastal Sailing Vessels");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct small to medium sailing ships "
        "designed for coastal waters and short sea voyages.");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addPrerequisite("carpentry", (["type":"skill", "value" : 5]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 3]));
    addPrerequisite("sewing", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/boats/river-vessels.c", 
        (["type":"research"]));
}
