//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("physical");
        addHitDictionary(({
            "impale", "stab", "puncture", "gore", "strike" }));

        addSimileDictionary(({
            "rending ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
            "the ##BodyPart##" }));

        // Had to be as generic as possible to allow for single or multiple tusks.

        addMissMessage("##AttackerName## ##Infinitive::stab## wildly at the air.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary##.", "1-150");
    }
}
