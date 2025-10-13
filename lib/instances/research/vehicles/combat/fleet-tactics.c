//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fleet Tactics");
    addSpecification("source", "vehicles");
    addSpecification("description", "Provides knowledge of commanding multiple "
        "ships in coordinated fleet actions.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("/lib/instances/research/vehicles/combat/ship-to-ship-combat.c",
        (["type":"research"]));

    addSpecification("bonus nautical warfare", 1);
    addSpecification("bonus strategy", 1);
    addSpecification("bonus logistics", 1);
}
