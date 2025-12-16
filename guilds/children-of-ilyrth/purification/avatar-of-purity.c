//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Purity");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of becoming an avatar of purity. The caster channels "
        "Ilyrths primordial essence, becoming temporarily immune to all "
        "forms of corruption and affliction.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 63 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/psionic-immunity.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);

    addSpecification("bonus resist poison", 100);
    addSpecification("bonus resist disease", 100);
    addSpecification("bonus resist paralysis", 100);
    addSpecification("bonus resist psionic", 50);

    addSpecification("duration", 180);

    addSpecification("cooldown", 300);
    addSpecification("event handler", "avatarOfPurityEvent");
    addSpecification("command template", "avatar of purity");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::become## suffused with Ilyrths primordial essence, "
        "##InitiatorPossessive## form shimmering with pure, crystalline light.");
}
