//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void BasicCombat()
{
    addResearchElement("/lib/instances/research/vehicles/combat/basic-vehicle-tactics.c");
    addChild("/lib/instances/research/vehicles/combat/basic-vehicle-tactics.c",
        "/lib/instances/research/vehicles/vehicleCombatBasics.c");

    addResearchElement("/lib/instances/research/vehicles/combat/vehicle-formations.c");
    addChild("/lib/instances/research/vehicles/combat/vehicle-formations.c",
        "/lib/instances/research/vehicles/combat/basic-vehicle-tactics.c");

    addResearchElement("/lib/instances/research/vehicles/combat/ramming-techniques.c");
    addChild("/lib/instances/research/vehicles/combat/ramming-techniques.c",
        "/lib/instances/research/vehicles/combat/basic-vehicle-tactics.c");
}

/////////////////////////////////////////////////////////////////////////////
public void NavalCombat()
{
    addResearchElement("/lib/instances/research/vehicles/combat/naval-tactics.c");
    addChild("/lib/instances/research/vehicles/combat/naval-tactics.c",
        "/lib/instances/research/vehicles/combat/vehicle-formations.c");

    addResearchElement("/lib/instances/research/vehicles/combat/boarding-actions.c");
    addChild("/lib/instances/research/vehicles/combat/boarding-actions.c",
        "/lib/instances/research/vehicles/combat/naval-tactics.c");

    addResearchElement("/lib/instances/research/vehicles/combat/ship-to-ship-combat.c");
    addChild("/lib/instances/research/vehicles/combat/ship-to-ship-combat.c",
        "/lib/instances/research/vehicles/combat/boarding-actions.c");

    addResearchElement("/lib/instances/research/vehicles/combat/fleet-tactics.c");
    addChild("/lib/instances/research/vehicles/combat/fleet-tactics.c",
        "/lib/instances/research/vehicles/combat/ship-to-ship-combat.c");
}

/////////////////////////////////////////////////////////////////////////////
public void SiegeCombat()
{
    addResearchElement("/lib/instances/research/vehicles/combat/siege-warfare.c");
    addChild("/lib/instances/research/vehicles/combat/siege-warfare.c",
        "/lib/instances/research/vehicles/combat/ramming-techniques.c");

    addResearchElement("/lib/instances/research/vehicles/combat/fortification-assault.c");
    addChild("/lib/instances/research/vehicles/combat/fortification-assault.c",
        "/lib/instances/research/vehicles/combat/siege-warfare.c");

    addResearchElement("/lib/instances/research/vehicles/combat/mobile-artillery.c");
    addChild("/lib/instances/research/vehicles/combat/mobile-artillery.c",
        "/lib/instances/research/vehicles/combat/siege-warfare.c");
}

/////////////////////////////////////////////////////////////////////////////
public void MagicalCombat()
{
    addResearchElement("/lib/instances/research/vehicles/combat/arcane-vehicle-combat.c");
    addChild("/lib/instances/research/vehicles/combat/arcane-vehicle-combat.c",
        "/lib/instances/research/vehicles/combat/basic-vehicle-tactics.c");

    addResearchElement("/lib/instances/research/vehicles/combat/mystical-defenses.c");
    addChild("/lib/instances/research/vehicles/combat/mystical-defenses.c",
        "/lib/instances/research/vehicles/combat/arcane-vehicle-combat.c");

    addResearchElement("/lib/instances/research/vehicles/combat/elemental-warfare.c");
    addChild("/lib/instances/research/vehicles/combat/elemental-warfare.c",
        "/lib/instances/research/vehicles/combat/mystical-defenses.c");

    addResearchElement("/lib/instances/research/vehicles/combat/planar-combat.c");
    addChild("/lib/instances/research/vehicles/combat/planar-combat.c",
        "/lib/instances/research/vehicles/combat/elemental-warfare.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Vehicle Combat");
    Description("This research tree tracks the knowledge required for "
        "vehicle-based combat and warfare");
    Source("vehicles");
    addPrerequisite("weapon smithing", 
        (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/craftVehicles.c",
        (["type":"research"]));
    addResearchElement("/lib/instances/research/vehicles/vehicleCombatBasics.c");
    TreeRoot("/lib/instances/research/vehicles/vehicleCombatBasics.c");

    BasicCombat();
    NavalCombat();
    SiegeCombat();
    MagicalCombat();
}
