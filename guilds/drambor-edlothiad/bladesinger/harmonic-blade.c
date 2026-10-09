//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Harmonic Blade");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the bladesinger "
        "to weave the fundamental harmonics of bladesong directly into their "
        "blade, enhancing its effectiveness as a weapon and magical conduit.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/perfect-bladesong.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 39
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 10);
    addSpecification("bonus attack", 8);
}
