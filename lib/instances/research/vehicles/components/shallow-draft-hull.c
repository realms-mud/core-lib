//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shallow Draft Hulls");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft hulls designed for shallow water "
        "navigation, allowing access to rivers and coastal areas.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("carpentry", (["type":"skill", "value" : 4]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 3]));
    addPrerequisite("engineering", (["type":"skill", "value" : 1]));
    addPrerequisite("/lib/instances/research/vehicles/components/basic-hull-construction.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting vehicle structure", 2);
    addSpecification("bonus crafting vehicle speed", 1);
}
