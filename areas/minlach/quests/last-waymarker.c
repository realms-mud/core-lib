//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("Beyond the Last Waymarker");
    setDescription("Roven's expected delivery has not arrived. A carter "
        "and apprentice may be stranded on the old mill road.");
    addState("started", "Roven asked me to search the old road for a cart.");
    addState("cart found", "A wheel has broken beside the old waymarker. "
        "The harness was unbuckled rather than cut.");
    addState("trail followed", "Two sets of walking tracks lead toward "
        "the mill. Someone used a cart slat as a crutch.");
    addState("ready", "A note in the mill shelter names the carter and "
        "apprentice. They reached the farm safely but need transport.");
    addTransition("started", "cart found", "inspectBrokenCart");
    addTransition("cart found", "trail followed", "followCarterTracks");
    addTransition("trail followed", "ready", "readMillShelterNote");
    addResolution("farm wagon", "Roven arranged a farm wagon to bring "
        "the injured carter and apprentice home.", "arrangeCarterWagon");
    addResolution("watch assistance", "I gave Roven the precise location "
        "for a watch-assisted recovery, leaving the cargo until later.",
        "requestCarterWatch");
    setInitialState("started");
}
