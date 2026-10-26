//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Longblade Stillness");
    addSpecification("source", "monk");
    addSpecification("description",
        "The master's odachi waits without sagging, its distant "
        "point as quiet as the hands that hold it. Beneath that "
        "still horizon, the stance has the patience of a mountain.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"odachi",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":70
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/odachi/longblade-mastery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 22);
    addSpecification("cooldown", 4);

    addSpecification("command template", "kata longblade stillness");

    addSpecification("bonus two-handed sword", 8);
    addSpecification("bonus parry", 4);
    addSpecification("penalty to dodge", 2);
}
