//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ember Potency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "improved knowledge of ember arts, further enhancing utility abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 13
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/ember-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Fury of Flames": 15,
        "Smoldering Presence": 15,
        "Fiery Determination": 15,
        "Ember Weapon": 15,
        "Sacred Flame Aura": 15,
        "Firebrand": 15
    ]));
    addSpecification("affected research type", "percentage");
}
