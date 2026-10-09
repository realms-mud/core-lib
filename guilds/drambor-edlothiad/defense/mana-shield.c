//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Shield");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the mana shield technique. The "
        "battlemage learns to reflexively convert "
        "incoming damage into spell point drain, "
        "absorbing physical and magical punishment "
        "alike by sacrificing magical reserves "
        "rather than suffering bodily harm.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "mystic-resilience.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus resist magical", 3);
}
