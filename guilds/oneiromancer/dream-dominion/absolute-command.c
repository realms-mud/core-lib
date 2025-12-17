//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Absolute Command");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "absolute command over psionic energies.");

    addPrerequisite("/guilds/oneiromancer/dream-dominion/sovereign-will.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 5
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 3);
    addSpecification("bonus attack", 3);

    addSpecification("affected research", ([
        "Mind Crush": 20
    ]));
    addSpecification("affected research type", "percentage");
}
