//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Longships");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct long, narrow vessels designed for "
        "both rowing and sailing, ideal for coastal raids and exploration.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("carpentry", (["type":"skill", "value" : 6]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 4]));
    addPrerequisite("leather crafting", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c", 
        (["type":"research"]));
}
