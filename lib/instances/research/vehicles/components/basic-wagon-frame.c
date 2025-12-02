//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Basic Wagon Frames");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft basic wooden frames for wagons and carts, "
        "providing the structural foundation for land vehicles.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addPrerequisite("carpentry", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/craftComponents.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart" })]));
    addSpecification("bonus crafting vehicle structure", 2);
}
