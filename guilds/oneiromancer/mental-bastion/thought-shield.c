//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thought Shield");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "a passive mental shield against psionic intrusion.");

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
    addSpecification("bonus resist psionic", 5);
    addSpecification("bonus defense", 2);

    addSpecification("affected research", ([
        "Psychic Barrier": 15
    ]));
    addSpecification("affected research type", "percentage");
}
