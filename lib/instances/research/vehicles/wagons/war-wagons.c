//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "War Wagons");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct armored wagons designed for battlefield "
        "use, featuring reinforced construction and weapon mounting points.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("carpentry", (["type":"skill", "value" : 5]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 3]));
    addPrerequisite("engineering", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/wagons/covered-wagons.c", 
        (["type":"research"]));
}
