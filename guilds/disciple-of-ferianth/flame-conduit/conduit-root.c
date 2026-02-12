//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flame Conduit Form");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the knowledge to "
        "transform yourself into a living conduit of Ferianth's sacred fire. "
        "While in this form, your body becomes wreathed in divine flames, "
        "granting enhanced fire abilities but making you vulnerable to water.");

    addSpecification("research type", "tree root");
    addSpecification("scope", "self");

    addSpecification("hit point cost", 50);
    addSpecification("spell point cost", 100);
    addSpecification("stamina point cost", 100);

    addSpecification("bonus fire attack", 40);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus elemental fire", 2);
    addSpecification("penalty to resist water", 5);
    addSpecification("penalty to resist cold", 3);

    addSpecification("trait",
        "/guilds/disciple-of-ferianth/flame-conduit/flame-conduit-active.c");

    addSpecification("command template", "flame conduit [form]");
    addSpecification("use ability activate message", "Sacred fire erupts from "
        "within ##InitiatorName## as ##InitiatorSubjective## ##Infinitive::transform## "
        "into a living conduit of Ferianth's divine flame!");
    addSpecification("use ability deactivate message", "The sacred flames "
        "surrounding ##InitiatorName## fade as ##InitiatorSubjective## "
        "##Infinitive::return## to ##InitiatorPossessive## mortal form.");
}
