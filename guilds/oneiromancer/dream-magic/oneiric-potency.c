//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oneiric Potency");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "knowledge that further enhances the oneiromancer's dream magic "
        "offensive abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 13
        ]));

    addPrerequisite("/guilds/oneiromancer/dream-magic/dream-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Dream Touch": 25,
        "Phantasmal Bolt": 25,
        "Nightmare Bolt": 25,
        "Oneiric Blast": 25,
        "Dream Rend": 25
    ]));
    addSpecification("affected research type", "percentage");
}
