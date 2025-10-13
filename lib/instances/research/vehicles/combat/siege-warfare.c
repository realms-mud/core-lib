//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Siege Warfare");
    addSpecification("source", "vehicles");
    addSpecification("description", "Provides knowledge of siege tactics, "
        "including the use of siege engines and fortification assault.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("/lib/instances/research/vehicles/combat/ramming-techniques.c",
        (["type":"research"]));

    addSpecification("bonus overland warfare", 1);
    addSpecification("bonus logistics", 1);
}
