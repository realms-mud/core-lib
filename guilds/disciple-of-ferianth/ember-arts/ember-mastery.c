//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ember Mastery");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "enhanced knowledge of ember arts, improving all utility abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 5
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/flame-sight.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Blazing Speed": 10,
        "Fire Shield": 10,
        "Flame Blessing": 10,
        "Burning Resolve": 10,
        "Heat Aura": 10
    ]));
    addSpecification("affected research type", "percentage");
}
