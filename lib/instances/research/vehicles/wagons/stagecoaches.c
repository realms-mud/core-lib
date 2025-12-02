//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stagecoaches");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct fast, enclosed coaches designed "
        "for passenger transport and mail delivery over established routes.");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addPrerequisite("carpentry", (["type":"skill", "value" : 4]));
    addPrerequisite("leather crafting", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/wagons/covered-wagons.c", 
        (["type":"research"]));
}
