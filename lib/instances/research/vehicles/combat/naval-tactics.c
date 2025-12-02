//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Naval Tactics");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required for naval warfare, including ship positioning, "
        "wind advantage, and water-based combat maneuvers.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("tactics", (["type":"skill", "value" : 6]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/combat/vehicle-formations.c", 
        (["type":"research"]));

    addSpecification("bonus nautical skills", 3);
    addSpecification("bonus tactics", 2);
}
