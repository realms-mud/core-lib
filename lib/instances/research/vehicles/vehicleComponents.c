//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void BasicComponents()
{
    // Basic frames and hulls
    addResearchElement("/lib/instances/research/vehicles/components/basic-wagon-frame.c");
    addChild("/lib/instances/research/vehicles/components/basic-wagon-frame.c",
        "/lib/instances/research/vehicles/craftComponents.c");

    addResearchElement("/lib/instances/research/vehicles/components/basic-hull-construction.c");
    addChild("/lib/instances/research/vehicles/components/basic-hull-construction.c",
        "/lib/instances/research/vehicles/craftComponents.c");

    // Basic sailmaking
    addResearchElement("/lib/instances/research/vehicles/components/basic-sailmaking.c");
    addChild("/lib/instances/research/vehicles/components/basic-sailmaking.c",
        "/lib/instances/research/vehicles/craftComponents.c");
}

/////////////////////////////////////////////////////////////////////////////
public void AdvancedFrames()
{
    addResearchElement("/lib/instances/research/vehicles/components/reinforced-wagon-frame.c");
    addChild("/lib/instances/research/vehicles/components/reinforced-wagon-frame.c",
        "/lib/instances/research/vehicles/components/basic-wagon-frame.c");

    addResearchElement("/lib/instances/research/vehicles/components/armored-wagon-body.c");
    addChild("/lib/instances/research/vehicles/components/armored-wagon-body.c",
        "/lib/instances/research/vehicles/components/reinforced-wagon-frame.c");

    addResearchElement("/lib/instances/research/vehicles/components/war-wagon-chassis.c");
    addChild("/lib/instances/research/vehicles/components/war-wagon-chassis.c",
        "/lib/instances/research/vehicles/components/armored-wagon-body.c");

    addResearchElement("/lib/instances/research/vehicles/components/luxury-wagon-body.c");
    addChild("/lib/instances/research/vehicles/components/luxury-wagon-body.c",
        "/lib/instances/research/vehicles/components/basic-wagon-frame.c");
}

/////////////////////////////////////////////////////////////////////////////
public void AdvancedHulls()
{
    addResearchElement("/lib/instances/research/vehicles/components/reinforced-hull-construction.c");
    addChild("/lib/instances/research/vehicles/components/reinforced-hull-construction.c",
        "/lib/instances/research/vehicles/components/basic-hull-construction.c");

    addResearchElement("/lib/instances/research/vehicles/components/ironclad-hull-construction.c");
    addChild("/lib/instances/research/vehicles/components/ironclad-hull-construction.c",
        "/lib/instances/research/vehicles/components/reinforced-hull-construction.c");

    addResearchElement("/lib/instances/research/vehicles/components/shallow-draft-hull.c");
    addChild("/lib/instances/research/vehicles/components/shallow-draft-hull.c",
        "/lib/instances/research/vehicles/components/basic-hull-construction.c");
}

/////////////////////////////////////////////////////////////////////////////
public void AdvancedSails()
{
    addResearchElement("/lib/instances/research/vehicles/components/lateen-sailmaking.c");
    addChild("/lib/instances/research/vehicles/components/lateen-sailmaking.c",
        "/lib/instances/research/vehicles/components/basic-sailmaking.c");

    addResearchElement("/lib/instances/research/vehicles/components/square-sailmaking.c");
    addChild("/lib/instances/research/vehicles/components/square-sailmaking.c",
        "/lib/instances/research/vehicles/components/lateen-sailmaking.c");
}

