//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("cold");
        addHitDictionary(({
            "blast", "whip", "slice", "freeze", "chill", "crush", "slam" }));

        addSimileDictionary(({
            "and ##Infinitive::lash## ##TargetPossessive## body with icy tendrils",
            "leaving ice crystals hanging in the air", "with a spine-tingling"
            " arctic force", "in ##TargetPossessive::Name## ##BodyPart##" }));

        addMissMessage("##AttackerName## ##Infinitive::make## a bunch of pretty "
            "snowflakes.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary##.", "1-50");
    }
}



