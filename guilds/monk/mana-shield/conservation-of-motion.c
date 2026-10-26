//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Conservation of Motion");
    addSpecification("source", "monk");
    addSpecification("description",
        "A master's gesture ends where intention begins. You learn to let "
        "the shield carry that intention outward, leaving no wasted "
        "movement between a merciful touch and a stern rebuke.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":52
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/economical-refuge.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/mindful-casting.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Sheltering Touch":2,
        "Stillpoint Rebuke":2
    ]));
}
