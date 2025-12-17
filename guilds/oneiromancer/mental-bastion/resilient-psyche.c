//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Resilient Psyche");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "a more resilient psyche, improving recovery.");

    addPrerequisite("/guilds/oneiromancer/mental-bastion/mental-armor.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "mentalist", "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus heal hit points", 1);
    addSpecification("bonus heal spell points", 1);
}
