//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("electricity");
    damagesEthereal();
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
        "scorching ##TargetPossessive## ##BodyPart##.", "51-190");
}
