//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flowing Stance");
    addSpecification("source", "monk");
    addSpecification("description",
        "A parry becomes a turn, the turn a step, the step a waiting hand. "
        "Maintaining this seamless current demands attention even while "
        "each movement appears to happen of its own accord.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":54
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/supple-form.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/heel-trajectory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 4);

    addSpecification("command template", "kata flowing stance");

    addSpecification("bonus unarmed", 10);
    addSpecification("bonus dodge", 5);

    addSpecification("per hit landed cost", ([
        "spell points":1
    ]));
}
