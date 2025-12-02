//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Reinforced Wagon Frames");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft reinforced frames with metal bands "
        "and additional bracing for heavy-duty wagon construction.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("carpentry", (["type":"skill", "value" : 4]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 2]));
    addPrerequisite("engineering", (["type":"skill", "value" : 1]));
    addPrerequisite("/lib/instances/research/vehicles/components/basic-wagon-frame.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart" })]));
    addSpecification("bonus crafting vehicle structure", 5);
    addSpecification("bonus crafting vehicle protection", 1);
}
