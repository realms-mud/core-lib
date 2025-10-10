//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "War Wagon Chassis");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft heavy-duty chassis designed specifically "
        "for war wagons with weapon mounts and crew protection.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("carpentry", (["type":"skill", "value" : 8]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("engineering", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/armored-wagon-body.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart" })]));
    addSpecification("bonus crafting structure", 12);
    addSpecification("bonus crafting protection", 6);
}
