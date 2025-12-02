//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void BasicVehicleConstruction()
{
    // Basic wagon construction
    addResearchElement("/lib/instances/research/vehicles/wagons/basic-wagon-construction.c");
    addChild("/lib/instances/research/vehicles/wagons/basic-wagon-construction.c",
        "/lib/instances/research/vehicles/craftVehicles.c");

    // Basic boat construction
    addResearchElement("/lib/instances/research/vehicles/boats/basic-boatbuilding.c");
    addChild("/lib/instances/research/vehicles/boats/basic-boatbuilding.c",
        "/lib/instances/research/vehicles/craftVehicles.c");
}

/////////////////////////////////////////////////////////////////////////////
public void AdvancedLandVehicles()
{
    addResearchElement("/lib/instances/research/vehicles/wagons/covered-wagons.c");
    addChild("/lib/instances/research/vehicles/wagons/covered-wagons.c",
        "/lib/instances/research/vehicles/wagons/basic-wagon-construction.c");

    addResearchElement("/lib/instances/research/vehicles/wagons/stagecoaches.c");
    addChild("/lib/instances/research/vehicles/wagons/stagecoaches.c",
        "/lib/instances/research/vehicles/wagons/covered-wagons.c");

    addResearchElement("/lib/instances/research/vehicles/wagons/war-wagons.c");
    addChild("/lib/instances/research/vehicles/wagons/war-wagons.c",
        "/lib/instances/research/vehicles/wagons/covered-wagons.c");

    addResearchElement("/lib/instances/research/vehicles/wagons/siege-wagons.c");
    addChild("/lib/instances/research/vehicles/wagons/siege-wagons.c",
        "/lib/instances/research/vehicles/wagons/war-wagons.c");
}

/////////////////////////////////////////////////////////////////////////////
public void RiverVessels()
{
    addResearchElement("/lib/instances/research/vehicles/boats/river-vessels.c");
    addChild("/lib/instances/research/vehicles/boats/river-vessels.c",
        "/lib/instances/research/vehicles/boats/basic-boatbuilding.c");

    addResearchElement("/lib/instances/research/vehicles/ships/multi-hull-vessel.c");
    addChild("/lib/instances/research/vehicles/ships/multi-hull-vessel.c",
        "/lib/instances/research/vehicles/boats/river-vessels.c");
}

/////////////////////////////////////////////////////////////////////////////
public void SeaVessels()
{
    addResearchElement("/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c");
    addChild("/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c",
        "/lib/instances/research/vehicles/boats/river-vessels.c");

    addResearchElement("/lib/instances/research/vehicles/ships/longships.c");
    addChild("/lib/instances/research/vehicles/ships/longships.c",
        "/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c");

    addResearchElement("/lib/instances/research/vehicles/ships/lateen-rigged-vessels.c");
    addChild("/lib/instances/research/vehicles/ships/lateen-rigged-vessels.c",
        "/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c");

    addResearchElement("/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c");
    addChild("/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c",
        "/lib/instances/research/vehicles/ships/lateen-rigged-vessels.c");

    addResearchElement("/lib/instances/research/vehicles/ships/oared-warships.c");
    addChild("/lib/instances/research/vehicles/ships/oared-warships.c",
        "/lib/instances/research/vehicles/ships/longships.c");

    addResearchElement("/lib/instances/research/vehicles/ships/dreadnoughts.c");
    addChild("/lib/instances/research/vehicles/ships/dreadnoughts.c",
        "/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c");
}

/////////////////////////////////////////////////////////////////////////////
public void MagicalVessels()
{
    addResearchElement("/lib/instances/research/vehicles/boats/arcane-vessels.c");
    addChild("/lib/instances/research/vehicles/boats/arcane-vessels.c",
        "/lib/instances/research/vehicles/boats/basic-boatbuilding.c");

    addResearchElement("/lib/instances/research/vehicles/boats/crystal-vessels.c");
    addChild("/lib/instances/research/vehicles/boats/crystal-vessels.c",
        "/lib/instances/research/vehicles/boats/arcane-vessels.c");

    addResearchElement("/lib/instances/research/vehicles/boats/arcane-glider.c");
    addChild("/lib/instances/research/vehicles/boats/arcane-glider.c",
        "/lib/instances/research/vehicles/boats/crystal-vessels.c");

    addResearchElement("/lib/instances/research/vehicles/ships/mystical-man-of-war.c");
    addChild("/lib/instances/research/vehicles/ships/mystical-man-of-war.c",
        "/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c");

    addResearchElement("/lib/instances/research/vehicles/ships/arcane-dreadnoughts.c");
    addChild("/lib/instances/research/vehicles/ships/arcane-dreadnoughts.c",
        "/lib/instances/research/vehicles/ships/mystical-man-of-war.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Vehicle Construction");
    Description("This research tree tracks the knowledge required to construct "
        "vehicles for land and sea travel");
    Source("vehicles");
    addPrerequisite("carpentry", 
        (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/crafting/craftItems.c",
        (["type":"research"]));
    addResearchElement("/lib/instances/research/vehicles/craftVehicles.c");
    TreeRoot("/lib/instances/research/vehicles/craftVehicles.c");

    BasicVehicleConstruction();
    AdvancedLandVehicles();
    RiverVessels();
    SeaVessels();
    MagicalVessels();
}