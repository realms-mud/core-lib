//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elastic Defense");
    addSpecification("source", "monk");
    addSpecification("description",
        "The shield bends, and you bend with it. Long practice teaches "
        "your body to return as naturally as a willow branch, never "
        "remaining where an enemy expects to find you.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":54
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
    addPrerequisite("/guilds/monk/mana-shield/stable-footing.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("bonus defense class", 12);
}
