//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("arrow");
        addHitDictionary(({
            "impale", "pierce", "puncture", "skewer", "shoot", "riddle",
            "perforate", "stick", "prick", "hit" }));

        addSimileDictionary(({
            "expertly with an arrow", 
            "with a well-aimed arrow", 
            "through ##TargetPossessive::Name## ##BodyPart## with an arrow",
            "with an arrow" }));

        addMissMessage("##AttackerName## ##Infinitive::shoot## an arrow at"
            " nothing whatsoever!");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## from ##AttackerPossessive##"
            " ##AttackerWeapon##.", "1-150");
    }
}
