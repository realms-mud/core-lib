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
        setDamageType("electricity");
        addHitDictionary(({
            "shock", "singe", "fry", "zap", "blast", "zing", "jolt",
            "zap" }));

        addSimileDictionary(({
            "through ##TargetPossessive::Name## ##BodyPart##", "leaving a scent of ozone",
            "with a sickening crackle" }));

        addMissMessage("##AttackerName## ##Infinitive::look## quite "
            "surprised as ##AttackerSubjective## ##Infinitive::shock## "
            "##AttackerReflexive## with a bolt of electricity.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary##.", "1-50");
        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName##, "
            "scorching ##TargetPossessive## ##BodyPart##.", "51-90");
    }
}



