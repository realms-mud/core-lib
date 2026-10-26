//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Defensive Timing");
    addSpecification("source", "monk");
    addSpecification("description",
        "The instant after a blow is not empty. By listening to the "
        "shield's fading tremor, you find the moment to breathe and "
        "prepare before the next disturbance arrives.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":12
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "student",
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/recovery-cycle.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Breath Conversion":4,
        "Brace the Spirit":6
    ]));
}
