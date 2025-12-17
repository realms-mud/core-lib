//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Mastery");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "true mastery over dream energies.");

    addPrerequisite("/guilds/oneiromancer/dream-dominion/reality-warp.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 2);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus resist psionic", 10);
}
