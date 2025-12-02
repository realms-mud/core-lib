//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Caltrop Dispensers");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft devices that scatter spiked caltrops "
        "to impede pursuit and damage following enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addPrerequisite("metal crafting", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/components/basic-wagon-frame.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart" })]));
    addSpecification("bonus crafting vehicle attack", 1);
}
