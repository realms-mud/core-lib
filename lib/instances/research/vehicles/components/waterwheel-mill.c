//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Waterwheel Mill");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft waterwheels for grinding grain while "
        "moored in a river, providing industrial capability to vessels.");
    addSpecification("research type", "points");
    addSpecification("research cost", 5);
    addPrerequisite("engineering", (["type":"skill", "value" : 6]));
    addPrerequisite("carpentry", (["type":"skill", "value" : 6]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/paddlewheel.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting capacity", 200);
    addSpecification("bonus crafting structure", 4);
}
