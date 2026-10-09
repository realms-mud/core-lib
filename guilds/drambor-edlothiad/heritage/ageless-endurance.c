//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ageless Endurance");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research grants the ageless "
        "endurance of immortal beings.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/spirit-of-the-wood.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 31
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus stamina points", 50);
    addSpecification("bonus constitution", 2);
}
