//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fortification Assault");
    addSpecification("source", "vehicles");
    addSpecification("description", "Provides knowledge of assaulting and "
        "defending fortifications using vehicles and siege equipment.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("/lib/instances/research/vehicles/combat/siege-warfare.c",
        (["type":"research"]));

    addSpecification("bonus overland warfare", 1);
    addSpecification("bonus tactics", 1);
}
