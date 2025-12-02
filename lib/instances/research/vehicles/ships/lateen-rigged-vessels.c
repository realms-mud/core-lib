//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lateen-Rigged Vessels");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct ships with triangular lateen sails, "
        "providing superior maneuverability and wind efficiency.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("carpentry", (["type":"skill", "value" : 7]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 5]));
    addPrerequisite("sewing", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c", 
        (["type":"research"]));
}
