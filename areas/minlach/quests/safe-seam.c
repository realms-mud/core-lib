//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Safe Seam");
    setDescription("Quarry foreman Harl asks for a careful survey of the "
        "spring, a small copper seam, and the old adit's supports.");
    addState("started", "Harl asked me to inspect Copper Hollow's spring.");
    addState("water measured", "The spring runs clear and at a steady level; "
        "it is separate from the flooded lower gallery.");
    addState("seam checked", "The copper seam is thin and the surrounding "
        "rock is mostly barren.");
    addState("supports checked", "The roof remains standing, but shifted "
        "props make the old gallery unsafe.");
    addState("ready", "The chapel register records shared upkeep and the "
        "closure of the adit after a roof fall.");
    addTransition("started", "water measured", "inspectSpringWater");
    addTransition("water measured", "seam checked", "inspectCopperSeam");
    addTransition("seam checked", "supports checked", "inspectRoofSupports");
    addTransition("supports checked", "ready", "readChapelRegister");
    addResolution("keep seam closed", "Harl kept the lower adit closed and "
        "posted a warning against descent. The surveyed surface seam can be "
        "worked with a pick from the stable passage.",
        "keepSeamClosed");
    addResolution("limited survey", "Harl authorized small-scale, supervised "
        "extraction from the exposed seam, with no entry into the lower "
        "gallery.",
        "allowLimitedSurvey");
    setInitialState("started");
}
