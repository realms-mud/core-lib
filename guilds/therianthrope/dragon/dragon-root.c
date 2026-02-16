//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dragon Form");
    addSpecification("source", "therianthrope");
    addSpecification("description", "This research provides the knowledge to "
        "transform yourself into a magnificent silver dragon. While in this "
        "form, you gain devastating claws and icy breath but sacrifice the "
        "use of weapons.");

    addSpecification("research type", "tree root");
    addSpecification("scope", "self");

    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 75);

    addSpecification("bonus strength", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus soak", 2);
    addSpecification("bonus damage", 1);
    addSpecification("penalty to dexterity", 2);
    addSpecification("penalty to charisma", 2);
    addSpecification("remove weapon attacks", 1);
    addSpecification("bonus claw attack", 15);
    addSpecification("bonus fangs attack", 15);
    addSpecification("bonus cold attack", 15);

    addSpecification("trait",
        "/guilds/therianthrope/dragon/dragon-form-active.c");

    addSpecification("command template", "dragon form");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::roar## as ##InitiatorPossessive## body swells to "
        "enormous proportions! Gleaming silver scales erupt across "
        "##InitiatorPossessive## form as vast wings unfurl and a "
        "serpentine tail lashes the ground.");
    addSpecification("use ability deactivate message", "The draconic power "
        "recedes as ##InitiatorName## ##Infinitive::shrink## back into "
        "##InitiatorPossessive## humanoid form.");
}