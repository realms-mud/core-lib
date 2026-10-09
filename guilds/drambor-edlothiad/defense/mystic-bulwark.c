//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Bulwark");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the knowledge of the mystic "
        "bulwark technique. The battlemage learns to "
        "project a towering wall of solidified arcane "
        "energy that absorbs tremendous punishment, "
        "allowing the warrior to stand firm against "
        "even the most devastating of assaults.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "mystic-aegis.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 45
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 6);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus resist physical", 5);
}
