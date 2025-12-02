//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Siege Rams");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft heavy ramming devices for breaking "
        "down gates, walls, and enemy vessels.");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addPrerequisite("carpentry", (["type":"skill", "value" : 4]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("engineering", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/components/armored-wagon-body.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle attack", 4);
    addSpecification("bonus crafting vehicle structure", 3);
}
