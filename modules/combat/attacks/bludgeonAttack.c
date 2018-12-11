//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("bludgeon");
        addHitDictionary(({
            "bash", "smash", "pummel", "slam", "smack", "clobber",
            "whack" }));

        addSimileDictionary(({
            "soundly", "solidly", "on ##TargetPossessive## ##BodyPart##",
            "viciously", "with bone-crushing force" }));

        addMissMessage("##AttackerName## ##Infinitive::bludgeon## invisible foes!");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary##.", "1-150");
    }
}



