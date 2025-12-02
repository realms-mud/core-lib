//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Armored Wagon Bodies");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft wagon bodies with metal plating "
        "and armor for battlefield use and dangerous travel.");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addPrerequisite("carpentry", (["type":"skill", "value" : 6]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("engineering", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/components/reinforced-wagon-frame.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart" })]));
    addSpecification("bonus crafting vehicle structure", 8);
    addSpecification("bonus crafting vehicle protection", 4);
}
