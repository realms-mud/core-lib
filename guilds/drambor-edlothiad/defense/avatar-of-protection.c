//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Protection");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the ultimate defensive mastery of "
        "the Drambor Edlothiad. The battlemage "
        "becomes a living fortress, surrounded at "
        "all times by interlocking fields of arcane "
        "protection so potent that even the mightiest "
        "blows barely register upon the senses.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "ward-of-the-ancients.c",
        (["type": "research"]));
    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "mystic-bulwark.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 67
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 8);
    addSpecification("bonus resist physical", 10);
    addSpecification("bonus resist magical", 10);
    addSpecification("bonus hit points", 75);
}
