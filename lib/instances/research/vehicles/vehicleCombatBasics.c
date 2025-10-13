//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Vehicle Combat Basics");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "fundamental knowledge required to engage in vehicle-based combat, "
        "including basic maneuvering, vehicle handling under stress, and "
        "elementary combat principles.");
    addSpecification("research type", "tree root");
    addPrerequisite("tactics", (["type":"skill", "value" : 2]));

    addSpecification("bonus overland warfare", 1);
    addSpecification("bonus nautical warfare", 1);
    addSpecification("bonus tactics", 1);
    addSpecification("bonus logistics", 1);
    addSpecification("bonus strategy", 1);
}
