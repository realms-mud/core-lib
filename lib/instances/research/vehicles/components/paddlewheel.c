//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Paddlewheel");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft paddlewheels for mechanical river "
        "propulsion, providing reliable movement in calm waters.");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addPrerequisite("engineering", (["type":"skill", "value" : 4]));
    addPrerequisite("carpentry", (["type":"skill", "value" : 4]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/components/basic-hull-construction.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting speed", 2);
    addSpecification("bonus crafting structure", 1);
}
