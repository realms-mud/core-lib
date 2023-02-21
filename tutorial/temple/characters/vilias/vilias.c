//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("vilias");
    short("A raven-haired woman");
    description("A woman dressed in a flowing midnight blue dress. She is a "
        "tall, raven-haired, gray-eyed woman of surpassing beauty.");
    addAlias("woman");
    addAlias("raven-haired woman");

    Gender("female");
    Race("deity");
    SetUpPersonaOfLevel("oneiromancer", 80);
    addTrait("/lib/instances/traits/archetypes/iitj.c");
    addTrait("/lib/instances/traits/educational/tactician.c");
    addTrait("/lib/instances/traits/educational/architect.c");
    addTrait("/lib/instances/traits/educational/articulate.c");
    addTrait("/lib/instances/traits/educational/arcane.c");
    addTrait("/lib/instances/traits/educational/educated.c");
    addTrait("/lib/instances/traits/educational/mastermind.c");
    addTrait("/lib/instances/traits/eyes/gray.c");
    addTrait("/lib/instances/traits/genetic/attractive.c");
    addTrait("/lib/instances/traits/genetic/genius.c");
    addTrait("/lib/instances/traits/hair/raven.c");
    addTrait("/lib/instances/traits/personality/cold.c");
    addTrait("/lib/instances/traits/personality/cynical.c");
    addTrait("/lib/instances/traits/personality/feared.c");
    addTrait("/lib/instances/traits/personality/manipulative.c");
    addTrait("/lib/instances/traits/personality/passionate.c");
    addTrait("/lib/instances/traits/personality/sardonic.c");
    addTrait("/lib/instances/traits/personality/stubborn.c");

    addConversation("/tutorial/temple/characters/vilias/startingConversation.c");
}

/////////////////////////////////////////////////////////////////////////////
public void revealName()
{
    short("Vilias");
}
