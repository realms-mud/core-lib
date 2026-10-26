//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Brace the Spirit");
    addSpecification("source", "monk");
    addSpecification("description",
        "Set your heel and let the shield settle against your stance. For "
        "a breath, body and spirit stand together like a mountain enduring "
        "the first thunder of a storm.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":22
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
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
    addPrerequisite("/guilds/monk/mana-shield/refuge-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 40);

    addSpecification("duration", 12);

    addSpecification("bonus defense", 8);
    addSpecification("bonus soak", 4);

    addSpecification("command template", "chi brace the spirit");
    addSpecification("use ability message",
        "##InitiatorName## brace##InitiatorReflexive## beneath the ward.");

    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/mana-shield/economical-refuge.c":1
    ]));

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/defensive-timing.c":6
    ]));
}
