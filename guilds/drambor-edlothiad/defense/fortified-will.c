//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fortified Will");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with a fortified will against magical "
        "assault. Through rigorous mental discipline "
        "and elven meditative techniques, the "
        "battlemage hardens the mind against "
        "enchantments, illusions, and psychic "
        "intrusions that would shatter a lesser "
        "warrior's concentration.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "mystic-resilience.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus wisdom", 1);
}
