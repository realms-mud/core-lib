//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Siege Wagons");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct massive, heavily armored wagons "
        "designed for siege warfare, capable of mounting large weapons and "
        "carrying substantial crews.");
    addSpecification("research type", "points");
    addSpecification("research cost", 6);
    addPrerequisite("carpentry", (["type":"skill", "value" : 8]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("engineering", (["type":"skill", "value" : 6]));
    addPrerequisite("/lib/instances/research/vehicles/wagons/war-wagons.c", 
        (["type":"research"]));
}
