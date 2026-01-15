//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Supreme Ember Potency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "supreme knowledge of ember arts, maximizing utility abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 45
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/master-ember-potency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Avatar of Ferianth": 35,
        "Divine Empowerment": 35,
        "Mantle of Flames": 35
    ]));
    addSpecification("affected research type", "percentage");
}
