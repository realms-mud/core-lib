//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Vehicle Formations");
    addSpecification("source", "vehicles");
    addSpecification("description", "Provides knowledge of effective vehicle "
        "formations for both offense and defense in combat.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("/lib/instances/research/vehicles/combat/basic-vehicle-tactics.c",
        (["type":"research"]));

    addSpecification("bonus overland warfare", 1);
    addSpecification("bonus tactics", 1);
}
