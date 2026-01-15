//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Ember Potency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "divine knowledge of ember arts, greatly enhancing utility abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 29
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/enhanced-ember-potency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianth's Vigor": 25,
        "Soul of Fire": 25,
        "Flame Tongue": 25,
        "Blazing Barrier": 25,
        "Radiant Presence": 25
    ]));
    addSpecification("affected research type", "percentage");
}
