//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oared Warships");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct large warships powered primarily "
        "by oars, such as galleys and triremes, designed for naval combat.");
    addSpecification("research type", "points");
    addSpecification("research cost", 5);
    addPrerequisite("carpentry", (["type":"skill", "value" : 8]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 6]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("engineering", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/ships/longships.c", 
        (["type":"research"]));
}
