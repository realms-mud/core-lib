//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elder Blood");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the awakening of elder blood, "
        "the most potent strain of elven heritage. "
        "This ancient vitality predates recorded "
        "history and carries within it echoes of "
        "power from when elves were young and the "
        "world was still being shaped.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "dance-of-shadows.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 41
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus strength", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus spell points", 25);
}
