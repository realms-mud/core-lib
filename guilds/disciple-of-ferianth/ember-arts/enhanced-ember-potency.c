//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enhanced Ember Potency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "greater knowledge of ember arts, significantly enhancing utility abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 21
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/ember-potency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Indomitable Spirit": 20,
        "Sacred Flame Aura": 20,
        "Firebrand": 20,
        "Flame Tongue": 20,
        "Blazing Barrier": 20
    ]));
    addSpecification("affected research type", "percentage");
}
