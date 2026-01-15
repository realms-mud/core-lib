//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Kindle Spirit");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of kindling the inner fire of their spirit, enhancing "
        "mental acuity and magical prowess.");
    addSpecification("usage summary", "Sustained buff to intelligence and spellcraft");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/flame-sight.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);

    addSpecification("bonus intelligence", 1);
    addSpecification("bonus spellcraft", 3);

    addSpecification("cooldown", 10);
    addSpecification("command template", "kindle spirit");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::kindle## ##InitiatorPossessive## inner spirit, and "
        "a faint warmth radiates from within.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "kindled spirit settles to embers.");
}
