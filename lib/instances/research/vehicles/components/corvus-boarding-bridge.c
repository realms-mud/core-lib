//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Corvus Boarding Bridges");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft pivoting bridges with spikes for "
        "boarding enemy ships, turning naval combat into infantry warfare.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("carpentry", (["type":"skill", "value" : 4]));
    addPrerequisite("engineering", (["type":"skill", "value" : 3]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/components/armored-wagon-body.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship" })]));
    addSpecification("bonus crafting vehicle attack", 4);
    addSpecification("bonus crafting vehicle structure", 3);
}
