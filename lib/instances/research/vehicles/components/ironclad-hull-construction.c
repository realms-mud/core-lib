//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ironclad Hull Construction");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft hulls armored with iron plating "
        "for maximum protection in naval combat.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("carpentry", (["type":"skill", "value" : 8]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 5]));
    addPrerequisite("engineering", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/components/reinforced-hull-construction.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting vehicle structure", 15);
    addSpecification("bonus crafting vehicle protection", 8);
}
