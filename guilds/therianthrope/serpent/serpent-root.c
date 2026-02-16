//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Serpent Form");
    addSpecification("source", "therianthrope");
    addSpecification("description", "This research provides the knowledge to "
        "transform yourself into a sinuous serpent. While in this form, you "
        "gain venomous fangs and crushing coils but sacrifice the use of "
        "weapons.");

    addSpecification("research type", "tree root");
    addSpecification("scope", "self");

    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 75);

    addSpecification("bonus dexterity", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus soak", 1);
    addSpecification("penalty to strength", 2);
    addSpecification("penalty to charisma", 2);
    addSpecification("remove weapon attacks", 1);
    addSpecification("bonus fangs attack", 15);
    addSpecification("bonus constriction attack", 12);

    addSpecification("trait",
        "/guilds/therianthrope/serpent/serpent-form-active.c");

    addSpecification("command template", "serpent form");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::writhe## as ##InitiatorPossessive## limbs fuse and "
        "##InitiatorPossessive## body elongates into the sinuous form of a "
        "massive serpent! Glistening scales ripple across "
        "##InitiatorPossessive## coiling frame.");
    addSpecification("use ability deactivate message", "The ophidian power "
        "recedes as ##InitiatorName## ##Infinitive::reform## back into "
        "##InitiatorPossessive## humanoid shape.");
}
