//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mental Armor");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "improved resistance to magical effects.");

    addPrerequisite("/guilds/oneiromancer/mental-bastion/iron-will.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "mentalist", "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 5
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus soak", 1);
}