/////////////////////////////////////////////////////////////////////////////
public void WeaponSystems()
{
    // Basic weapon systems
    addResearchElement("/lib/instances/research/vehicles/components/harpoon-launcher.c");
    addChild("/lib/instances/research/vehicles/components/harpoon-launcher.c",
        "/lib/instances/research/vehicles/components/basic-wagon-frame.c");

    // Historical siege weapons - building from basic frame
    addResearchElement("/lib/instances/research/vehicles/components/springald-mount.c");
    addChild("/lib/instances/research/vehicles/components/springald-mount.c",
        "/lib/instances/research/vehicles/components/basic-wagon-frame.c");

    addResearchElement("/lib/instances/research/vehicles/components/onager-mount.c"); 
    addChild("/lib/instances/research/vehicles/components/onager-mount.c",
        "/lib/instances/research/vehicles/components/springald-mount.c");

    // Chemical/alchemical weapons
    addResearchElement("/lib/instances/research/vehicles/components/oil-dispenser.c");
    addChild("/lib/instances/research/vehicles/components/oil-dispenser.c",
        "/lib/instances/research/vehicles/components/basic-wagon-frame.c");

    addResearchElement("/lib/instances/research/vehicles/components/greek-fire-projector.c");
    addChild("/lib/instances/research/vehicles/components/greek-fire-projector.c",
        "/lib/instances/research/vehicles/components/oil-dispenser.c");

    // Advanced physical weapons - requiring armored construction
    addResearchElement("/lib/instances/research/vehicles/components/siege-ram.c");
    addChild("/lib/instances/research/vehicles/components/siege-ram.c",
        "/lib/instances/research/vehicles/components/armored-wagon-body.c");

    addResearchElement("/lib/instances/research/vehicles/components/corvus-boarding-bridge.c");
    addChild("/lib/instances/research/vehicles/components/corvus-boarding-bridge.c",
        "/lib/instances/research/vehicles/components/armored-wagon-body.c");

    // Tactical weapons - building from basic systems
    addResearchElement("/lib/instances/research/vehicles/components/net-launcher.c");
    addChild("/lib/instances/research/vehicles/components/net-launcher.c",
        "/lib/instances/research/vehicles/components/harpoon-launcher.c");

    addResearchElement("/lib/instances/research/vehicles/components/caltrop-dispenser.c");
    addChild("/lib/instances/research/vehicles/components/caltrop-dispenser.c",
        "/lib/instances/research/vehicles/components/basic-wagon-frame.c");

    // Basic arcane weapons - requiring arcane frame
    addResearchElement("/lib/instances/research/vehicles/components/magic-missile-launcher.c");
    addChild("/lib/instances/research/vehicles/components/magic-missile-launcher.c",
        "/lib/instances/research/vehicles/components/arcane-wagon-frame.c");

    addResearchElement("/lib/instances/research/vehicles/components/frost-projector.c");
    addChild("/lib/instances/research/vehicles/components/frost-projector.c",
        "/lib/instances/research/vehicles/components/arcane-wagon-frame.c");

    addResearchElement("/lib/instances/research/vehicles/components/acid-sprayer.c");
    addChild("/lib/instances/research/vehicles/components/acid-sprayer.c",
        "/lib/instances/research/vehicles/components/arcane-wagon-frame.c");

    // Advanced arcane weapons - building from basic arcane
    addResearchElement("/lib/instances/research/vehicles/components/arcane-cannon.c");
    addChild("/lib/instances/research/vehicles/components/arcane-cannon.c",
        "/lib/instances/research/vehicles/components/magic-missile-launcher.c");

    addResearchElement("/lib/instances/research/vehicles/components/lightning-cannon.c");
    addChild("/lib/instances/research/vehicles/components/lightning-cannon.c",
        "/lib/instances/research/vehicles/components/arcane-cannon.c");

    addResearchElement("/lib/instances/research/vehicles/components/sonic-disruptor.c");
    addChild("/lib/instances/research/vehicles/components/sonic-disruptor.c",
        "/lib/instances/research/vehicles/components/arcane-cannon.c");

    // High-level arcane weapons
    addResearchElement("/lib/instances/research/vehicles/components/arcane-flame-thrower.c");
    addChild("/lib/instances/research/vehicles/components/arcane-flame-thrower.c",
        "/lib/instances/research/vehicles/components/arcane-cannon.c");

    addResearchElement("/lib/instances/research/vehicles/components/confusion-projector.c");
    addChild("/lib/instances/research/vehicles/components/confusion-projector.c",
        "/lib/instances/research/vehicles/components/sonic-disruptor.c");

    addResearchElement("/lib/instances/research/vehicles/components/soul-reaper.c");
    addChild("/lib/instances/research/vehicles/components/soul-reaper.c",
        "/lib/instances/research/vehicles/components/lightning-cannon.c");

    addResearchElement("/lib/instances/research/vehicles/components/mind-spike-launcher.c");
    addChild("/lib/instances/research/vehicles/components/mind-spike-launcher.c",
        "/lib/instances/research/vehicles/components/confusion-projector.c");
}

