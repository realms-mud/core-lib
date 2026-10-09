//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bladesong of Creation");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the bladesinger "
        "an ancient and powerful bladesong whose harmonics resonate with the "
        "creative forces of existence, mending wounds and restoring allies.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/advanced-bladesong.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 39
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points", 8);
    addSpecification("bonus heal hit points rate", 12);
}
