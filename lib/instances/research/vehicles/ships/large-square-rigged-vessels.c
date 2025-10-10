//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Large Square-Rigged Vessels");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct large ships with square-rigged sails, "
        "such as galleons and carracks, designed for ocean voyages and heavy cargo.");
    addSpecification("research type", "points");
    addSpecification("research cost", 6);
    addPrerequisite("carpentry", (["type":"skill", "value" : 10]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 7]));
    addPrerequisite("sewing", (["type":"skill", "value" : 5]));
    addPrerequisite("engineering", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/ships/lateen-rigged-vessels.c", 
        (["type":"research"]));
}
