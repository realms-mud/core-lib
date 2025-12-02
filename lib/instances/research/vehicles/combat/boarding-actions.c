//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Boarding Actions");
    addSpecification("source", "vehicles");
    addSpecification("description", "Provides knowledge of boarding enemy "
        "vessels and repelling boarders.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("/lib/instances/research/vehicles/combat/naval-tactics.c",
        (["type":"research"]));

    addSpecification("bonus nautical warfare", 1);
    addSpecification("bonus tactics", 1);
}
