//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Woodland Boundary");
    setDescription("Forester Maelin wants an old boundary checked "
        "before a tenant is fined for gathering on the common.");
    addState("started", "Maelin asked me to inspect the boundary stone.");
    addState("boundary checked", "The stone distinguishes the common "
        "hedge from privately managed timber.");
    addState("stumps checked", "The fresh cuts are in the managed "
        "plot, while berry gathering occurred outside it.");
    addState("ready", "The tenant's recorded winter-fuel permit "
        "allows fallen branches but not standing timber.");
    addTransition("started", "boundary checked", "inspectBoundaryStone");
    addTransition("boundary checked", "stumps checked", "inspectTimberCuts");
    addTransition("stumps checked", "ready", "readTenantFuelPermit");
    addResolution("mediated repair", "Maelin arranged compensation "
        "for the timber and preserved lawful common forage.",
        "mediateWoodlandCosts");
    addResolution("formal boundary", "Maelin recorded the timber "
        "violation separately from the permitted berry gathering.",
        "recordWoodlandBoundary");
    setInitialState("started");
}
