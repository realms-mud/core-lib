//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Still Edge");
    addSpecification("source", "monk");
    addSpecification("description",
        "Hold the edge as though its reflection rested on undisturbed "
        "water. Beneath the apparent stillness, every part of the "
        "swordsman remains awake.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":62
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/katana/unwavering-eye.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 4);

    addSpecification("command template", "kata still edge");

    addSpecification("bonus hand and a half sword", 4);
    addSpecification("bonus parry", 2);

    addSpecification("per hit landed cost", ([
        "spell points":1
    ]));
}
