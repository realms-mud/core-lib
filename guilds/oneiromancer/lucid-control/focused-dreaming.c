//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Focused Dreaming");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "enhanced focus while channeling dream energy.");

    addPrerequisite("/guilds/oneiromancer/lucid-control/clarity-of-purpose.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "adept", "mentalist", "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 1);
    addSpecification("bonus spellcraft", 2);

    addSpecification("affected research", ([
        "Lucid Burst": 15
    ]));
    addSpecification("affected research type", "percentage");
}
