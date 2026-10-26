//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sickle Endurance");
    addSpecification("source", "monk");
    addSpecification("description",
        "In the long watch, the sickle scarcely moves. You have "
        "learned to rest behind its curve, easing the breath and "
        "forearm without surrendering the line you keep for the foe.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":56
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/kama/hook-recovery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("bonus heal stamina rate", 4);
}
