//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void advanceState(object player, string state)
{
    questItem::advanceState(player, state);
    player->onStateChanged(this_object(), state);
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setName("Something's Rotten in Tol-Dhurath");
    setType("primary");
    setDescription("At our own initiative, Galadhel, Halgaladh and I "
        "set out from Argalen to investigate reports of unfamiliar "
        "travelers on the western road to Tol-Dhurath.");

    addState("journey begun", "Galadhel, Halgaladh and I left Argalen "
        "by choice to investigate reports of unfamiliar carts heading "
        "along the western road toward Tol-Dhurath.");

    addState("met maiwyn",
        "In the ruins, we met a captive woman who called herself "
        "Maiwyn. Her account suggests that the outlaws here are part "
        "of a larger design, and she named Lord Sullath.");
    addTransition("journey begun", "met maiwyn", "met maiwyn");

    addState("a helping hand",
        "Maiwyn has chosen to help us understand the ruins and the "
        "people holding them. She will stay near the gate while we "
        "investigate further.");
    addTransition("met maiwyn", "a helping hand", "maiwyn helps");

    addState("trial complete", "By obeying the Test's final demand, I "
        "broke the seal and unleashed the great evil upon the world "
        "again. The goddess is free, and the ruin she promised is my "
        "responsibility. I must return to Argalen and tell my family "
        "what my obedience has wrought.");
    addTransition("a helping hand", "trial complete",
        "obedience trial complete");
    addFinalState("trial complete", "success");

    setInitialState("journey begun");
}
