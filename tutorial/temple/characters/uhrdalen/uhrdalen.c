//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("uhrdalen");
    short("A wispy figure");
    description("The wispy figure is largely skeletal in nature, though "
        "ethereal and without substance. A bitterly frigid chill emanates "
        "from the thing. It is enveloped by a thin white veil, almost as of "
        "silk.");
    addAlias("wispy figure");
    addAlias("figure");

    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("wraith", 20);

    addConversation("/tutorial/temple/characters/uhrdalen/startingConversation.c");

    registerEventHandler("uhrdalenLeft");
    registerEventHandler("startFirstTest");
}

/////////////////////////////////////////////////////////////////////////////
public void revealName()
{
    short("Uhrdalen");
}
