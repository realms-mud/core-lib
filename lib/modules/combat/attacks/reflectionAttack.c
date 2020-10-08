//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("magical");

        addMissMessage("##AttackerName## ##Infinitive::reflect## the attack, but fails to do any damage.");

        addHitMessage("##AttackerName## ##Infinitive::reflect## the attack back to ##TargetName##.", "1-150");
    }
}
