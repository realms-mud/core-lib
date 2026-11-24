//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Scions Begin Again");
    setDescription("After reading the Scions' history, I can help Renveth "
        "restore the collapsed order.");

    addState("history read", "I read the history of the Scions of Dhuras. "
        "Renveth, a Minlach resident with no former membership in the "
        "order, believes it can be rebuilt.");
    addState("book delivered", "I gave Renveth the Scions' history book. "
        "He has the record he needs, but has not yet heard what happened "
        "at Tol-Dhurath.");
    addState("release reported", "I told Renveth that the prisoner beneath "
        "Tol-Dhurath was freed. He now understands why the order must "
        "begin again.");
    addState("order restored", "Renveth accepted the history and the "
        "responsibility of leading a renewed Scions of Dhuras. The order "
        "can accept new members again.");

    addTransition("history read", "book delivered", "scionsBookGiven");
    addTransition("history read", "release reported",
        "tolDhurathReleaseReported");
    addTransition("book delivered", "order restored",
        "tolDhurathReleaseReported");
    addTransition("release reported", "order restored", "scionsBookGiven");
    addFinalState("order restored", "success");
    setInitialState("history read");
}
