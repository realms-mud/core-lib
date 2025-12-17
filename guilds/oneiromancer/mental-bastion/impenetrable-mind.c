//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Impenetrable Mind");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "knowledge of making the mind truly impenetrable.");

    addPrerequisite("/guilds/oneiromancer/mental-bastion/fortified-mind.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "mentalist", "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 17
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research", ([
        "Psychic Barrier": 35
    ]));
    addSpecification("affected research type", "percentage");
}
