//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ramming Techniques");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to effectively use vehicles as battering rams, "
        "including optimal angles of attack and structural reinforcement.");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 5]));
    addPrerequisite("engineering", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/combat/basic-vehicle-tactics.c", 
        (["type":"research"]));

    addSpecification("bonus damage", 2);
    addSpecification("bonus attack", 1);
    addSpecification("bonus resist physical", 2);
}
