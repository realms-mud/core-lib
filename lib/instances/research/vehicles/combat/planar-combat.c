//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Planar Combat");
    addSpecification("source", "vehicles");
    addSpecification("description", "Provides knowledge of vehicle combat "
        "involving planar or extraplanar forces.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 5 ]));
    addPrerequisite("/lib/instances/research/vehicles/combat/elemental-warfare.c",
        (["type":"research"]));

    addSpecification("bonus tactics", 1);
    addSpecification("bonus strategy", 1);
}
