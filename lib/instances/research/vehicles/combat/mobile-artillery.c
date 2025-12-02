//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mobile Artillery");
    addSpecification("source", "vehicles");
    addSpecification("description", "Provides knowledge of using and "
        "countering mobile artillery in vehicle combat.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("/lib/instances/research/vehicles/combat/siege-warfare.c",
        (["type":"research"]));

    addSpecification("bonus overland warfare", 1);
    addSpecification("bonus logistics", 1);
}