/////////////////////////////////////////////////////////////////////////////
public void MagicalComponents()
{
    addResearchElement("/lib/instances/research/vehicles/components/arcane-wagon-frame.c");
    addChild("/lib/instances/research/vehicles/components/arcane-wagon-frame.c",
        "/lib/instances/research/vehicles/components/reinforced-wagon-frame.c");

    addResearchElement("/lib/instances/research/vehicles/components/arcane-hull-construction.c");
    addChild("/lib/instances/research/vehicles/components/arcane-hull-construction.c",
        "/lib/instances/research/vehicles/components/reinforced-hull-construction.c");

    addResearchElement("/lib/instances/research/vehicles/components/arcane-sailmaking.c");
    addChild("/lib/instances/research/vehicles/components/arcane-sailmaking.c",
        "/lib/instances/research/vehicles/components/square-sailmaking.c");

    addResearchElement("/lib/instances/research/vehicles/components/arcane-propulsion.c");
    addChild("/lib/instances/research/vehicles/components/arcane-propulsion.c",
        "/lib/instances/research/vehicles/components/arcane-hull-construction.c");

    addResearchElement("/lib/instances/research/vehicles/components/arcane-warding.c");
    addChild("/lib/instances/research/vehicles/components/arcane-warding.c",
        "/lib/instances/research/vehicles/components/arcane-wagon-frame.c");

    addResearchElement("/lib/instances/research/vehicles/components/arcane-cargo.c");
    addChild("/lib/instances/research/vehicles/components/arcane-cargo.c",
        "/lib/instances/research/vehicles/components/arcane-warding.c");

    addResearchElement("/lib/instances/research/vehicles/components/arcane-sanctum.c");
    addChild("/lib/instances/research/vehicles/components/arcane-sanctum.c",
        "/lib/instances/research/vehicles/components/arcane-cargo.c");
}

/////////////////////////////////////////////////////////////////////////////
public void ExoticComponents()
{
    addResearchElement("/lib/instances/research/vehicles/components/levitation-matrix.c");
    addChild("/lib/instances/research/vehicles/components/levitation-matrix.c",
        "/lib/instances/research/vehicles/components/arcane-propulsion.c");

    addResearchElement("/lib/instances/research/vehicles/components/illusion-shroud.c");
    addChild("/lib/instances/research/vehicles/components/illusion-shroud.c",
        "/lib/instances/research/vehicles/components/arcane-warding.c");

    addResearchElement("/lib/instances/research/vehicles/components/teleportation-rune.c");
    addChild("/lib/instances/research/vehicles/components/teleportation-rune.c",
        "/lib/instances/research/vehicles/components/levitation-matrix.c");

    addResearchElement("/lib/instances/research/vehicles/components/elemental-binding.c");
    addChild("/lib/instances/research/vehicles/components/elemental-binding.c",
        "/lib/instances/research/vehicles/components/arcane-propulsion.c");

    addResearchElement("/lib/instances/research/vehicles/components/elemental-engine.c");
    addChild("/lib/instances/research/vehicles/components/elemental-engine.c",
        "/lib/instances/research/vehicles/components/elemental-binding.c");

    addResearchElement("/lib/instances/research/vehicles/components/planar-rudder.c");
    addChild("/lib/instances/research/vehicles/components/planar-rudder.c",
        "/lib/instances/research/vehicles/components/teleportation-rune.c");
}

/////////////////////////////////////////////////////////////////////////////
public void UtilityComponents()
{
    addResearchElement("/lib/instances/research/vehicles/components/paddlewheel.c");
    addChild("/lib/instances/research/vehicles/components/paddlewheel.c",
        "/lib/instances/research/vehicles/components/basic-hull-construction.c");

    addResearchElement("/lib/instances/research/vehicles/components/waterwheel-mill.c");
    addChild("/lib/instances/research/vehicles/components/waterwheel-mill.c",
        "/lib/instances/research/vehicles/components/paddlewheel.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Vehicle Components");
    Description("This research tree tracks the knowledge required to craft "
        "specialized components for vehicles");
    Source("vehicles");
    addPrerequisite("carpentry", (["type":"skill", "value": 1]));
    addPrerequisite("/lib/instances/research/vehicles/craftVehicles.c",
        (["type":"research"]));
    addResearchElement("/lib/instances/research/vehicles/craftComponents.c");
    TreeRoot("/lib/instances/research/vehicles/craftComponents.c");

    BasicComponents();
    AdvancedFrames();
    AdvancedHulls();
    AdvancedSails();
    MagicalComponents();
    WeaponSystems();
    ExoticComponents();
    UtilityComponents();
}