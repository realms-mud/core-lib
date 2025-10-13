//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystical Defenses");
    addSpecification("source", "vehicles");
    addSpecification("description", "Provides knowledge of magical and "
        "mystical defenses for vehicles in combat.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/combat/arcane-vehicle-combat.c",
        (["type":"research"]));

    addSpecification("bonus tactics", 1);
    addSpecification("bonus logistics", 1);
}
