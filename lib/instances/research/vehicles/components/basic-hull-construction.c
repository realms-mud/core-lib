//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Basic Hull Construction");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft basic wooden hulls for boats and ships, "
        "providing the watertight foundation for water vessels.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addPrerequisite("carpentry", (["type":"skill", "value" : 2]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 1]));
    addPrerequisite("/lib/instances/research/vehicles/craftComponents.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting vehicle structure", 3);
    addSpecification("bonus crafting vehicle protection", 1);
}
