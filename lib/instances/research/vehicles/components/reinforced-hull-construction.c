//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Reinforced Hull Construction");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft reinforced hulls with extra timber "
        "and metal bands for enhanced durability and seaworthiness.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("carpentry", (["type":"skill", "value" : 5]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 2]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 3]));
    addPrerequisite("engineering", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/components/basic-hull-construction.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting structure", 6);
    addSpecification("bonus crafting protection", 2);
}
