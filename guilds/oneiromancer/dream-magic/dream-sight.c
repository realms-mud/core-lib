//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Sight");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of perceiving the world through dream-touched senses, "
        "granting enhanced awareness and perception.");

    addPrerequisite("/guilds/oneiromancer/dream-magic/phantasmal-bolt.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("bonus senses", 3);
    addSpecification("bonus perception", 3);
    addSpecification("bonus mind", 2);
}
