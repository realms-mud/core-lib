//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancient Fortitude");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the ancient fortitude that "
        "sustained the first elven kingdoms through "
        "ages of war. By communing with ancestral "
        "memory, the battlemage taps into a deep "
        "reservoir of endurance that transcends "
        "mortal limitations.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "starlit-blood.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 35
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus stamina points", 30);
    addSpecification("bonus hit points", 30);
}
