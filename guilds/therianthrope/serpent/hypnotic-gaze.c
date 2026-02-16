//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hypnotic Gaze");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in serpent form, you can fix your "
        "prey with a mesmerizing stare, weakening their will and defenses. "
        "This enhances your accuracy but reduces your own defenses as you "
        "focus intently on your target.");

    addPrerequisite("/guilds/therianthrope/serpent/viper-reflexes.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 21
        ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("spell point cost", 25);

    addSpecification("bonus attack", 6);
    addSpecification("bonus damage", 4);
    addSpecification("penalty to dodge", 2);
    addSpecification("penalty to defense", 1);

    addSpecification("trait",
        "/guilds/therianthrope/serpent/hypnotic-gaze-active.c");

    addSpecification("command template", "hypnotic gaze");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::fix## ##InitiatorPossessive## prey with an "
        "unblinking, mesmerizing stare, weaving ##InitiatorPossessive## "
        "head in a slow hypnotic pattern!");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::break## ##InitiatorPossessive## hypnotic gaze, "
        "releasing the mesmerizing hold.");
}
