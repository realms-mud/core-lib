//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Springald Mounts");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft mounts for springald torsion engines, "
        "powerful bolt-throwing weapons for vehicle mounting.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("carpentry", (["type":"skill", "value" : 4]));
    addPrerequisite("engineering", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/basic-wagon-frame.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle attack", 3);
}
