//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Basic Vehicle Tactics");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of fundamental vehicle combat tactics, including flanking "
        "maneuvers, positioning strategies, and basic engagement principles.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 4]));
    addPrerequisite("tactics", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/vehicleCombatBasics.c", 
        (["type":"research"]));

    addSpecification("bonus attack", 1);
    addSpecification("bonus defense", 1);
    addSpecification("bonus tactics", 1);
}
