//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Master Ember Potency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "masterful knowledge of ember arts, vastly enhancing utility abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 37
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/divine-ember-potency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianth's Blessing": 30,
        "Mantle of Flames": 30,
        "Radiant Presence": 30,
        "Soul of Fire": 30
    ]));
    addSpecification("affected research type", "percentage");
}
