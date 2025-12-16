//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Absolute Purification");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of absolute purification. The caster invokes the full "
        "cleansing power of Ilyrth, removing all negative effects from "
        "the target and surrounding them with restorative waters that "
        "continue to heal and protect.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 67 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/avatar-of-purity.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);

    addSpecification("bonus heal hit points", 25);
    addSpecification("bonus heal hit points rate", 5);
    addSpecification("bonus heal spell points", 25);
    addSpecification("bonus heal spell points rate", 2);
    addSpecification("bonus resist poison", 50);
    addSpecification("bonus resist disease", 50);
    addSpecification("bonus resist paralysis", 50);

    addSpecification("duration", 120);

    addSpecification("cooldown", 180);
    addSpecification("event handler", "absolutePurificationEvent");
    addSpecification("command template", "absolute purification [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon the absolute purity of Ilyrths domain as "
        "a cascade of pristine water engulfs ##TargetName##, washing away "
        "every trace of corruption and surrounding ##TargetObjective## "
        "with restorative waters.");
}
