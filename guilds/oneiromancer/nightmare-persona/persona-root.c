//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Persona");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "ability to adopt a nightmare persona - a dark identity drawn from "
        "the realm of dreams. While active, the oneiromancer cannot make "
        "weapon attacks but gains psionic attacks and access to powerful "
        "passive abilities.");
    addSpecification("usage summary", "Activates the nightmare persona");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("spell point cost", 25);

    addSpecification("bonus mind", 1);
    addSpecification("bonus spirit", 1);
    addSpecification("bonus psionic attack", 25);

    addSpecification("trait", 
        "/lib/instances/traits/personas/oneiromancer/nightmare-persona-active.c");

    addSpecification("event handler", "nightmarePersonaEvent");
    addSpecification("command template", "nightmare persona");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::embrace## ##InitiatorPossessive## nightmare persona, "
        "##InitiatorPossessive## form flickering with shadowy menace.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::release## ##InitiatorPossessive## nightmare persona, "
        "##InitiatorPossessive## form solidifying once more.");
}
