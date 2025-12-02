//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Vehicles");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "fundamental knowledge required to construct basic vehicles for "
        "transportation and commerce.");
    addSpecification("research type", "tree root");
    addPrerequisite("carpentry", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/crafting/craftItems.c", 
        (["type":"research"]));
}