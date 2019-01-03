//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("vilias");
    short("A raven-haired woman");
    description("A woman dressed in a flowing midnight blue robe. She is a "
        "tall, raven-haired, gray-eyed woman of surpassing beauty.");
    addAlias("woman");
    addAlias("raven-haired woman");

    Gender(2);
    Race("deity");
    SetUpPersonaOfLevel("oneiromancer", 80);
    addTrait("lib/modules/traits/archetypes/intj.c");
    addTrait("lib/modules/traits/educational/tactician.c");
    addTrait("lib/modules/traits/educational/architect.c");
    addTrait("lib/modules/traits/educational/articulate.c");
    addTrait("lib/modules/traits/educational/arcane.c");
    addTrait("lib/modules/traits/educational/educated.c");
    addTrait("lib/modules/traits/educational/mastermind.c");
    addTrait("lib/modules/traits/eyes/gray.c");
    addTrait("lib/modules/traits/genetic/attractive.c");
    addTrait("lib/modules/traits/genetic/genius.c");
    addTrait("lib/modules/traits/hair/raven.c");
    addTrait("lib/modules/traits/personality/cold.c");
    addTrait("lib/modules/traits/personality/cynical.c");
    addTrait("lib/modules/traits/personality/feared.c");
    addTrait("lib/modules/traits/personality/manipulative.c");
    addTrait("lib/modules/traits/personality/passionate.c");
    addTrait("lib/modules/traits/personality/sardonic.c");
    addTrait("lib/modules/traits/personality/stubborn.c");

    addConversation("/lib/tutorial/temple/characters/vilias/startingConversation.c");
}

/////////////////////////////////////////////////////////////////////////////
public void revealName()
{
    short("Vilias");
}
