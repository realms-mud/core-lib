//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("unarmed");
    addHitDictionary(({
        "punch", "slam", "pound", "jab", "crush", "batter", "pummel", "strike",
        "slap", "cuff", "swat", "thump" }));

    addSimileDictionary(({
        "right in the ##BodyPart##", "ferociously", "with a bone-crunching force",
        "resoundingly" }));

    addMissMessage("##AttackerName## ##Infinitive::shadowbox##!");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-150");
}
