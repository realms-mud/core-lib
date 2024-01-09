//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("magical");

    addMissMessage("##AttackerName## ##Infinitive::reflect## the attack, but "
        "fails to do any damage.");

    addHitMessage("##AttackerName## ##Infinitive::reflect## the attack back "
        "to ##TargetName##.", "1-150");
}
